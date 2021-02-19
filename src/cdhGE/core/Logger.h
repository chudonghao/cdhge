#ifndef CDHGE_H_2021_2_19_1594A9696F8241768D731E341BFA3EBA_
#define CDHGE_H_2021_2_19_1594A9696F8241768D731E341BFA3EBA_

#include <sstream>
#include <string>

#include <cdhGE/export.h>

namespace cdhGE {

class CDHGE_EXPORT Logger {
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

} // namespace cdhGE

#define CDHGE_LOG_(x) cdhGE::LogHelper(__FILE__, __LINE__, __func__, cdhGE::Logger::LEVEL_##x)
#define CDHGE_LOG_TRACE CDHGE_LOG_(TRACE)
#define CDHGE_LOG_DEBUG CDHGE_LOG_(DEBUG)
#define CDHGE_LOG_WARNING CDHGE_LOG_(WARNING)
#define CDHGE_LOG_ERROR CDHGE_LOG_(ERROR)
#define CDHGE_LOG_FATAL CDHGE_LOG_(FATAL)

#endif // CDHGE_H_2021_2_19_1594A9696F8241768D731E341BFA3EBA_
