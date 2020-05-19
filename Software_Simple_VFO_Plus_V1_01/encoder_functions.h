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


// define encoder pins
// So this project has one encoder so we'll call this encoder0, hence the following pin definitions
#define encoder0PinA  3
#define encoder0PinB  4
#define encoder0PinSW 2

// ******** Encoder routines ****************************************************************************
volatile int encState = 0;

const uint8_t encTableHalfStep[6][4] =
{
    {0x3, 0x2, 0x1, 0x0},
    {0x23, 0x0, 0x1, 0x0},
    {0x13, 0x2, 0x0, 0x0},
    {0x3, 0x5, 0x4, 0x0},
    {0x3, 0x3, 0x4, 0x10},
    {0x3, 0x5, 0x3, 0x20},
};

const uint8_t encTableFullStep[7][4] =
{
    {0x0, 0x2, 0x4,  0x0},
    {0x3, 0x0, 0x1, 0x10},
    {0x3, 0x2, 0x0,  0x0},
    {0x3, 0x2, 0x1,  0x0},
    {0x6, 0x0, 0x4,  0x0},
    {0x6, 0x5, 0x0, 0x20},
    {0x6, 0x5, 0x4,  0x0},
};

void MainRotEncHalfStep()
{
  // disable the global interrupt setting with cli()
  cli();
  if(flag.mode == false){
    
    if(flag.vfo_lock==false){
      if(flag.vfo_A_active == true){
        encState = encTableHalfStep[encState & 0xF][(digitalRead(encoder0PinB) << 1) | digitalRead(encoder0PinA)];

        int result = encState & 0x30;

        //if (result)
        // SerialUSB.println(result == 0x20 ? "Left" : "Right");  // 0x20 = Left, 0x10 = Right
        int temp;
        if (result){
        //SerialUSB.println(result == 0x20 ? "Left" : "Right");  // 0x20 = Left, 0x10 = Right
        
          if(result == 0x10){
            temp = 1;
          }
          if(result == 0x20){
            temp = -1;
          }
// -------------- now for frequency multipliers

          if((u.tune_multi)==1){
              u.vfo_a += temp;
          }
          if((u.tune_multi)==2){
              u.vfo_a += (temp * 10);
          }
          if((u.tune_multi)==3){
              u.vfo_a += (temp * 100);
          }
          if((u.tune_multi)==4){
              u.vfo_a += (temp * 1000);
          }
          if((u.tune_multi)==5){
              u.vfo_a += (temp * 10000);
          }
          if((u.tune_multi)==6){
              u.vfo_a += (temp * 100000);
          }
  // --------------- end of frequency multipliers 
     
          flag.freq_Changed=true;
        }
      }

        if(flag.vfo_B_active == true){
        encState = encTableHalfStep[encState & 0xF][(digitalRead(encoder0PinB) << 1) | digitalRead(encoder0PinA)];

        int result = encState & 0x30;

        //if (result)
        // SerialUSB.println(result == 0x20 ? "Left" : "Right");  // 0x20 = Left, 0x10 = Right
        int temp;
        if (result){
          //SerialUSB.println(result == 0x20 ? "Left" : "Right");  // 0x20 = Left, 0x10 = Right
        
          if(result == 0x10){
            temp = 1;
          }
          if(result == 0x20){
            temp = -1;
          }
// -------------- now for frequency multipliers

          if((u.tune_multi)==1){
              u.vfo_b += temp;
          }
          if((u.tune_multi)==2){
              u.vfo_b += (temp * 10);
          }
          if((u.tune_multi)==3){
              u.vfo_b += (temp * 100);
          }
          if((u.tune_multi)==4){
              u.vfo_b += (temp * 1000);
          }
          if((u.tune_multi)==5){
              u.vfo_b += (temp * 10000);
          }
          if((u.tune_multi)==6){
              u.vfo_b += (temp * 100000);
          }
// --------------- end of frequency multipliers 
     
          flag.freq_Changed=true;
        }
      }   
    }
  }
  if(flag.mode == true) { // were're in frequency generation mode so update accordingly

     //fg_tune_multi
    
   }
   // re-enable the global interrupt setting with sei()
   sei();
}

void MainRotEncFullStep()
{
  // disable the global interrupt setting with cli()
  cli();
  if(flag.mode == false){
    if(flag.vfo_lock==false){
      if(flag.vfo_A_active == true){
        encState = encTableFullStep[encState & 0xF][(digitalRead(encoder0PinB) << 1) | digitalRead(encoder0PinA)];

        int result = encState & 0x30;

        //if (result)
        // SerialUSB.println(result == 0x20 ? "Left" : "Right");  // 0x20 = Left, 0x10 = Right
        int temp;
        if (result){
          //SerialUSB.println(result == 0x20 ? "Left" : "Right");  // 0x20 = Left, 0x10 = Right
        
          if(result == 0x10){
            temp = 1;
          }
          if(result == 0x20){
            temp = -1;
          }
// -------------- now for frequency multipliers

          if((u.tune_multi)==1){
              u.vfo_a += temp;
          }
          if((u.tune_multi)==2){
              u.vfo_a += (temp * 10);
          }
          if((u.tune_multi)==3){
              u.vfo_a += (temp * 100);
          }
          if((u.tune_multi)==4){
              u.vfo_a += (temp * 1000);
          }
          if((u.tune_multi)==5){
              u.vfo_a += (temp * 10000);
          }
          if((u.tune_multi)==6){
              u.vfo_a += (temp * 100000);
          }
// --------------- end of frequency multipliers 
     
          flag.freq_Changed=true;
        }
      }

        if(flag.vfo_B_active == true){
        encState = encTableFullStep[encState & 0xF][(digitalRead(encoder0PinB) << 1) | digitalRead(encoder0PinA)];

        int result = encState & 0x30;

        //if (result)
        // SerialUSB.println(result == 0x20 ? "Left" : "Right");  // 0x20 = Left, 0x10 = Right
        int temp;
        if (result){
          //SerialUSB.println(result == 0x20 ? "Left" : "Right");  // 0x20 = Left, 0x10 = Right
        
          if(result == 0x10){
            temp = 1;
          }
          if(result == 0x20){
            temp = -1;
          }
// -------------- now for frequency multipliers

          if((u.tune_multi)==1){
              u.vfo_b += temp;
          }
          if((u.tune_multi)==2){
              u.vfo_b += (temp * 10);
          }
          if((u.tune_multi)==3){
              u.vfo_b += (temp * 100);
          }
          if((u.tune_multi)==4){
              u.vfo_b += (temp * 1000);
          }
          if((u.tune_multi)==5){
              u.vfo_b += (temp * 10000);
          }
          if((u.tune_multi)==6){
              u.vfo_b += (temp * 100000);
          }
// --------------- end of frequency multipliers 
     
          flag.freq_Changed=true;
        }
      }   
    }
  }

   if(flag.mode == true) { // were're in frequency generation mode so update accordingly

    if(flag.fg_lock==false){
      
      if(flag.fg_A_active == true){
        encState = encTableFullStep[encState & 0xF][(digitalRead(encoder0PinB) << 1) | digitalRead(encoder0PinA)];

        int result = encState & 0x30;
        int temp;
        if (result){
        
          if(result == 0x10){
            temp = 1;
          }
          if(result == 0x20){
            temp = -1;
          }
// -------------- now for frequency multipliers

          if((u.fg_tune_multi)==1){
              u.fg_A_value += temp;
          }
          if((u.fg_tune_multi)==2){
              u.fg_A_value += (temp * 10);
          }
          if((u.fg_tune_multi)==3){
              u.fg_A_value += (temp * 100);
          }
          if((u.fg_tune_multi)==4){
              u.fg_A_value += (temp * 1000);
          }
          if((u.fg_tune_multi)==5){
              u.fg_A_value += (temp * 10000);
          }
          if((u.fg_tune_multi)==6){
              u.fg_A_value += (temp * 100000);
          }
          if((u.fg_tune_multi)==7){
              u.fg_A_value += (temp * 1000000);
          }
           // now check to see if in limits
          if(u.fg_A_value >= u.fg_upper_limit) u.fg_A_value = u.fg_upper_limit;
          if(u.fg_A_value <= u.fg_lower_limit) u.fg_A_value = u.fg_lower_limit; 
                             
// --------------- end of frequency multipliers 
     
          flag.fg_freq_Changed=true;
        }
      }

        if(flag.fg_B_active == true){
        encState = encTableFullStep[encState & 0xF][(digitalRead(encoder0PinB) << 1) | digitalRead(encoder0PinA)];

        int result = encState & 0x30;

        //if (result)
        // SerialUSB.println(result == 0x20 ? "Left" : "Right");  // 0x20 = Left, 0x10 = Right
        int temp;
        if (result){
          //SerialUSB.println(result == 0x20 ? "Left" : "Right");  // 0x20 = Left, 0x10 = Right
        
          if(result == 0x10){
            temp = 1;
          }
          if(result == 0x20){
            temp = -1;
          }
// -------------- now for frequency multipliers

          if((u.fg_tune_multi)==1){
              u.fg_B_value += temp;
          }
          if((u.fg_tune_multi)==2){
              u.fg_B_value += (temp * 10);
          }
          if((u.fg_tune_multi)==3){
              u.fg_B_value += (temp * 100);
          }
          if((u.fg_tune_multi)==4){
              u.fg_B_value += (temp * 1000);
          }
          if((u.fg_tune_multi)==5){
              u.fg_B_value += (temp * 10000);
          }
          if((u.fg_tune_multi)==6){
              u.fg_B_value += (temp * 100000);
          }
          if((u.fg_tune_multi)==7){
              u.fg_B_value += (temp * 1000000);
          }

          // now check to see if in limits
          if(u.fg_B_value >= u.fg_upper_limit) u.fg_B_value = u.fg_upper_limit;
          if(u.fg_B_value <= u.fg_lower_limit) u.fg_B_value = u.fg_lower_limit; 
                                                 
// --------------- end of frequency multipliers 
     
          flag.fg_freq_Changed=true;
        }
      }   
    }
  }
  // re-enable the global interrupt setting with sei()
  sei();
}
