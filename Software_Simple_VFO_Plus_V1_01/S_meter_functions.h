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


// SMeter Bar graph max - min
  int graghMax = 276;
  int graghMin = 24;

// test values
int LastPercent = 0;
int drawBar_value = 276;
int test_value = 276;

//----- meter ------------------------------
//
 void meter(){

  if(flag.Smeter==false){
     tft.setFont(DroidSansMono_8);
     tft.setTextColor(ILI9341_LIGHTGREY);
     tft.setCursor(10,10);
     //tft.print("S : 1-----3-------6-------9---+20--+40---dB");
     tft.print("S : 1-----3-------6-------9");
     tft.setTextColor(ILI9341_GREEN);
     tft.print("---+20--+40-----");
     tft.setTextColor(ILI9341_LIGHTGREY);
     tft.setCursor(10,35);
     //tft.print("Po: 1----20----40----60----80----100%------");
     tft.print("Po: 1----20----40----60----80----");
     tft.setTextColor(ILI9341_RED);
     tft.print("100%------");
     tft.setTextColor(ILI9341_LIGHTGREY);
     flag.Smeter = true;
  }
} 
// ------- end of meter() ---------------

// ------- Colour grdauation table for rainbow bar display
byte rgbtable[70][3]{
  {0,0,255},
  {0,16,255},
  {0,32,255},
  {0,48,255},
  {0,64,255},
  {0,80,255},
  {0,96,255},
  {0,112,255},
  {0,128,255},
  {0,144,255},
  {0,160,255},
  {0,176,255},
  {0,192,255},
  {0,208,255},
  {0,224,255},
  {0,240,255},
  {0,255,255},
  {0,255,240},
  {0,255,224},
  {0,255,209},
  {0,255,192},
  {0,255,177},
  {0,255,160},
  {0,255,145},
  {0,255,128},
  {0,255,113},
  {0,255,96},
  {0,255,81},
  {0,255,64},
  {0,255,49},
  {0,255,32},
  {0,255,16},
  {0,255,0},
  {16,255,0},
  {32,255,0},
  {48,255,0},
  {64,255,0},
  {80,255,0},
  {96,255,0},
  {102,255,0},
  {128,255,0},
  {144,255,0},
  {160,255,0},
  {176,255,0},
  {192,255,0},
  {208,255,0},
  {224,255,0},
  {240,255,0},
  {255,255,0},
  {255,240,0},
  {255,224,0},
  {255,208,0},
  {255,192,0},
  {255,176,0},
  {255,160,0},
  {255,144,0},
  {255,128,0},
  {255,112,0},
  {255,96,0},
  {255,80,0},
  {255,64,0},
  {255,48,0},
  {255,32,0},
  {255,16,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0},
  {255,0,0}
  };
// ----- End of Colour grdauation table for rainbow bar display

// ----- Plot the lastest bar 
void rainbow_gragh(int value){

  value = map(value,0,273,0,69);
   
   //Inspiration for gradient bar taken from here:
   // ********* https://www.youtube.com/watch?v=8HfOyRfHlAU ********
    int l = 0;
       
    for(int i=0; i<69; i++) {
       if(i<=value){
           l=33+(i*4);
          // tft.fillRect(l,171,4,4,CL(rgbtable[i][0],rgbtable[i][1],rgbtable[i][2]));
           tft.fillRect(l,24,4,4,CL(rgbtable[i][0],rgbtable[i][1],rgbtable[i][2]));
        }
        else{
           l=33+(i*4);
           //tft.fillRect(l,171,4,4,ILI9341_BLACK);
           tft.fillRect(l,24,4,4,ILI9341_BLACK);
        }
    }
}
// ----- Plot the lastest bar 

// ----- SmeterBarGragh entry function
void SmeterBarGragh(){

      if(!flag.SmeterBarGragh){
        tft.drawRect(32,23,278,6,ILI9341_DARKGREY);   
        flag.SmeterBarGragh = !flag.SmeterBarGragh;
      }

      if (metroSGragh.check() == 1) { // check if the metro has passed its interval .

        // rainbow_gragh expecting int range between 0 - 273 at the moment
        int temp_value;
        temp_value = analogRead(A14);    
        temp_value = map(temp_value,0,1023,0,273);

        drawBar_value = temp_value; // between 0 & 273
          
        if(drawBar_value <= 0){
              drawBar_value = 276;      
        }
        flag.GraphUpdate = false; 
      }
      if(!flag.GraphUpdate){
         // rainbow_gragh expecting int range between 0 - 273 at the moment
         rainbow_gragh(drawBar_value);
         flag.GraphUpdate = !flag.GraphUpdate;
      }
}
// ----- End of SmeterBarGragh entry function
