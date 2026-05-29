#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app_logic.h"
#include "user_interface.h"
#include "serial_comm.h"

void runApp() {
    // Initialize serial port, display main menu in a while loop, 
    // and route the user's choice to the functions below.
}

void addInventory() {
    // Prompt UI for new item details, format into ADD string, 
    // send via serial, and print Arduino's ACK response.
}

void deleteInventory() {
    // Prompt UI for ID, format into DEL string, 
    // send via serial, and print Arduino's ACK response.
}

void searchByID() {
    // Prompt UI for ID, call GET_ALL via serial, 
    // parse the returned data, and display only the matching item.
}

void updateStockAndStatus() {
    // Prompt UI for ID, prompt for new quantities, 
    // format into ADD/UPDATE string, and send via serial to overwrite.
}

void displayAllInventory() {
    // Call GET_ALL via serial, parse the incoming CSV data, 
    // and print it using the UI header and formatted rows.
}

void displaySummary() {
    // Call GET_ALL via serial, parse data to calculate 
    // total available/borrowed/broken items, and print the math summary.
}