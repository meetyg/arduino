#include "Log4aMacroOpt.h"

#define LOG4A_LOG_LEVEL LogLevelDebug

Log4a Log(Serial, LogLevelDebug);
//The setup function is called once at startup of the sketch
void setup()
{
	int a = LOG4A_LOG_LEVEL;
	LOG_DEBUG(Log,"Test %s %s", "me","you");

	Serial.begin(19200);
	Log.Debug("Hello World!");
	Log.Debug(F("F Hello World!"));
	Log.Info("Hello World!");
	Log.Info(F("F Hello World!"));
	Log.Warn("Hello World!");
	Log.Warn(F("F Hello World!"));
	Log.Error("Hello World!");
	Log.Error(F("F Hello World!"));
	// Add your initialization code here
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
}
