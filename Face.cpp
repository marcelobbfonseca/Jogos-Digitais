
#include "Face.h"


Face::Face(float x, float y){
	sp.Open("img/penguinface.png");
	hitpoints = FULL_HEALTH;
	//coordenadas do canto superio esquerdo: x, y
	box.x = sp.width; //x
	box.y = sp.height;//y
}


Face::Damage(int damage){
	hitpoints = hitpoints - damage;

}
void Face::Update(float dt){

}
void Face::Render(){
	//renderiza sp na pos atual
}
void Face::isDead(){
	if(hitpoints <= 0)
		return true;
	else
		return false;
}




Face::~Face(){

}

