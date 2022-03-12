/* 
 * File:   ax.h
 * Author: Utilisateur
 *
 * Created on April 12, 2017, 9:15 PM
 */

#ifndef AX_H
#define	AX_H
#include <stdint.h>
#include "mcc_generated_files/adc.h"
#ifdef	__cplusplus
extern "C" {
#endif

    // Commands, first byte sent
#define CMD_SET_LED_ON		10
#define CMD_SET_LED_OFF		11
#define CMD_GET_ADC			12
#define CMD_PING_AX			20
#define CMD_READ_AX			21
#define CMD_WRITE_AX		22

    // AX12 memory address
#define P_MODEL_NUMBER				0
#define P_VERSION					2
#define P_ID						3
#define P_BAUD_RATE					4
#define P_RETURN_DELAY_TIME			5
#define P_CW_ANGLE_LIMIT			6
#define P_CCW_ANGLE_LIMIT			8
#define P_SYSTEM_DATA2				10
#define P_LIMIT_TEMPERATURE			11
#define P_DOWN_LIMIT_VOLTAGE		12
#define P_UP_LIMIT_VOLTAGE			13
#define P_MAX_TORQUE				14
#define P_RETURN_LEVEL				16
#define P_ALARM_LED					17
#define P_ALARM_SHUTDOWN			18
#define P_OPERATING_MODE			19
#define P_DOWN_CALIBRATION		    20
#define P_UP_CALIBRATION			22
#define P_TORQUE_ENABLE				24
#define P_LED						25
#define P_CW_COMPLIANCE_MARGIN		26
#define P_CCW_COMPLIANCE_MARGIN		27
#define P_CW_COMPLIANCE_SLOPE		28
#define P_CCW_COMPLIANCE_SLOPE		29
#define P_GOAL_POSITION				30
#define P_GOAL_SPEED				32
#define P_TORQUE_LIMIT				34
#define P_PRESENT_POSITION			36
#define P_PRESENT_SPEED				38
#define P_PRESENT_LOAD				40
#define P_PRESENT_VOLTAGE			42
#define P_PRESENT_TEMPERATURE		43
#define P_REGISTERED_INSTRUCTION	44
#define P_PAUSE_TIME				45
#define P_MOVING					46
#define P_LOCK						47
#define P_PUNCH						48

    volatile adc_result_t adc_values[10];

    void delay_ms(int ms);
    int getAddressSize(int address);

    // Set the led on
    // @param led :  1 - 10
    void setLedOn(int led);

    // Set the led off
    // @param led :  1 - 10
    void setLedOff(int led);

    // Get the adc value (12bits)
    // @param led :  0 - 9
    // @returns value : 0 - 4095
    int getADC(int adc);


    int pingAX(int id);

    int readAXData(int id, int address, int *err);
    int writeAXData(int id, int address, int data);

    // callback I2C
    void handleByteReceived(uint8_t i2c_data_received);

    uint8_t getByteToSend(uint8_t i2c_data_received);

#ifdef	__cplusplus
}
#endif

#endif	/* AX_H */

