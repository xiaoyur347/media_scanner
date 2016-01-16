#include "test_base.h"
#include "test_factory.h"
#include "player/player.h"

#include <unistd.h>

class CTestSeek: public ITestBase
{
public:
	CTestSeek();
	~CTestSeek();
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
	bool m_bSeekSuccess;
};

CTestSeek::CTestSeek()
	:m_bOnPlay(false),
	 m_bOnEof(false),
	 m_bOnError(false),
	 m_bSeekSuccess(false)
{
}

CTestSeek::~CTestSeek()
{
}

void CTestSeek::OnPlayCallback()
{
	m_bOnPlay = true;
}

void CTestSeek::OnEofCallback()
{
	m_bOnEof = true;
}

void CTestSeek::OnErrorCallback()
{
	m_bOnError = true;
}

void CTestSeek::Init()
{
	m_bOnPlay = false;
	m_bOnEof = false;
	m_bOnError = false;
	m_bSeekSuccess = false;
	
	CPlayer &player = CPlayer::GetInstance(IPlayerBase::ID_MAIN);
	player.AddPlayCallback(std::bind(&CTestSeek::OnPlayCallback, this));
	player.AddEofCallback(std::bind(&CTestSeek::OnEofCallback, this));
	player.AddErrorCallback(std::bind(&CTestSeek::OnErrorCallback, this));
}

void CTestSeek::Run(const std::string &strUrl)
{
	CPlayer &player = CPlayer::GetInstance(IPlayerBase::ID_MAIN);
	player.SetSource(strUrl);
	player.Play();

	while (true)
	{
		if (m_bOnError)
		{
			return;
		}
		int64_t nTime = 0;
		player.GetPlayTime(nTime);
		if (nTime > 5*1000)
		{
			break;
		}
		usleep(100 * 1000);
	}
	
	int nDest = 10*60*1000;
	player.SeekToTime(10*60*1000);
	for (int i = 0; i < 20; i++)
	{
		if (m_bOnError)
		{
			return;
		}
		int64_t nTime = 0;
		player.GetPlayTime(nTime);
		if (nTime > nDest)
		{
			m_bSeekSuccess = true;
			break;
		}
		usleep(1000 * 1000);
	}
}

void CTestSeek::UnInit()
{
	CPlayer &player = CPlayer::GetInstance(IPlayerBase::ID_MAIN);
	player.Stop();
}

std::string CTestSeek::GetResult()
{
	if (m_bSeekSuccess)
	{
		return RESULT_SUCCESS;
	}

	return RESULT_FAIL;
}

static bool bRegister = CTestFactory::GetInstance().RegisterTest(
	"seek", new CTestSeek());

