/*
 *
 * Module: ultrasonic
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the ultrasonic driver
 * Created on: Oct 18, 2021
 * Author: mahmoud Mohamed
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* ultrasonic HW Ports and Pins Ids */
#define ULTRASONIC_TRIGGER_PORT_ID                 PORTB_ID
#define ULTRASONIC_TRIGGER_PIN_ID                  PIN5_ID

#define ULTRASONIC_ECHO_PORT_ID                 PORTD_ID
#define ULTRASONIC_ECHO_PIN_ID                  PIN6_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description: Function to init. ultrasonic sensor
 * 1-Initialize  the ICU driver
 * 2-setup pins of sensor
 *
 */
void Ultrasonic_init(void);


/*
 * Description: Function to Send the Trigger pulse to the ultrasonic.
 *
 */

void Ultrasonic_Trigger(void);


/*
 * Description: Function to
 *1- Send the trigger pulse by using Ultrasonic_Trigger function.
 *2- Start the measurements by the ICU from this moment
 */
uint16 Ultrasonic_readDistance(void);


/*
 * Description: Function to calculate time of high  depend on value of counter
 * 1-detect falling edge by icu
 * 2-store high time value in global variable
 * 3_detect Rissing edge by icu
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */


