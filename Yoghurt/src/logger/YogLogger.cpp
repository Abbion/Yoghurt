#include "YogLogger.h"

namespace yog {
	plog::ColorConsoleAppender<plog::TxtFormatter>* Logger::consoleAppender = nullptr;
	plog::RollingFileAppender<plog::CsvFormatter>* Logger::fileAppender = nullptr;

	void Logger::init()
	{
		#ifdef YOG_DEBUG
		consoleAppender = new plog::ColorConsoleAppender<plog::TxtFormatter>();
		fileAppender = new plog::RollingFileAppender<plog::CsvFormatter>("YogLog.csv", 10000, 2);
		plog::init<Logger::consoleLogger>(plog::verbose, consoleAppender);
		plog::init<Logger::fileLogger>(plog::verbose, fileAppender);
		#endif //YOG_DEBUG
	}

	void Logger::terminate()
	{
		if(consoleAppender != nullptr)
			delete consoleAppender;
		if(fileAppender != nullptr)
			delete fileAppender;
	}

	void Logger::setSeverity(Logger::Severity severity, Logger::Type loggerType)
	{
		if(loggerType == Logger::Type::consoleLogger)
			plog::get<yog::Logger::Type::consoleLogger>()->setMaxSeverity((plog::Severity)severity);
		else if (loggerType == Logger::Type::fileLogger)
			plog::get<yog::Logger::Type::fileLogger>()->setMaxSeverity((plog::Severity)severity);
	}
}