#ifndef FILE_REPORT_H
#define FILE_REPORT_H

#include "report.h"

class CFileReport : public IReport
{
public:
	CFileReport();
	~CFileReport();
	void SetOutput(const std::string &output);
	void Reset();
	void SetName(const std::string &name);
	void Write(const std::string &key, const std::string &value);
	void Flush();

private:
	std::string m_strOutput;
	std::string m_strReport;
};

#endif // FILE_REPORT_H
