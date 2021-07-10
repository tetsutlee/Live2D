#include"Timer.h"

Timer::Timer(float time) 
{
	currentTime = time * 60;
}

void Timer::CountDown() 
{
	currentTime--;
	if (currentTime <= 0)
	{
		currentTime = 0;
	}
}

void Timer::StopWatch() 
{
	currentTime++;
}

void Timer::SetTime(float time) 
{
	currentTime = time * 60;
}

float Timer::GetTime() 
{
	return currentTime;
}

float Timer::GetSecond() 
{
	return currentTime / 60;
}

bool Timer::isTime() 
{
	return currentTime == 0;
}