#include "ax.h"
#include "mcc_generated_files/mcc.h"

int getAddressSize(int address) {
    switch (address) {
        case P_MODEL_NUMBER:
        case P_CW_ANGLE_LIMIT:
        case P_CCW_ANGLE_LIMIT:
        case P_MAX_TORQUE:
        case P_DOWN_CALIBRATION:
        case P_UP_CALIBRATION:
        case P_GOAL_POSITION:
        case P_GOAL_SPEED:
        case P_TORQUE_LIMIT:
        case P_PRESENT_POSITION:
        case P_PRESENT_SPEED:
        case P_PRESENT_LOAD:
        case P_PUNCH:
            return 2;
        default:
            return 1;
    }
}

void setLedOn(int led) {
    switch (led) {
        case 1:
            LED1_SetHigh();
            break;
        case 2:
            LED2_SetHigh();
            break;
        case 3:
            LED3_SetHigh();
            break;
        case 4:
            LED4_SetHigh();
            break;
        case 5:
            LED5_SetHigh();
            break;
        case 6:
            LED6_SetHigh();
            break;
        case 7:
            LED7_SetHigh();
            break;
        case 8:
            LED8_SetHigh();
            break;
        case 9:
            LED9_SetHigh();
            break;
        case 10:
            LED10_SetHigh();
            break;
    }
}

void setLedOff(int led) {
    switch (led) {
        case 1:
            LED1_SetLow();
            break;
        case 2:
            LED2_SetLow();
            break;
        case 3:
            LED3_SetLow();
            break;
        case 4:
            LED4_SetLow();
            break;
        case 5:
            LED5_SetLow();
            break;
        case 6:
            LED6_SetLow();
            break;
        case 7:
            LED7_SetLow();
            break;
        case 8:
            LED8_SetLow();
            break;
        case 9:
            LED9_SetLow();
            break;
        case 10:
            LED10_SetLow();
            break;
    }

}


// Get the adc value (12bits)
// @param led :  0 - 9
// @returns value : 0 - 4095

int getADC(int adc) {
    return ADC_GetConversion(adc);
}

int pingAX(int id) {
    return 1;
}

int readAXData(int id, int address) {
    return 1;
}

void writeAXData(int id, int address, int data) {

}


int readIndex = 0;
uint8_t currentCommand;
uint8_t parameter1;
uint8_t parameter2;
uint8_t parameter3;
// callback I2C
int nbBytesToSend = 0;
int bytesSent = 0;
uint8_t dataToSend[32];

void handleByteReceived(uint8_t data) {
    if (readIndex == 0) {
        currentCommand = data;
        readIndex++;
    } else if (readIndex == 1) {
        parameter1 = data;
        readIndex = 0;
        if (currentCommand == CMD_SET_LED_ON) {
            setLedOn(parameter1);
        } else if (currentCommand == CMD_SET_LED_OFF) {
            setLedOff(parameter1);
        } else if (currentCommand == CMD_GET_ADC) {
            int value = getADC(parameter1);
            bytesSent = 0;
            nbBytesToSend = 2;
            uint8_t xlow = value & 0xff;
            uint8_t xhigh = (value >> 8);
            dataToSend[0] = xlow;
            dataToSend[1] = xhigh;
        } else if (currentCommand == CMD_PING_AX) {
            // TODO 
           
        } else if (currentCommand == CMD_READ_AX) {
            // TODO
            
            
        } else if (currentCommand == CMD_WRITE_AX) {
            readIndex = 2;
            // allons recevoir encore 1 ou 2 bytes
        } else {
            // On est mal...
        }

    } else if (readIndex == 2) {
        parameter2 = data;
        if (currentCommand == CMD_WRITE_AX) {
            // TODO 
            
            
        } else {
            // On est mal...
        }

    } else if (readIndex == 3) {
        parameter3 = data;
        if (currentCommand == CMD_WRITE_AX) {
            // TODO 

            readIndex = 0;
        } else {
            // On est mal...
        }



    }

}

uint8_t getByteToSend() {
    if (nbBytesToSend == 0) {
        // oups..
        return 0;
    }
    uint8_t d = dataToSend[bytesSent];
    bytesSent++;
    if (bytesSent >= nbBytesToSend) {
        // Too much read!!!!!!
        return 0;
    }
    return d;

}