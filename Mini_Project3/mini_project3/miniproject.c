/*
 * miniproject.c
 *
 *  Created on: Oct 10, 2021
 *      Author: farah
 */

#include <avr/io.h> /* To use SREG register */
#include"lcd.h"
#include"ADC.h"
#include"lm35_sensor.h"
#include"DC_motor.h"
int main(void){
	uint8 LM_reading;
	ADC_ConfigType adc_config={Internal,F_CPU_8};
	LCD_init();/* initialize LCD driver */
	ADC_init(&adc_config);	/* initialize ADC driver */
	DcMotor_Init();	/* initialize DC_Motor driver */
	while(1){
		LM_reading=LM35_getTemperature();	//Reading the temperature
		LCD_moveCursor(0,4);	//Setting the cursor position to the first row 5th column
		if(LM_reading<30){
			DcMotor_Rotate(STOP,0);
			LCD_displayString("FAN is OFF");
		}
		else if(LM_reading>=120){
			DcMotor_Rotate(CW,100);
			LCD_displayString("FAN is ON ");
		}
		else if(LM_reading>=90){
			DcMotor_Rotate(CW,75);
			LCD_displayString("FAN is ON ");
		}
		else if(LM_reading>=60){
			DcMotor_Rotate(CW,50);
			LCD_displayString("FAN is ON ");
		}
		else{
			DcMotor_Rotate(CW,25);
			LCD_displayString("FAN is ON ");
		}
		LCD_moveCursor(1,4);	//Setting the cursor position to the second row 5th column
		LCD_displayString("TEMP = ");
		LCD_intgerToString(LM_reading);	//Writing the temperature read by the sensor on the LCD
		LCD_displayCharacter('C');
	}
	return 0;
}
