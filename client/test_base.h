#ifndef TEST_BASE_H
#define TEST_BASE_H

#include <string>

#define RESULT_SUCCESS "success"
#define RESULT_FAIL "fail"

class ITestBase
{
public:
	virtual ~ITestBase() {}
	virtual void Init() = 0;
	virtual void Run(const std::string &strUrl) = 0;
	virtual void UnInit() = 0;
	virtual std::string GetResult() = 0;
};

#endif // TEST_BASE_H
