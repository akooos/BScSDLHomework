#ifndef FILE_LOGGER_COMPONENT_H
#define FILE_LOGGER_COMPONENT_H

#include "LoggerComponent.h"
#include <iostream>
#include <fstream>

class FileLoggerComponent : public LoggerComponent{
private:
	std::string filename;
protected:
	virtual void debug(const std::string &txt, unsigned int severity = 0) {		
		std::ofstream file;
		file.open(filename, std::ofstream::out | std::ofstream::app);
		if (file.is_open()){
			file << "(D) " << txt.c_str() << std::endl;
			file.close();
		}
	}
	virtual void warning(const std::string &txt, unsigned int severity = 0) {
		std::ofstream file;
		file.open(filename, std::ofstream::out | std::ofstream::app);
		if (file.is_open()){
			file << "(W) " << txt.c_str() << std::endl;
			file.close();
		}
	}
	virtual void error(const std::string &txt, unsigned int severity = 0) {
		std::ofstream file;
		file.open(filename, std::ofstream::out | std::ofstream::app);
		if (file.is_open()){
			file << "(E) " << txt.c_str() << std::endl;
			file.close();
		}
	}
	virtual void info(const std::string &txt, unsigned int severity = 0) {
		std::ofstream file;
		file.open(filename, std::ofstream::out | std::ofstream::app);
		if (file.is_open()){
			file << "(I) " << txt.c_str() << std::endl;
			file.close();
		}
	}
public:
	FileLoggerComponent(const std::string &filename) :LoggerComponent(), filename(filename){}
public:
      virtual ~FileLoggerComponent(){}


};
#endif 
