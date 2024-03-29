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

void display_update_freq_gen_bg(){

if(flag.fg_ReDraw_Screen==true){
  
     // now clear the display
      tft.fillScreen(ILI9341_BLACK);
  
     // display outlines and CLK0 freq
     // draw boarder around full display
     rectangle(outline_boarder_x, outline_boarder_y, outline_boarder_w, outline_boarder_d, outline_boarder_colour);

     // draw rectangle around frequency display
     tft.drawRoundRect(main_freq_boarder_x,main_freq_boarder_y,main_freq_boarder_w,main_freq_boarder_d,3,ILI9341_DARKGREY);

     // clear frequency text area just incase there is something there!
     tft.fillRect((main_freq_boarder_x +1),(main_freq_boarder_y + 1), (main_freq_boarder_w - 3), (main_freq_boarder_d - 2), ILI9341_BLACK);

     // draw rectangle around frequency display
     tft.drawRoundRect(sub_freq_boarder_x,sub_freq_boarder_y,sub_freq_boarder_w,sub_freq_boarder_d,3,ILI9341_DARKGREY);

     // clear frequency text area just incase there is something there!
     tft.fillRect((sub_freq_boarder_x +1),(sub_freq_boarder_y + 1), (sub_freq_boarder_w - 3), (sub_freq_boarder_d - 2), ILI9341_BLACK);

     // draw rectangle around frequency display
     tft.drawRoundRect(info_boarder_x,info_boarder_y,info_boarder_w,info_boarder_d,3,ILI9341_DARKGREY);
     //flag.fg_ReDraw_Screen=false;
     // redraw fg lock status 
     display_fg_lock();
  }
}

void display_update_freq_gen(){

    // ------ variables used for vfo uodates etc.
      String freqt=String(u.fg_A_value);    // Text frquency convertrd
      char F100m,F10m,Fmega,F100k,F10k,F1k,F100,F10,F1; //EachdDigit for VFO A
      char f100m,f10m,fmega,f100k,f10k,f1k,f100,f10,f1; //EachdDigit for VFO B
      int freqMulti;
      int freqlength;

      

      // clear frequency text area just incase there is something there!
  if((((flag.fg_A_active==true) && (flag.fg_freq_Changed==true)) || (flag.fg_A_B_changed==true)) || (flag.fg_AB_changed==true))
    
  {      
      // set frequency readout font size
      tft.setFont(DroidSansMono_24);
      if(flag.fg_A_active==false)
      {
          tft.setTextColor(ILI9341_DARKGREY);
      }
      if(flag.fg_A_active==true)
      {
          tft.setTextColor(main_freq_text_colour); 
      }
      tft.setCursor(main_freq_cursor_pos_x,main_freq_cursor_pos_y);
      
      // ------ Display VFO A frequency

      freqt=String(u.fg_A_value);
      freqlength=(freqt.length());

      if(F1 !=(freqt.charAt(freqlength-1))){

          int F1_OffSet = 159;
          int F1_x = main_freq_cursor_pos_x + F1_OffSet;
          int F1_y = main_freq_cursor_pos_y ;

          tft.fillRect(F1_x,F1_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F1_x,F1_y);
          tft.print(freqt.charAt(freqlength-1)); 
          F1 = (freqt.charAt(freqlength-1)); 
          tft.print(" Hz"); 
      }
    
      if(F10 !=(freqt.charAt(freqlength-2))){
      
          int F10_OffSet = 138;
          int F10_x = main_freq_cursor_pos_x + F10_OffSet;
          int F10_y = main_freq_cursor_pos_y ;
    
          tft.fillRect(F10_x,F10_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F10_x,F10_y);
          tft.print(freqt.charAt(freqlength-2)); 
          F10 = (freqt.charAt(freqlength-2));
      }
     
      if(F100 !=(freqt.charAt(freqlength-3))){
      
          int F100_OffSet = 117;
          int F100_x = main_freq_cursor_pos_x + F100_OffSet;
          int F100_y = main_freq_cursor_pos_y ;
    
          tft.fillRect(F100_x,F100_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F100_x,F100_y);
          tft.print(freqt.charAt(freqlength-3));
          F100 = (freqt.charAt(freqlength-3));
      }
     
      if(F1k !=(freqt.charAt(freqlength-4))){
      
          int F1k_OffSet = 82;
          int F1k_x = main_freq_cursor_pos_x + F1k_OffSet;
          int F1k_y = main_freq_cursor_pos_y ;
    
          tft.fillRect(F1k_x,F1k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F1k_x,F1k_y);
          tft.print(freqt.charAt(freqlength-4));
          // now print seperator
          tft.print(".");  
          F1k = (freqt.charAt(freqlength-4));
      }
     
      if(F10k !=(freqt.charAt(freqlength-5))){
      
          int F10k_OffSet = 61;
          int F10k_x = main_freq_cursor_pos_x + F10k_OffSet;
          int F10k_y = main_freq_cursor_pos_y ;
    
          tft.fillRect(F10k_x,F10k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F10k_x,F10k_y);
          tft.print(freqt.charAt(freqlength-5)); 
          F10k = (freqt.charAt(freqlength-5));
          if(freqlength==5){       
            tft.fillRect( main_freq_cursor_pos_x - 50, main_freq_cursor_pos_y - 2,111,28,ILI9341_BLACK);
          }
      }
     
       if(F100k !=(freqt.charAt(freqlength-6))){
        
          int F100k_OffSet = 40;
          int F100k_x = main_freq_cursor_pos_x + F100k_OffSet;
          int F100k_y = main_freq_cursor_pos_y ;
      
          tft.fillRect(F100k_x,F100k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F100k_x,F100k_y);
          tft.print(freqt.charAt(freqlength-6)); 
          F100k = (freqt.charAt(freqlength-6));
          if(freqlength==6){       
            tft.fillRect( main_freq_cursor_pos_x - 50, main_freq_cursor_pos_y - 2,89,28,ILI9341_BLACK);
          }
       }
     
       if(Fmega !=(freqt.charAt(freqlength-7))){
        
          int Fmega_OffSet = 5;
          int Fmega_x = main_freq_cursor_pos_x + Fmega_OffSet;
          int Fmega_y = main_freq_cursor_pos_y ;
      
          tft.fillRect(Fmega_x,Fmega_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(Fmega_x,Fmega_y);
          tft.print(freqt.charAt(freqlength-7));
          // now print seperator
          tft.print(".");
          Fmega = (freqt.charAt(freqlength-7));
          if(freqlength==7){       
            tft.fillRect( main_freq_cursor_pos_x - 50, main_freq_cursor_pos_y - 2,54,28,ILI9341_BLACK);
          }
       }
     
       if(F10m !=(freqt.charAt(freqlength-8))){
        
          int F10m_OffSet = -16;
          int F10m_x = main_freq_cursor_pos_x + F10m_OffSet;
          int F10m_y = main_freq_cursor_pos_y ;
      
          tft.fillRect(F10m_x,F10m_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F10m_x,F10m_y);
          tft.print(freqt.charAt(freqlength-8)); 
          F10m = (freqt.charAt(freqlength-8));
       }
     
       if(F100m !=(freqt.charAt(freqlength-9))){
        
          int F100m_OffSet = -37;
          int F100m_x = main_freq_cursor_pos_x + F100m_OffSet;
          int F100m_y = main_freq_cursor_pos_y ;
      
          tft.fillRect(F100m_x,F100m_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F100m_x,F100m_y);
          tft.print(freqt.charAt(freqlength-9)); 
          F100m = (freqt.charAt(freqlength-9));
       }
  }
  


  if(((((flag.fg_B_active==true) && (flag.fg_freq_Changed==true)) || (flag.fg_ReDraw_Screen==true)) || (flag.fg_A_B_changed==true)) || (flag.fg_AB_changed==true))
  {
    
       // set frequency readout colour & font size
      tft.setFont(DroidSansMono_24);

      if(flag.fg_B_active==false)
      {
          tft.setTextColor(ILI9341_DARKGREY);
      }
      if(flag.fg_B_active==true)
      {
          tft.setTextColor(main_freq_text_colour); 
      }

      tft.setCursor(sub_freq_cursor_pos_x,main_freq_cursor_pos_y);
      
      // ------ Display VFO B frequency

      freqt=String(u.fg_B_value);
      freqlength=(freqt.length());

      if(f1 !=(freqt.charAt(freqlength-1))){

          int f1_OffSet = 159;
          int f1_x = sub_freq_cursor_pos_x + f1_OffSet;
          int f1_y = sub_freq_cursor_pos_y ;

          tft.fillRect(f1_x,f1_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f1_x,f1_y);
          tft.print(freqt.charAt(freqlength-1)); 
          f1 = (freqt.charAt(freqlength-1)); 
          tft.print(" Hz"); 
      }
    
      if(f10 !=(freqt.charAt(freqlength-2))){
      
          int f10_OffSet = 138;
          int f10_x = sub_freq_cursor_pos_x + f10_OffSet;
          int f10_y = sub_freq_cursor_pos_y ;
    
          tft.fillRect(f10_x,f10_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f10_x,f10_y);
          tft.print(freqt.charAt(freqlength-2)); 
          f10 = (freqt.charAt(freqlength-2));
      }
     
      if(f100 !=(freqt.charAt(freqlength-3))){
      
          int f100_OffSet = 117;
          int f100_x = sub_freq_cursor_pos_x + f100_OffSet;
          int f100_y = sub_freq_cursor_pos_y ;
    
          tft.fillRect(f100_x,f100_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f100_x,f100_y);
          tft.print(freqt.charAt(freqlength-3));
          f100 = (freqt.charAt(freqlength-3));
      }
     
      if(f1k !=(freqt.charAt(freqlength-4))){
      
          int f1k_OffSet = 82;
          int f1k_x = sub_freq_cursor_pos_x + f1k_OffSet;
          int f1k_y = sub_freq_cursor_pos_y ;
    
          tft.fillRect(f1k_x,f1k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f1k_x,f1k_y);
          tft.print(freqt.charAt(freqlength-4));
          // now print seperator
          tft.print(".");  
          f1k = (freqt.charAt(freqlength-4));
      }
     
      if(f10k !=(freqt.charAt(freqlength-5))){
      
          int f10k_OffSet = 61;
          int f10k_x = sub_freq_cursor_pos_x + f10k_OffSet;
          int f10k_y = sub_freq_cursor_pos_y ;
    
          tft.fillRect(f10k_x,f10k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f10k_x,f10k_y);
          tft.print(freqt.charAt(freqlength-5)); 
          f10k = (freqt.charAt(freqlength-5));
          if(freqlength==5){       
            tft.fillRect( sub_freq_cursor_pos_x - 50, sub_freq_cursor_pos_y - 2,111,28,ILI9341_BLACK);
          }
      }
     
       if(f100k !=(freqt.charAt(freqlength-6))){
        
          int f100k_OffSet = 40;
          int f100k_x = sub_freq_cursor_pos_x + f100k_OffSet;
          int f100k_y = sub_freq_cursor_pos_y ;
      
          tft.fillRect(f100k_x,f100k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f100k_x,f100k_y);
          tft.print(freqt.charAt(freqlength-6)); 
          f100k = (freqt.charAt(freqlength-6));
          if(freqlength==6){       
            tft.fillRect( sub_freq_cursor_pos_x - 50, sub_freq_cursor_pos_y - 2,89,28,ILI9341_BLACK);
          }
       }
     
       if(fmega !=(freqt.charAt(freqlength-7))){
        
          int fmega_OffSet = 5;
          int fmega_x = sub_freq_cursor_pos_x + fmega_OffSet;
          int fmega_y = sub_freq_cursor_pos_y ;
      
          tft.fillRect(fmega_x,fmega_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(fmega_x,fmega_y);
          tft.print(freqt.charAt(freqlength-7));
          // now print seperator
          tft.print(".");
          fmega = (freqt.charAt(freqlength-7));
          if(freqlength==7){       
            tft.fillRect( sub_freq_cursor_pos_x - 50, sub_freq_cursor_pos_y - 2,54,28,ILI9341_BLACK);
          }
       }
     
       if(f10m !=(freqt.charAt(freqlength-8))){
        
          int f10m_OffSet = -16;
          int f10m_x = sub_freq_cursor_pos_x + f10m_OffSet;
          int f10m_y = sub_freq_cursor_pos_y ;
      
          tft.fillRect(f10m_x,f10m_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f10m_x,f10m_y);
          tft.print(freqt.charAt(freqlength-8)); 
          f10m = (freqt.charAt(freqlength-8));
       }
     
       if(f100m !=(freqt.charAt(freqlength-9))){
        
          int f100m_OffSet = -37;
          int f100m_x = sub_freq_cursor_pos_x + f100m_OffSet;
          int f100m_y = sub_freq_cursor_pos_y ;
      
          tft.fillRect(f100m_x,f100m_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f100m_x,f100m_y);
          tft.print(freqt.charAt(freqlength-9)); 
          f100m = (freqt.charAt(freqlength-9));
       }    
      
  }
      flag.fg_ReDraw_Screen= false;
      flag.fg_A_B_changed=false;
      flag.fg_freq_Changed=false;
      flag.fg_AB_changed=false; 
      delay(50); 
}

void display_CLK0_CLK2_Txt(){

    // CLK0

    tft.setTextColor(info_text_colour);
    // set readout colour & font size
    tft.setFont(DroidSansMono_14);
    tft.setCursor(vanity_cursor_pos_x + 20,vanity_cursor_pos_y +10);
    tft.print("Si5351 Clk_0 : +7dBm");

    //CLK2

    tft.setTextColor(info_text_colour);
    // set readout colour & font size
    tft.setFont(DroidSansMono_14);
    tft.setCursor(info_cursor_pos_x + 20,info_cursor_pos_y ); 
    tft.print("Si5351 Clk_2 : +7dBm");
    
}
