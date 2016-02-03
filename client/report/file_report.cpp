#include "file_report.h"
#include <fstream>

CFileReport::CFileReport()
{
	m_strOutput = "1.txt";
}

CFileReport::~CFileReport()	
{
}

void CFileReport::SetOutput(const std::string &output)
{
	m_strOutput = output;
}

void CFileReport::Reset()
{
	m_strReport.clear();
}

void CFileReport::SetName(const std::string &name)
{
	m_strReport.append(name);
}

void CFileReport::Write(const std::string &key, const std::string &value)
{
	m_strReport.append(",");
	m_strReport.append(key);
	m_strReport.append(",");
	m_strReport.append(value);
}

void CFileReport::Flush()
{
	m_strReport.append("\r\n");

	std::ofstream fout(m_strOutput.c_str(), std::ios::app);
	fout << m_strReport;
	fout.close();
}

