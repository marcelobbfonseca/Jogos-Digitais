#include "Timer.h"

Timer::Timer(){
	_time = 0.0;
}
Timer::~Timer(){

}
	
void Timer::Update(float dt){
	_time = _time + dt;
}

void Timer::Restart(){
	_time = 0.0;
}

float Timer::Get(){
	return _time;
}