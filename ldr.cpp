#include "ldr.h"
#include "Arduino.h"
#include "main.h"

void init_ldr(void)
{
   pinMode(GARDEN_LIGHT, OUTPUT);
   pinMode(LDR_SENSOR, INPUT);

}

void brightness_control(void)
{
  unsigned int adc_value;
  // to read values from LDR sensor
  adc_value = analogRead(LDR_SENSOR);
  //scale it down 0 to 255 and reverse to 255 to 0... it because... ldr is inversely proportional to resistance....  more resistance light...less resistance day
  adc_value = 255 - (adc_value/4);
  // map(0,1023,255,0)
  analogWrite(GARDEN_LIGHT, adc_value);
  delay(100); 
}
