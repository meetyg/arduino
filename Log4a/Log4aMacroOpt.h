/*
 * Log4aMacroOpt.h
 *
 *  Created on: Feb 5, 2016
 *      Author: amit
 */

#ifndef LOG4AMACROOPT_H_
#define LOG4AMACROOPT_H_

#include "Log4a.h"

#ifndef LOG4A_LOG_LEVEL
	#define LOG4A_LOG_LEVEL LogLevelNone
#endif

#define LOG_DEBUG(LogInstance,StringFmt,...) LogInstance.Debug(StringFmt,__VA_ARGS__)
#define LOG_WARN(LogInstance,StringFmt,...) LogInstance.Warn(StringFmt,__VA_ARGS__)
#define LOG_INFO(LogInstance,StringFmt,...) LogInstance.Info(StringFmt,__VA_ARGS__)
#define LOG_ERROR(LogInstance,StringFmt,...) LogInstance.Error(StringFmt,__VA_ARGS__)

#endif /* LOG4AMACROOPT_H_ */
