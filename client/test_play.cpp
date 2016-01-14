#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <stdio.h>
#include "test_base.h"
#include "test_factory.h"
#include "player/player.h"

#include <unistd.h>

class CTestPlay: public ITestBase
{
public:
	CTestPlay();
	~CTestPlay();
	void Init();
	void Run(const std::string &strUrl);
	void UnInit();
	std::string GetResult();

private:
	void OnPlayCallback();
	void OnEofCallback();
	void OnErrorCallback();

	bool m_bOnPlay;
	bool m_bOnEof;
	bool m_bOnError;
};

CTestPlay::CTestPlay()
	:m_bOnPlay(false),
	 m_bOnEof(false),
	 m_bOnError(false)
{
}

CTestPlay::~CTestPlay()
{
}

void CTestPlay::OnPlayCallback()
{
	m_bOnPlay = true;
}

void CTestPlay::OnEofCallback()
{
	m_bOnEof = true;
}

void CTestPlay::OnErrorCallback()
{
	m_bOnError = true;
}

void CTestPlay::Init()
{
	m_bOnPlay = false;
	m_bOnEof = false;
	m_bOnError = false;
	
	CPlayer &player = CPlayer::GetInstance(IPlayerBase::ID_MAIN);
	player.AddPlayCallback(std::bind(&CTestPlay::OnPlayCallback, this));
	player.AddEofCallback(std::bind(&CTestPlay::OnEofCallback, this));
	player.AddErrorCallback(std::bind(&CTestPlay::OnErrorCallback, this));
}

void CTestPlay::Run(const std::string &strUrl)
{
	CPlayer &player = CPlayer::GetInstance(IPlayerBase::ID_MAIN);
	player.SetSource(strUrl);
	player.Play();

	for (int i = 0; i < 60; i++)
	{
		if (m_bOnError)
		{
			return;
		}
		int64_t nTime = 0;
		player.GetPlayTime(nTime);
		if (nTime > 0)
		{
			printf("time=%" PRId64 "\n", nTime);
		}
		if (nTime > 5*1000)
		{
			if (m_bOnPlay)
			{
				break;
			}
		}
		usleep(1000 * 1000);
	}
}

void CTestPlay::UnInit()
{
	CPlayer &player = CPlayer::GetInstance(IPlayerBase::ID_MAIN);
	player.Stop();
}

std::string CTestPlay::GetResult()
{
	if (m_bOnPlay)
	{
		return RESULT_SUCCESS;
	}

	return RESULT_FAIL;
}

static bool bRegister = CTestFactory::GetInstance().RegisterTest(
	"play", new CTestPlay());

