#ifndef S3GE_H_2021_2_19_1594A9696F8241768D731E341BFA3EBA_
#define S3GE_H_2021_2_19_1594A9696F8241768D731E341BFA3EBA_

#include <sstream>
#include <string>

#include <s3ge/export.h>

namespace s3ge {

class S3GE_EXPORT Logger {
public:
  enum Level { LEVEL_TRACE, LEVEL_DEBUG, LEVEL_WARNING, LEVEL_ERROR, LEVEL_FATAL };
  static const char *toString(Level level);
  static void setGlobalLogger(Logger *logger);
  static void setLogLevel(Level level);
  static Logger *get();

public:
  virtual void log(const char *file, int line, const char *func, Level, const std::string &message) = 0;

protected:
  static Level s_logLevel;

protected:
  std::string _name;

private:
  static Logger *s_logger;
};

static inline void log(const char *file, int line, const char *func, Logger::Level level, const std::string &message) {
  Logger::get()->log(file, line, func, level, message);
}

class StdCoutLogger : public Logger {
public:
  StdCoutLogger();
  void log(const char *file, int line, const char *func, Level level, const std::string &message) override;
};

struct LogHelper {
  LogHelper(const char *file, int line, const char *func, Logger::Level level) : file(file), line(line), func(func), level(level) {}
  ~LogHelper() { log(file, line, func, level, ss.str()); }

  template <class T>
  LogHelper &operator<<(const T &v) {
    ss << v;
    return *this;
  }

private:
  std::stringstream ss;

  const char *file;
  int line;
  const char *func;
  Logger::Level level;
};

} // namespace s3ge

#define S3GE_LOG_(x) s3ge::LogHelper(__FILE__, __LINE__, __func__, s3ge::Logger::LEVEL_##x)
#define S3GE_LOG_TRACE S3GE_LOG_(TRACE)
#define S3GE_LOG_DEBUG S3GE_LOG_(DEBUG)
#define S3GE_LOG_WARNING S3GE_LOG_(WARNING)
#define S3GE_LOG_ERROR S3GE_LOG_(ERROR)
#define S3GE_LOG_FATAL S3GE_LOG_(FATAL)

#endif // S3GE_H_2021_2_19_1594A9696F8241768D731E341BFA3EBA_
