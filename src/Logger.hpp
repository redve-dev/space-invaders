#pragma once
#include <iostream>

class Logger{
	public:
		enum class LogLevel{
			DEBUG,
			INFO,
			WARN,
			ERROR
		};
	private:
		static LogLevel level;
	public:
		static void SetLogLevel(LogLevel l);
		static void LogMessage(LogLevel l, const char* messege);
};
