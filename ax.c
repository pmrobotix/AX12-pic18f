#include "ax.h"
#include "mcc_generated_files/mcc.h"



// PINGNo action. Used for obtaining a Status Packet (0 parameter)
#define AX_CMD_PING   0x01
// Reading values in the Control Table (2 parameters)
#define AX_CMD_READ_DATA   0x02 
// Writing values to the Control Table (2+ parameters)
#define AX_CMD_WRITE_DATA  0x03

void delay_ms(int ms) {
    if (ms < 10) {
        __delay_ms(10);
    } else {
        int n = ms / 10;
        for (int i = 0; i < n; i++) {
            __delay_ms(10);
        }
    }
}

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
// @param adc :  0 - 9
// @returns value : 0 - 4095

int getADC(int adc) {
    return ADC_GetConversion(adc);
}

/*
 * buffer : trame à envoyer (sans checksum)
 * packetSize : taille de la trame à envoyer (sans checksum)
 * result : parametres à lire
 * parametersToRead : nombre de parametres à lire
 * 
 * retourne 0 si pas d'erreur
 * 251 si on ne trouve pas le premier octet du header à FF
 * 252 si le deuxieme octet du header n'est pas FF
 * 253 si le CRC est mauvais
 * 
 */
uint8_t sendAX(uint8_t* buffer, int packetSize, uint8_t* result, int parametersToRead) {
    
    // On desactive la lecture asynchrone du port série pour ne pas recevoir de "parasites"
    // SPEN : Serial Port Enable
    // CREN : Continous Read Enable
    
    RCSTA1bits.SPEN = 0;
    RCSTA1bits.SPEN = 1;
    RCSTA1bits.CREN= 0;
    
    // Envoi de la trame
    
    uint8_t checksum = 0;
    SET_TX_SetHigh();
     __delay_us(10);
    for (int i = 2; i < packetSize; i++) {
        checksum += buffer[i];
    }
    checksum = ~checksum;
    // Write to UART

    for (int i = 0; i < packetSize; i++) {
        EUSART1_Write(buffer[i]);
    }
    EUSART1_Write(checksum);

    int stop = 6 + parametersToRead;
    // fill buffer 
    for (int i = 0; i < stop; i++) {
        result[i] = 0X00;
    }
    /*
        int param0 = result[0];
        int param1 = result[1];
        int param2 = result[2];
        int param3 = result[3];
        int param4 = result[4];
        int param5 = result[5];
        int param6 = result[6];
     */
    
    // Reception
    
    __delay_us(10);
    SET_TX_SetLow();
   
     // On active le "continous read"
    RCSTA1bits.SPEN = 0;
    RCSTA1bits.SPEN = 1;
    RCSTA1bits.CREN= 1;
    
    // L' AX12 doit repondre apres les 10us, 50us par exemple
    
    // read until 0xFF
    int count = 0;
    int header_found=0;
    int r0 = EUSART1_Read();
    if(r0==0xFF){
        header_found=1;
    } else {
        while (r0 != 0xFF) {
            r0 = EUSART1_Read();
           count++;
           //nb d'essai pour sortir de la boucle
           if (count > 5) {
               break;
          }
        }
    }
    if(header_found==0){
        // On a pas le début de la réponse du l'AX (FF)
        return 251;
    }
    
    result[0] = r0;
    
    for (int i = 1; i < stop; i++) {
        result[i] = EUSART1_Read();
        if(result[1]!=0xFF){
            return 250;
        }
    }

    int param0 = result[0];
    int param1 = result[1];
    int param2 = result[2];
    int param3 = result[3];
    int param4 = result[4];
    int param5 = result[5];
    int param6 = result[6];

    //verif CHECKSUM !!
    uint8_t checksumResult = 0;
    for (int i = 2; i < stop - 1; i++) {
        checksumResult += result[i];
    }
    checksumResult = ~checksumResult;
   

    {// Wait to stabilize DATA [DO NOT REMOVE] 
        SET_TX_SetHigh();
        __delay_us(10);
    }
    if (checksumResult != result[stop - 1]) {
       // TODO verifier le calcul avec le port serie :  
        return 253;
    }
    return result[4]; //on retourne l'erreur du paquet

}

int pingAX(int id) {
    uint8_t packet[20];
    uint8_t result[20];
    packet[0] = 0xFF;
    packet[1] = 0xFF;
    packet[2] = id;
    int nbParameters = 0;
    int length = nbParameters + 2;
    packet[3] = length;
    int instruction = AX_CMD_PING;
    packet[4] = instruction;

    // Send to AX
    int error = sendAX(packet, 5, result, 0);
    if(error!=0){
        // pas de reponse, on retry
        error = sendAX(packet, 5, result, 0);  
    } 
    if(error!=0){
        // pas de reponse, on retry
        error = sendAX(packet, 5, result, 0);  
    }
    return error;
}

int readAXData(int id, int address, int* err) {
    int size = getAddressSize(address);

    uint8_t packet[20];
    uint8_t result[20];
    packet[0] = 0xFF;
    packet[1] = 0xFF;
    packet[2] = id;
    int nbParameters = 2;
    int length = nbParameters + 2;
    packet[3] = length;
    int instruction = AX_CMD_READ_DATA;
    packet[4] = instruction;
    packet[5] = address;
    packet[6] = size;
   
    // Send to AX
    int error = sendAX(packet, 7, result, size);
    if(error!=0){
        // pas de reponse, on retry
        error = sendAX(packet, 7, result, size);    
    }
     if(error!=0){
        // pas de reponse, on retry
        error = sendAX(packet, 7, result, size);    
    }
    *err=error;
    
    if (size == 1) {
        // 1
        return result[5];
    } else {
        // 2
        return result[5] + result[6]*256;
    }
}

int writeAXData(int id, int address, int data) {
    int size = getAddressSize(address);

    uint8_t packet[20];
    uint8_t result[20];
    packet[0] = 0xFF;
    packet[1] = 0xFF;
    packet[2] = id;
    int length = size + 3;
    packet[3] = length;
    int instruction = AX_CMD_WRITE_DATA;
    packet[4] = instruction;
    packet[5] = address;
    if (size == 1) {
        packet[6] = data;
    } else {
        packet[6] = data & 0xff;
        packet[7] = (data >> 8);
    }

    // Send to AX
    int error = sendAX(packet, 6 + size, result, 0);
    if(error!=0){
        // pas de reponse, on retry
        error = sendAX(packet, 6 + size, result, 0);   
    }
    if(error!=0){
        // pas de reponse, on retry
        error = sendAX(packet, 6 + size, result, 0);   
    }
    return error;
}


volatile int readIndex = 0;
volatile uint8_t currentCommand = -1;
volatile uint8_t parameter1 = 0;
volatile uint8_t parameter2 = 0;
volatile uint8_t parameter3 = 0;
volatile uint8_t parameter4 = 0;
volatile uint8_t parameter5 = 0;
volatile uint8_t parameter6 = 0;
// callback I2C
volatile int nbBytesToSend = 0;
volatile int bytesSent = 0;
volatile uint8_t dataToSend[32];

void handleByteReceived(uint8_t data) {
    //  printf("handleByteReceived readIndex:%d -> %d\r\n", readIndex, data);
    if (readIndex == 0) {
        currentCommand = data;
        readIndex++;
        // clear with 0
        for (int i = 0; i < 32; i++) {
            dataToSend[i] = 66;
        }
    } else if (readIndex == 1) {
        parameter1 = data;
        readIndex++;
        if (currentCommand == CMD_SET_LED_ON) {
            setLedOn(parameter1);
            readIndex = 0;
        } else if (currentCommand == CMD_SET_LED_OFF) {
            setLedOff(parameter1);
            readIndex = 0;
        }

    } else if (readIndex == 2) {
        parameter2 = data;
        readIndex++;
    } else if (readIndex == 3) {
        parameter3 = data;
        readIndex++;
    } else if (readIndex == 4) {
        parameter4 = data;
        readIndex++;
    } else if (readIndex == 5) {
        parameter5 = data;
        readIndex++;
    } else if (readIndex == 6) {
        parameter6 = data;
        readIndex++;
    } else {
        readIndex++;
    }

}
// Le read côté master est bloquant
// Un read (1byte) côté master, appel 2 fois getByteToSend(), et retourne la premiere valeur

void clearState() {
    bytesSent = 0;
    currentCommand = -1;
    parameter1 = 0;
    parameter2 = 0;
    parameter3 = 0;
    parameter4 = 0;
    parameter5 = 0;
    parameter6 = 0;
    readIndex = 0;
}

uint8_t getByteToSend(uint8_t i2c_data_received) {
    //  printf("getByteToSend bytesSent:%d data_received:%d \r\n",bytesSent,i2c_data_received);

    if (currentCommand == CMD_PING_AX) {
        int error = pingAX(parameter1);
        nbBytesToSend = 1;
        dataToSend[0] = error;
        clearState();
    } else if (currentCommand == CMD_READ_AX) {
        //   printf("read AX %d %d\r\n",parameter1, parameter2);
        int error=0;
        int value = readAXData(parameter1, parameter2, &error);
        nbBytesToSend = 3;
        uint8_t xlow = value & 0xff;
        uint8_t xhigh = (value >> 8);
        dataToSend[0] = xlow;
        dataToSend[1] = xhigh;
        dataToSend[2] = error;
        clearState();
    } else if (currentCommand == CMD_WRITE_AX) {
        int error = writeAXData(parameter1, parameter2, parameter3 + (parameter4 << 8));
        nbBytesToSend = 1;
        dataToSend[0] = error;
        clearState();
    } else if (currentCommand == CMD_GET_ADC) {
        uint16_t r = ADC_GetConversion(parameter1) / 16;
        //filtre
        if (r == 4095 || r == 4094)
            r = 0;
        adc_values[parameter1] = r;
        //        printf("ADC %d : %ld\r\n", parameter1, adc_values[parameter1]);
        int value = adc_values[parameter1];
        nbBytesToSend = 2;
        uint8_t xlow = value & 0xff;
        uint8_t xhigh = (value >> 8);
        dataToSend[0] = xlow;
        dataToSend[1] = xhigh;
        clearState();
    }
    if (nbBytesToSend == 0) {
        // oups..
        clearState();
        return 0;
    }
    uint8_t d = dataToSend[bytesSent];
    bytesSent++;

    if (bytesSent > nbBytesToSend) {
        // Too much read!!!!!!
        clearState();
        return 111;
    }

    return d;
}