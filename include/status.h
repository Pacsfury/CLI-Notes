#pragma once

#include <stdbool.h>
#include "style.h"

typedef enum e_log_level{
	ERROR = 0,
	SUCCESS = 1,
	WARNING = 2
}LOGLEVEL;

typedef struct s_log_style {
	bool bold;
	bool italic;
	bool underLine;

}LOGSTYLE;

typedef struct s_log {
	const char* msg;
	LOGLEVEL logLevel;
	LOGSTYLE logStyle;
	bool newLine;

}LOG;

LOGSTYLE create_default_style(void);
LOG create_default_log(void);

// ===== LOG FUNCTIONS =====
void printLog(LOG log);


// LOG TEMPLATES
void logSuccess(const char* msg);
void logWarning(const char* msg);
void logError(const char* msg);