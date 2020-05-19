EESchema Schematic File Version 4
LIBS:2M_DRA818V_Transceiver_tft_encoder-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_02x10_Odd_Even J1
U 1 1 5F109261
P 4100 2550
F 0 "J1" H 4150 3167 50  0000 C CNN
F 1 "Conn" H 4150 3076 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x10_P2.54mm_Vertical" H 4100 2550 50  0001 C CNN
F 3 "~" H 4100 2550 50  0001 C CNN
	1    4100 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 2150 3550 2150
Wire Wire Line
	3900 2250 3550 2250
Wire Wire Line
	3900 2350 3550 2350
Wire Wire Line
	3900 2450 3550 2450
Wire Wire Line
	3900 2550 3550 2550
Wire Wire Line
	3900 2650 3550 2650
Wire Wire Line
	3900 2850 3550 2850
Wire Wire Line
	3900 2950 3550 2950
Wire Wire Line
	4400 2250 4750 2250
Wire Wire Line
	4400 2350 4750 2350
Wire Wire Line
	4400 2450 4750 2450
Wire Wire Line
	4400 2650 4750 2650
Wire Wire Line
	4400 2750 4750 2750
Wire Wire Line
	4400 2850 4750 2850
Wire Wire Line
	4400 2950 4750 2950
Wire Wire Line
	5350 2150 5350 2200
Wire Wire Line
	4400 2150 5350 2150
$Comp
L power:GND #PWR02
U 1 1 5F10E2E3
P 5350 2200
F 0 "#PWR02" H 5350 1950 50  0001 C CNN
F 1 "GND" H 5355 2027 50  0000 C CNN
F 2 "" H 5350 2200 50  0001 C CNN
F 3 "" H 5350 2200 50  0001 C CNN
	1    5350 2200
	1    0    0    -1  
$EndComp
Text GLabel 3550 2150 0    50   Input ~ 0
+3V3
Text GLabel 3550 2250 0    50   Input ~ 0
CS
Text GLabel 3550 2350 0    50   Input ~ 0
DC_RS
Text GLabel 3550 2450 0    50   Input ~ 0
SCK
Text GLabel 3550 2550 0    50   Input ~ 0
SDO_MOSO
Text GLabel 3550 2650 0    50   Input ~ 0
ENC_A
Text GLabel 3550 2950 0    50   Input ~ 0
btnRIGHT
Text GLabel 3550 3050 0    50   Input ~ 0
btnDOWN
Text GLabel 4750 2250 2    50   Input ~ 0
+3V3
Text GLabel 4750 2350 2    50   Input ~ 0
SDI_MOSI
Text GLabel 4750 2450 2    50   Input ~ 0
LED
Text GLabel 4750 2650 2    50   Input ~ 0
ENC_SW
Text GLabel 4750 2750 2    50   Input ~ 0
ENC_B
Text GLabel 4750 2850 2    50   Input ~ 0
btnUP
Text GLabel 4750 2950 2    50   Input ~ 0
btnLEFT
Text Notes 4850 1850 2    50   ~ 0
2x10 vertical connector (female)\nFarnell 102 2300\nArcher M50 Series
$Comp
L Connector_Generic:Conn_01x09 J2
U 1 1 5F10F391
P 4150 4850
F 0 "J2" H 4230 4892 50  0000 L CNN
F 1 "Conn" H 4230 4801 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical" H 4150 4850 50  0001 C CNN
F 3 "~" H 4150 4850 50  0001 C CNN
	1    4150 4850
	1    0    0    -1  
$EndComp
Text Notes 4650 4250 2    50   ~ 0
Generic 1.27mm pin header for tft display
Wire Wire Line
	3950 4450 3550 4450
Wire Wire Line
	3950 4650 3550 4650
Wire Wire Line
	3950 4750 3550 4750
Wire Wire Line
	3950 4850 3550 4850
Wire Wire Line
	3950 4950 3550 4950
Wire Wire Line
	3950 5050 3550 5050
Wire Wire Line
	3950 5150 3550 5150
Wire Wire Line
	3950 5250 3550 5250
Text GLabel 3550 4450 0    50   Input ~ 0
+3V3
Text GLabel 3550 4650 0    50   Input ~ 0
CS
Text GLabel 3550 4750 0    50   Input ~ 0
+3V3
Text GLabel 3550 4850 0    50   Input ~ 0
DC_RS
Text GLabel 3550 4950 0    50   Input ~ 0
SDI_MOSI
Text GLabel 3550 5050 0    50   Input ~ 0
SCK
Text GLabel 3550 5150 0    50   Input ~ 0
LED
Text GLabel 3550 5250 0    50   Input ~ 0
SDO_MOSO
Wire Wire Line
	2950 4550 2950 4650
Wire Wire Line
	2950 4550 3950 4550
$Comp
L power:GND #PWR01
U 1 1 5F114C68
P 2950 4650
F 0 "#PWR01" H 2950 4400 50  0001 C CNN
F 1 "GND" H 2955 4477 50  0000 C CNN
F 2 "" H 2950 4650 50  0001 C CNN
F 3 "" H 2950 4650 50  0001 C CNN
	1    2950 4650
	1    0    0    -1  
$EndComp
$Comp
L dk_Encoders:PEC11R-4215F-S0024 S1
U 1 1 5F1154DD
P 7650 2500
F 0 "S1" H 7600 2872 60  0000 C CNN
F 1 "Encoder" H 7600 2766 60  0000 C CNN
F 2 "digikey-footprints:Rotary_Encoder_Switched_PEC11R" H 7850 2700 60  0001 L CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PEC11R.pdf" H 7850 2800 60  0001 L CNN
F 4 "PEC11R-4215F-S0024-ND" H 7850 2900 60  0001 L CNN "Digi-Key_PN"
F 5 "PEC11R-4215F-S0024" H 7850 3000 60  0001 L CNN "MPN"
F 6 "Sensors, Transducers" H 7850 3100 60  0001 L CNN "Category"
F 7 "Encoders" H 7850 3200 60  0001 L CNN "Family"
F 8 "https://www.bourns.com/docs/Product-Datasheets/PEC11R.pdf" H 7850 3300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/bourns-inc/PEC11R-4215F-S0024/PEC11R-4215F-S0024-ND/4499665" H 7850 3400 60  0001 L CNN "DK_Detail_Page"
F 10 "ROTARY ENCODER MECHANICAL 24PPR" H 7850 3500 60  0001 L CNN "Description"
F 11 "Bourns Inc." H 7850 3600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 7850 3700 60  0001 L CNN "Status"
	1    7650 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2600 7050 2600
Wire Wire Line
	7050 2600 7050 3100
Wire Wire Line
	7850 2400 8000 2400
Wire Wire Line
	8000 2400 8000 3100
Wire Wire Line
	8000 3100 7250 3100
Wire Wire Line
	8000 3100 8000 3200
Connection ~ 8000 3100
$Comp
L power:GND #PWR03
U 1 1 5F118B44
P 8000 3200
F 0 "#PWR03" H 8000 2950 50  0001 C CNN
F 1 "GND" H 8005 3027 50  0000 C CNN
F 2 "" H 8000 3200 50  0001 C CNN
F 3 "" H 8000 3200 50  0001 C CNN
	1    8000 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2400 6850 2400
Wire Wire Line
	7350 2500 6850 2500
Wire Wire Line
	7350 2700 6850 2700
Text GLabel 6850 2400 0    50   Input ~ 0
ENC_SW
Text GLabel 6850 2700 0    50   Input ~ 0
ENC_B
Text GLabel 6850 2500 0    50   Input ~ 0
ENC_A
Wire Wire Line
	3900 3050 3550 3050
Text Notes 8250 1900 2    50   ~ 0
Standard 12mm 24 Detents, 24 Pulses encoder\nFarnell 152 0813\nPull-ups on main PCB
Text GLabel 4750 3050 2    50   Input ~ 0
btnToneBurst
Wire Wire Line
	4400 3050 4750 3050
Wire Wire Line
	3900 2750 3550 2750
Text GLabel 3550 2850 0    50   Input ~ 0
GPS_TX
Text GLabel 3550 2750 0    50   Input ~ 0
GPS_RX
Text Notes 7000 7100 0    50   ~ 0
Copyright (C) K Wheatley 2020\nThis documentation describes Open Hardware and is licensed under the CERN OHL v. 1.1.\nYou may redistribute and modify this documentation under the terms of the CERN OHL v.1.1. \n(http://ohwr.org/cernohl). \nThis documentation is distributed WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, \nINCLUDING OF MERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A PARTICULAR PURPOSE. \nPlease see the CERN OHL v.1.1 for applicable conditions.
$Comp
L Connector_Generic:Conn_01x10 J3
U 1 1 5DC7047D
P 7850 4750
F 0 "J3" H 7930 4742 50  0000 L CNN
F 1 "Conn" H 7930 4651 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical" H 7850 4750 50  0001 C CNN
F 3 "~" H 7850 4750 50  0001 C CNN
	1    7850 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 4350 7300 4350
Wire Wire Line
	7650 4450 7300 4450
Wire Wire Line
	7650 4550 7300 4550
Wire Wire Line
	7650 4650 7300 4650
Wire Wire Line
	7650 4750 7300 4750
Wire Wire Line
	7650 4850 7300 4850
Wire Wire Line
	7650 4950 7300 4950
Wire Wire Line
	7650 5150 7300 5150
Text GLabel 7300 4350 0    50   Input ~ 0
btnUP
Text GLabel 7300 4450 0    50   Input ~ 0
btnDOWN
Text GLabel 7300 4550 0    50   Input ~ 0
btnLEFT
Text GLabel 7300 4650 0    50   Input ~ 0
btnRIGHT
Text GLabel 7300 4750 0    50   Input ~ 0
btnToneBurst
Text GLabel 7300 4850 0    50   Input ~ 0
GPS_RX
Text GLabel 7300 4950 0    50   Input ~ 0
GPS_TX
Text GLabel 7300 5150 0    50   Input ~ 0
+3V3
Wire Wire Line
	6800 5250 6800 5350
Wire Wire Line
	6800 5250 7650 5250
Wire Wire Line
	6800 5050 6800 5250
Wire Wire Line
	6800 5050 7650 5050
Connection ~ 6800 5250
$Comp
L power:GND #PWR04
U 1 1 5DC81A5F
P 6800 5350
F 0 "#PWR04" H 6800 5100 50  0001 C CNN
F 1 "GND" H 6805 5177 50  0000 C CNN
F 2 "" H 6800 5350 50  0001 C CNN
F 3 "" H 6800 5350 50  0001 C CNN
	1    6800 5350
	1    0    0    -1  
$EndComp
Text Notes 7100 4100 0    50   ~ 0
1 x 10 vertical connector (female)\nFarnell 280 2334
Wire Wire Line
	7350 2800 7250 2800
Wire Wire Line
	7250 2800 7250 3100
Connection ~ 7250 3100
Wire Wire Line
	7250 3100 7050 3100
$EndSCHEMATC
