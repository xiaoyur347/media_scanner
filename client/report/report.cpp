#include "report.h"
#include "console_report.h"
#include "file_report.h"
#include "commu_report.h"
#include <stdlib.h>
#include <string.h>

IReport& IReport::GetInstance()
{
	static IReport* pReport = NULL;
	if (pReport == NULL)
	{
		const char *env = getenv("REPORT");
		if (env == NULL)
		{
			static CConsoleReport report;
			pReport = &report;
		}
		else if (strcmp(env, "console") == 0)
		{
			static CConsoleReport report;
			pReport = &report;
		}
		else if (strcmp(env, "file") == 0)
		{
			static CFileReport report;
			pReport = &report;
		}
		else
		{
			static CCommuReport report;
			pReport = &report;
		}
	}

	return *pReport;
}

