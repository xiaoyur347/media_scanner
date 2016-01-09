#ifndef CONSOLE_REPORT_H
#define CONSOLE_REPORT_H

#include "report.h"

class CConsoleReport : public IReport
{
public:
	CConsoleReport();
	~CConsoleReport();
	void Reset();
	void SetName(const std::string &name);
	void Write(const std::string &key, const std::string &value);
	void Flush();
private:
	std::string m_strReport;
};

#endif // CONSOLE_REPORT_H

