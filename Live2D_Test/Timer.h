#pragma once

class Timer 
{
public:
	Timer(float time);
	float GetTime();
	float GetSecond();
	bool isTime();
	void SetTime(float time);
	void CountDown();
	void StopWatch();
protected:
	float currentTime;
};