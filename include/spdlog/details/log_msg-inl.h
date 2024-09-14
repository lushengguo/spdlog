// Copyright(c) 2015-present, Gabi Melman & spdlog contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once

#ifndef SPDLOG_HEADER_ONLY
    #include <spdlog/details/log_msg.h>
#endif

#include <spdlog/details/os.h>

namespace spdlog {
namespace details {

SPDLOG_INLINE log_msg::log_msg(spdlog::log_clock::time_point log_time,
                               spdlog::log_source_location location,
                               string_view_t a_logger_name,
                               spdlog::level::level_enum level,
                               spdlog::string_view_t msg)
    : logger_name(a_logger_name),
      level(level),
      time(log_time)
#ifndef SPDLOG_NO_THREAD_ID
      ,
      thread_id(os::thread_id())
#endif
      ,
      source(location),
      payload(msg) {
}

SPDLOG_INLINE log_msg::log_msg(spdlog::log_source_location location,
                               string_view_t a_logger_name,
                               spdlog::level::level_enum level,
                               spdlog::string_view_t msg)
    : log_msg(os::now(), location, a_logger_name, level, msg) {}

SPDLOG_INLINE log_msg::log_msg(string_view_t a_logger_name,
                               spdlog::level::level_enum level,
                               spdlog::string_view_t msg)
    : log_msg(os::now(), log_source_location{}, a_logger_name, level, msg) {}

}  // namespace details
}  // namespace spdlog
