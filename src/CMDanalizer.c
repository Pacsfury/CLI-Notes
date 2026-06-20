#pragma once

#include <stdio.h>
#include <string.h>

void analizeCMD(const char* cmd) {
    char operation[5];
    snprintf(operation, sizeof(operation), "%.4s", cmd);

    if (operation == "newn") {
        printf("New note");
    } else if (operation == "list") {

    } else if (operation == "open") {

    } else if (operation == "clse") {

    } else if (operation == "supr") {

    }
}