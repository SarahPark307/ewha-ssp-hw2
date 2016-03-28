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

if (stop == false)  {
	int stage = 100;
    int i ;
	for( i = stage ; i>0 ; i--){

		int time_1 = (int)(10000/stage);

		myAnalogWrite(REAR_LED_PIN,i,time_1);
	  }
	stop = true;
}
}

