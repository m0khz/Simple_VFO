EESchema Schematic File Version 4
LIBS:Simple_VFO-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Simple VFO"
Date "5 April 2020"
Rev "V1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Regulator_Linear:LT1085-ADJ U6
U 1 1 5DA5BB4C
P 7750 1100
F 0 "U6" H 7750 1342 50  0000 C CNN
F 1 "LT1085-ADJ" H 7750 1251 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-263-3_TabPin2" H 7750 1350 50  0001 C CIN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/108345fh.pdf" H 7750 1100 50  0001 C CNN
	1    7750 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 5DA5D402
P 7150 1500
F 0 "C9" H 7265 1546 50  0000 L CNN
F 1 "10uF elec" H 7265 1455 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3216-12_Kemet-S_Pad1.58x1.35mm_HandSolder" H 7188 1350 50  0001 C CNN
F 3 "~" H 7150 1500 50  0001 C CNN
	1    7150 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5DA5DCA8
P 8750 1450
F 0 "C12" H 8865 1496 50  0000 L CNN
F 1 "10uF Tant" H 8865 1405 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3216-12_Kemet-S_Pad1.58x1.35mm_HandSolder" H 8788 1300 50  0001 C CNN
F 3 "~" H 8750 1450 50  0001 C CNN
	1    8750 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5DA60094
P 9400 1450
F 0 "C13" H 9285 1404 50  0000 R CNN
F 1 "100n" H 9285 1495 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9438 1300 50  0001 C CNN
F 3 "~" H 9400 1450 50  0001 C CNN
	1    9400 1450
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R7
U 1 1 5DA615EB
P 8300 1400
F 0 "R7" H 8359 1446 50  0000 L CNN
F 1 "120R" H 8359 1355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8300 1400 50  0001 C CNN
F 3 "~" H 8300 1400 50  0001 C CNN
	1    8300 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R8
U 1 1 5DA61C81
P 8300 1750
F 0 "R8" H 8359 1796 50  0000 L CNN
F 1 "365R" H 8359 1705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8300 1750 50  0001 C CNN
F 3 "~" H 8300 1750 50  0001 C CNN
	1    8300 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 1100 8300 1100
Wire Wire Line
	9400 1300 9400 1100
Wire Wire Line
	8750 1300 8750 1100
Wire Wire Line
	8300 1500 8300 1600
Wire Wire Line
	8300 1300 8300 1100
Connection ~ 8300 1100
Wire Wire Line
	8300 1100 8750 1100
Wire Wire Line
	8300 1850 8300 1900
Wire Wire Line
	7750 1600 8300 1600
Wire Wire Line
	7750 1400 7750 1600
Connection ~ 8300 1600
Wire Wire Line
	8300 1600 8300 1650
Wire Wire Line
	7150 1650 7150 1900
Wire Wire Line
	7150 1900 8300 1900
Connection ~ 8300 1900
Wire Wire Line
	8300 1900 8300 1950
Wire Wire Line
	7150 1350 7150 1100
Wire Wire Line
	7150 1100 7450 1100
Wire Wire Line
	8750 1600 8750 1900
Wire Wire Line
	8750 1900 8300 1900
Wire Wire Line
	9400 1600 9400 1900
Wire Wire Line
	8750 1100 9400 1100
Connection ~ 8750 1100
Wire Wire Line
	8750 1900 9400 1900
Connection ~ 8750 1900
Wire Wire Line
	7150 1100 7000 1100
Connection ~ 7150 1100
$Comp
L m0khz-symbol:Teensy_3_2 U3
U 1 1 5DDB5684
P 4600 3000
F 0 "U3" H 3950 3400 30  0000 C CNN
F 1 "Teensy_3_2" H 4050 3300 30  0000 C CNN
F 2 "m0khz-footprint:Teensy_3_2" H 4600 3000 30  0001 C CNN
F 3 "https://www.pjrc.com/store/teensy32.html" H 4600 3000 30  0001 C CNN
	1    4600 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0112
U 1 1 5DDC76BD
P 3250 3000
F 0 "#PWR0112" H 3250 2750 50  0001 C CNN
F 1 "GNDD" H 3255 2827 50  0000 C CNN
F 2 "" H 3250 3000 50  0001 C CNN
F 3 "" H 3250 3000 50  0001 C CNN
	1    3250 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 3200 5350 3200
Wire Wire Line
	4200 4000 3850 4000
Wire Wire Line
	4200 4100 3850 4100
Wire Wire Line
	4200 4200 3850 4200
Wire Wire Line
	4200 4300 3850 4300
Wire Wire Line
	5200 4300 5400 4300
Text GLabel 5400 3600 2    30   Input ~ 0
DC_RS
Text GLabel 5400 3500 2    30   Input ~ 0
CS
Text GLabel 3850 4200 0    30   Input ~ 0
SDI_MOSI
Text GLabel 3850 4300 0    30   Input ~ 0
SDO_MOSO
Text GLabel 5400 4300 2    30   Input ~ 0
SCK
Wire Wire Line
	5200 3500 5400 3500
Wire Wire Line
	5200 3400 5400 3400
Wire Wire Line
	4200 3300 3800 3300
Wire Wire Line
	4200 3800 3850 3800
Wire Wire Line
	4200 3900 3850 3900
Text GLabel 3850 3900 0    30   Input ~ 0
GPS_TX
Text GLabel 3850 3800 0    30   Input ~ 0
GPS_RX
Wire Wire Line
	4200 3400 3800 3400
Wire Wire Line
	4200 3500 3800 3500
Text GLabel 3800 3500 0    30   Input ~ 0
ENC_A
Text GLabel 3800 3400 0    30   Input ~ 0
ENC_B
Wire Wire Line
	4200 3600 3800 3600
Wire Wire Line
	4200 3700 3800 3700
Wire Wire Line
	5200 3600 5400 3600
Wire Wire Line
	5200 3900 5400 3900
Wire Wire Line
	5200 4000 5400 4000
Wire Wire Line
	5200 4100 5400 4100
Wire Wire Line
	5200 4200 5400 4200
Text GLabel 5400 4200 2    30   Input ~ 0
btnRIGHT
Text GLabel 5400 4100 2    30   Input ~ 0
btnUP
Text GLabel 5400 4000 2    30   Input ~ 0
btnDOWN
Text GLabel 5400 3900 2    30   Input ~ 0
btnLEFT
Text GLabel 5350 3200 2    30   Input ~ 0
+3V3
$Comp
L Connector_Generic:Conn_02x10_Odd_Even J3
U 1 1 5DBE36B9
P 3200 6150
F 0 "J3" H 3250 6767 50  0000 C CNN
F 1 "Conn" H 3250 6676 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x10_P2.54mm_Horizontal" H 3200 6150 50  0001 C CNN
F 3 "~" H 3200 6150 50  0001 C CNN
	1    3200 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 5750 2750 5750
Wire Wire Line
	3000 5850 2750 5850
Wire Wire Line
	3000 5950 2750 5950
Wire Wire Line
	3000 6050 2750 6050
Wire Wire Line
	3000 6150 2750 6150
Wire Wire Line
	3000 6450 2750 6450
Wire Wire Line
	3000 6550 2750 6550
Wire Wire Line
	3000 6650 2750 6650
Wire Wire Line
	3500 5850 3800 5850
Wire Wire Line
	3500 5950 3800 5950
Wire Wire Line
	3500 6250 3800 6250
Wire Wire Line
	3500 6450 3800 6450
Wire Wire Line
	3500 6550 3800 6550
Text GLabel 2750 5750 0    30   Input ~ 0
+3V3
Text GLabel 2750 5850 0    30   Input ~ 0
CS
Text GLabel 2750 5950 0    30   Input ~ 0
DC_RS
Text GLabel 2750 6050 0    30   Input ~ 0
SCK
Text GLabel 2750 6150 0    30   Input ~ 0
SDO_MOSO
Text GLabel 3800 5850 2    30   Input ~ 0
+3V3
Text GLabel 3800 5950 2    30   Input ~ 0
SDI_MOSI
$Comp
L Device:R_Small R2
U 1 1 5DD70435
P 4100 6050
F 0 "R2" V 4000 6100 50  0000 C CNN
F 1 "100R" V 4200 6100 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4100 6050 50  0001 C CNN
F 3 "~" H 4100 6050 50  0001 C CNN
	1    4100 6050
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 6050 4300 6050
Text GLabel 4300 6050 2    30   Input ~ 0
+3V3
Wire Wire Line
	4550 5750 4550 5800
Wire Wire Line
	3500 5750 4550 5750
Wire Wire Line
	3500 6050 4000 6050
Text GLabel 3800 6250 2    30   Input ~ 0
ENC_SW
Text GLabel 2200 6250 0    30   Input ~ 0
ENC_A
Text GLabel 4900 6350 2    30   Input ~ 0
ENC_B
Text GLabel 2750 6550 0    30   Input ~ 0
btnRIGHT
Text GLabel 3800 6450 2    30   Input ~ 0
btnUP
Text GLabel 2750 6650 0    30   Input ~ 0
btnDOWN
Text GLabel 3800 6550 2    30   Input ~ 0
btnLEFT
$Comp
L Device:R_Small R1
U 1 1 5DECAB55
P 2300 6000
F 0 "R1" H 2359 6046 50  0000 L CNN
F 1 "10K" H 2359 5955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2300 6000 50  0001 C CNN
F 3 "~" H 2300 6000 50  0001 C CNN
	1    2300 6000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R3
U 1 1 5DECB476
P 4800 6000
F 0 "R3" H 4859 6046 50  0000 L CNN
F 1 "10K" H 4859 5955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4800 6000 50  0001 C CNN
F 3 "~" H 4800 6000 50  0001 C CNN
	1    4800 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 6250 2300 6250
Wire Wire Line
	2300 6100 2300 6250
Connection ~ 2300 6250
Wire Wire Line
	2300 6250 3000 6250
Wire Wire Line
	3500 6350 4800 6350
Wire Wire Line
	4800 6100 4800 6350
Connection ~ 4800 6350
Wire Wire Line
	4800 6350 4900 6350
Wire Wire Line
	4800 5900 4800 5400
Wire Wire Line
	4800 5400 2300 5400
Wire Wire Line
	2300 5400 2300 5900
Wire Wire Line
	2300 5400 2150 5400
Connection ~ 2300 5400
Text GLabel 2150 5400 0    30   Input ~ 0
+3V3
Text GLabel 3800 3300 0    30   Input ~ 0
ENC_SW
Wire Wire Line
	5200 3300 5400 3300
$Comp
L Connector:USB_A J2
U 1 1 5DE3454C
P 2150 1500
F 0 "J2" H 2207 1967 50  0000 C CNN
F 1 "USB_A" H 2207 1876 50  0000 C CNN
F 2 "Connector_USB:USB_A_Stewart_SS-52100-001_Horizontal" H 2300 1450 50  0001 C CNN
F 3 " ~" H 2300 1450 50  0001 C CNN
	1    2150 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 1900 2050 1950
Wire Wire Line
	2050 1950 2150 1950
Wire Wire Line
	2150 1950 2150 1900
Wire Wire Line
	2150 1950 2250 1950
Connection ~ 2150 1950
$Comp
L power:GNDD #PWR0111
U 1 1 5DE5E23E
P 2250 2050
F 0 "#PWR0111" H 2250 1800 50  0001 C CNN
F 1 "GNDD" H 2255 1877 50  0000 C CNN
F 2 "" H 2250 2050 50  0001 C CNN
F 3 "" H 2250 2050 50  0001 C CNN
	1    2250 2050
	1    0    0    -1  
$EndComp
Text GLabel 2600 1300 2    30   Input ~ 0
RAW
Text Notes 1850 950  0    30   ~ 0
5V in from portable PowerPack
Wire Wire Line
	5200 3000 5400 3000
$Comp
L Device:C C7
U 1 1 5DEF4F84
P 4800 6550
F 0 "C7" H 4685 6504 50  0000 R CNN
F 1 "100n" H 4685 6595 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4838 6400 50  0001 C CNN
F 3 "~" H 4800 6550 50  0001 C CNN
	1    4800 6550
	-1   0    0    1   
$EndComp
$Comp
L Device:C C6
U 1 1 5DEF6842
P 2300 6450
F 0 "C6" H 2185 6404 50  0000 R CNN
F 1 "100n" H 2185 6495 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2338 6300 50  0001 C CNN
F 3 "~" H 2300 6450 50  0001 C CNN
	1    2300 6450
	-1   0    0    1   
$EndComp
Wire Wire Line
	4800 6400 4800 6350
Wire Wire Line
	4800 6700 4800 6750
Wire Wire Line
	2300 6600 2300 6650
Wire Wire Line
	2300 6300 2300 6250
$Comp
L power:GNDD #PWR0113
U 1 1 5DF49DA2
P 4800 6750
F 0 "#PWR0113" H 4800 6500 50  0001 C CNN
F 1 "GNDD" H 4650 6700 50  0000 C CNN
F 2 "" H 4800 6750 50  0001 C CNN
F 3 "" H 4800 6750 50  0001 C CNN
	1    4800 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0114
U 1 1 5DF4A36F
P 2300 6650
F 0 "#PWR0114" H 2300 6400 50  0001 C CNN
F 1 "GNDD" H 2305 6477 50  0000 C CNN
F 2 "" H 2300 6650 50  0001 C CNN
F 3 "" H 2300 6650 50  0001 C CNN
	1    2300 6650
	1    0    0    -1  
$EndComp
Text GLabel 5400 3000 2    30   Input ~ 0
RAW
Text Notes 3050 5350 0    30   ~ 0
Right Angle (male) 2x10\nFarnell 102 2317\nArcher M50 Series
Text Notes 7250 1650 0    30   ~ 0
Farnell 145 7412
Text Notes 2450 1800 0    30   ~ 0
Farnell 145 0206\nMolex TH
Wire Wire Line
	2250 1950 2250 2050
Wire Wire Line
	2450 1300 2600 1300
Text Notes 6900 2650 2    39   ~ 8
Before fitting the Teensy module, disconnect Mini USB supply.\nSee link for full details:\nhttps://www.pjrc.com/teensy/external_power.html
Wire Wire Line
	3500 6650 3800 6650
Text GLabel 3800 6650 2    30   Input ~ 0
btnToneBurst
Wire Wire Line
	3000 6350 2750 6350
Text GLabel 2750 6450 0    30   Input ~ 0
GPS_TX
Text GLabel 2750 6350 0    30   Input ~ 0
GPS_RX
Wire Wire Line
	3250 3000 4200 3000
Text Notes 7050 7050 0    39   ~ 0
Copyright (C) K Wheatley 2020\nThis documentation describes Open Hardware and is licensed under the CERN OHL v. 1.2.\nYou may redistribute and modify this documentation under the terms of the CERN OHL v.1.2. \n(http://ohwr.org/cernohl). \nThis documentation is distributed WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, \nINCLUDING OF MERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A PARTICULAR PURPOSE. \nPlease see the CERN OHL v.1.2 for applicable conditions.
Wire Wire Line
	4500 2600 4500 1900
Wire Wire Line
	5200 3700 5400 3700
Wire Wire Line
	5200 3800 5400 3800
Wire Wire Line
	4900 4600 4900 4700
Wire Wire Line
	4900 4700 4950 4700
Text GLabel 4950 4700 2    30   Input ~ 0
A14_DAC
Text GLabel 5400 3700 2    30   Input ~ 0
SCL
Text GLabel 7500 4900 0    30   Input ~ 0
SCL
Text GLabel 5400 3800 2    30   Input ~ 0
SDA
Text GLabel 7500 5000 0    30   Input ~ 0
SDA
$Comp
L power:GNDD #PWR03
U 1 1 5F09B33A
P 4550 5800
F 0 "#PWR03" H 4550 5550 50  0001 C CNN
F 1 "GNDD" H 4400 5750 50  0000 C CNN
F 2 "" H 4550 5800 50  0001 C CNN
F 3 "" H 4550 5800 50  0001 C CNN
	1    4550 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 1900 4550 1900
Wire Wire Line
	4600 2600 4600 2050
Wire Wire Line
	4600 2050 4650 2050
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5E969E52
P 4950 1100
F 0 "J4" H 5030 1092 50  0000 L CNN
F 1 "Conn" H 5030 1001 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4950 1100 50  0001 C CNN
F 3 "~" H 4950 1100 50  0001 C CNN
	1    4950 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1100 4550 1100
Wire Wire Line
	4750 1200 4550 1200
Wire Wire Line
	4550 1200 4550 1300
Text GLabel 4550 1100 0    30   Input ~ 0
RAW
$Comp
L power:GNDD #PWR04
U 1 1 5E9931D4
P 4550 1300
F 0 "#PWR04" H 4550 1050 50  0001 C CNN
F 1 "GNDD" H 4555 1127 50  0000 C CNN
F 2 "" H 4550 1300 50  0001 C CNN
F 3 "" H 4550 1300 50  0001 C CNN
	1    4550 1300
	1    0    0    -1  
$EndComp
Text Notes 4500 950  0    30   ~ 0
External +5V if not powered from USB
$Comp
L Connector_Generic:Conn_02x10_Odd_Even J1
U 1 1 5E9EC6DD
P 8300 5100
F 0 "J1" H 8350 5717 50  0000 C CNN
F 1 "Conn" H 8350 5626 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x10_P2.54mm_Horizontal" H 8300 5100 50  0001 C CNN
F 3 "~" H 8300 5100 50  0001 C CNN
	1    8300 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 4700 9050 4700
Wire Wire Line
	8100 4700 7500 4700
Wire Wire Line
	8100 5600 7500 5600
Wire Wire Line
	8600 5600 9050 5600
Text GLabel 7500 4800 0    30   Input ~ 0
+3V3
Text GLabel 9050 4800 2    30   Input ~ 0
+3V3
Wire Wire Line
	9050 5600 9050 5750
Wire Wire Line
	7500 5600 7500 5750
$Comp
L power:GNDD #PWR0101
U 1 1 5EA07450
P 7500 5750
F 0 "#PWR0101" H 7500 5500 50  0001 C CNN
F 1 "GNDD" H 7505 5577 50  0000 C CNN
F 2 "" H 7500 5750 50  0001 C CNN
F 3 "" H 7500 5750 50  0001 C CNN
	1    7500 5750
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0102
U 1 1 5EA07A33
P 9050 5750
F 0 "#PWR0102" H 9050 5500 50  0001 C CNN
F 1 "GNDD" H 9055 5577 50  0000 C CNN
F 2 "" H 9050 5750 50  0001 C CNN
F 3 "" H 9050 5750 50  0001 C CNN
	1    9050 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 4800 7500 4800
Wire Wire Line
	8600 4800 9050 4800
Wire Wire Line
	8100 4900 7500 4900
Wire Wire Line
	8600 4900 9050 4900
Wire Wire Line
	8600 5000 9050 5000
Wire Wire Line
	8600 5100 9050 5100
Wire Wire Line
	8600 5200 9050 5200
Wire Wire Line
	8600 5400 9050 5400
Wire Wire Line
	8600 5500 9050 5500
Wire Wire Line
	8100 5000 7500 5000
Wire Wire Line
	8100 5100 7500 5100
Wire Wire Line
	8100 5200 7500 5200
Wire Wire Line
	8100 5400 7500 5400
Wire Wire Line
	8100 5500 7500 5500
Text GLabel 9050 5500 2    30   Input ~ 0
A14_DAC
Text GLabel 9650 1100 2    30   Input ~ 0
RAW
Text GLabel 7000 1100 0    30   Input ~ 0
+13V8
Text GLabel 7500 4700 0    30   Input ~ 0
+13V8
Text GLabel 9050 4700 2    30   Input ~ 0
+13V8
Text Notes 9550 1050 0    30   ~ 0
+5V
Wire Wire Line
	9400 1100 9650 1100
Connection ~ 9400 1100
$Comp
L m0khz-symbol:Adafruit_Si5351_Module U1
U 1 1 5EA84F73
P 8500 2900
F 0 "U1" H 8450 3250 30  0000 L CNN
F 1 "Adafruit_Si5351_Module" H 8250 3150 30  0000 L CNN
F 2 "m0khz-footprint:Adafruit_Si5351_Module" H 8500 2900 30  0001 C CNN
F 3 "" H 8500 2900 30  0001 C CNN
	1    8500 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 3100 7800 3100
Wire Wire Line
	8200 3200 7800 3200
Text GLabel 7800 3100 0    30   Input ~ 0
SCL
Text GLabel 7800 3200 0    30   Input ~ 0
SDA
Wire Wire Line
	7500 3300 7500 3600
Wire Wire Line
	7500 3300 8200 3300
$Comp
L power:GNDD #PWR02
U 1 1 5EAA22FB
P 8300 1950
F 0 "#PWR02" H 8300 1700 50  0001 C CNN
F 1 "GNDD" H 8305 1777 50  0000 C CNN
F 2 "" H 8300 1950 50  0001 C CNN
F 3 "" H 8300 1950 50  0001 C CNN
	1    8300 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR01
U 1 1 5EAA2A47
P 7500 3600
F 0 "#PWR01" H 7500 3350 50  0001 C CNN
F 1 "GNDD" H 7505 3427 50  0000 C CNN
F 2 "" H 7500 3600 50  0001 C CNN
F 3 "" H 7500 3600 50  0001 C CNN
	1    7500 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 3100 3800 3100
Wire Wire Line
	4200 3200 3800 3200
Text GLabel 3800 3100 0    30   Input ~ 0
RX1
Text GLabel 3800 3200 0    30   Input ~ 0
TX1
Text GLabel 7500 5100 0    30   Input ~ 0
RX1
Text GLabel 9050 5100 2    30   Input ~ 0
TX1
Text GLabel 3850 4000 0    30   Input ~ 0
RX2
Text GLabel 3850 4100 0    30   Input ~ 0
TX2
Text GLabel 7500 5200 0    30   Input ~ 0
RX2
Text GLabel 9050 5200 2    30   Input ~ 0
TX2
Text GLabel 3800 3600 0    30   Input ~ 0
PIN5
Text GLabel 3800 3700 0    30   Input ~ 0
PIN6
Text GLabel 9050 4900 2    30   Input ~ 0
PIN5
Text GLabel 9050 5000 2    30   Input ~ 0
PIN6
Text GLabel 5400 3400 2    30   Input ~ 0
PIN22
Text GLabel 7500 5500 0    30   Input ~ 0
PIN22
Text GLabel 4650 2050 2    30   Input ~ 0
A10
Text GLabel 4550 1900 2    30   Input ~ 0
A11
Text GLabel 7500 5400 0    30   Input ~ 0
A10
Text GLabel 9050 5400 2    30   Input ~ 0
A11
Wire Wire Line
	4700 2600 4700 2200
Wire Wire Line
	4700 2200 4750 2200
Text GLabel 4750 2200 2    30   Input ~ 0
AREF
Text GLabel 7500 5300 0    30   Input ~ 0
AREF
Wire Wire Line
	8200 3400 7800 3400
Text GLabel 7800 3400 0    30   Input ~ 0
+3V3
Text GLabel 5400 3300 2    30   Input ~ 0
btnToneBurst
Wire Wire Line
	8100 5300 7500 5300
$EndSCHEMATC
