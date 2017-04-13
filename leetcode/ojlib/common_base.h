#ifndef COMMON_BASE_H_
#define COMMON_BASE_H_

#define _NAMESPACE_COMMONLIB_START namespace commonlib {
#define _NAMESPACE_COMMONLIB_END }

#define LOG_MSG(type, format, ...) \
        logger_t::get_logger().log(type, "[%s:%d] [%x][%x] " format, __FILE__, __LINE__, (unsigned int)getpid(), (unsigned long)pthread_self(), ##__VA_ARGS__)

#define LOG_DEBUG(format,...) LOG_MSG(LOG_DEBUG, format, ##__VA_ARGS__)
#define LOG_INFO(format,...) LOG_MSG(LOG_INFO, format, ##__VA_ARGS__)
#define LOG_WARN(format,...) LOG_MSG(LOG_WARN, format, ##__VA_ARGS__)
#define LOG_ERROR(format,...) LOG_MSG(LOG_ERROR, format, ##__VA_ARGS__)

#endif
