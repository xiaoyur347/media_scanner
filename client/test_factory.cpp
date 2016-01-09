#include "test_factory.h"

CTestFactory::CTestFactory()
{
	
}

CTestFactory::~CTestFactory()
{
	for (auto it = m_mapAllTest.begin(); 
		it != m_mapAllTest.end();
		it++)
	{
		delete it->second;
	}
}

std::string CTestFactory::FindTestName(ITestBase *pTest)
{
	for (auto it = m_mapAllTest.begin(); 
		it != m_mapAllTest.end();
		it++)
	{
		if (it->second == pTest)
		{
			return it->first;
		}
	}
	return std::string();
}

bool CTestFactory::RegisterTest(const std::string &strName, ITestBase *pTest)
{
	if (strName.empty() || pTest == NULL)
	{
		return false;
	}
	m_mapAllTest[strName] = pTest;
	return true;
}

void CTestFactory::Reset()
{
	m_vecRunTest.clear();
}

bool CTestFactory::AddTest(const std::string &strName)
{
	auto it = m_mapAllTest.find(strName);
	if (it == m_mapAllTest.end())
	{
		return false;
	}
	m_vecRunTest.push_back(it->second);
	return true;
}

void CTestFactory::RunTest(const std::string &strUrl)
{
	for (auto it = m_vecRunTest.begin(); 
		it != m_vecRunTest.end();
		it++)
	{
		(*it)->Init();
	}
	for (auto it = m_vecRunTest.begin(); 
		it != m_vecRunTest.end();
		it++)
	{
		(*it)->Run(strUrl);
	}
	for (auto it = m_vecRunTest.begin(); 
		it != m_vecRunTest.end();
		it++)
	{
		(*it)->UnInit();
	}
}

std::map<std::string, std::string> CTestFactory::GetResult()
{
	std::map<std::string, std::string> ret;
	for (auto it = m_vecRunTest.begin(); 
		it != m_vecRunTest.end();
		it++)
	{
		std::string str = (*it)->GetResult();
		ret[FindTestName(*it)] = str;
	}
	return ret;
}