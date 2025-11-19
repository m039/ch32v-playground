#ifndef _M039_H
#define _M039_H

#if defined(ARDUINO)

#include <Arduino.h>

#define PROGRAM_INFO(name, version)\
Serial.write("program_info:" "{\"name\":\"" name "\",\"version\":\"" version "\"}", 0 );

#elif defined(CH32V003)
#include <ch32fun.h>

#define PROGRAM_INFO(name, version)\
_write( 0, "program_info:" "{\"name\":\"" name "\",\"version\":\"" version "\"}", 0 );

#endif


#endif