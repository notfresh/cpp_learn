//
// Created by zxzx on 2021/1/12.
//


#include <cstdlib>
#include <ctime>

#include "threadsafe_logger.h"

// 初始化静态变量
std::ofstream Logger::m_error_log_file;
std::ofstream Logger::m_info_log_file;
std::ofstream Logger::m_warn_log_file;

void initLogger(const std::string& info_log_filename,
				const std::string& warn_log_filename,
				const std::string& error_log_filename){
	Logger::m_info_log_file.open(info_log_filename.c_str());
	Logger::m_warn_log_file.open(warn_log_filename.c_str());
	Logger::m_error_log_file.open(error_log_filename.c_str());
}

Logger::~Logger(){
	getStream(m_log_rank) << std::endl;
	if (FATAL == m_log_rank) {
		m_info_log_file.close();
		m_info_log_file.close();
		m_info_log_file.close();
		abort();
	}
}

std::ostream& Logger::start(log_rank_t log_rank,
							const int line,
							const std::string& function) {
	time_t tm;
	time(&tm);
	char time_string[128];
	ctime_r(&tm, time_string);
	return getStream(log_rank) << time_string
							   << "function (" << function << ")"
							   << "line " << line
							   <<std::flush;
}


std::ostream& Logger::getStream(log_rank_t log_rank){
	return (INFO == log_rank) ?
		   (m_info_log_file.is_open() ?m_info_log_file : std::cout) :
		   (WARNING == log_rank ?
			(m_warn_log_file.is_open()? m_warn_log_file : std::cerr) :
			(m_error_log_file.is_open()? m_error_log_file : std::cerr));
}





