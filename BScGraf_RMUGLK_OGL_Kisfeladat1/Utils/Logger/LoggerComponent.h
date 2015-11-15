#ifndef LOGGER_COMPONENT_H
#define LOGGER_COMPONENT_H

#include <string>

class Logger;

class LoggerComponent{
	friend class Logger;	
protected:		
	virtual void debug(const std::string &txt , unsigned int severity = 0 ) = 0;
	virtual void warning(const std::string &txt , unsigned int severity = 0) = 0;
	virtual void error(const std::string &txt, unsigned int severity = 0) = 0;
	virtual void info(const std::string &txt, unsigned int severity = 0) = 0;
public:
      virtual ~LoggerComponent(){};
};

#endif
