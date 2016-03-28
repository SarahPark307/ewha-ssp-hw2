// Do not remove the include below
#include "Lab_2_1.h"



#define REAR_LED_PIN 9
#define DUTY_CYCLE 20

boolean stop = false;
void myAnalogWrite(int pin,int percent,int time)

{

    int display = (int)(time/DUTY_CYCLE) ;
	int on = (int)(DUTY_CYCLE*percent/100);
	int off = (int)(DUTY_CYCLE*(100-percent)/100);

	for (int i = 0 ; i < display ; i++)

		{
			digitalWrite(pin,HIGH);
			delay(on);

			digitalWrite(pin,LOW);
			delay(off);

		}



}



void setup(){
pinMode(REAR_LED_PIN,OUTPUT);

}

void loop(){


if(stop==false)
{
	myAnalogWrite(REAR_LED_PIN,100,2000);

	myAnalogWrite(REAR_LED_PIN,75,2000);

	myAnalogWrite(REAR_LED_PIN,50,2000);

	myAnalogWrite(REAR_LED_PIN,25,2000);
	myAnalogWrite(REAR_LED_PIN,0,2000);

	digitalWrite(REAR_LED_PIN,LOW);
	stop=true;
}

}
