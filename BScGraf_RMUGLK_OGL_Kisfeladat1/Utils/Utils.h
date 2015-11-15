#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <ctime>
#include "Logger/Logger.h"
#include "Logger/StdErrLoggerComponent.h"
#include "Logger/FileLoggerComponent.h"

#ifdef _MSC_VER
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#endif

#ifndef APP_NAME
#define APP_NAME
#endif


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
( std::ostringstream() << std::dec << x ) ).str()

inline static std::string get_curtime_str(){
	time_t t = time(0);
	std::ostringstream ostream;
	struct tm * now = localtime(&t); //_CRT_SECURE_NO_WARNINGS definiálása szükséges
	ostream << (now->tm_year + 1900) <<  "_" << (now->tm_mon + 1) << "_" << now->tm_mday;	
	return ostream.str();
}



#define SETUP_DEFAULT_LOGGER2(s) Logger* logger = Logger::instance(); \
									 logger->addLoggerComponent((new StdErrLoggerComponent())); \
									 logger->addLoggerComponent((new FileLoggerComponent(s + get_curtime_str() + ".log")));

#define SETUP_DEFAULT_LOGGER Logger* logger = Logger::instance(); \
									 logger->addLoggerComponent((new StdErrLoggerComponent())); \
									 logger->addLoggerComponent((new FileLoggerComponent( std::string(APP_NAME) + get_curtime_str() + ".log")));
inline static std::string build_date(){
	return SSTR(__TIMESTAMP__);
}

#if defined(_DEBUG) || defined(DEBUG)
#ifndef PRINT_DEBUG_LOG
#define PRINT_DEBUG_LOG
#endif
#define ITT(s) Logger::instance()->debug( (__FILE__ + std::string(":") + SSTR(__LINE__) + "/r/n" + s) );
#else
#define ITT(s)
#endif


#endif
