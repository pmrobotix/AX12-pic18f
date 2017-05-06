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
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC18F46K80
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

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

// get/set channel_AN0 aliases
#define channel_AN0_TRIS               TRISAbits.TRISA0
#define channel_AN0_LAT                LATAbits.LATA0
#define channel_AN0_PORT               PORTAbits.RA0
#define channel_AN0_ANS                ANCON0bits.ANSEL0
#define channel_AN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_AN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_AN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_AN0_GetValue()           PORTAbits.RA0
#define channel_AN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_AN0_SetAnalogMode()  do { ANCON0bits.ANSEL0 = 1; } while(0)
#define channel_AN0_SetDigitalMode() do { ANCON0bits.ANSEL0 = 0; } while(0)

// get/set channel_AN1 aliases
#define channel_AN1_TRIS               TRISAbits.TRISA1
#define channel_AN1_LAT                LATAbits.LATA1
#define channel_AN1_PORT               PORTAbits.RA1
#define channel_AN1_ANS                ANCON0bits.ANSEL1
#define channel_AN1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_AN1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_AN1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_AN1_GetValue()           PORTAbits.RA1
#define channel_AN1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_AN1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_AN1_SetAnalogMode()  do { ANCON0bits.ANSEL1 = 1; } while(0)
#define channel_AN1_SetDigitalMode() do { ANCON0bits.ANSEL1 = 0; } while(0)

// get/set channel_AN2 aliases
#define channel_AN2_TRIS               TRISAbits.TRISA2
#define channel_AN2_LAT                LATAbits.LATA2
#define channel_AN2_PORT               PORTAbits.RA2
#define channel_AN2_ANS                ANCON0bits.ANSEL2
#define channel_AN2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define channel_AN2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define channel_AN2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define channel_AN2_GetValue()           PORTAbits.RA2
#define channel_AN2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define channel_AN2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define channel_AN2_SetAnalogMode()  do { ANCON0bits.ANSEL2 = 1; } while(0)
#define channel_AN2_SetDigitalMode() do { ANCON0bits.ANSEL2 = 0; } while(0)

// get/set channel_AN3 aliases
#define channel_AN3_TRIS               TRISAbits.TRISA3
#define channel_AN3_LAT                LATAbits.LATA3
#define channel_AN3_PORT               PORTAbits.RA3
#define channel_AN3_ANS                ANCON0bits.ANSEL3
#define channel_AN3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define channel_AN3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define channel_AN3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define channel_AN3_GetValue()           PORTAbits.RA3
#define channel_AN3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define channel_AN3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define channel_AN3_SetAnalogMode()  do { ANCON0bits.ANSEL3 = 1; } while(0)
#define channel_AN3_SetDigitalMode() do { ANCON0bits.ANSEL3 = 0; } while(0)

// get/set channel_AN4 aliases
#define channel_AN4_TRIS               TRISAbits.TRISA5
#define channel_AN4_LAT                LATAbits.LATA5
#define channel_AN4_PORT               PORTAbits.RA5
#define channel_AN4_ANS                ANCON0bits.ANSEL4
#define channel_AN4_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define channel_AN4_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define channel_AN4_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define channel_AN4_GetValue()           PORTAbits.RA5
#define channel_AN4_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define channel_AN4_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define channel_AN4_SetAnalogMode()  do { ANCON0bits.ANSEL4 = 1; } while(0)
#define channel_AN4_SetDigitalMode() do { ANCON0bits.ANSEL4 = 0; } while(0)

// get/set LED8 aliases
#define LED8_TRIS               TRISBbits.TRISB0
#define LED8_LAT                LATBbits.LATB0
#define LED8_PORT               PORTBbits.RB0
#define LED8_WPU                WPUBbits.WPUB0
#define LED8_ANS                ANCON1bits.ANSEL10
#define LED8_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define LED8_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define LED8_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define LED8_GetValue()           PORTBbits.RB0
#define LED8_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define LED8_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define LED8_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define LED8_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define LED8_SetAnalogMode()  do { ANCON1bits.ANSEL10 = 1; } while(0)
#define LED8_SetDigitalMode() do { ANCON1bits.ANSEL10 = 0; } while(0)

// get/set channel_AN8 aliases
#define channel_AN8_TRIS               TRISBbits.TRISB1
#define channel_AN8_LAT                LATBbits.LATB1
#define channel_AN8_PORT               PORTBbits.RB1
#define channel_AN8_WPU                WPUBbits.WPUB1
#define channel_AN8_ANS                ANCON1bits.ANSEL8
#define channel_AN8_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define channel_AN8_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define channel_AN8_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define channel_AN8_GetValue()           PORTBbits.RB1
#define channel_AN8_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define channel_AN8_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define channel_AN8_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define channel_AN8_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define channel_AN8_SetAnalogMode()  do { ANCON1bits.ANSEL8 = 1; } while(0)
#define channel_AN8_SetDigitalMode() do { ANCON1bits.ANSEL8 = 0; } while(0)

// get/set LED9 aliases
#define LED9_TRIS               TRISBbits.TRISB2
#define LED9_LAT                LATBbits.LATB2
#define LED9_PORT               PORTBbits.RB2
#define LED9_WPU                WPUBbits.WPUB2
#define LED9_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define LED9_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define LED9_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define LED9_GetValue()           PORTBbits.RB2
#define LED9_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define LED9_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define LED9_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define LED9_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)

// get/set LED10 aliases
#define LED10_TRIS               TRISBbits.TRISB3
#define LED10_LAT                LATBbits.LATB3
#define LED10_PORT               PORTBbits.RB3
#define LED10_WPU                WPUBbits.WPUB3
#define LED10_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define LED10_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define LED10_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define LED10_GetValue()           PORTBbits.RB3
#define LED10_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define LED10_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define LED10_SetPullup()      do { WPUBbits.WPUB3 = 1; } while(0)
#define LED10_ResetPullup()    do { WPUBbits.WPUB3 = 0; } while(0)

// get/set channel_AN9 aliases
#define channel_AN9_TRIS               TRISBbits.TRISB4
#define channel_AN9_LAT                LATBbits.LATB4
#define channel_AN9_PORT               PORTBbits.RB4
#define channel_AN9_WPU                WPUBbits.WPUB4
#define channel_AN9_ANS                ANCON1bits.ANSEL9
#define channel_AN9_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define channel_AN9_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define channel_AN9_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define channel_AN9_GetValue()           PORTBbits.RB4
#define channel_AN9_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define channel_AN9_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define channel_AN9_SetPullup()      do { WPUBbits.WPUB4 = 1; } while(0)
#define channel_AN9_ResetPullup()    do { WPUBbits.WPUB4 = 0; } while(0)
#define channel_AN9_SetAnalogMode()  do { ANCON1bits.ANSEL9 = 1; } while(0)
#define channel_AN9_SetDigitalMode() do { ANCON1bits.ANSEL9 = 0; } while(0)

// get/set LED7 aliases
#define LED7_TRIS               TRISCbits.TRISC0
#define LED7_LAT                LATCbits.LATC0
#define LED7_PORT               PORTCbits.RC0
#define LED7_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED7_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LED7_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LED7_GetValue()           PORTCbits.RC0
#define LED7_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LED7_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set LED6 aliases
#define LED6_TRIS               TRISCbits.TRISC1
#define LED6_LAT                LATCbits.LATC1
#define LED6_PORT               PORTCbits.RC1
#define LED6_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LED6_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LED6_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LED6_GetValue()           PORTCbits.RC1
#define LED6_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LED6_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set LED5 aliases
#define LED5_TRIS               TRISCbits.TRISC2
#define LED5_LAT                LATCbits.LATC2
#define LED5_PORT               PORTCbits.RC2
#define LED5_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED5_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED5_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED5_GetValue()           PORTCbits.RC2
#define LED5_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()    do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()   do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()   do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()         PORTCbits.RC3
#define RC3_SetDigitalInput()   do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()  do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()    do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()   do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()   do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()         PORTCbits.RC4
#define RC4_SetDigitalInput()   do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()  do { TRISCbits.TRISC4 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()    do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()   do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()   do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()         PORTCbits.RC6
#define RC6_SetDigitalInput()   do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()  do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()    do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()   do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()   do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()         PORTCbits.RC7
#define RC7_SetDigitalInput()   do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()  do { TRISCbits.TRISC7 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS               TRISDbits.TRISD0
#define LED4_LAT                LATDbits.LATD0
#define LED4_PORT               PORTDbits.RD0
#define LED4_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LED4_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LED4_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LED4_GetValue()           PORTDbits.RD0
#define LED4_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS               TRISDbits.TRISD1
#define LED3_LAT                LATDbits.LATD1
#define LED3_PORT               PORTDbits.RD1
#define LED3_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LED3_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LED3_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LED3_GetValue()           PORTDbits.RD1
#define LED3_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS               TRISDbits.TRISD2
#define LED2_LAT                LATDbits.LATD2
#define LED2_PORT               PORTDbits.RD2
#define LED2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LED2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LED2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LED2_GetValue()           PORTDbits.RD2
#define LED2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS               TRISDbits.TRISD3
#define LED1_LAT                LATDbits.LATD3
#define LED1_PORT               PORTDbits.RD3
#define LED1_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define LED1_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define LED1_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define LED1_GetValue()           PORTDbits.RD3
#define LED1_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)

// get/set SET_TX aliases
#define SET_TX_TRIS               TRISDbits.TRISD4
#define SET_TX_LAT                LATDbits.LATD4
#define SET_TX_PORT               PORTDbits.RD4
#define SET_TX_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define SET_TX_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define SET_TX_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define SET_TX_GetValue()           PORTDbits.RD4
#define SET_TX_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define SET_TX_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

// get/set RD6 procedures
#define RD6_SetHigh()    do { LATDbits.LATD6 = 1; } while(0)
#define RD6_SetLow()   do { LATDbits.LATD6 = 0; } while(0)
#define RD6_Toggle()   do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define RD6_GetValue()         PORTDbits.RD6
#define RD6_SetDigitalInput()   do { TRISDbits.TRISD6 = 1; } while(0)
#define RD6_SetDigitalOutput()  do { TRISDbits.TRISD6 = 0; } while(0)

// get/set RD7 procedures
#define RD7_SetHigh()    do { LATDbits.LATD7 = 1; } while(0)
#define RD7_SetLow()   do { LATDbits.LATD7 = 0; } while(0)
#define RD7_Toggle()   do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define RD7_GetValue()         PORTDbits.RD7
#define RD7_SetDigitalInput()   do { TRISDbits.TRISD7 = 1; } while(0)
#define RD7_SetDigitalOutput()  do { TRISDbits.TRISD7 = 0; } while(0)

// get/set channel_AN5 aliases
#define channel_AN5_TRIS               TRISEbits.TRISE0
#define channel_AN5_LAT                LATEbits.LATE0
#define channel_AN5_PORT               PORTEbits.RE0
#define channel_AN5_ANS                ANCON0bits.ANSEL5
#define channel_AN5_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define channel_AN5_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define channel_AN5_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define channel_AN5_GetValue()           PORTEbits.RE0
#define channel_AN5_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define channel_AN5_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define channel_AN5_SetAnalogMode()  do { ANCON0bits.ANSEL5 = 1; } while(0)
#define channel_AN5_SetDigitalMode() do { ANCON0bits.ANSEL5 = 0; } while(0)

// get/set channel_AN6 aliases
#define channel_AN6_TRIS               TRISEbits.TRISE1
#define channel_AN6_LAT                LATEbits.LATE1
#define channel_AN6_PORT               PORTEbits.RE1
#define channel_AN6_ANS                ANCON0bits.ANSEL6
#define channel_AN6_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define channel_AN6_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define channel_AN6_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define channel_AN6_GetValue()           PORTEbits.RE1
#define channel_AN6_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define channel_AN6_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define channel_AN6_SetAnalogMode()  do { ANCON0bits.ANSEL6 = 1; } while(0)
#define channel_AN6_SetDigitalMode() do { ANCON0bits.ANSEL6 = 0; } while(0)

// get/set channel_AN7 aliases
#define channel_AN7_TRIS               TRISEbits.TRISE2
#define channel_AN7_LAT                LATEbits.LATE2
#define channel_AN7_PORT               PORTEbits.RE2
#define channel_AN7_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define channel_AN7_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define channel_AN7_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define channel_AN7_GetValue()           PORTEbits.RE2
#define channel_AN7_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define channel_AN7_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/