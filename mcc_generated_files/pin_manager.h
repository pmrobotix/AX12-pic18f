/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.16
        Device            :  PIC18F46K80
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED8 aliases
#define LED8_TRIS               TRISB0
#define LED8_LAT                LATB0
#define LED8_PORT               RB0
#define LED8_WPU                WPUB0
#define LED8_ANS                ANSEL10
#define LED8_SetHigh()    do { LATB0 = 1; } while(0)
#define LED8_SetLow()   do { LATB0 = 0; } while(0)
#define LED8_Toggle()   do { LATB0 = ~LATB0; } while(0)
#define LED8_GetValue()         PORTBbits.RB0
#define LED8_SetDigitalInput()    do { TRISB0 = 1; } while(0)
#define LED8_SetDigitalOutput()   do { TRISB0 = 0; } while(0)

#define LED8_SetPullup()    do { WPUB0 = 1; } while(0)
#define LED8_ResetPullup()   do { WPUB0 = 0; } while(0)
#define LED8_SetAnalogMode()   do { ANSEL10 = 1; } while(0)
#define LED8_SetDigitalMode()   do { ANSEL10 = 0; } while(0)


// get/set LED9 aliases
#define LED9_TRIS               TRISB2
#define LED9_LAT                LATB2
#define LED9_PORT               RB2
#define LED9_WPU                WPUB2
#define LED9_SetHigh()    do { LATB2 = 1; } while(0)
#define LED9_SetLow()   do { LATB2 = 0; } while(0)
#define LED9_Toggle()   do { LATB2 = ~LATB2; } while(0)
#define LED9_GetValue()         PORTBbits.RB2
#define LED9_SetDigitalInput()    do { TRISB2 = 1; } while(0)
#define LED9_SetDigitalOutput()   do { TRISB2 = 0; } while(0)

#define LED9_SetPullup()    do { WPUB2 = 1; } while(0)
#define LED9_ResetPullup()   do { WPUB2 = 0; } while(0)


// get/set LED10 aliases
#define LED10_TRIS               TRISB3
#define LED10_LAT                LATB3
#define LED10_PORT               RB3
#define LED10_WPU                WPUB3
#define LED10_SetHigh()    do { LATB3 = 1; } while(0)
#define LED10_SetLow()   do { LATB3 = 0; } while(0)
#define LED10_Toggle()   do { LATB3 = ~LATB3; } while(0)
#define LED10_GetValue()         PORTBbits.RB3
#define LED10_SetDigitalInput()    do { TRISB3 = 1; } while(0)
#define LED10_SetDigitalOutput()   do { TRISB3 = 0; } while(0)

#define LED10_SetPullup()    do { WPUB3 = 1; } while(0)
#define LED10_ResetPullup()   do { WPUB3 = 0; } while(0)


// get/set LED7 aliases
#define LED7_TRIS               TRISC0
#define LED7_LAT                LATC0
#define LED7_PORT               RC0
#define LED7_SetHigh()    do { LATC0 = 1; } while(0)
#define LED7_SetLow()   do { LATC0 = 0; } while(0)
#define LED7_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define LED7_GetValue()         PORTCbits.RC0
#define LED7_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define LED7_SetDigitalOutput()   do { TRISC0 = 0; } while(0)



// get/set LED6 aliases
#define LED6_TRIS               TRISC1
#define LED6_LAT                LATC1
#define LED6_PORT               RC1
#define LED6_SetHigh()    do { LATC1 = 1; } while(0)
#define LED6_SetLow()   do { LATC1 = 0; } while(0)
#define LED6_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define LED6_GetValue()         PORTCbits.RC1
#define LED6_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define LED6_SetDigitalOutput()   do { TRISC1 = 0; } while(0)



// get/set LED5 aliases
#define LED5_TRIS               TRISC2
#define LED5_LAT                LATC2
#define LED5_PORT               RC2
#define LED5_SetHigh()    do { LATC2 = 1; } while(0)
#define LED5_SetLow()   do { LATC2 = 0; } while(0)
#define LED5_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define LED5_GetValue()         PORTCbits.RC2
#define LED5_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISC2 = 0; } while(0)



// get/set LED5 aliases
#define LED5_TRIS               TRISC2
#define LED5_LAT                LATC2
#define LED5_PORT               RC2
#define LED5_SetHigh()    do { LATC2 = 1; } while(0)
#define LED5_SetLow()   do { LATC2 = 0; } while(0)
#define LED5_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define LED5_GetValue()         PORTCbits.RC2
#define LED5_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISC2 = 0; } while(0)



// get/set LED5 aliases
#define LED5_TRIS               TRISC2
#define LED5_LAT                LATC2
#define LED5_PORT               RC2
#define LED5_SetHigh()    do { LATC2 = 1; } while(0)
#define LED5_SetLow()   do { LATC2 = 0; } while(0)
#define LED5_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define LED5_GetValue()         PORTCbits.RC2
#define LED5_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISC2 = 0; } while(0)



// get/set LED5 aliases
#define LED5_TRIS               TRISC2
#define LED5_LAT                LATC2
#define LED5_PORT               RC2
#define LED5_SetHigh()    do { LATC2 = 1; } while(0)
#define LED5_SetLow()   do { LATC2 = 0; } while(0)
#define LED5_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define LED5_GetValue()         PORTCbits.RC2
#define LED5_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISC2 = 0; } while(0)



// get/set LED5 aliases
#define LED5_TRIS               TRISC2
#define LED5_LAT                LATC2
#define LED5_PORT               RC2
#define LED5_SetHigh()    do { LATC2 = 1; } while(0)
#define LED5_SetLow()   do { LATC2 = 0; } while(0)
#define LED5_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define LED5_GetValue()         PORTCbits.RC2
#define LED5_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISC2 = 0; } while(0)



// get/set LED4 aliases
#define LED4_TRIS               TRISD0
#define LED4_LAT                LATD0
#define LED4_PORT               RD0
#define LED4_SetHigh()    do { LATD0 = 1; } while(0)
#define LED4_SetLow()   do { LATD0 = 0; } while(0)
#define LED4_Toggle()   do { LATD0 = ~LATD0; } while(0)
#define LED4_GetValue()         PORTDbits.RD0
#define LED4_SetDigitalInput()    do { TRISD0 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISD0 = 0; } while(0)



// get/set LED3 aliases
#define LED3_TRIS               TRISD1
#define LED3_LAT                LATD1
#define LED3_PORT               RD1
#define LED3_SetHigh()    do { LATD1 = 1; } while(0)
#define LED3_SetLow()   do { LATD1 = 0; } while(0)
#define LED3_Toggle()   do { LATD1 = ~LATD1; } while(0)
#define LED3_GetValue()         PORTDbits.RD1
#define LED3_SetDigitalInput()    do { TRISD1 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISD1 = 0; } while(0)



// get/set LED2 aliases
#define LED2_TRIS               TRISD2
#define LED2_LAT                LATD2
#define LED2_PORT               RD2
#define LED2_SetHigh()    do { LATD2 = 1; } while(0)
#define LED2_SetLow()   do { LATD2 = 0; } while(0)
#define LED2_Toggle()   do { LATD2 = ~LATD2; } while(0)
#define LED2_GetValue()         PORTDbits.RD2
#define LED2_SetDigitalInput()    do { TRISD2 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISD2 = 0; } while(0)



// get/set LED1 aliases
#define LED1_TRIS               TRISD3
#define LED1_LAT                LATD3
#define LED1_PORT               RD3
#define LED1_SetHigh()    do { LATD3 = 1; } while(0)
#define LED1_SetLow()   do { LATD3 = 0; } while(0)
#define LED1_Toggle()   do { LATD3 = ~LATD3; } while(0)
#define LED1_GetValue()         PORTDbits.RD3
#define LED1_SetDigitalInput()    do { TRISD3 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISD3 = 0; } while(0)



// get/set LED1 aliases
#define LED1_TRIS               TRISD3
#define LED1_LAT                LATD3
#define LED1_PORT               RD3
#define LED1_SetHigh()    do { LATD3 = 1; } while(0)
#define LED1_SetLow()   do { LATD3 = 0; } while(0)
#define LED1_Toggle()   do { LATD3 = ~LATD3; } while(0)
#define LED1_GetValue()         PORTDbits.RD3
#define LED1_SetDigitalInput()    do { TRISD3 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISD3 = 0; } while(0)



// get/set LED1 aliases
#define LED1_TRIS               TRISD3
#define LED1_LAT                LATD3
#define LED1_PORT               RD3
#define LED1_SetHigh()    do { LATD3 = 1; } while(0)
#define LED1_SetLow()   do { LATD3 = 0; } while(0)
#define LED1_Toggle()   do { LATD3 = ~LATD3; } while(0)
#define LED1_GetValue()         PORTDbits.RD3
#define LED1_SetDigitalInput()    do { TRISD3 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISD3 = 0; } while(0)



// get/set LED1 aliases
#define LED1_TRIS               TRISD3
#define LED1_LAT                LATD3
#define LED1_PORT               RD3
#define LED1_SetHigh()    do { LATD3 = 1; } while(0)
#define LED1_SetLow()   do { LATD3 = 0; } while(0)
#define LED1_Toggle()   do { LATD3 = ~LATD3; } while(0)
#define LED1_GetValue()         PORTDbits.RD3
#define LED1_SetDigitalInput()    do { TRISD3 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISD3 = 0; } while(0)




/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);





#endif // PIN_MANAGER_H
/**
 End of File
*/