#include <stdio.h>
#include "../include/style.h"
#include "../include/status.h"
#include "../include/CMDanalizer.h"

int main() {
    logSuccess("Welcome to temporary notes.");
    printf("Write '/help' to receive a list of commands\n>> ");
    char cmd[64] = "Welcome";
    analizeCMD(cmd);
    
    return 0;
}