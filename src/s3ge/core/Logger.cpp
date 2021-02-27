#include "Logger.h"

#include <iostream>

namespace s3ge {

Logger *Logger::s_logger = new StdCoutLogger;
Logger::Level Logger::s_logLevel = Logger::LEVEL_DEBUG;

const char *Logger::toString(Logger::Level level) {
  switch (level) {
  case LEVEL_TRACE:
    return "Trace";
  case LEVEL_DEBUG:
    return "Debug";
  case LEVEL_WARNING:
    return "Warning";
  case LEVEL_ERROR:
    return "Error";
  case LEVEL_FATAL:
    return "Fatal";
  }
  return "Unknown";
}

void Logger::setGlobalLogger(Logger *logger) {
  if (logger) {
    S3GE_LOG_TRACE << "changing logger. new logger name: " << logger->_name;
    delete s_logger;
    s_logger = logger;
  }
}

void Logger::setLogLevel(Logger::Level level) { s_logLevel = level; }

Logger *Logger::get() { return s_logger; }

StdCoutLogger::StdCoutLogger() { _name = "std cout logger"; }

void StdCoutLogger::log(const char *file, int line, const char *func, Logger::Level level, const std::string &message) {
  if (level < s_logLevel) {
    return;
  }
  std::cout << file << ":" << line << "[" << func << "][" << toString(level) << "] " << message << std::endl;
}

} // namespace s3ge
