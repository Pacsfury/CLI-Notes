#pragma once

#include <stdbool.h>

// ===== COLORS =====
#define RESET   "\033[0m"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

#define BOLD    "\033[1m"
#define DIM     "\033[2m"

// ===== RGB FUNCTIONS (styling optional via style struct) =====

typedef struct {
    bool newLine;     // whether to append a newline after the message
    bool isBold;      // bold text
    bool isItalic;    // italic text
    bool isUnderLine; // underline text
} RGBStyle;

// rgb_print prints the message using a 24-bit RGB foreground color.
// The style parameter is optional: if NULL, sensible defaults are used
// (newLine = true, all style flags = false).
void rgb_print(unsigned int r, unsigned int g, unsigned int b,
    const char* msg,
    const RGBStyle* style);
