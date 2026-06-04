#include <stdio.h>
#include <windows.h> // Required for Sleep() on Windows
#include "serial_comm.h"

int main() {
    printf("=== ISOLATED SERIAL MODULE TEST (WINDOWS) ===\n");
    
    initSerialPort("COM7");

    // Wait 2000 milliseconds for the connection to stabilize
    Sleep(2000); 

    printf("\n[TEST] Sending GET_ALL command to Arduino...\n");
    sendSerialData("GET_ALL\n");

    // Give the Arduino 1 second to process and reply
    Sleep(1000); 

    printf("\n[TEST] Listening for response...\n");
    char buffer[4096] = {0};
    receiveSerialData(buffer);
    
    printf("\n--- ARDUINO RESPONSE ---\n");
    printf("%s", buffer);
    printf("------------------------\n");

    closeSerialPort();
    return 0;
}