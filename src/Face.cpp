
#include "Face.h"

//parametros sao coordenadas do canto superio esquerdo: (x, y)
Face::Face(float x, float y){

	//sp = new Sprite();

	sp.Open("img/penguinface.png");
	hitpoints = FULL_HEALTH;
	
	box.w= sp.GetWidth();
 	box.h= sp.GetHeight();

	box.x= x; // x-(box.w*0.5);
 	box.y= y; // y-(box.h*0.5);
}


void Face::Damage(int damage){
	hitpoints = hitpoints - damage;
	return;
}	

void Face::Update(float dt){
	
}
void Face::Render(){
	sp.Render(box.x, box.y, 0);
	return;
}
bool Face::isDead(){
	if(hitpoints <= 0)
		return true;
	else
		return false;
}




Face::~Face(){
	//delete sp;
}

