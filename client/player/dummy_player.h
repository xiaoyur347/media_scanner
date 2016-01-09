#ifndef DUMMY_PLAYER_H
#define DUMMY_PLAYER_H

#include "player_base.h"

class CDummyPlayer : public IPlayerBase
{
public:
	CDummyPlayer();
	~CDummyPlayer();

	void RegisterPlayCallback(std::function<void()> cb);
	void RegisterEofCallback(std::function<void()> cb);
	void RegisterErrorCallback(std::function<void()> cb);
	void RegisterStuckCallback(std::function<void()> cb);
	
	bool SetSource(const std::string &str);
	bool SetAudioPassThrough(bool bEnable);

	STATE GetState();

	bool Play();
	bool Pause();
	bool Stop();
	bool GetTotalTime(int64_t &nTime);
	bool SeekToTime(int64_t nTime);
	bool GetPlayTime(int64_t &nTime);
};

#endif //DUMMY_PLAYER_H
