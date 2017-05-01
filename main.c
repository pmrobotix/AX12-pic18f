/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.16
        Device            :  PIC18F46K80
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#include "mcc_generated_files/mcc.h"
#include "ax.h"

/*
                         Main application
 */
void main(void) {

    for (int adc = 0; adc < 10; adc++) {
        adc_values[adc] = 0;
    }

    // Initialize the device
    SYSTEM_Initialize();
    LED1_SetHigh();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    LED2_SetHigh();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    //  LED3_SetHigh();
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    printf("PM Robotix\r\n");
    printf("Init completed\r\n");

    int delay = 10;
    LED3_SetHigh();
    LED4_SetHigh();
    for (int i = 0; i < 2; i++) {
        // Add your application code
        LED1_SetHigh();
        delay_ms(delay);
        LED1_SetLow();
        LED2_SetHigh();
        delay_ms(delay);
        LED2_SetLow();
        LED3_SetHigh();
        delay_ms(delay);
        LED3_SetLow();
        LED4_SetHigh();
        delay_ms(delay);
        LED4_SetLow();
        LED5_SetHigh();
        delay_ms(delay);
        LED5_SetLow();
        LED6_SetHigh();
        delay_ms(delay);
        LED6_SetLow();
        LED7_SetHigh();
        delay_ms(delay);
        LED7_SetLow();
        LED8_SetHigh();
        delay_ms(delay);
        LED8_SetLow();
        LED9_SetHigh();
        delay_ms(delay);
        LED9_SetLow();
        LED10_SetHigh();
        delay_ms(delay);
        LED10_SetLow();
        delay_ms(delay);

    }


    SET_TX_SetLow();
    while (1) {
        LED10_SetHigh();
        if(false){
        for (int i = 0; i < 1; i++) {
            // read all ADC
            printf("Reading all ADC\r\n");
            for (int adc = 0; adc < 10; adc++) {
                adc_values[adc] = ADC_GetConversion(adc) / 16;
                printf("ADC %d : %ld\r\n", adc, adc_values[adc]);
            }
            delay_ms(50);
        }}
        delay_ms(500);
        LED10_SetLow();
        delay_ms(500);
    }



}
/**
 End of File
 */