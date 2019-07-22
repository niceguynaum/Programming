/////////////////////////////////  Includes  //////////////////////////////////

#include "stdafx.h"
#include "SerialPort.h"


//////////////////////////////// Implementation ///////////////////////////////

VOID WINAPI CompletionRoutine(_In_ DWORD dwErrorCode, _In_ DWORD dwNumberOfBytesTransfered, _Inout_ LPOVERLAPPED lpOverlapped) noexcept
{
  UNREFERENCED_PARAMETER(dwErrorCode);
  UNREFERENCED_PARAMETER(dwNumberOfBytesTransfered);
  UNREFERENCED_PARAMETER(lpOverlapped);
}

int _tmain()
{
#ifdef CSERIALPORT_MFC_EXTENSIONS
  //initialize MFC
  if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
  {
    _tprintf(_T("Failed to initialize MFC\n"));
    return 1;
  }
#endif //#ifdef CSERIALPORT_MFC_EXTENSIONS

  //Please note that all the following is just test code to exercise the CSerialPort API. It assumes
  //that a COM1 is available on the local computer.
  std::vector<BYTE> buf;
  buf.resize(10000);
  for (size_t i=0; i<buf.size(); i++)
#pragma warning(suppress: 26446)
    buf[i] = '%';
  HANDLE hEvent = nullptr;
  const int nPortToUse = 1;

  try
  {
    COMMCONFIG config;
    CSerialPort::GetDefaultConfig(nPortToUse, config);

    CSerialPort port;
    port.Open(nPortToUse, 1200, CSerialPort::NoParity, 8, CSerialPort::OneStopBit, CSerialPort::XonXoffFlowControl);

    HANDLE hPort = port.Detach();
    port.Attach(hPort);

    DWORD dwModemStatus;
    port.GetModemStatus(dwModemStatus);

    DCB dcb;
    port.GetState(dcb);

    dcb.BaudRate = 9600;
    port.SetState(dcb);    

    DWORD dwErrors = 0;                      
    port.ClearError(dwErrors);

    port.SetBreak();
    port.ClearBreak();

    COMSTAT stat = { 0 };
    port.GetStatus(stat);

    COMMTIMEOUTS timeouts = { 0 };
    port.GetTimeouts(timeouts);

    port.Setup(10000, 10000);

    port.GetConfig(config);

    config.dcb.BaudRate = 9600;
    port.SetConfig(config);

    port.Set0WriteTimeout();
    port.Set0ReadTimeout();

    const char* pszBuf = "This should appear on the serial port";
#pragma warning(suppress: 26472)
    port.Write(pszBuf, static_cast<DWORD>(strlen(pszBuf)));

    DWORD dwMask = 0;
    port.GetMask(dwMask);

    port.SetMask(EV_TXEMPTY); 

    //port.WaitEvent(dwMask);

    port.TerminateOutstandingWrites();

    port.TransmitChar('p');

    port.Set0Timeout();

    std::vector<char> rxBuf;
    rxBuf.resize(10);
#pragma warning(suppress: 26472)
    const DWORD dwRead = port.Read(rxBuf.data(), static_cast<DWORD>(rxBuf.size()));
    UNREFERENCED_PARAMETER(dwRead);

    port.TerminateOutstandingReads();

    port.ClearDTR();

    port.ClearRTS();

    port.SetDTR();

    port.SetRTS();

    //port.SetXOFF();

    //port.SetXON();

    COMMPROP properties = { 0 };
    port.GetProperties(properties);

    port.ClearWriteBuffer();

    port.ClearReadBuffer();

    port.Flush();

    port.CancelIo();

    port.Close();


    //Try out the overlapped functions
    CSerialPort port2;
    port2.Open(nPortToUse, 9600, CSerialPort::NoParity, 8, CSerialPort::OneStopBit, CSerialPort::XonXoffFlowControl, TRUE);

    OVERLAPPED overlapped = { 0 };
    hEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);
#pragma warning(suppress: 26477)
    ATLASSERT(hEvent != nullptr);
    overlapped.hEvent = hEvent;

    try
    {
#pragma warning(suppress: 26472 26486)
      port2.Write(buf.data(), static_cast<DWORD>(buf.size()), overlapped);
    }
  #ifdef CSERIALPORT_MFC_EXTENSIONS
    catch(CSerialException* pEx)
    {
      if (pEx->m_dwError == ERROR_IO_PENDING)
      {
        DWORD dwBytesTransferred = 0;
        port2.GetOverlappedResult(overlapped, dwBytesTransferred, TRUE);
        pEx->Delete();
      }
      else
      {
        const DWORD dwError = pEx->m_dwError;
        pEx->Delete();
        CSerialPort::ThrowSerialException(dwError);
      }
    }
  #else
    catch(CSerialException& e)
    {
      if (e.m_dwError == ERROR_IO_PENDING)
      {
        DWORD dwBytesTransferred = 0;
        port2.GetOverlappedResult(overlapped, dwBytesTransferred, TRUE);
      }
      else
      {
        CSerialPort::ThrowSerialException(e.m_dwError);
      }
    }
  #endif
    try
    {
      port2.Read(buf.data(), 10, overlapped);
    }
  #ifdef CSERIALPORT_MFC_EXTENSIONS
    catch(CSerialException* pEx)
    {
      if (pEx->m_dwError == ERROR_IO_PENDING)
      {
        DWORD dwBytesTransferred = 0;
        port2.GetOverlappedResult(overlapped, dwBytesTransferred, TRUE);
        pEx->Delete();
      }
      else
      {
        const DWORD dwError = pEx->m_dwError;
        pEx->Delete();
        CSerialPort::ThrowSerialException(dwError);
      }
    }
  #else
    catch(CSerialException& e)
    {
      if (e.m_dwError == ERROR_IO_PENDING)
      {
        DWORD dwBytesTransferred = 0;
        port2.GetOverlappedResult(overlapped, dwBytesTransferred, TRUE);
      }
      else
      {
        CSerialPort::ThrowSerialException(e.m_dwError);
      }
    }
  #endif

    port2.SetMask(EV_TXEMPTY);

#pragma warning(suppress: 26472)
    port2.WriteEx(pszBuf, static_cast<DWORD>(strlen(pszBuf)), &overlapped, CompletionRoutine);
    SleepEx(INFINITE, TRUE);
    port2.ReadEx(buf.data(), 10, &overlapped, CompletionRoutine);
    SleepEx(INFINITE, TRUE);
  }
#ifdef CSERIALPORT_MFC_EXTENSIONS
#pragma warning(suppress: 26462)
  catch (CSerialException* pEx)
  {
    ATLTRACE(_T("Unexpected CSerialPort exception, Error:%u,%s\n"), pEx->m_dwError, pEx->GetErrorMessage().GetString());
    pEx->Delete();
  }
#else
  catch (CSerialException& e)
  {
    ATLTRACE(_T("Unexpected CSerialPort exception, Error:%u\n"), e.m_dwError);
    UNREFERENCED_PARAMETER(e);
  }
#endif //#ifdef CSERIALPORT_MFC_EXTENSIONS

  //Clean up the resources we have been using
  if (hEvent != nullptr)
  {
    CloseHandle(hEvent);
    hEvent = nullptr;
  }

  return 0;
}
