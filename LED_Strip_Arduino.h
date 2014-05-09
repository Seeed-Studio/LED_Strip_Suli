/*
  LED_Strip_Arduino.h
  For Arduino Only
  This is a Suly compatible Library
  
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

#include "Suli.h"
#include "LED_Strip_Suli.h"

class led_strip{

public:

    led_strip(PIN_T clk, PIN_T dta)             // initialize
    {
        led_strip_init(clk, dta);
    }
    
    void begin()
    {
        led_strip_begin();
    }
    
    void end()
    {
        led_strip_end();
    }
    
    void setColor(uint8 r, uint8 g, uint8 b)
    {
        led_strip_set_color(r, g, b);
    }
};
