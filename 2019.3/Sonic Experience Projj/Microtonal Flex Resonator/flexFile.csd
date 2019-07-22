<CsoundSynthesizer>

sr = 44100
kr = 4410
ksmps = 10
nchnls = 1

<CsInstruments>

	instr 1
isine = 1
itriangle = 2
isawtooth = 3
isquare = 4
ipulse = 5
ga1 init 0.0
ga2 init 0.0
ga9 init 0.0
ga3 init 0.0
ga8 init 0.0
ga4 init 0.0
ga7 init 0.0
ga5 init 0.0
ga6 init 0.0
ga1 oscil 1.0, 27.5, isquare
ga2 oscil 1.0, 55 * (1.0 + 0.055), isquare
ga9 oscil 1.0, 55, isquare
ga3 oscil 1.0, 82.5 * (1.0 + 0.0825), isquare
ga8 oscil 1.0, 82.5, isquare
ga4 oscil 1.0, 110 * (1.0 + 0.11), isquare
ga7 oscil 1.0, 110, isquare
ga5 oscil 1.0, 137.5 * (1.0 + 0.1375), isquare
ga6 oscil 1.0, 137.5, isquare
kenv linseg 0,.05,2000.000000,p3-0.1,2000.000000,.05,0
out (ga1+ga2+ga3+ga4+ga5+ga6+ga7+ga8+ga9)*kenv
	endin

</CsInstruments>
<CsScore>

f1 0 8192 10 1 ; sine
f2 0 8192 10 1 0 .111 0 .04 0 .02 0 ; triangle
f3 0 8192 10 1 .5 .333 .25 .2 .166 .142 .125 ; sawtooth
f4 0 8192 10 1 0 .333 0 .2 0 .142 0 .111; square
f5 0 8192 10 1 1 1 1 1 1 1 1 1 1 1 1 1; pulse

i1 0 11.162800

</CsScore>
</CsoundSynthesizer>
