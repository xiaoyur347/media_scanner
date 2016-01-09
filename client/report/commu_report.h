#ifndef COMMU_REPORT_H
#define COMMU_REPORT_H

#include "report.h"

class CCommuReport : public IReport
{
public:
	CCommuReport();
	~CCommuReport();
	void Reset();
	void SetName(const std::string &name);
	void Write(const std::string &key, const std::string &value);
	void Flush();
};

#endif // COMMU_REPORT_H

