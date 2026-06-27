#include <stdio.h>
#include "../include/status.h"

void printLog(LOG log) {
    char buffer[255];
    char* prefix;
    int r, g, b;

    switch (log.logLevel) {
    case SUCCESS:
        prefix = "[+]";
        r = 0; g = 255; b = 0;
        break;

    case WARNING:
        prefix = "[!]";
        r = 255; g = 165; b = 0;
        break;

    case ERROR:
        prefix = "[!!]";
        r = 255; g = 0; b = 0;
        break;

    default:
        prefix = "[i]";
        r = 200; g = 200; b = 200;
        break;
    }


    snprintf(buffer, sizeof(buffer), "%s %s", prefix, log.msg);
    RGBStyle style = { .newLine = log.newLine, .isBold = log.logStyle.bold, .isItalic = log.logStyle.italic, .isUnderLine = log.logStyle.underLine };
    rgb_print(r, g, b, buffer, &style);
}

// LOG TEMPLATES
void logSuccess(const char* msg) {
    LOGSTYLE logStyle = { .bold = false,.italic = false,.underLine = false };
    LOG log = { .msg = msg,.logStyle = logStyle, .newLine=true,.logLevel=SUCCESS};
    printLog(log);
};
void logWarning(const char* msg) {
    LOGSTYLE logStyle = { .bold = false,.italic = false,.underLine = false };
    LOG log = { .msg = msg,.logStyle = logStyle, .newLine = true,.logLevel = WARNING};
    printLog(log);
};
void logError(const char* msg) {
    LOGSTYLE logStyle = { .bold = false,.italic = false,.underLine = false };
    LOG log = { .msg = msg,.logStyle = logStyle, .newLine = true,.logLevel = ERROR};
    printLog(log);
};

LOGSTYLE create_default_style(void) {
    LOGSTYLE style = { .bold = false, .italic = false, .underLine = false };
    return style;
}

LOG create_default_log(void) {
    LOGSTYLE style = create_default_style();
    LOG log = { .msg = "", .logLevel = SUCCESS, .logStyle = style, .newLine = true };
    return log;
}