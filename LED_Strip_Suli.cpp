/*
  LED_Strip_Suli.cpp
  This is a Suly compatable Library
  
  2014 Copyright (c) Seeed Technology Inc.  All right reserved.
  
  Loovee
  2013-5-8

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "LED_Strip_Suli.h"

IO_T *__pinClk;
IO_T *__pinDta;


void led_strip_init(PIN_T clk, PIN_T dta)
{
    suli_pin_init(__pinDta, dta);
    suli_pin_init(__pinClk, clk);

    suli_pin_dir(__pinDta, HAL_PIN_OUTPUT);
    suli_pin_dir(__pinClk, HAL_PIN_OUTPUT);
}

void led_strip_begin()
{
    led_strip_32_zero();
}

void led_strip_end()
{
    led_strip_32_zero();
}

void led_strip_clk_rise()
{
    suli_pin_write(__pinClk, HAL_PIN_LOW);
    suli_delay_us(20);
    suli_pin_write(__pinClk, HAL_PIN_HIGH);
    suli_delay_us(20);
}

void led_strip_32_zero()
{
    suli_pin_write(__pinDta, HAL_PIN_LOW);
    for(int i=0; i<32; i++)
    {
        led_strip_clk_rise();
    }
}

uint8 led_strip_take_anticode(uint8 dta)
{
    uint8 tmp = 0;
    if(!(dta & 0x80))
    {
        tmp |= 0x02; 
    }
    
    if(!(dta & 0x40))
    {
        tmp |= 0x01;
    }
    
    return tmp;
}

void led_strip_dta_send(uint32 dta)
{
    for(int i=0; i<32; i++)
    {
        if(!(dta & 0x80000000))
        {
            suli_pin_write(__pinDta, HAL_PIN_HIGH);
        }
        else
        {
            suli_pin_write(__pinDta, HAL_PIN_LOW);
        }
        
        dta <<= 0x01;
        led_strip_clk_rise();
    }
}

void led_strip_set_color(uint8 r, uint8 g, uint8 b)
{
    uint32 dx = 0x00;
    dx |= (uint32_t)0x03 << 30;             // highest two bits 1£¬flag bits
    dx |= (uint32_t)led_strip_take_anticode(b) << 28;
    dx |= (uint32_t)led_strip_take_anticode(g) << 26;	
    dx |= (uint32_t)led_strip_take_anticode(r) << 24;
 
    dx |= (uint32_t)b << 16;
    dx |= (uint32_t)g << 8;
    dx |= r;
    led_strip_dta_send(dx);
}