#include "Animation.h"
#include "Camera.h"
using std::string;

Animation::Animation(float x, float y, 
	float rotation, string sprite, 
	int frameCount, float frameTime, bool ends): timeLimit(frameCount * frameTime),GameObject(), endTimer(), sp(sprite, frameCount, frameTime) {
	
	timeLimit = frameCount * frameTime ;
	box= Vec2(x, y);
	this->rotation= rotation;
	this->oneTimeOnly = ends;


}
Animation::~Animation(){

}
	
void Animation::Update(float dt){
	sp.Update(dt);
	endTimer.Update(dt);

}
void Animation::Render(){

	sp.Render(box.x-Camera::pos.x, box.y-Camera::pos.y, rotation);
}
bool Animation::isDead(){
	if(oneTimeOnly){
		if(endTimer.Get() > timeLimit)
			return true;
		
	}
	return false;
}

void Animation::NotifyCollision(GameObject& other){
	//must not react to collision
}
bool Animation::Is(string type){
	return type == "Animation";
}