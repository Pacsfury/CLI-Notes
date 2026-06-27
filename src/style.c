#include "../include/style.h"
#include <stdio.h>
#include <stdbool.h>

#define RESET "\033[0m"

#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define ITALIC "\033[3m"

void rgb_print(unsigned int r, unsigned int g, unsigned int b,
    const char* msg,
    const RGBStyle* style)
{
    /* Provide a sensible default style when none is supplied. */
    RGBStyle default_style = { .newLine = true, .isBold = false, .isItalic = false, .isUnderLine = false };
    const RGBStyle* s = style ? style : &default_style;

    int bold = s->isBold ? 1 : 0;
    int italic = s->isItalic ? 3 : 0;
    int underline = s->isUnderLine ? 4 : 0;

    /* Use combined SGR parameters to include optional style codes and the 24-bit color. */
    printf("\033[%d;%d;%d;38;2;%u;%u;%um%s\033[0m%s",
        bold, italic, underline,
        r, g, b,
        msg,
        s->newLine ? "\n" : "");
}