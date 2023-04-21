#include <iostream>

#ifndef GLOG_NO_ABBREVIATED_SEVERITIES
#define GLOG_NO_ABBREVIATED_SEVERITIES // 如果不加这个宏定义代码就会报错
#endif
#include <glog/logging.h>


#pragma comment(lib, "glog.lib")


int main(int argc, char* argv[])
{
	
	google::InitGoogleLogging(argv[0]);//使用glog之前必须先初始化库，仅需执行一次，括号内为程序名
 	FLAGS_alsologtostderr = true;//是否将日志输出到文件和stderr
 	FLAGS_colorlogtostderr = true;//是否启用不同颜色显示
//	FLAGS_logbufsecs = 0;
	FLAGS_max_log_size = 10;

	std::string appPath = ".\\log\\";
//	FLAGS_log_dir = ".\\log";
	google::SetLogDestination(google::GLOG_INFO, std::string(appPath + "INFO").c_str());//INFO级别的日志都存放到logs目录下且前缀为INFO_
	google::SetLogDestination(google::GLOG_WARNING, "");//WARNING级别的日志都存放到logs目录下且前缀为WARNING_
	google::SetLogDestination(google::GLOG_ERROR, "");	//ERROR级别的日志都存放到logs目录下且前缀为ERROR_
	google::SetLogDestination(google::GLOG_FATAL, "");	//FATAL级别的日志都存放到logs目录下且前缀为FATAL_



	
	LOG(INFO) << "消息测试！";
	LOG(WARNING) << "警告警告";
	LOG(ERROR) << "报错了怎么办";
	
	std::cout << 11111;

	google::ShutdownGoogleLogging();//当要结束glog时必须关闭库，否则会内存溢出

	return 0;
}