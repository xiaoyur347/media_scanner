#include "dummy_player.h"

CDummyPlayer::CDummyPlayer()
{
}

CDummyPlayer::~CDummyPlayer()
{
}

void CDummyPlayer::RegisterPlayCallback(std::function<void()> cb)
{
}

void CDummyPlayer::RegisterEofCallback(std::function<void()> cb)
{
}

void CDummyPlayer::RegisterErrorCallback(std::function<void()> cb)
{
}

void CDummyPlayer::RegisterStuckCallback(std::function<void()> cb)
{
}

bool CDummyPlayer::SetSource(const std::string &str)
{
}

bool CDummyPlayer::SetAudioPassThrough(bool bEnable)
{
}

IPlayerBase::STATE CDummyPlayer::GetState()
{
}

bool CDummyPlayer::Play()
{
}

bool CDummyPlayer::Pause()
{
}

bool CDummyPlayer::Stop()
{
}

bool CDummyPlayer::GetTotalTime(int64_t &nTime)
{
}

bool CDummyPlayer::SeekToTime(int64_t nTime)
{
}

bool CDummyPlayer::GetPlayTime(int64_t &nTime)
{
}

