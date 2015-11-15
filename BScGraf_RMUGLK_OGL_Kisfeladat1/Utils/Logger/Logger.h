#ifndef LOGGER_H
#define LOGGER_H

#include <sstream>
#include <string>
#include <vector>

#include "../../Templates/Singleton.h"
#include "LoggerComponent.h"

typedef std::vector <LoggerComponent*> LoggerComponents;

class Logger: public Singleton<Logger>
{	
	LoggerComponents comps;
protected:
	~Logger(){
		while ( !comps.empty() ){
			LoggerComponent *comp = comps.back();
			comps.pop_back();
			delete comp;
		}
	}
public:
	void addLoggerComponent(LoggerComponent *comp){		
		comps.push_back(comp);
	}
	void debug(const std::string &txt, unsigned int severity = 0){
#ifdef PRINT_DEBUG_LOG
		for( LoggerComponents::iterator it = comps.begin(); it != comps.end() ;++it){
			(*it)->debug(txt,severity);
		}
#endif
	}
	void warning(const std::string &txt, unsigned int severity = 0){
		for (LoggerComponents::iterator it = comps.begin(); it != comps.end(); ++it){
			(*it)->warning(txt, severity);
		}
	}
	void error(const std::string &txt, unsigned int severity = 0){
		for (LoggerComponents::iterator it = comps.begin(); it != comps.end(); ++it){
			(*it)->error(txt, severity);
		}
	}
	void info(const std::string &txt, unsigned int severity = 0){
		for (LoggerComponents::iterator it = comps.begin(); it != comps.end(); ++it){
			(*it)->info(txt, severity);
		}
	}
};

#define Log Logger::instance()

#endif
