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

//----- VFO A/B -- Down Button --------------------------
// Swap VFO's
void vfochange(){
  if(flag.mode == false){
    flag.vfo_A_active =! flag.vfo_A_active;
    flag.vfo_B_active =! flag.vfo_B_active;
    flag.freq_Changed=true;
    flag.vfo_AB_changed = true;
  }
  if(flag.mode == true){
    flag.fg_A_active =! flag.fg_A_active;
    flag.fg_B_active =! flag.fg_B_active;
    flag.fg_freq_Changed=true;
    flag.fg_AB_changed = true;
  }
}

void  vfoequal(){

  if(flag.mode == false){
    u.vfo_a_temp = 0;
    u.vfo_b_temp = 0;
    
    u.vfo_a_temp = u.vfo_a;
    u.vfo_b_temp = u.vfo_b;
    
    u.vfo_a = u.vfo_b_temp;
    u.vfo_b = u.vfo_a_temp;
 
    u.band_2M_vfo_A_value = ((u.vfo_a + u.transverter_offset) + (u.if_offset));
    u.vfo_A_value = u.band_2M_vfo_A_value;

    u.band_2M_vfo_B_value = ((u.vfo_b + u.transverter_offset) + (u.if_offset));
    u.vfo_B_value = u.band_2M_vfo_B_value;
    
    flag.vfo_A_active =! flag.vfo_A_active;
    flag.vfo_B_active =! flag.vfo_B_active;

    flag.vfo_A_B_changed = true;
    flag.freq_Changed=true;
  }
  if(flag.mode == true){
    u.fg_a_temp = 0;
    u.fg_b_temp = 0;
    
    u.fg_a_temp = u.fg_A_value;
    u.fg_b_temp = u.fg_B_value;
    
    u.fg_A_value = u.fg_b_temp;
    u.fg_B_value = u.fg_a_temp;
 
    flag.fg_A_active =! flag.fg_A_active;
    flag.fg_B_active =! flag.fg_B_active;

    flag.fg_A_B_changed = true;
    flag.fg_freq_Changed=true;
  }
}

//--------- display_vfo_lock

void display_vfo_lock(){

    if(flag.vfo_lock==true){
          tft.drawRoundRect(main_freq_boarder_x +2,main_freq_boarder_y +2,main_freq_boarder_w -4,main_freq_boarder_d -4,3,ILI9341_RED);
          tft.drawRoundRect(main_freq_boarder_x +3,main_freq_boarder_y +3,main_freq_boarder_w -6,main_freq_boarder_d -6,3,ILI9341_RED);
          tft.drawRoundRect(main_freq_boarder_x +4,main_freq_boarder_y +4,main_freq_boarder_w -8,main_freq_boarder_d -8,3,ILI9341_RED);

          tft.drawRoundRect(sub_freq_boarder_x +2,sub_freq_boarder_y +2,sub_freq_boarder_w -4,sub_freq_boarder_d -4,3,ILI9341_RED);
          tft.drawRoundRect(sub_freq_boarder_x +3,sub_freq_boarder_y +3,sub_freq_boarder_w -6,sub_freq_boarder_d -6,3,ILI9341_RED);
          tft.drawRoundRect(sub_freq_boarder_x +4,sub_freq_boarder_y +4,sub_freq_boarder_w -8,sub_freq_boarder_d -8,3,ILI9341_RED);
       }
       if(flag.vfo_lock==false){
          tft.drawRoundRect(main_freq_boarder_x +2,main_freq_boarder_y +2,main_freq_boarder_w -4,main_freq_boarder_d -4,3,ILI9341_BLACK);
          tft.drawRoundRect(main_freq_boarder_x +3,main_freq_boarder_y +3,main_freq_boarder_w -6,main_freq_boarder_d -6,3,ILI9341_BLACK);
          tft.drawRoundRect(main_freq_boarder_x +4,main_freq_boarder_y +4,main_freq_boarder_w -8,main_freq_boarder_d -8,3,ILI9341_BLACK);

          tft.drawRoundRect(sub_freq_boarder_x +2,sub_freq_boarder_y +2,sub_freq_boarder_w -4,sub_freq_boarder_d -4,3,ILI9341_BLACK);
          tft.drawRoundRect(sub_freq_boarder_x +3,sub_freq_boarder_y +3,sub_freq_boarder_w -6,sub_freq_boarder_d -6,3,ILI9341_BLACK);
          tft.drawRoundRect(sub_freq_boarder_x +4,sub_freq_boarder_y +4,sub_freq_boarder_w -8,sub_freq_boarder_d -8,3,ILI9341_BLACK);
       }
}

// ------------display_fg_lock();

void display_fg_lock(){

    if(flag.fg_lock==true){
          tft.drawRoundRect(main_freq_boarder_x +2,main_freq_boarder_y +2,main_freq_boarder_w -4,main_freq_boarder_d -4,3,ILI9341_RED);
          tft.drawRoundRect(main_freq_boarder_x +3,main_freq_boarder_y +3,main_freq_boarder_w -6,main_freq_boarder_d -6,3,ILI9341_RED);
          tft.drawRoundRect(main_freq_boarder_x +4,main_freq_boarder_y +4,main_freq_boarder_w -8,main_freq_boarder_d -8,3,ILI9341_RED);

          tft.drawRoundRect(sub_freq_boarder_x +2,sub_freq_boarder_y +2,sub_freq_boarder_w -4,sub_freq_boarder_d -4,3,ILI9341_RED);
          tft.drawRoundRect(sub_freq_boarder_x +3,sub_freq_boarder_y +3,sub_freq_boarder_w -6,sub_freq_boarder_d -6,3,ILI9341_RED);
          tft.drawRoundRect(sub_freq_boarder_x +4,sub_freq_boarder_y +4,sub_freq_boarder_w -8,sub_freq_boarder_d -8,3,ILI9341_RED);
       }
       if(flag.fg_lock==false){
          tft.drawRoundRect(main_freq_boarder_x +2,main_freq_boarder_y +2,main_freq_boarder_w -4,main_freq_boarder_d -4,3,ILI9341_BLACK);
          tft.drawRoundRect(main_freq_boarder_x +3,main_freq_boarder_y +3,main_freq_boarder_w -6,main_freq_boarder_d -6,3,ILI9341_BLACK);
          tft.drawRoundRect(main_freq_boarder_x +4,main_freq_boarder_y +4,main_freq_boarder_w -8,main_freq_boarder_d -8,3,ILI9341_BLACK);

          tft.drawRoundRect(sub_freq_boarder_x +2,sub_freq_boarder_y +2,sub_freq_boarder_w -4,sub_freq_boarder_d -4,3,ILI9341_BLACK);
          tft.drawRoundRect(sub_freq_boarder_x +3,sub_freq_boarder_y +3,sub_freq_boarder_w -6,sub_freq_boarder_d -6,3,ILI9341_BLACK);
          tft.drawRoundRect(sub_freq_boarder_x +4,sub_freq_boarder_y +4,sub_freq_boarder_w -8,sub_freq_boarder_d -8,3,ILI9341_BLACK);
       }
}
     
//---------switch debounce update
void switch_bouncer(){
  
    bouncer_VFO_AB.update ( );  
    bouncer_VFO_A_B.update ( );  
    bouncer_Tune_Step_Plus.update ( );  
    bouncer_Tune_Step_Minus.update ( );  
    bouncer_VFO_LOCK.update ( ); 
    bouncer_MODE.update ( ); 
 
  
  if (bouncer_VFO_AB.fallingEdge()) { 
      vfoequal(); 
      flag.freq_multi_bar = true;
    }

  if (bouncer_VFO_A_B.fallingEdge()) {
      vfochange(); 
      flag.freq_multi_bar = true;     
    } 

  if (bouncer_Tune_Step_Plus.fallingEdge()) {
    if(flag.mode == false) {
      u.tune_multi++;
      if(u.tune_multi==7) u.tune_multi=6;
      flag.freq_multi_bar = true;         
    }
    if(flag.mode == true) {
      u.fg_tune_multi++;
      if(u.fg_tune_multi==8) u.fg_tune_multi=7;
      flag.freq_multi_bar = true;         
      }
    }

  if (bouncer_Tune_Step_Minus.fallingEdge()) {
    if(flag.mode == false) {
      u.tune_multi--;
      if(u.tune_multi==0) u.tune_multi=1;
      flag.freq_multi_bar = true;
    }
     if(flag.mode == true) {
        u.fg_tune_multi--;
        if(u.fg_tune_multi==0) u.tune_multi=1;
        flag.freq_multi_bar = true;
    } 
   } 

  if (bouncer_VFO_LOCK.fallingEdge()) {
    if(flag.mode == false){
       flag.vfo_lock = !flag.vfo_lock;
       display_vfo_lock(); 
    }
    if(flag.mode == true){
       flag.fg_lock = !flag.fg_lock;
       display_fg_lock();  
    }
       flag.freq_Changed=true;
    }

     if (bouncer_MODE.fallingEdge()) {
       
        flag.mode = !flag.mode;
        flag.freq_multi_bar = true;          
     }  
}
