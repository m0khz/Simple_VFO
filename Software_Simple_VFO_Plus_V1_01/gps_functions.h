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


// variables etc. used for gps / time / maidenhead cals & display
float lat = 28.5458,lon = 77.1703; // create variable for latitude and longitude object  
float oldLat;
float oldLon;
//int flag = 0;
String currentLat;
String previousLat;
long previousMillis = 0;        // will store last time LED was updated
long interval = 5000;           // interval at which co-ordinates / time & Maidenhead displays are switched (milliseconds)
int switchCase = 0; 

byte last_second;
char Time[]  = "Time  :00:00:00";
char Date[]  = "Date  :00.00.2000";

// Maidenhead Locator
char mh[10] = "";

void findMH(char *dst, float fa, float fo)
{
  int a1, a2, a3;
  int o1, o2, o3;
  double rd;

  // Latitude
  rd = fa + 90.0;
  a1 = (int)(rd / 10.0);
  rd = rd - (double)a1 * 10.0;
  a2 = (int)(rd);
  rd = rd - (double)a2;
  a3 = (int)(24.0 * rd);

  // Longitude
  rd = fo + 180.0;
  o1 = (int)(rd / 20.0);
  rd = rd - (double)o1 * 20.0;
  o2 = (int)(rd / 2.0);
  rd = rd - 2.0 * (double)o2;
  o3 = (int)(12.0 * rd);

  dst[0] = (char)o1 + 'A';
  dst[1] = (char)a1 + 'A';
  dst[2] = (char)o2 + '0';
  dst[3] = (char)a2 + '0';
  dst[4] = (char)o3 + 'A';
  dst[5] = (char)a3 + 'A';
  dst[6] = '\0';
}


  /*
   *  int info_boarder_x = 5;             // position for top left 
      int info_boarder_y = 160;           // position for top left
      int info_boarder_w = 310;           // width of boarder
      int info_boarder_d = 75;            // depth of boarder
      int info_boarder_colour = ILI9341_GREEN;
   *  int info_cursor_pos_x = 20;         // position for top left
      int info_cursor_pos_y = 207;        // position for top left
      int info_text_colour = ILI9341_YELLOW;
   * 
   * 
   */

void gpsDisplays()
{
 
unsigned long currentMillis = millis();
int     mhFlag = 0;
  
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis; 

      for(int i=0; i<5; i++);
      { 
        switch (switchCase)
        {
          case 0:   // initial Case entry - 1st time around  
          //tft.fillRect((info_boarder_x +1),(info_boarder_y + 1), (info_boarder_w - 3), (info_boarder_d - 2), ILI9341_BLACK);
           
          break;
          case 1: // Calculates current Latitude & Longitude from gps data & displays
          tft.fillRect((info_boarder_x +1),(info_boarder_y + 1), (info_boarder_w - 3), (info_boarder_d - 2), ILI9341_BLACK);
          tft.setTextColor(info_text_colour);
          // set frequency readout colour & font size
          tft.setFont(DroidSansMono_14);
          //tft.setTextSize(1);
          tft.setCursor(info_cursor_pos_x,info_cursor_pos_y); 
        
          if (gps.location.isValid())
            {  
              tft.print("Latitude :  ");
              tft.fillRect((info_cursor_pos_x + 115),(info_cursor_pos_y - 1), (160), (15), ILI9341_BLACK);
              tft.println(gps.location.lat(), 6);
              tft.setCursor(info_cursor_pos_x,(info_cursor_pos_y + 17));
              tft.print("Longitude:  ");
              tft.fillRect((info_cursor_pos_x + 115),(info_cursor_pos_y + 16), (160), (15), ILI9341_BLACK);
              tft.println(gps.location.lng(), 6);
            }
          else
            {
              tft.print(F("GPS not locked ..."));
             }
          break;
          case 2:    // Calculates current time from gps data & displays
              tft.fillRect((info_boarder_x +1),(info_boarder_y + 1), (info_boarder_w - 3), (info_boarder_d - 2), ILI9341_BLACK);
              tft.setTextColor(info_text_colour);
              // set frequency readout colour & font size
              tft.setFont(DroidSansMono_14);
              //tft.setTextSize(1);
             
              while (gpsSerial.available()) 
              {
                if(gps.encode(gpsSerial.read()));
                {
                   if (gps.date.isUpdated())

                    if (gps.time.isValid()) {
                      Time[7]   = gps.time.hour()   / 10 + 48;
                      Time[8]   = gps.time.hour()   % 10 + 48;
                      Time[10]  = gps.time.minute() / 10 + 48;
                      Time[11]  = gps.time.minute() % 10 + 48;
                      Time[13]  = gps.time.second() / 10 + 48;
                      Time[14]  = gps.time.second() % 10 + 48;
                     }
 
                    if (gps.date.isValid()) {
                      Date[7]   = gps.date.day()    / 10 + 48;
                      Date[8]   = gps.date.day()    % 10 + 48;
                      Date[10]  = gps.date.month()  / 10 + 48;
                      Date[11]  = gps.date.month()  % 10 + 48;
                      Date[15]  =(gps.date.year()   / 10) % 10 + 48;
                      Date[16]  = gps.date.year()   % 10 + 48;
                     }
 
                    if(last_second != gps.time.second()) {
                      last_second = gps.time.second();

                      tft.setCursor(info_cursor_pos_x,info_cursor_pos_y); 
                      tft.print(Date);
                      
                      tft.setCursor(info_cursor_pos_x,(info_cursor_pos_y + 17)); 
                      tft.print(Time);
                      tft.print("   UTC");
                     }
                }
          break;
          case 3: //Calculates and displays current Maidenhead locator square    
         tft.fillRect((info_boarder_x +1),(info_boarder_y + 1), (info_boarder_w - 3), (info_boarder_d - 2), ILI9341_BLACK);
           while(gpsSerial.available() > 0){
              if(gps.encode(gpsSerial.read()));{
                if (gps.location.isValid()){
                   lat = (gps.location.lat());
                   lon = (gps.location.lng());
                   findMH(mh, lat, lon);
                   if(mhFlag == 0){
                      tft.setCursor(info_cursor_pos_x + 75,info_cursor_pos_y + 10); 
                      tft.setTextColor(info_text_colour);
                      // set frequency readout colour & font size
                      tft.setFont(DroidSansMono_18);
                      //tft.setTextSize(1);
                      tft.print(mh);
                      mhFlag = 1;
                   }
                }
              }          
           }
          //switchCase = 0; 
          break;

          case 4: // Display MY_CALLSIGN
             tft.fillRect((info_boarder_x +1),(info_boarder_y + 1), (info_boarder_w - 3), (info_boarder_d - 2), ILI9341_BLACK);
             tft.setCursor(info_cursor_pos_x + 35,info_cursor_pos_y + 10); 
             tft.setTextColor(info_text_colour);
             // set frequency readout colour & font size
             tft.setFont(DroidSansMono_18);
             //tft.setTextSize(1);
             tft.print(MY_CALLSIGN);

             switchCase = 0; 
             break;
        }
      }
      switchCase ++;
    }
  }
}

void fetchGpsData()
{
  while(gpsSerial.available() > 0) // check for gps data   
      if(gps.encode(gpsSerial.read()))
        gpsDisplays();     
        if (millis() > 5000 && gps.charsProcessed() < 10)
        {
          Serial.println(F("No GPS detected: check wiring."));
          while(true);
        }
} 
