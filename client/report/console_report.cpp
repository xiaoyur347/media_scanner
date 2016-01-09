#include "console_report.h"
#include <stdio.h>

CConsoleReport::CConsoleReport()
{
}

CConsoleReport::~CConsoleReport()	
{
}

void CConsoleReport::Reset()
{
	m_strReport.clear();
}

void CConsoleReport::SetName(const std::string &name)
{
	m_strReport.append("######");
	m_strReport.append(name);
}

void CConsoleReport::Write(const std::string &key, const std::string &value)
{
	m_strReport.append(",");
	m_strReport.append(key);
	m_strReport.append(",");
	m_strReport.append(value);
}

void CConsoleReport::Flush()
{
	m_strReport.append("\n");

	printf("%s\n", m_strReport.c_str());
}

