// a mock file to at least make the program runs
#include <stdio.h>
#include <string.h>
#include "mock_serial_comm.h"

void initSerialPort(const char* portName) {
    printf("\n[SYSTEM] Successfully faked connection to %s\n", portName);
}

void sendSerialData(const char* dataStr) {
    printf("[SYSTEM] Faked sending to Arduino: %s\n", dataStr);
}

void receiveSerialData(char* buffer) {
    // For now, it just fakes a successful acknowledgement
    strcpy(buffer, "ACK_ADD"); 
    printf("[SYSTEM] Faked receiving from Arduino: %s\n", buffer);
}

void closeSerialPort() {
    printf("[SYSTEM] Fake connection closed.\n");
}