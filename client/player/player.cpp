#include "player.h"
#include <map>

CPlayer::CPlayer()
	:m_pBasePlayer(NULL),
	m_nTotalTime(0)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::OnPlayCallback()
{
	m_pBasePlayer->GetTotalTime(m_nTotalTime);
	
	for (auto it = m_vecPlayCallback.begin(); it != m_vecPlayCallback.end(); it++)
	{
		(*it)();
	}
}

void CPlayer::OnEofCallback()
{
	for (auto it = m_vecEofCallback.begin(); it != m_vecEofCallback.end(); it++)
	{
		(*it)();
	}
}

void CPlayer::OnErrorCallback()
{
	for (auto it = m_vecErrorCallback.begin(); it != m_vecErrorCallback.end(); it++)
	{
		(*it)();
	}
}

void CPlayer::OnStuckCallback()
{
	for (auto it = m_vecStuckCallback.begin(); it != m_vecStuckCallback.end(); it++)
	{
		(*it)();
	}
}

void CPlayer::Reset()
{
	m_nTotalTime = 0;
	m_vecPlayCallback.clear();
	m_vecEofCallback.clear();
	m_vecErrorCallback.clear();
	m_vecStuckCallback.clear();
}

void CPlayer::AddPlayCallback(std::function<void()> cb)
{
	m_vecPlayCallback.push_back(cb);
}

void CPlayer::AddEofCallback(std::function<void()> cb)
{
	m_vecEofCallback.push_back(cb);
}

void CPlayer::AddErrorCallback(std::function<void()> cb)
{
	m_vecErrorCallback.push_back(cb);
}

void CPlayer::AddStuckCallback(std::function<void()> cb)
{
	m_vecStuckCallback.push_back(cb);
}

bool CPlayer::SetSource(const std::string &str)
{
	if (m_pBasePlayer == NULL)
	{
		return false;
	}
	
	return m_pBasePlayer->SetSource(str);
}

bool CPlayer::SetAudioPassThrough(bool bEnable)
{
	if (m_pBasePlayer == NULL)
	{
		return false;
	}
	
	return m_pBasePlayer->SetAudioPassThrough(bEnable);
}

bool CPlayer::Play()
{
	if (m_pBasePlayer == NULL)
	{
		return false;
	}
	
	IPlayerBase::STATE state = m_pBasePlayer->GetState();
	if (state == IPlayerBase::STATE_IDLE)
	{
		return m_pBasePlayer->Play();
	}
	else if (state == IPlayerBase::STATE_PAUSE)
	{
		return m_pBasePlayer->Play();
	}
	else if (state != IPlayerBase::STATE_INVALID
			&& state != IPlayerBase::STATE_ERROR)
	{
		return true;
	}
	return false;
}

bool CPlayer::Pause()
{
	if (m_pBasePlayer == NULL)
	{
		return false;
	}
	
	IPlayerBase::STATE state = m_pBasePlayer->GetState();
	if (state == IPlayerBase::STATE_PLAY)
	{
		return m_pBasePlayer->Pause();
	}
	else if (state == IPlayerBase::STATE_PAUSE)
	{
		return true;
	}
	return false;
}

bool CPlayer::Stop()
{
	if (m_pBasePlayer == NULL)
	{
		return false;
	}
	
	IPlayerBase::STATE state = m_pBasePlayer->GetState();
	if (state != IPlayerBase::STATE_IDLE)
	{
		return m_pBasePlayer->Stop();
	}
	return true;
}

bool CPlayer::GetTotalTime(int64_t &nTime)
{
	if (m_pBasePlayer == NULL)
	{
		return false;
	}
	
	if (m_nTotalTime == 0)
	{
		return false;
	}

	nTime = m_nTotalTime;

	return true;
}

bool CPlayer::SeekToTime(int64_t nTime)
{
	if (m_pBasePlayer == NULL)
	{
		return false;
	}
	
	return m_pBasePlayer->SeekToTime(nTime);
}

bool CPlayer::GetPlayTime(int64_t &nTime)
{
	if (m_pBasePlayer == NULL)
	{
		return false;
	}
	
	return m_pBasePlayer->GetPlayTime(nTime);
}

void CPlayer::SetPlayerId(int playerid)
{
	m_pBasePlayer = &IPlayerBase::GetInstance(playerid);
	m_pBasePlayer->RegisterPlayCallback(std::bind(&CPlayer::OnPlayCallback, this));
	m_pBasePlayer->RegisterEofCallback(std::bind(&CPlayer::OnEofCallback, this));
	m_pBasePlayer->RegisterErrorCallback(std::bind(&CPlayer::OnErrorCallback, this));
	m_pBasePlayer->RegisterStuckCallback(std::bind(&CPlayer::OnStuckCallback, this));
}

CPlayer& CPlayer::GetInstance(int playerid)
{
	static std::map<int, CPlayer> s_map;
	auto it = s_map.find(playerid);
	if (it == s_map.end())
	{
		CPlayer player;
		s_map[playerid] = player;
		s_map[playerid].SetPlayerId(playerid);
		return s_map[playerid];
	}
	return it->second;
}

