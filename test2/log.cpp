#include "stdafx.h"
#include "../main/Logger.h"

	void CLogger:: Log(const _eLogLevel level, const char* logline, ...)
	{
		va_list argList;
		char cbuffer[1024];
		va_start(argList, logline);
		vsnprintf(cbuffer, sizeof(cbuffer), logline, argList);
		printf("%s\n",cbuffer);
		va_end(argList);
	}

CLogger _Log;


CLogger::_tLogLineStruct::_tLogLineStruct(const _eLogLevel nlevel, const std::string &nlogmessage)
{
}

CLogger::CLogger(void)
{
}


CLogger::~CLogger(void)
{
}

void CLogger::SetOutputFile(const char *OutputFile)
{
}

void CLogger::SetVerboseLevel(_eLogFileVerboseLevel vLevel)
{
}


bool strhasEnding(std::string const &fullString, std::string const &ending)
{
	return 0;
}

void CLogger::LogNoLF(const _eLogLevel level, const char* logline, ...)
{
}

void CLogger::LogSequenceStart()
{
}

void CLogger::LogSequenceEnd(const _eLogLevel level)
{
}

void CLogger::LogSequenceAdd(const char* logline)
{
}

void CLogger::LogSequenceAddNoLF(const char* logline)
{
}

void CLogger::EnableLogTimestamps(const bool bEnableTimestamps)
{
}

std::list<CLogger::_tLogLineStruct> CLogger::GetLog(const _eLogLevel lType)
{
	std::list<_tLogLineStruct> mlist;
	return mlist;
}

void CLogger::SetFilterString(std::string  &pFilter)
{
}
//return true if trace enable
bool CLogger::isTraceEnable()
{
return 0;
}

//return true if the log shall be filtered
//
bool CLogger::TestFilter(char * cbuffer)
{
return 0;
}
void CLogger::setLogVerboseLevel(int LogLevel)
{

}
void CLogger::SetLogPreference (std::string  LogFilter, std::string  LogFileName , std::string  LogLevel )
{
}
void CLogger::GetLogPreference ()
{
}
