/*
 * dcm.h
 *
 *  Created on: 12 Oct 2021
 *      Author: kirol
 */

#ifndef DCM_H_
#define DCM_H_
#define DCM_EN1_PORT PORTB_ID
#define DCM_EN1_PIN PIN3_ID
#define DCM_IN_PORT PORTD_ID
#define DCM_IN1_PIN PIN3_ID
#define DCM_IN2_PIN PIN4_ID
#include "std_types.h"



typedef enum{
	DCM_STOP , DCM_CW , DCM_CCW

}DcMotor_State;



void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DCM_H_ */
