#ifndef STDERR_LOGGER_COMPONENT_H
#define STDERR_LOGGER_COMPONENT_H

#include "LoggerComponent.h"
#include <iostream>

class StdErrLoggerComponent : public LoggerComponent{

protected:
	virtual void debug(const std::string &txt, unsigned int severity = 0) {
		std::cout << "(D) " << txt.c_str() << std::endl;
	}
	virtual void warning(const std::string &txt, unsigned int severity = 0) {
		std::cerr << "(W) " << txt.c_str() << std::endl;
	}
	virtual void error(const std::string &txt, unsigned int severity = 0) {
		std::cerr << "(E) " << txt.c_str() << std::endl;
	}
	virtual void info(const std::string &txt, unsigned int severity = 0) {
		std::cerr << "(I) " << txt.c_str() << std::endl;
	}
public:
      virtual ~StdErrLoggerComponent(){}

};

#endif
