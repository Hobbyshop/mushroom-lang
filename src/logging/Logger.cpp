#include "Logger.h"

#include <iostream>

void mushroom::Logger::log(const std::string& message, mushroom::LogLevel level) {
	std::string level_name;

	switch (level) {
		case LogLevel::INFO:
			level_name = "INFO";
			break;

		case LogLevel::WARNING:
			level_name = "WARNING";
			break;

		case LogLevel::ERROR:
			level_name = "ERROR";
			break;
	}

	std::cout << '[' << level_name << "] " << message << '\n';
}
