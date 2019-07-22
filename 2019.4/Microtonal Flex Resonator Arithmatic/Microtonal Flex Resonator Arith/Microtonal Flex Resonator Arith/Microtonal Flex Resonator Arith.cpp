#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

//User Inputs
char UI_Choice;
double BeatsPerMeasure;
double BeatsPerMin;
double BarsNum;
std::string WaveForm[] = {"SINE", "TRIANGLE", "SAWTOOTH", "SQUARE", "PULSE"};
bool Unison;
int WaveFormSelect; //selects between a string array of options
double inputFreqArray[] = {27.5, 29.1352, 30.8677, 32.7032, 34.6478, 36.7081, 38.8909, 41.2034, 43.6535, 46.2493, 48.9994, 51.9131}; //range is A0 to G#0, any additional Choices are simply multiplying by the harmonic.
double inputFreq;
double inputHarm;
double synthNum = 0;
double flexAmount; //preferably between 1-5% otherwise the results will be too unweildy;
bool DualOscGen = false;

//Outputs/Variables
double Duration; // Calculation of bpm inputs and number of bars

//Declaration for the compiler
double DurationCalc(double beatsPerMeasure, double beatsPerMin, double bars);
double OSCCreator(std::string OSCSelect, double frequency, double HarmonicNum, double flex);
double FlexCalc(double flexAmount);

//Global Variable for Text file output
std::string line; //used to parse through the file and output its contents
std::ofstream genFile("flexFile.txt");


int FileOutput() //mainly used for debugging purposes. Outputs file to command line console.
{
	//below is a test for reading output for the csound files, then changing the output.
	std::string line; //used to parse through the file and output its contents
	std::ifstream genFile("vcf2.txt");
	if (genFile.is_open())
	{
		while (getline(genFile, line))
		{
			std::cout << line << '\n';
		}
		genFile.close();
	}
	else std::cout << "Unable to open file.";
	return 0;
}

double DurationCalc(double beatsPerMeasure, double beatsPerMin, double bars) //takes in the beats per measure (time sig), number of measures (length), and tempo (bpm)
{
	Duration = (beatsPerMeasure * (bars / beatsPerMin) * 60.0);
	return Duration;
}


double OSCCreator(std::string OSCSelect, double frequency, double HarmonicNum, double flex)
{
	if (DualOscGen == false)
	{
		genFile << "OSC ga" << 1 << " " << frequency << " " << OSCSelect << " NONE NONE -1 1\n"; //original specified Frequency. "Root Note"
		synthNum++;
		for (double x = 2; x <= HarmonicNum; x++)
		{
			//generates the harmonics by using x as the harmonic selector. The flex is added in the FM modulation slot to essentially change the frequency by the flexed amount.
			genFile << "OSC ga" << x << " " << frequency * x << " " << OSCSelect << " " << "NONE" << " " << frequency * x * flex << " -1 1\n";
			synthNum++;
		}
	}
	if (DualOscGen == true)
	{
		int y = (2 * HarmonicNum) - 1;
		genFile << "OSC ga" << 1 << " " << frequency << " " << OSCSelect << " NONE NONE -1 1\n"; //original specified Frequency. "Root Note"
		synthNum++;
		for (double x = 2; x <= HarmonicNum; x++)
		{
			//generates the harmonics by using x as the harmonic selector. The flex is added in the FM modulation slot to essentially change the frequency by the flexed amount.
			genFile << "OSC ga" << x << " " << frequency * x << " " << OSCSelect << " " << "NONE" << " " << frequency * x * flex << " -1 1\n";
			synthNum++;
			genFile << "OSC ga" << y << " " << frequency * x << " " << OSCSelect << " " << "NONE" << " " << "NONE" << " -1 1\n";
			synthNum++;
			y--;
		}
		for (double x = (2 * HarmonicNum) - 1; HarmonicNum <= x; x--)
		{

		}
	}
	return 0;
}

double MixOutCalc(int SynthNum)
{
	genFile << "MIXOUT ";
	for (int x = 1; x <= SynthNum; x++)
	{
		genFile << "ga" << x;
		if (x < SynthNum)
		{
			genFile << "+";
		}
	}
	genFile << " " << 2000;
	return 0;
}

double FlexCalc(double flexAmount)
{
	double f;
	f = flexAmount / 100000.0;
	return f;
}

int FileCreate() // Creates a file used in conjunction with synmod to create a csd file.
{
	if (genFile.is_open())
	{
		genFile << "DURATION ";
		genFile << DurationCalc(BeatsPerMeasure, BeatsPerMin, BarsNum) << "\n";
		OSCCreator(WaveForm[WaveFormSelect], inputFreq, inputHarm, FlexCalc(flexAmount));
		MixOutCalc(synthNum);
		genFile.close();
	}
	else std::cout << "Unable to open file.";
	return 0;
}

int ModifyDefaultDuration() {
	switch (UI_Choice)
	{
	case 'y':
		std::cout << "Please enter beats per measure, beats per minute, and number of bars requested.\n";
		std::cin >> BeatsPerMeasure;
		std::cin >> BeatsPerMin;
		std::cin >> BarsNum;
		break;
	case 'n':
		break;
	default:
		std::cout << "Invalid Selection." << std::endl;
		ModifyDefaultDuration();
		break;
	}
	return 0;
}

int UI_WaveFormSelect() {
	std::cout << "Please enter which waveform you'd like to use.";
	for (int i = 0; i <= 4; i++)
	{
		std::cout << "\n" << (i+1) << ". " << WaveForm[i];
	}
	std::cin >> UI_Choice;
	switch (UI_Choice)
	{
	case '1':
		WaveFormSelect = 0;
		break;
	case '2':
		WaveFormSelect = 1;
		break;
	case '3':
		WaveFormSelect = 2;
		break;
	case '4':
		WaveFormSelect = 3;
		break;
	case '5':
		WaveFormSelect = 4;
		break;
	default:
		std::cout << "Invalid Selection." << std::endl;
		UI_WaveFormSelect();
		break;
	}
	return 0;
}

int ModifyDefaultWaveform() {
	std::cout << "Would you like to change the waveform used in generation? (Default is Sine). y/n\n";
	std::cin >> UI_Choice;
	switch (UI_Choice)
	{
	case 'y':
		UI_WaveFormSelect();
		break;
	case 'n':
		break;
	default:
		std::cout << "Invalid Selection." << std::endl;
		ModifyDefaultWaveform();
		break;
	}
	return 0;
}

int NoteSelection() {
	std::string NoteInput;
	std::cout << "Please enter which note you'd like to generate:  (Ex, enter A0, B#2, and only enter sharps)\n";
	std::cin >> NoteInput;

	char *InputArray = new char[NoteInput.size() + 1];
	InputArray[NoteInput.size()] = '0';
	memcpy(InputArray, NoteInput.c_str(), NoteInput.size());

	switch (InputArray[0])
	{
	case 'A':
		if (InputArray[1] == '#'){
			if (InputArray[2] != '0') {
				inputFreq = inputFreqArray[(InputArray[2] - '0')]  * (InputArray[2] - '0');
			}
			else
			{
				inputFreq = inputFreqArray[(InputArray[2]- '0')];
			}
			
		}
		else {
			if (InputArray[1] != '0') {
				inputFreq = inputFreqArray[(InputArray[1]- '0')] * (InputArray[1] - '0');
			}
			else
			{
				inputFreq = inputFreqArray[(InputArray[1] - '0')];
			}
		}
		break;
	case 'B':
		if (InputArray[1] != '0') {
			inputFreq = inputFreqArray[(InputArray[1] - '0')] * (InputArray[1] - '0');
		}
		else
		{
			inputFreq = inputFreqArray[(InputArray[1] - '0')];
		}
		break;
	case 'C':
		if (InputArray[1] == '#') {
			if (InputArray[2] != '0') {
				inputFreq = inputFreqArray[(InputArray[2] - '0')] * (InputArray[2] - '0');
			}
			else
			{
				inputFreq = inputFreqArray[(InputArray[2] - '0')];
			}

		}
		else {
			if (InputArray[1] != '0') {
				inputFreq = inputFreqArray[(InputArray[1] - '0')] * (InputArray[1] - '0');
			}
			else
			{
				inputFreq = inputFreqArray[(InputArray[1] - '0')];
			}
		}
		break;
	case 'D':
		if (InputArray[1] == '#') {
			if (InputArray[2] != '0') {
				inputFreq = inputFreqArray[(InputArray[2] - '0')] * (InputArray[2] - '0');
			}
			else
			{
				inputFreq = inputFreqArray[(InputArray[2] - '0')];
			}

		}
		else {
			if (InputArray[1] != '0') {
				inputFreq = inputFreqArray[(InputArray[1] - '0')] * (InputArray[1] - '0');
			}
			else
			{
				inputFreq = inputFreqArray[(InputArray[1] - '0')];
			}
		}
		break;
	case 'E':
		if (InputArray[1] != '0') {
			inputFreq = inputFreqArray[(InputArray[1] - '0')] * (InputArray[1] - '0');
		}
		else
		{
			inputFreq = inputFreqArray[(InputArray[1] - '0')];
		}
		break;
	case 'F':
		if (InputArray[1] == '#') {
			if (InputArray[2] != '0') {
				inputFreq = inputFreqArray[(InputArray[2] - '0')] * (InputArray[2] - '0');
			}
			else
			{
				inputFreq = inputFreqArray[(InputArray[2] - '0')];
			}

		}
		else {
			if (InputArray[1] != '0') {
				inputFreq = inputFreqArray[(InputArray[1] - '0')] * (InputArray[1] - '0');
			}
			else
			{
				inputFreq = inputFreqArray[(InputArray[1] - '0')];
			}
		}
		break;
	case 'G':
		if (InputArray[1] == '#') {
			if (InputArray[2] != '0') {
				inputFreq = inputFreqArray[(InputArray[2] - '0')] * (InputArray[2] - '0');
			}
			else
			{
				inputFreq = inputFreqArray[(InputArray[2] - '0')];
			}

		}
		else {
			if (InputArray[1] != '0') {
				inputFreq = inputFreqArray[(InputArray[1] - '0')] * (InputArray[1] - '0');
			}
			else
			{
				inputFreq = inputFreqArray[(InputArray[1] - '0')];
			}
		}
		break;
	default:
		std::cout << "Invalid Selection." << std::endl;
		NoteSelection();
		break;
	}
	return 0;
	delete InputArray;
}

int SelectFrequencyOrNote()
{
	std::cout << "Would you like to input a frequency or select a note?\n";
	std::cout << "1. Frequency" << "\n2. Note" << std::endl;
	std::cin >> UI_Choice;
	switch (UI_Choice)
	{
	case '1':
		std::cout << "Please Input a primary Frequency and number of harmonics desired." << std::endl;
		std::cin >> inputFreq;
		std::cin >> inputHarm;
		break;
	case '2':
		NoteSelection();
		std::cout << "Please Input the number of harmonics desired." << std::endl;
		std::cin >> inputHarm;
		break;
	default:
		std::cout << "Invalid Selection." << std::endl;
		SelectFrequencyOrNote();
		break;
	}
	return 0;
}

int UI_FlexAmount() {
	std::cout << "Finally, how much flex would you like to add to the harmonics? (1-100) 1 flex unit is equivilent to aproximately .001 hz of detune.\n";
	std::cin >> flexAmount;
	return 0;
}

int DualOscEffect() {
	std::cout << "Would you like double oscillators for each harmonic? This introduces a beating effect.\n";
	std::cin >> UI_Choice;
	switch (UI_Choice)
	{
	case 'y':
		DualOscGen = true;
		break;
	case 'n':
		DualOscGen = false;
		break;
	default:
		std::cout << "Invalid Selection." << std::endl;
		DualOscEffect();
		break;
	}
	return 0;
}

int UserInputGather()
{
	std::cout << "Welcome to The Microtonal Flex Resonator!" << std::endl;
	std::cout << "Default Construction is 4 beats per measure at 172bpm with 8 bars total.\n";
	std::cout << "Would you like to change any of these values? y/n\n";
	std::cin >> UI_Choice;
	ModifyDefaultDuration();
	ModifyDefaultWaveform();
	SelectFrequencyOrNote();
	UI_FlexAmount();
	DualOscEffect();
	return 0;
}

int main()
{
	//Default Paramter mappings
	BeatsPerMeasure = 4.0;
	BeatsPerMin = 172.0;
	BarsNum = 8.0;
	WaveFormSelect = 0;

	UserInputGather();
	FileCreate();
	std::cout << "FLEX FILE GENERATED";
	//FileOutput();
}


/*
CSD File Formatting information

KEY: 
DURATION TIME(SECONDS)
OSC: OUTPUT, FREQUENCY, WAVEFORM, AM, FM, OUTMIN, OUTMAX	//Oscillator Generator:	
	//Available Waveforms: SINE, TRIANGLE, SAWTOOTH, SQUARE, and PULSE
	//
NOISE OUTPUT, SPEED, SEED, OUTMIN, OUTMAX					//Noise Generator
MIXOUT OUTPUT, AMPLITUDE									//Outputs and amplitude functionality

Keep the combined outputs under 32000 otherwise it'll clip.
Each signal outputs around 2000,

(osc * number_of_osc) * 2000 <= 32000 otherwise it'll clip.


Example File Formatting
DURATION 30													//for total score length
OSC ga1 100 SAWTOOTH NONE NONE -1 1							//oscillator 1, frequency, type, 
OSC ga2 125.1 SAWTOOTH NONE NONE -1 1
OSC ga3 150.25 SAWTOOTH NONE NONE -1 1
OSC ga4 187.6 SAWTOOTH NONE NONE -1 1
OSC ga5 225.8 SAWTOOTH NONE NONE -1 1
NOISE ga6 1.5 .845 100 1500
VCF ga7 (ga1+ga2+ga3+ga4+ga5)*0.2 ga6 0.9
NOISE ga8 0.3 .225 100 1500
VCF ga9 (ga1+ga2+ga3+ga4+ga5)*0.2 ga8 0.9
NOISE ga10 0.3 .125 400 2500
VCF ga11 (ga1+ga2+ga3+ga4+ga5)*0.2 ga10 0.9
MIXOUT ga7+ga9+ga11 10000
*/