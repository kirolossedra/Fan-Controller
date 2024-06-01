/*
 ================================================================================================
 Name        : MINIPROJET3.C
 Author      : Kirolos SEDRA
 Description :

 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dcm.h"

int main(void)
{
	uint8 temp;
	LCD_init(); /* initialize LCD driver */
	ADC_ConfigType config = { FCPU_8 , USE_INTERNAL_VOLT};
	DcMotor_State state;
	ADC_init(&config);

	DcMotor_Init();
	LCD_displayString("FAN IS");
	    	LCD_moveCursor(1,0);

	    	LCD_displayString("Temp =    C");






    while(1)
    {

    	temp = LM35_getTemperature();
    	if(temp < 30){ state = DCM_STOP; LCD_moveCursor(0,7); LCD_displayString("OFF"); }
    	else{ state = DCM_CW; LCD_moveCursor(0,7); LCD_displayString("ON ");}
    	if(temp >= 30 && temp < 60)DcMotor_Rotate(state,25);
    	if(temp >= 60 && temp < 90) DcMotor_Rotate(state,50);
    	if(temp >=90 && temp <120) DcMotor_Rotate(state,75);
    	if(temp>=120) DcMotor_Rotate(state,100);




		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,7);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
    }
}
