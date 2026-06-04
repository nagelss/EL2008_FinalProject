#include <stdio.h>
#include <unistd.h>
#include "serial_comm.h"

int main() {
    printf("=== ISOLATED SERIAL MODULE TEST ===\n");
    
    // Connect to the specific macOS port (make sure always check at every trial of connection)
    initSerialPort("/dev/cu.usbmodem1301");

    // Wait a moment for the connection to stabilize
    sleep(2); 

    printf("\n[TEST] Sending GET_ALL command to Arduino...\n");
    sendSerialData("GET_ALL\n");

    // printf("\n[TEST] Sending DEL,10 command to Arduino...\n");
    // sendSerialData("DEL,10\n");

    // printf("\n[TEST] Sending ADD,50,RASPI,0,15,8,3,1,AMR command to Arduino...\n");
    // sendSerialData("ADD,50,RASPI,0,15,8,3,1,AMR\n");

    // Give the Arduino time to process and reply
    sleep(1); 

    printf("\n[TEST] Listening for response...\n");
    char buffer[4096] = {0};
    receiveSerialData(buffer);
    
    printf("\n--- ARDUINO RESPONSE ---\n");
    printf("%s", buffer);
    printf("------------------------\n");

    closeSerialPort();
    return 0;
}