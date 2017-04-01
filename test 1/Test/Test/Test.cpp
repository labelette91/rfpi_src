// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Record.h"
#include "../main/SQLHelper.h"
#include "HomeEasy.h"

static TRecord Record;

time_t mytime(time_t * _Time)
{
	return 0 ;
}

void sleep_milliseconds(long i) {};

std::vector<std::vector<std::string> > CSQLHelper::safe_query(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
std::vector<std::vector<std::string> > results;
		return results;
}

std::vector<std::vector<std::string> > CSQLHelper::Query(const char fmt[], ...)
{
	std::vector<std::vector<std::string> > results;
	return results;

}

CSQLHelper::CSQLHelper(void) {};
CSQLHelper::~CSQLHelper(void) {};


unsigned long long CSQLHelper::UpdateValue(const int HardwareID, const char* ID, const unsigned char unit, const unsigned char devType, const unsigned char subType, const unsigned char signallevel, const unsigned char batterylevel, const int nValue, std::string &devname, const bool bUseOnOffAction)
{
	return UpdateValue(HardwareID, ID, unit, devType, subType, signallevel, batterylevel, nValue, "", devname, bUseOnOffAction);
}

unsigned long long CSQLHelper::UpdateValue(const int HardwareID, const char* ID, const unsigned char unit, const unsigned char devType, const unsigned char subType, const unsigned char signallevel, const unsigned char batterylevel, const char* sValue, std::string &devname, const bool bUseOnOffAction)
{
	return UpdateValue(HardwareID, ID, unit, devType, subType, signallevel, batterylevel, 0, sValue, devname, bUseOnOffAction);
}

unsigned long long CSQLHelper::UpdateValue(const int HardwareID, const char* ID, const unsigned char unit, const unsigned char devType, const unsigned char subType, const unsigned char signallevel, const unsigned char batterylevel, const int nValue, const char* sValue, std::string &devname, const bool bUseOnOffAction)
{
	return 0;
}
void StringSplit(std::string str, const std::string &delim, std::vector<std::string> &results)
{
	results.clear();
	size_t cutAt;
	while ((cutAt = str.find_first_of(delim)) != str.npos)
	{
		if (cutAt > 0)
		{
			results.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if (str.length() > 0)
	{
		results.push_back(str);
	}
}

LastValue::LastValue(float pdelta)
{
	Delta = pdelta;
}

unsigned char Get_Humidity_Level(const unsigned char hlevel)
{
	return 0;
}
CSQLHelper m_sql;

int main()
{
/*	Record.put(100);
	Record.put(200);
	Record.put(300);
	printf("%s", Record.ToString().c_str());
	printf("%s", Record.ToString().c_str());
	Record.clear();
	printf("%s", Record.ToString().c_str());
	*/
	HomeEasy * HE= new HomeEasy(1);
	
	
	
	return 0;



}

