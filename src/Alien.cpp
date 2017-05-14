#include "Alien.h"
#include "InputManager.h"
#include "Camera.h"
#include "error.h"
#include "Collision.h"
#include "Bullet.h"

#define MOVE_TYPE 0
#define SHOOT_TYPE 1
#define FULL_HEALTH 30
#define DISTANCE_TOLERANCE 5
#define PI 3.141592
#define DISTANCE_INITIALIZE 999999
#define ALIEN_DMG 9
using std::vector;
 
typedef unsigned int uint;
Alien::Alien(float x, float y, int nMinions): sp(){
	
	sp.Open("img/alien.png");
	box.x = x - sp.GetWidth()/2; 
	box.y = y - sp.GetHeight()/2;
	box.w = sp.GetWidth();
	box.h = sp.GetHeight();
	
	hp = FULL_HEALTH;

	//Build minion array. Sort the minions positions around the circle(in 360degrees) and convert to radians
	for(int i=0; i < nMinions; i++){
		minionArray.emplace_back( Minion(this, ( ( (i*360)/nMinions)*PI)/180 )); 
	}
}

void Alien::Update(float dt){
	int x, y;

	InputManager &i = InputManager::GetInstance();
	
	//mouse esquerdo para tiro e direito para movimento
	if(i.MousePress(LEFT_MOUSE_BUTTON)){
		x = i.GetMouseX()+Camera::pos.x;
		y = i.GetMouseY()+Camera::pos.y;
		Action action(Alien::Action::ActionType::SHOOT, x, y ); 
		taskQueue.push(action);
	}
	else if(i.MousePress(RIGHT_MOUSE_BUTTON)){
		x = i.GetMouseX()+Camera::pos.x;
		y = i.GetMouseY()+Camera::pos.y;
		Action action(Alien::Action::ActionType::MOVE, x, y );
		taskQueue.push(action);
	}
	

	//check for incoming actions
	if(taskQueue.empty()==false){
		Action nextAction = taskQueue.front();

		if(nextAction.type == SHOOT_TYPE){
			if(minionArray.empty()==false){
				float minimumDistance = DISTANCE_INITIALIZE;
				float minionDistance=0;
				uint closerMinion;

				for (uint i = 0; i < minionArray.size(); i++){
					minionDistance = minionArray.at(i).box.Center().Distance(nextAction.pos);
					if(minionDistance < minimumDistance ){
						minimumDistance = minionDistance;
						closerMinion = i;
					}
				}
				minionArray.at(closerMinion).Shoot(nextAction.pos);
			}
			else{
				ErrorExit(__LINE__, "minionArray is empty!" ,__FILE__);
			}
			
			taskQueue.pop();

		}else if(nextAction.type == MOVE_TYPE){
			//calcular velocidade
			//speed = distancia.posx/dt;

			Vec2 d = nextAction.pos-Vec2(box.x, box.y);
			
			//SE CHEGOU NO local. desempilha
			if(DISTANCE_TOLERANCE >= d.Magnitude()){
				box.x= nextAction.pos.x;
				box.y= nextAction.pos.y;
				taskQueue.pop();
			}
			else{
				d.Normalize();
				d= (d*sqrt(ALIEN_MOVE_SPEED*dt));
				box.x+= d.x;
				box.y+= d.y;
			}

		}
		else{
			ErrorExit(__LINE__, "Undentified Alien action on queue" ,__FILE__);
		}

	}
	rotation -= ALIEN_ROTATION_SPEED;
	for(unsigned int i=0; i < minionArray.size(); i++){
		minionArray.at(i).Update(dt);
	}


}
void Alien::Render(){
	
	sp.Render(box.x-Camera::pos.x, box.y-Camera::pos.y, rotation);
	for (unsigned int j = 0; j < minionArray.size(); j++){
		minionArray[j].Render();
	}
}
bool Alien::isDead(){
	if(hp <=0)
		return true;
	else
		return false;
}
 
bool Alien::Is(string type){
	return type == "Alien";
	//return (Being::Is(type)|| type == "Alien");
}

void Alien::NotifyCollision(GameObject& other){
 
	if (other.Is("Bullet")){
		if( ( (Bullet&)other).GetTargetsPlayer()==false){
			printf("ai ai To morrendo\n");
			hp = hp - ALIEN_DMG;
			if(isDead()){
				//~Alien();

			}
		}
	}
	
}


Alien::Action::Action(ActionType type, float x, float y){
	this->type = type;
	this->pos.x=x;
	this->pos.y=y;
}

Alien::~Alien(){
	
}