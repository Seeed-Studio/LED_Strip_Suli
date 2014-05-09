#include <Wire.h>
#include <SoftwareSerial.h>

#include "Suli.h"
#include "LED_Strip_Arduino.h"

const int pin_clk = 2;
const int pin_dta = 3;

led_strip led(pin_clk, pin_dta);


void setup()
{

}


void loop()
{
    led.begin();                            // begin
    led.SetColor(255, 0, 0);                // Red. first node data
    led.SetColor(0, 0, 255);                // Blue. second node data
    led.end();
    delay(500);
    
    led.begin();                            // begin
    led.SetColor(0, 0, 255);                // Blue. first node data
    led.SetColor(0, 255, 0);                // Green. second node data
    led.end();
    delay(500);
    
    led.begin();                            // begin
    led.SetColor(0, 255, 0);                // Green. first node data
    led.SetColor(255, 0, 0);                // Red. second node data
    led.end();
    delay(500);
}
