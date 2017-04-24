/**
  MSSP Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    i2c.c

  @Summary
    This is the generated header file for the MSSP driver using 
    MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for MSSP.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.16
        Device            :  PIC18F46K80
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB 	          :  MPLAB X 3.20
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

#include "i2c.h"
#include "../ax.h"

#define I2C_SLAVE_ADDRESS 0x08 
#define I2C_SLAVE_MASK    0x7F

typedef enum {
    SLAVE_NORMAL_DATA,
    SLAVE_DATA_ADDRESS,
} SLAVE_WRITE_DATA_TYPE;

/**
 Section: Global Variables
 */

volatile uint8_t I2C_slaveWriteData = 0x55;

/**
 Section: Local Functions
 */
void I2C_StatusCallback(I2C_SLAVE_DRIVER_STATUS i2c_bus_state);

/**
  Prototype:        void I2C_Initialize(void)
  Input:            none
  Output:           none
  Description:      I2C_Initialize is an
                    initialization routine that takes inputs from the GUI.
  Comment:          
  Usage:            I2C_Initialize();

 */
void I2C_Initialize(void) {
    // initialize the hardware
    // R_nW write_noTX; P stopbit_notdetected; S startbit_notdetected; BF RCinprocess_TXcomplete; SMP High Speed; UA dontupdate; CKE disabled; D_nA lastbyte_address; 
    SSPSTAT = 0x00;
    // SSPEN enabled; WCOL no_collision; CKP enabled; SSPM 7 Bit; SSPOV no_overflow; 
    SSPCON1 = 0x3E;
    // ACKEN disabled; GCEN disabled; PEN disabled; ACKDT acknowledge; RSEN disabled; RCEN disabled; ACKSTAT received; SEN enabled; 
    SSPCON2 = 0x01;
    // 
    SSPADD = (I2C_SLAVE_MASK << 1); // adjust UI mask for R/nW bit            
    // SSPADD 8; 
    SSPADD = (I2C_SLAVE_ADDRESS << 1); // adjust UI address for R/nW bit

    // clear the slave interrupt flag
    PIR1bits.SSPIF = 0;
    // enable the master interrupt
    PIE1bits.SSPIE = 1;

}

void I2C_ISR(void) {



    // NOTE: The slave driver will always acknowledge
    //       any address match.
    if (SSPSTATbits.BF == 0) {
        return;
    }
    PIR1bits.SSPIF = 0; // clear the slave interrupt flag
    uint8_t i2c_data_received = SSPBUF; // read SSPBUF to clear BF
    if (1 == SSPSTATbits.R_nW) {
        if ((1 == SSPSTATbits.D_nA) && (1 == PORTCbits.RC4)) {
            // callback routine can perform any post-read processing
            I2C_StatusCallback(I2C_SLAVE_READ_COMPLETED);
        } else {
            uint8_t i2c_data_tosend = getByteToSend(i2c_data_received);
            // envoi data au master
            SSPBUF = i2c_data_tosend;
        }
    } else if (1 == SSPSTATbits.D_nA) {
        // R_nW =0  D_nA=1
        handleByteReceived(i2c_data_received);

    }

    SSPCON1bits.CKP = 1; // release SCL

} // end I2C_ISR()

