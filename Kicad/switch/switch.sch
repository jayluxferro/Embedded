EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Simple Switch Design"
Date "2018-05-28"
Rev "1.0"
Comp "SPERIXLABS"
Comment1 "Jay Lux Ferro"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R1
U 1 1 5B0C1F34
P 4750 3100
F 0 "R1" V 4830 3100 50  0000 C CNN
F 1 "1K" V 4650 3100 50  0000 C CNN
F 2 "" V 4680 3100 50  0001 C CNN
F 3 "" H 4750 3100 50  0001 C CNN
	1    4750 3100
	0    -1   -1   0   
$EndComp
$Comp
L LED_ALT D1
U 1 1 5B0C228B
P 5150 3100
F 0 "D1" H 5150 3200 50  0000 C CNN
F 1 "LED_ALT" H 5150 3000 50  0000 C CNN
F 2 "" H 5150 3100 50  0001 C CNN
F 3 "" H 5150 3100 50  0001 C CNN
	1    5150 3100
	-1   0    0    1   
$EndComp
$Comp
L Battery BT1
U 1 1 5B0C2322
P 4300 3350
F 0 "BT1" H 4400 3450 50  0000 L CNN
F 1 "Battery" H 4400 3350 50  0000 L CNN
F 2 "" V 4300 3410 50  0001 C CNN
F 3 "" V 4300 3410 50  0001 C CNN
	1    4300 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 3100 4300 3100
Wire Wire Line
	4300 3100 4300 3150
Wire Wire Line
	4900 3100 5000 3100
Wire Wire Line
	5300 3100 5300 3550
Wire Wire Line
	5300 3550 4300 3550
$Comp
L +5V #PWR01
U 1 1 5B0C263C
P 4450 2950
F 0 "#PWR01" H 4450 2800 50  0001 C CNN
F 1 "+5V" H 4450 3090 50  0000 C CNN
F 2 "" H 4450 2950 50  0001 C CNN
F 3 "" H 4450 2950 50  0001 C CNN
	1    4450 2950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5B0C265C
P 4750 3650
F 0 "#PWR02" H 4750 3400 50  0001 C CNN
F 1 "GND" H 4750 3500 50  0000 C CNN
F 2 "" H 4750 3650 50  0001 C CNN
F 3 "" H 4750 3650 50  0001 C CNN
	1    4750 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 2950 4450 3100
Connection ~ 4450 3100
Wire Wire Line
	4750 3650 4750 3550
Connection ~ 4750 3550
$Comp
L GND #PWR?
U 1 1 5B0C27F9
P 3850 3100
F 0 "#PWR?" H 3850 2850 50  0001 C CNN
F 1 "GND" H 3850 2950 50  0000 C CNN
F 2 "" H 3850 3100 50  0001 C CNN
F 3 "" H 3850 3100 50  0001 C CNN
	1    3850 3100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5B0C280D
P 3500 3100
F 0 "#PWR?" H 3500 2950 50  0001 C CNN
F 1 "+5V" H 3500 3240 50  0000 C CNN
F 2 "" H 3500 3100 50  0001 C CNN
F 3 "" H 3500 3100 50  0001 C CNN
	1    3500 3100
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 5B0C2826
P 3500 2950
F 0 "#FLG?" H 3500 3025 50  0001 C CNN
F 1 "PWR_FLAG" H 3500 3100 50  0000 C CNN
F 2 "" H 3500 2950 50  0001 C CNN
F 3 "" H 3500 2950 50  0001 C CNN
	1    3500 2950
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 5B0C2855
P 3850 2950
F 0 "#FLG?" H 3850 3025 50  0001 C CNN
F 1 "PWR_FLAG" H 3850 3100 50  0000 C CNN
F 2 "" H 3850 2950 50  0001 C CNN
F 3 "" H 3850 2950 50  0001 C CNN
	1    3850 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 2950 3850 3100
Wire Wire Line
	3500 2950 3500 3100
$EndSCHEMATC
