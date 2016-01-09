#ifndef PLAYER_H
#define PLAYER_H

#include "player_base.h"
#include <vector>

class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	
	void Reset();
	void AddPlayCallback(std::function<void()> cb);
	void AddEofCallback(std::function<void()> cb);
	void AddErrorCallback(std::function<void()> cb);
	void AddStuckCallback(std::function<void()> cb);
	
	bool SetSource(const std::string &str);
	bool SetAudioPassThrough(bool bEnable);

	bool Play();
	bool Pause();
	bool Stop();
	bool GetTotalTime(int64_t &nTime);
	bool SeekToTime(int64_t nTime);
	bool GetPlayTime(int64_t &nTime);

	static CPlayer& GetInstance(int playerid);

private:
	void SetPlayerId(int playerid);

	void OnPlayCallback();
	void OnEofCallback();
	void OnErrorCallback();
	void OnStuckCallback();

	IPlayerBase *m_pBasePlayer;
	int64_t m_nTotalTime;
	std::vector< std::function<void()> > m_vecPlayCallback;
	std::vector< std::function<void()> > m_vecEofCallback;
	std::vector< std::function<void()> > m_vecErrorCallback;
	std::vector< std::function<void()> > m_vecStuckCallback;
};

#endif //PLAYER_H

