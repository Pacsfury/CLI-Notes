#pragma once

#include <stdio.h>
#include <string.h>

void analizeCMD(const char* cmd) {
    char operation[5];
    snprintf(operation, sizeof(operation), "%.4s", cmd);
}