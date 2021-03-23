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

void initialise_dds(){
    // Initialize the DDS
    si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
    si5351.set_correction(31830, SI5351_PLL_INPUT_XO);      // Set to specific Si5351 calibration number
    si5351.set_pll(SI5351_PLL_FIXED, SI5351_PLLA);
    si5351.drive_strength(SI5351_CLK0, SI5351_DRIVE_8MA);
    si5351.drive_strength(SI5351_CLK2, SI5351_DRIVE_8MA);
    //si5351.set_freq((freq * 100ULL), SI5351_CLK0);
    //si5351.set_freq((BFO_freq * 100ULL), SI5351_CLK2);

}

void update_si5351(){
  
/*
 *  So Si5351 output needs to be 19 - 21 Mhz
 *  And display needs to be transverter(116Mhz)+IF(9Mhz)+vfo_a(19 - 21Mhz) 
 *                    or    transverter(116Mhz)+IF(9Mhz)+vfo_b(19 - 21Mhz) 
 */

  if(flag.mode == false) { // were're in VFO mode so update accordingly
      if(flag.vfo_A_active == true)
      {
        //Serial.print("Si5351a value A to set is =  ");
        //Serial.println(u.vfo_a);
        si5351.set_freq((u.vfo_a * 100ULL), SI5351_CLK0);
        //si5351.set_freq((u.BFO_freq * 100ULL), SI5351_CLK2);
        delay(50);
      }
  
      if(flag.vfo_B_active == true)
      {
        //Serial.print("Si5351a value B to set is =  ");
        //Serial.println(u.vfo_b);
        si5351.set_freq((u.vfo_b * 100ULL), SI5351_CLK0);
        //si5351.set_freq((u.BFO_freq * 100ULL), SI5351_CLK2);
        delay(50);
      }
      //Serial.println();
    }
  if(flag.mode == true) { // were're in Frequency Generation mode so update accordingly
    
      //Serial.println(u.fg_A_value);
      si5351.set_freq((u.fg_A_value * 100ULL), SI5351_CLK0);
      delay(50);
      //Serial.println(u.fg_B_value);
      si5351.set_freq((u.fg_B_value * 100ULL), SI5351_CLK2);
      delay(50);
    }
    //Serial.println(); 
}
