/*
 * Log4a.h
 *
 *  Created on: Jan 23, 2016
 *      Author: meetyg
 */

#ifndef LOG4A_H_
#define LOG4A_H_

#include <Stream.h>
#include <Arduino.h>

enum LogLevel
{
	LogLevelDebug,
	LogLevelInfo,
	LogLevelWarning,
	LogLevelError,
	LogLevelNone,
};

class Log4a {

private:
    LogLevel _level;
    Stream& _stream;
    bool _printLevelString;

    const __FlashStringHelper* _debugStr; //= F("Debug: ");
    const __FlashStringHelper* _infoStr; //= F("Info: ");
    const __FlashStringHelper* _warningStr;// = F("Warning: ");
    const __FlashStringHelper* _errorStr; //= F("Error: ");
public:
	Log4a(Stream& stream, LogLevel level, bool printLevelString = true);
	virtual ~Log4a();

	void Debug(const char* msg, ...);
	void Debug(const __FlashStringHelper* msg, ...);

	void Info(const char* msg, ...);
	void Info(const __FlashStringHelper* msg, ...);

	void Warn(const char* msg, ...);
	void Warn(const __FlashStringHelper* msg, ...);

	void Error(const char* msg, ...);
	void Error(const __FlashStringHelper* msg, ...);

private:
	void print(const char* format, va_list args);
	void print(const __FlashStringHelper* format, va_list args);

};

#endif /* LOG4A_H_ */
