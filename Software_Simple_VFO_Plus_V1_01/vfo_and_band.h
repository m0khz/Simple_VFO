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

void vfo_and_band_handler (){

// OK so the default band (i.e.startup band is 2M) so we need to setup the 2M VFO values
// Initially VFO A = VFO B - standard practice
 if((u.band_2M_active == 1) && (flag.vfo_set_for_band == false))
 {

  //unsigned int transverter_offset     = 116000000;
  //unsigned int if_offset              =   9000000;
  // And display needs to be vfo_freq(19 - 21Mhz) + transverter(116Mhz) +IF(9Mhz)
    u.band_2M_vfo_A_value = ((u.vfo_a + u.transverter_offset) + (u.if_offset));
    u.band_2M_vfo_B_value = ((u.vfo_b + u.transverter_offset) + (u.if_offset));
    // now set the vfo display variables, this may seem over the top but as we add different bands this will make sence!
    u.vfo_A_value = u.band_2M_vfo_A_value;
    u.vfo_B_value = u.band_2M_vfo_B_value;
    // now reset the flag so we only do this once i.e. from startup or when changing from another band
    flag.vfo_set_for_band = true;
 }
 // Now if the frequency is changed we need to update the correct VFO
 if((u.band_2M_active == 1) && (flag.freq_Changed==true))
 {
    if(flag.vfo_A_active == true)
    {
      u.band_2M_vfo_A_value = ((u.vfo_a + u.transverter_offset) + (u.if_offset));
      u.vfo_A_value = u.band_2M_vfo_A_value;
    }
    if(flag.vfo_B_active == true)
    {
      u.band_2M_vfo_B_value = ((u.vfo_b + u.transverter_offset) + (u.if_offset));
      u.vfo_B_value = u.band_2M_vfo_B_value;
    }   
 }  
}
