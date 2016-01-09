#ifndef TEST_FACTORY_H
#define TEST_FACTORY_H

#include "test_base.h"
#include <string>
#include <vector>
#include <map>

class CTestFactory
{
public:
	static CTestFactory &GetInstance()
	{
		static CTestFactory _instance;
		return _instance;
	}
	// take ownership
	bool RegisterTest(const std::string &strName, ITestBase *pTest);
	void Reset();
	bool AddTest(const std::string &strName);
	
	void RunTest(const std::string &strUrl);
	std::map<std::string, std::string> GetResult();
private:
	CTestFactory();
	~CTestFactory();
	std::string FindTestName(ITestBase *pTest);
	
	std::map<std::string, ITestBase *> m_mapAllTest;
	std::vector<ITestBase *> m_vecRunTest;
};

#endif // TEST_FACTORY_H
