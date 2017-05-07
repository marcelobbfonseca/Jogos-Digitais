#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
	Timer();
	~Timer();
	
	void Update(float dt);
	void Restart();
	float Get();
private:
	float time;

};

#endif