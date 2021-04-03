#ifndef _YOG_LOGGER_H_
#define _YOG_LOGGER_H_

#include <plog/Log.h>
#include <plog/Init.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Formatters/CsvFormatter.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>


#define LOG_CV PLOGV_(yog::Logger::consoleLogger)
#define LOG_CD PLOGD_(yog::Logger::consoleLogger)
#define LOG_CI PLOGI_(yog::Logger::consoleLogger)
#define LOG_CW PLOGW_(yog::Logger::consoleLogger)
#define LOG_CE PLOGE_(yog::Logger::consoleLogger)
#define LOG_CF PLOGF_(yog::Logger::consoleLogger)

#define LOG_FV PLOGV_(yog::Logger::fileLogger)
#define LOG_FD PLOGD_(yog::Logger::fileLogger)
#define LOG_FI PLOGI_(yog::Logger::fileLogger)
#define LOG_FW PLOGW_(yog::Logger::fileLogger)
#define LOG_FE PLOGE_(yog::Logger::fileLogger)
#define LOG_FF PLOGF_(yog::Logger::fileLogger)


namespace yog {
	class Logger {
	public:
		enum Severity;
		enum Type;

		static void init();
		static void terminate();

		void setSeverity(Logger::Severity severity, Logger::Type loggerType);

	private:
		static plog::ColorConsoleAppender<plog::TxtFormatter>* consoleAppender;
		static plog::RollingFileAppender<plog::CsvFormatter>* fileAppender;

	public:
		enum Severity {
			fatal = 0,
			error = 1,
			warning = 2,
			info = 3,
			debug = 5,
			verbose = 6
		};
		enum Type {
			consoleLogger = 0,
			fileLogger = 1
		};
	};
}

#endif // !_YOG_LOGGER_H_
