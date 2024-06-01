 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE    1023


#define ADC_REF_VOLT_VALUE 2.56

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern Public global variables to be used by other modules */
typedef enum {
	FCPU_1 , FCPU_2 , FCPU_4 ,FCPU_8 , FCPU_16 ,FCPU_32 ,FCPU_64 , FCPU_128
}Prescale_divsor;
typedef enum {
	USE_AREF_VOLT , USE_AVCC_VOLT , RESERVED , USE_INTERNAL_VOLT
}Reference_Setting;

typedef struct{
 Prescale_divsor prescale ;
 Reference_Setting setting;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
void ADC_readChannel(uint8 channel_num);
uint16 ADC_readOutput(void);
ADC_ConfigType * ADC_setConfig(uint8 Ref_Setting , uint8 Prescale_Setting);

#endif /* ADC_H_ */
