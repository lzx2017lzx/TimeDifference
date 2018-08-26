#ifndef __TIMEVAL__H
#define __TIMEVAL__H
#include <iostream>
#include<string>
#include <chrono>
#include <unistd.h>
#include<cstdio>
using namespace std;

#define int32 int32_t
#define int64 int64_t
class TimeValTool
{
struct TimeVal
{
	TimeVal()
	{

	}

	int32 m_hour = 0;
	int32 m_minute = 0;
	int32 m_sec = 0;
	int32 m_msec = 0;
};
public:
	int64 currentTimeMillis()
	{
	int64_t timems = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	return timems;
	}	

	void setBeginTime(const int64 & time)
	{
		beginTime = time;
	}

	void setEndTime(const int64 & time)
	{
		endTime = time;
	}

	void setTimeVal()
	{
		valTime = endTime - beginTime;	
		tVal.m_msec = valTime%1000;	
		
		auto totSec = valTime/1000;
		tVal.m_sec = totSec % 60;
		
		auto totMin = totSec / 60;
		tVal.m_minute = totMin % 60;
		
		tVal.m_hour = totMin / 60;
	}

	void printtVal()
	{
	printf("hours:%d, minutes:%d, seconds:%d, msecs:%d\n", tVal.m_hour, tVal.m_minute, tVal.m_sec, tVal.m_msec);
	}	
	
	void printvalTime()
	{
	printf("valTime:%ld\n", valTime);
	}
	
	void reset()
	{
		memset(this, 0, sizeof(*this));
	}
private:
	TimeVal tVal;
	int64 beginTime = 0;
	int64 endTime = 0;
	int64 valTime = 0;
	
};
#endif
