/*
 * ***********************************************************************************
 * Copyright (c) 2020  M0KHZ - Kevin Wheatley
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * ***********************************************************************************
 * 
 * OK so the initial objectives here are to have a basic VFO operational.
 * Hardware: 
 * 
 *    Si5351 braekout board
 *    Teensy 3.2
 *    2.2 TFT display
 *    
 *    
 * Version 0.001   - 4.04.2020 - Project start basic screen layout (more to add later).
 *                             - Pin assignments
 *                             - 0  - USB Comms / programming / debug 
 *                             - 1  - UBS Comms / programming / debug
 *                             - 2  - IN_ENCODER0_PINSW
 *                             - 3  - IN_ENCODER0_PINA
 *                             - 4  - IN_ENCODER0_PINB
 *                             - 5  - Spare
 *                             - 6  - Spare
 *                             - 7  - Serial3 Rx - possible future use
 *                             - 8  - Serial3 Tx - possible future use
 *                             - 9  - possible future use
 *                             - 10 - possible future use
 *                             - 11 - TFT_SDI/MOSI
 *                             - 12 - TFT_SDO/MOSO
 *                             - 13 - TFT_SCK
 *                             - 14 - Button Right  - Tune_Step_Minus
 *                             - 15 - Button Up     - VFO_AB
 *                             - 16 - Button Down   - VFO_A_B
 *                             - 17 - Button Left   - Tune_Step_Plus
 *                             - 18 - SDA0 - Si5351a breakout module 
 *                             - 19 - SCL0 - Si5351a breakout module 
 *                             - 20 - TFT_DC/RS
 *                             - 21 - TFT_CS
 *                             - 22 - possible future use
 *                             - 23 - Button Enter  - VFO_LOCK
 *                             -    - A14/DAC       - S meter input
 * 
 * Version 0.002   - 5.04.2020 - Started to add encoder code - interrupt driven
 * Version 0.003   - 5.04.2020 - Started to add freq display update code,
 *                             - basic program flow implemented VFO's updated via encoder, switching between VFO's via encoder pushbutton
 * Version 0.004   - 5.04.2020 - TFT display update started.                             
 *                             - added some additional fonts included to start making the display look prity, namely:
 *                             - an aggregation of DroidSansMono and AwesomeF000 fonts.
 *                             - Main and sub VFO's displaying correctly.
 *                             - Splash screen integrated.
 *                             - Sketch uses 190452 bytes (72%) of program storage space. Maximum is 262144 bytes.
 *                             - Global variables use 5516 bytes (8%) of dynamic memory, leaving 60020 bytes for local variables. 
 *                             - Maximum is 65536 bytes.
 * Version 0.005  - 6.04.2020  - Started to implement S meter - test bar working nicely
 *                             - Band limits implemented - limits set in - display_co_ordinates.h
 *                             - Display positioning shuffled about a bit
 * Version 0.006  - 7.04.2020  - Implemented interrupt driven encoder switch. 
 *                             - GPS data added to info screen area
 *                             - Added vanity call display within gps info loop
 * Version 0.007  - 8.04.2020  - Frequency offset code implemented.
 *                             - VFO A/B, VFO A=B and VFO Lock implemented.
 *                             - VFO output implemented on SI5351_CLK0
 *                             - Sketch uses 215808 bytes (82%) of program storage space. Maximum is 262144 bytes.
 *                             - Global variables use 6560 bytes (10%) of dynamic memory, 
 *                             - leaving 58976 bytes for local variables. Maximum is 65536 bytes.
 * Version 0.008  - 12.04.2020 - New method for encoder routines (better transition handling for lookup table).
 *                             - including full and half step, to help with different encoder types.
 *                             - Also freq. multiplier via a new variable : u.tune_multi 
 *                             - Implemented display 'bar' for VFO tuning rate.
 *                             - Implemented VFO Lock indication.
 * Version 0.009  - 14.04.2020 - Implemented S meter on A14, the rainbow_gragh expecting int range between 0 - 273, so
 *                             - after reading the value I'm mapping to the correct range:
 *                             - temp_value = analogRead(A14); 
 *                             - temp_value = map(temp_value,0,1023,0,273);
 *                             - with no input connected and just measureing noise, provides quite a good representation!
 *                             - Changed splash screen image and added call - GQRP - SPRAT.
 * Version 1.0    - 15.04.2020 - Initial release.
 *                             - Sketch uses 218444 bytes (83%) of program storage space. Maximum is 262144 bytes.
 *                             - Global variables use 6652 bytes (10%) of dynamic memory,
 *                             - leaving 58884 bytes for local variables. Maximum is 65536 bytes.
 *                             ************** Started signal generator functionality ******************
 * Version 0.01   - 12.05.2020 - Added a simple signal generator function, encoder push button
 *                             - toggles between VFO & Sig gen modes.
 * Version 0.02   - 13.05.2020 - Added second Si5351 clock output, A=B, AB exchange, frequency multipliers text improvement.
 *                             - Changed splash screen to 'eye test'
 * Version 0.03   - 13.05.2020 - Added disable the global interrupt setting with cli() and reenable with with sei() on encoder 
 *                             - inturrupt routines
 *                             - Added lock to frequency generator mode.
 * Version 0.04   - 13.05.2020 - Added 1Mhz tuning to frequency generation mode
 * Version 1.01   - 14.05.2020 - Project renamed as Simple VFO Plus, for release.
 *                             
 * *********************************************************************************************
 * 
 * Hardware notes:
 *                            - Teensy 3.2 module available from https://www.pjrc.com/store/teensy32.html 
 *                            - I bought mine from eBay
 *                                               
 *                            - tft module uses the ILI9341 driver there are different versions out there and the pinout changes,
 *                            - the boards have been designed for this type:
 *                            - https://www.elektor.com/2-2-spi-tft-display-module-240x320 
 *                            - I bought mine from eBay
 *                            
 *                            - Processor board version 1.1
 *                            - Display board version 1.0
 *                            - Button board version 1.0
 *                        
 *                            - Implement this Si5351 library : https://github.com/etherkit/Si5351Arduino
 *                            - VFO output implemented on SI5351_CLK0
 *                            - Signal generator implemented on Si5351_CLK0 & SI5351_CLK2
 *                            
 *                            
 * *********************************************************************************************
 *                            
 * Development environment:                           
 * 
 *  Teensyduino   version - 1.49-beta1  For instalation details see: https://www.pjrc.com/teensy/td_download.html
 *    
 *                            
 * -------------------- To Do List ----------------
 * 
 *  Implement:
 *  Add files to gitHub
 *  
 *  Future development - needs addition hardware (under development 19.05.2020) developed first.....
 *  Long push on encoder switch then implement power meter.
 *  This Power meter capability will be 'rolled into' the existing code, with the ability to switch between
 *  Simple VFO/Sig gen mode & Power meter modes.
 *  
 *  Note with above hardware and different software loaded it should be possible to use
 *  Farhan VU2ESE's Sweeperino software (after modification to suit this hardware etc.)
 *  
 *  
 */

#define MY_CALLSIGN "GQRP - SPRAT"            // callsign used for display testing

// add the libraries to support the display
#include "SPI.h"
#include "ILI9341_t3.h"
// end of display library requirements

// tft display definitions
#define TFT_DC 20
#define TFT_CS 21
ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC);

// used for S meter update timing
#include <Metro.h>
// Instantiate a metro object and set the interval to 250 milliseconds (0.25 seconds).
Metro metroSGragh = Metro(200); 

// used for button debounce etc.
#include <Bounce.h>

// add the library for the interrupt handler timer
#include <TimerOne.h>

// use this utility to create new picture content:
// http://www.rinkydinkelectronics.com/_t_doimageconverter565.php
//
#include "image_240_320.c"

// Things to make the display look pretty :)
#include "display_co_ordinates.h"

/*
 *  Left           - increase frequency multiplier
 *  Right          - decrease frequency multiplier
 *  Enter          - Lock VFO
 *  Up             - VFO A=B
 *  Down           - VFO A/B
 *  encoder switch - MODE exchange - VFO or Freq Gen mode
 */

// Button assignments:
#define VFO_AB              15  // VFO A=B i.e A=B or B=A
// Instantiate a Bounce object with a 5 millisecond debounce time
Bounce bouncer_VFO_AB = Bounce(VFO_AB, 50);   // VFO A=B

#define VFO_A_B             16  // VFO A/B Swap active 
// Instantiate a Bounce object with a 5 millisecond debounce time
Bounce bouncer_VFO_A_B = Bounce(VFO_A_B, 50); // VFO A/B

#define Tune_Step_Plus      17   // Tuning step ++ 
// Instantiate a Bounce object with a 5 millisecond debounce time    
Bounce bouncer_Tune_Step_Plus = Bounce(Tune_Step_Plus,50 ); 

#define Tune_Step_Minus     14  // Tuning step --  
// Instantiate a Bounce object with a 5 millisecond debounce time   
Bounce bouncer_Tune_Step_Minus = Bounce(Tune_Step_Minus,50 ); 

#define VFO_LOCK            23  // 
// Instantiate a Bounce object with a 5 millisecond debounce time
Bounce bouncer_VFO_LOCK = Bounce(VFO_LOCK,50 ); 

#define MODE                 2  // switches between simple VFO & simple signal gen modes
// Instantiate a Bounce object with a 5 millisecond debounce time
Bounce bouncer_MODE = Bounce(MODE,50 ); 

// Button functions
#include "Button_functions.h"


// Display drawing / refresh functions
#include "display_functions.h"

// Si5351a update functions
#include <si5351.h>
// Instantiate the VFO Object
Si5351 si5351;
#include "si5351_functions.h"

// Encoder functions
#include "encoder_functions.h"

// vfo_and_band functions
#include "vfo_and_band.h"

// S meter functions
#include "S_meter_functions.h"
#define s_meter A14

// GPS functions
#define gpsSerial Serial3
#include <TinyGPS++.h>
TinyGPSPlus gps; 
#include "gps_functions.h"
// create gps object

// Frequency Generation functions
#include "freq_gen.h"

// ------------- Setup ---------------------------------
void setup() {
  // put your setup code here, to run once:
  // just incase we need some diagnostics
  Serial.begin(9600);
  // and comms to gps module
  gpsSerial.begin(9600);
  
  // Initialise I2C Communications
  Wire.begin();

  // Setup encoder pins with internal pullups enabled.
  pinMode (encoder0PinA,INPUT_PULLUP);
  pinMode (encoder0PinB,INPUT_PULLUP);

  // initialise physical buttons
  pinMode(VFO_AB, INPUT_PULLUP);
  pinMode(VFO_A_B, INPUT_PULLUP);
  pinMode(MODE, INPUT_PULLUP); // swaps between simple VFO & simple sig gen mode
  pinMode(VFO_LOCK, INPUT_PULLUP);
  pinMode(Tune_Step_Plus, INPUT_PULLUP);
  pinMode(Tune_Step_Minus, INPUT_PULLUP);
  
  // init display
  tft.begin();
  tft.setRotation(1); // will need to change this to 1 for panel mounting in case
  tft.fillScreen(ILI9341_BLACK);
  // display welcome message
  splashscreen();

  // small delay before clearing screen
  delay(5000);
  // now clear the display
  tft.fillScreen(ILI9341_BLACK);

  // So for this sort of project, i.e. where the user will expect instant response to a change on the frequency dial,
  // we have chosen to make the encoder routine interrupt driven, so if the interrupt is triggered
  // irrespective of where the main loop is, the interrupt 'handler' is actioned.
  //
  // Two methods are available below, select the one most suitable for your type of encoder, 
  // note some cheap encoders tend to double count, choosing the right interrupt routine below should help.

  // Setup interrupt handling for the encoder half- or full-step
  attachInterrupt(digitalPinToInterrupt(encoder0PinA), MainRotEncFullStep, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(encoder0PinA), MainRotEncHalfStep, CHANGE);

  attachInterrupt(digitalPinToInterrupt(encoder0PinB), MainRotEncFullStep, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(encoder0PinB), MainRotEncHalfStep, CHANGE);
  
  // now setup Si5351 module
  initialise_dds();

   //Load default start frequency
      u.vfo_a = u.vfo_default;
      u.vfo_b = u.vfo_default;

    //Load default sig gen frequency
      u.fg_A_value = u.sig_gen_def_freq;
      u.fg_B_value = u.sig_gen_def_freq;

// Setup S meter
  analogReference(INTERNAL);                   // use internal reference for the ADC  
  pinMode(s_meter, INPUT);   
}
// ------------- End of Setup ---------------------------------


// ------------- Main Loop ------------------------------------
void loop() {
  // put your main code here, to run repeatedly:
  
  // button handler check for action
    switch_bouncer();

  // if flag.mode == 0 then we are in VFO mode
  if(flag.mode==false){
  // redraw display only if "flag.ReDraw_Screen==true" - this stop screen flicker and only changes the display when requested.
    if(flag.ReDraw_Screen==true)
    {
      display_main_screen(); 
      // OK we've drawn the display or redrawn if we requeted it
      
      // draw S meter background
      meter();
   
    }
    // now process any user requests, i.e change of VFO or band etc.
    // this fubction is called on each loop through of code
    vfo_and_band_handler ();   
    
    // So if the encoder has changed the freq_Changed flag will be 'true'
    // So we need to update the display, we do this here
    if(flag.freq_Changed==true)
    {
      // call function to update the VFO
      display_update_vfo();
      // call function to update the Si5351 output
      update_si5351();
      flag.freq_Changed=false;
      flag.vfo_AB_changed = false;
      flag.vfo_A_B_changed = false;
    }
    // update S meter this runs on each loop through of code
    SmeterBarGragh(); 

    // update gps data
    fetchGpsData();

    // update multiplyer bar
    if(flag.freq_multi_bar == true){
      Freq_Multi_Bar ();
      flag.freq_multi_bar = false;
    }
  }
  if(flag.mode == true){
    // set vfo screen redraw flags for when we return to vfo mode
    flag.ReDraw_Screen=true;
    flag.freq_Changed=true; 
    flag.vfo_A_B_changed=true;
    flag.Smeter = false;
    // now clear screen to enable simple signal gen display
   
    // now display fre gen screen
    display_update_freq_gen_bg();
    // if freq changed
    if(flag.fg_freq_Changed==true){
      // now set Si5351 output
      update_si5351();
    }
    display_update_freq_gen();
    
    display_CLK0_CLK2_Txt ();

    // update multiplyer bar
    if(flag.freq_multi_bar == true){
      Freq_Multi_Bar ();
      flag.freq_multi_bar = false;
    }
  }
} 
// ------------- End of Main Loop ---------------------------------
// ------------- End of file --------------------------------------
