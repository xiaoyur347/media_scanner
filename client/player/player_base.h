#ifndef PLAYER_BASE_H
#define PLAYER_BASE_H

#include <string>
#include <stdint.h>

#include "functional.h"

class IPlayerBase
{
public:
	enum ID
	{
		ID_MAIN,
		ID_PREVIEW
	};
	enum STATE
	{
		STATE_INVALID,
		STATE_IDLE,
		STATE_BUFFERING,
		STATE_PLAY,
		STATE_PAUSE,
		STATE_EOF,
		STATE_ERROR,
	};
	virtual ~IPlayerBase() {}

	virtual void RegisterPlayCallback(std::function<void()> cb) = 0;
	virtual void RegisterEofCallback(std::function<void()> cb) = 0;
	virtual void RegisterErrorCallback(std::function<void()> cb) = 0;
	virtual void RegisterStuckCallback(std::function<void()> cb) = 0;
	
	virtual bool SetSource(const std::string &str) = 0;
	virtual bool SetAudioPassThrough(bool bEnable) = 0;

	virtual STATE GetState() = 0;

	virtual bool Play() = 0;
	virtual bool Pause() = 0;
	virtual bool Stop() = 0;
	virtual bool GetTotalTime(int64_t &nTime) = 0;
	virtual bool SeekToTime(int64_t nTime) = 0;
	virtual bool GetPlayTime(int64_t &nTime) = 0;

	static IPlayerBase& GetInstance(int playerid);
};

#endif //PLAYER_BASE_H

