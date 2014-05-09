/*
  LED_Strip_Suli.h
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

#ifndef __LED_STRIP_SULI_H__
#define __LED_STRIP_SULI_H__

#include "Suli.h"

static void led_strip_clk_rise();
static void led_strip_32_zero();
static uint8 led_strip_take_anticode(uint8 dta);
static void led_strip_dta_send(uint32 dta);

// user api
void led_strip_begin();
void led_strip_end();
void led_strip_init(PIN_T clk, PIN_T dta);
void led_strip_set_color(uint8 r, uint8 g, uint8 b);


#endif