#include "Logger.hpp"

Logger::LogLevel Logger::level = Logger::LogLevel::DEBUG;

void Logger::SetLogLevel(Logger::LogLevel l){
	level = l;
}

void Logger::LogMessage(Logger::LogLevel l, const char* messege){
	if( l < level ){
		return;
	}

#define SWITCH_MACRO(s) \
	case LogLevel::s:\
					 std::cout<<#s":\n";\
	break;

	switch(l){
		SWITCH_MACRO(DEBUG)
			SWITCH_MACRO(INFO)
			SWITCH_MACRO(WARN)
			SWITCH_MACRO(ERROR)
	}

#undef SWITCH_MACRO
	std::cout<<messege<<'\n';
}
