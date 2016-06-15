/*
 * Log4a.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: meetyg
 */

#include "Log4a.h"

Log4a::Log4a(Stream& stream, LogLevel level, bool printLevelString): _stream(stream) {
	_level = constrain(level,LogLevelDebug,LogLevelNone);
	_printLevelString = printLevelString;
	_debugStr = F("DEBUG: ");
	_infoStr = F("INFO: ");
	_warningStr = F("WARNING: ");
	_errorStr = F("ERROR: ");


}

Log4a::~Log4a() {
	// TODO Auto-generated destructor stub
}



void Log4a::Error(const char* msg, ...)
{
	if (LogLevelError >= _level)
	{
		if(_printLevelString)
			print(_errorStr, NULL);

		va_list args;
		va_start(args, msg);

		print(msg,args);
	}
}

void Log4a::Error(const __FlashStringHelper* msg, ...)
{
	if (LogLevelError >= _level)
	{
		if(_printLevelString)
			print(_errorStr, NULL);

		va_list args;
		va_start(args, msg);
		print(msg,args);
	}
}

void Log4a::Info(const char* msg, ...)
{
	if (LogLevelInfo >= _level)
	{
		if(_printLevelString)
			print(_infoStr, NULL);

		va_list args;
		va_start(args, msg);
		print(msg,args);
	}
}

void Log4a::Info(const __FlashStringHelper* msg, ...)
{
	if (LogLevelInfo >= _level)
	{
		if(_printLevelString)
			print(_infoStr, NULL);

		va_list args;
		va_start(args, msg);
		print(msg,args);
	}
}

void Log4a::Debug(const char* msg, ...)
{
	if (LogLevelDebug >= _level)
	{
		if(_printLevelString)
			print(_debugStr, NULL);

		va_list args;
		va_start(args, msg);
		print(msg,args);
	}
}

void Log4a::Debug(const __FlashStringHelper* msg, ...)
{
	if (LogLevelDebug >= _level)
	{
		if(_printLevelString)
			print(_debugStr, NULL);

		va_list args;
		va_start(args, msg);
		print(msg,args);
	}
}

void Log4a::Warn(const char* msg, ...)
{
	if (LogLevelWarning >= _level)
	{
		if(_printLevelString)
			print(_warningStr, NULL);

		va_list args;
		va_start(args, msg);
		print(msg,args);
	}
}

void Log4a::Warn(const __FlashStringHelper* msg, ...)
{
	if (LogLevelWarning >= _level)
	{
		if(_printLevelString)
			print(_warningStr, NULL);

		va_list args;
		va_start(args, msg);
		print(msg,args);
	}
}

void Log4a::print(const char* format, va_list args)
{
	    // loop through format string
	    for (; *format != 0; ++format) {
	        if (*format == '%') {
	            ++format;
	            if (*format == '\0') break;
	            if (*format == '%') {
	                _stream.print(*format);
	                continue;
	            }
	            if( *format == 's' ) {
					register char *s = (char *)va_arg( args, int );
					_stream.print(s);
					continue;
				}
	            if( *format == 'd' || *format == 'i') {
					_stream.print(va_arg( args, int ),DEC);
					continue;
				}
	            if( *format == 'f') {
					_stream.print(va_arg( args, double ),2);
					continue;
				}
	            if( *format == 'x' ) {
					_stream.print(va_arg( args, int ),HEX);
					continue;
				}
	            if( *format == 'X' ) {
					_stream.print("0x");
					_stream.print(va_arg( args, int ),HEX);
					continue;
				}
	            if( *format == 'b' ) {
					_stream.print(va_arg( args, int ),BIN);
					continue;
				}
	            if( *format == 'B' ) {
					_stream.print("0b");
					_stream.print(va_arg( args, int ),BIN);
					continue;
				}
	            if( *format == 'l' ) {
					_stream.print(va_arg( args, long ),DEC);
					continue;
				}

	            if( *format == 'c' ) {
					_stream.print(va_arg( args, int ));
					continue;
				}
	            if( *format == 't' ) {
					if (va_arg( args, int ) == 1) {
						_stream.print("T");
					}
					else {
						_stream.print("F");
					}
					continue;
				}
	            if( *format == 'T' ) {
					if (va_arg( args, int ) == 1) {
						_stream.print("true");
					}
					else {
						_stream.print("false");
					}
					continue;
				}

	        }

	       	_stream.print(*format);
	    }

	    if(args != NULL)
			_stream.println();
}

void Log4a::print(const __FlashStringHelper* format, va_list args)
{
	  PGM_P p = reinterpret_cast<PGM_P>(format);
	  char chr;

	  // loop through format string
	  do
	  {
	    chr = (char)pgm_read_byte(p++);

	    if (chr == '%')
	   {
	       // read next:
	        chr = (char)pgm_read_byte(p++);

		    switch (chr)
		    {
		      case '%':
		      {
		 	 _stream.print(chr);
			break;
		      }
		      case 's' :
		      {
		        register char *s = (char *)va_arg( args, int );
		        _stream.print(s);
		        break;
		      }
		      case 'd':
		      case 'i':
		      {
		        _stream.print(va_arg( args, int ),DEC);
		        break;
		      }
		      case 'f' :
		      {
		        _stream.print(va_arg( args, double ),2);
		        break;
		      }
		      case 'x' :
		      {
		        _stream.print(va_arg( args, int ),HEX);
		        break;
		      }
		      case 'X' :
		      {
		        _stream.print("0x");
		        _stream.print(va_arg( args, int ),HEX);
		        break;
		      }
		      case 'b' :
		      {
		        _stream.print(va_arg( args, int ),BIN);
		        break;
		      }
		      case 'B' :
		      {
		        _stream.print("0b");
		        _stream.print(va_arg( args, int ),BIN);
		        break;
		      }
		      case 'l' :
		      {
		        _stream.print(va_arg( args, long ),DEC);
		        break;
		      }
		      case 'c' :
		      {
		        _stream.print(va_arg( args, int ));
		        break;
		      }
		      case 't' :
		      {
		        if (va_arg( args, int ) == 1)
		          _stream.print("T");
		        else
		          _stream.print("F");

		        break;
		      }
		      case 'T' :
		      {
		        if (va_arg( args, int ) == 1)
		          _stream.print("true");
		        else
		          _stream.print("false");

		        break;
		      }
		      default:
		      {
		        _stream.print(chr);
		        break;
		      }
		    }
		}
		else if (chr == '\0') break;
		else
			 _stream.print(chr);
	  } while (chr != NULL);


	  if(args != NULL)
	    _stream.println();
}
