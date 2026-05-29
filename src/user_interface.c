#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user_interface.h"

void printMainMenu() {
    // Print the welcome banner and the numbered list of 
    // available inventory operations (1-7).
}

void getUserChoice(int* choice) {
    // Print a prompt, capture the integer using scanf, 
    // and safely clear the input buffer.
}

void promptString(const char* promptText, char* inputBuffer, int maxLength) {
    // Print the prompt text, safely capture string using fgets 
    // up to maxLength, and strip the trailing newline character.
}

void promptInt(const char* promptText, int* inputValue) {
    // Print the prompt text, capture the integer using scanf, 
    // and safely flush the leftover newline from the stdin buffer.
}

void printHeader() {
    // Print the formatted table header (e.g., ID | Name | Tersedia | ...) 
    // for use before listing inventory items.
}