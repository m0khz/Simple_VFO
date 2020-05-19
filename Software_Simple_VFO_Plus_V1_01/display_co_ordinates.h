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
*/


 // Colours to choose from:
 // ILI9341_BLACK       
 // LI9341_NAVY        
 // ILI9341_DARKGREEN    
 // ILI9341_DARKCYAN     
 // ILI9341_MAROON      
 // ILI9341_PURPLE      
 // ILI9341_OLIVE       
 // ILI9341_LIGHTGREY   
 // ILI9341_DARKGREY   
 // ILI9341_BLUE       
 // ILI9341_GREEN        
 // ILI9341_CYAN       
 // ILI9341_RED         
 // ILI9341_MAGENTA    
 // ILI9341_YELLOW      
 // ILI9341_WHITE      
 // ILI9341_ORANGE      
 // ILI9341_GREENYELLOW 
 // ILI9341_PINK       

// ---------------------------------------------------
// Structure to make handling program control 'flags' easier to work with
struct flags
{
  bool ReDraw_Screen      = true;      // this will force the screen to be updated on first loop
  bool freq_Changed       = true;      // set within the encoder interrupt routine.
  bool vfo_A_active       = true;      // No real reason to add a comment here as the variable name says it all!
  bool vfo_B_active       = false;     // No real reason to add a comment here as the variable name says it all!
  bool vfo_A_B_changed    = false;     // used when VFO A=B i.e. redraw freq. with active VFO colour change.
  bool vfo_AB_changed     = false;     // used when VFO AB  i.e exchange values and redraw freq. with active VFO colour change.
  bool vfo_set_for_band   = false;     // used when setting VFO values according to band
  bool vfo_lock           = false;     // used to lock VFO with 'Enter' button
  bool Smeter             = false;     // used to update S meter
  bool SmeterBarGragh     = false;     // used to update the SmeterBarGragh
  bool GraphUpdate        = false;     // used to update S meter Graph
  bool freq_multi_bar     = true;      // used to update frequency multiplier display bar position
  
  // Frequency generator flags
  bool mode               = false;     // 0 = VFO , 1 = Sig Gen
  bool fg_ReDraw_Screen   = true;      // this will force the screen to be updated on first loop  fg_ReDraw_Screen
  bool fg_freq_Changed    = true;      // set within the encoder interrupt routine.
  bool fg_A_active        = true;      // No real reason to add a comment here as the variable name says it all!
  bool fg_B_active        = false;     // No real reason to add a comment here as the variable name says it all!
  bool fg_A_B_changed     = false;     // used when VFO A=B i.e. redraw freq. with active VFO colour change.
  bool fg_AB_changed      = false;     // used when VFO AB  i.e exchange values and redraw freq. with active VFO colour change.
  bool fg_lock            = false;     // used to lock VFO with 'Enter' button
  bool fg_freq_multi_bar  = false;      // used to update frequency multiplier display bar position
  // others will be added when developing the program flow
};
struct flags flag;
// ---------------------------------------------------

struct userparameters
{
  //unsigned int BFO_freq             =   9000000;  // not used for this application
  unsigned int transverter_offset     = 116000000;
  unsigned int if_offset              =   9000000;
  unsigned int vfo_default            =  20500000;
  unsigned int vfo_a                  =         0; // start frequency we'll change this later when we introduce IF offsets etc.
  unsigned int vfo_b                  =         0; // start frequency we'll change this later when we introduce IF offsets etc.
  unsigned int tune_multi             = 4;         // Frequency multiplier reference
  long vfo_A_value                    = 0;         // variable to store current VFO_A frequency value
  long vfo_B_value                    = 0;         // variable to store current VFO_B frequency value
  long vfo_a_temp                     = 0;         // temporary storage used for vfo swapping
  long vfo_b_temp                     = 0;         // temporary storage used for vfo swapping
  unsigned int band_2M_active         = 1;         // pointer to active band
  unsigned int band_70cms_active      = 2;         // pointer to active band ***** spare at the moment
  unsigned int band_2M_vfo_A_value    = 0;         // variable to store current 2M VFO_A frequency value, as we might want to store this if we change bands
                                                   // and want to return to the same VFO frequency if we return to 2M
  unsigned int band_2M_vfo_B_value    = 0;         // variable to store current 2M VFO_B frequency value, as we might want to store this if we change bands
                                                   // and want to return to the same VFO frequency if we return to 2M
  unsigned int band_70cms_vfo_A_value = 0;         // variable to store current 70cms VFO_A frequency value, as we might want to store this if we change bands
                                                   // and want to return to the same VFO frequency if we return to 2M
  unsigned int band_70cms_vfo_B_value = 0;         // variable to store current 70cms VFO_B frequency value, as we might want to store this if we change bands
                                                   // and want to return to the same VFO frequency if we return to 2M
                                                   
  // Freq Generation variables                                                 
  unsigned int sig_gen_def_freq       =  10000000; // signal generator mode default frequency 
  long fg_A_value                     = 0;         // variable to store current Freq Gen_A frequency value
  long fg_B_value                     = 0;         // variable to store current Freq Gen_B frequency value
  long fg_a_temp                      = 0;         // temporary storage used for Freq gen swapping
  long fg_b_temp                      = 0;         // temporary storage used for Freq gen swapping
  unsigned int fg_a                   =         0; // start frequency
  unsigned int fg_b                   =         0; // start frequency
  unsigned int fg_tune_multi          = 6;         // Frequency Generator  multiplier reference
  long fg_upper_limit                 = 200000000; // Frequency Generator upper limit
  long fg_lower_limit                 =   3000000; // Frequency Generator upper limit
                                                   
};
struct userparameters u;

// variables for screen layout
// outline boarder
int outline_boarder_x = 0;        // position for top left  
int outline_boarder_y = 0;        // position for top left 
int outline_boarder_w = 320;      // width of boarder
int outline_boarder_d = 240;      // depth of boarder
int outline_boarder_colour = ILI9341_YELLOW;

//when we clear the display to re-write anything we don't want to re-draw the outline boarder
// so these variables define the are we'll call upon in the code, when required.
int clearscreen_x = 5;
int clearscreen_y = 5;             // position for top left 
int clearscreen_w = 315;           // width of boarder
int clearscreen_d = 215;           // depth of boarder
int clearscreen_colour = ILI9341_BLACK;

int vanity_boarder_x = 5;           // position for top left 
int vanity_boarder_y = 5;           // position for top left
int vanity_boarder_w = 310;         // width of boarder
int vanity_boarder_d = 38;          // depth of boarder
int vanity_boarder_colour = ILI9341_GREEN;

int vanity_cursor_pos_x = 40;       // position for top left
int vanity_cursor_pos_y = 13;       // position for top left
int vanity_text_colour = ILI9341_WHITE;
// ------------------------------------

int main_freq_boarder_x = 5;        // position for top left 
int main_freq_boarder_y = 55;       // position for top left
int main_freq_boarder_w = 310;      // width of boarder
int main_freq_boarder_d = 50;       // depth of boarder
int main_freq_boarder_colour = ILI9341_GREEN;

int main_freq_cursor_pos_x = 60;    // position for top left
int main_freq_cursor_pos_y = 68;    // position for top left

int main_freq_text_colour = ILI9341_MAGENTA;
int main_mhz_cursor_pos_x = 185;    // position for top left
int main_mhz_cursor_pos_y = 75;     // position for top left
// -------------------------------------

int sub_freq_boarder_x = 5;         // position for top left 
int sub_freq_boarder_y = 108;       // position for top left
int sub_freq_boarder_w = 310;       // width of boarder
int sub_freq_boarder_d = 50;        // depth of boarder
int sub_freq_boarder_colour = ILI9341_GREEN;

int sub_freq_cursor_pos_x = 60;     // position for top left
int sub_freq_cursor_pos_y = 122;    // position for top left

int sub_freq_text_colour = ILI9341_MAGENTA;
int sub_mhz_cursor_pos_x = 185;     // position for top left
int sub_mhz_cursor_pos_y = 148;     // position for top left
// -------------------------------------

int info_boarder_x = 5;             // position for top left 
int info_boarder_y = 160;           // position for top left
int info_boarder_w = 310;           // width of boarder
int info_boarder_d = 75;            // depth of boarder
int info_boarder_colour = ILI9341_GREEN;

int info_cursor_pos_x = 35;         // position for top left
int info_cursor_pos_y = 180;        // position for top left
int info_text_colour = ILI9341_YELLOW;
// --------------------------------------
