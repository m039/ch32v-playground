#ifndef _M039_H
#define _M039_H

#ifndef M039_DEBUG
#define M039_DEBUG 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define PROGRAM_INFO_STR(name, version) "program_info:" "{\"name\":\"" name "\",\"version\":\"" version "\"}\n"

int logd( const char* format, ... );

void log_program_info(const char* programInfo);

#ifdef __cplusplus
}
#endif

#if defined(ARDUINO)

#include <Arduino.h>

#if M039_DEBUG

#define PROGRAM_INFO(name, version)\
Serial.write(PROGRAM_INFO_STR(name, version), 0);

#else

#define PROGRAM_INFO(name, version)\
Serial.begin(115200);\
Serial.write(PROGRAM_INFO_STR(name, version), sizeof(PROGRAM_INFO_STR(name, version)));\
Serial.end();

#endif

#elif defined(CH32V003)
#include <ch32fun.h>

#define PROGRAM_INFO(name, version)\
printf(PROGRAM_INFO_STR(name, version));

#endif

#endif