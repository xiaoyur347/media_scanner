#ifndef REPORT_H
#define REPORT_H

#include <string>

class IReport
{
public:
	virtual ~IReport() {}
	virtual void Reset() = 0;
	virtual void SetName(const std::string &name) = 0;
	virtual void Write(const std::string &key, const std::string &value) = 0;
	virtual void Flush() = 0;
	
	static IReport& GetInstance();
};

#endif //REPORT_H

