#include "Text.h"
#include "error.h"
#include "Resources.h"
#include "Game.h"

Text::Text(string fontFile, int fontSize, TextStyle style, string text, SDL_Color color, int x, int y
	): font(Resources::GetFont(fontFile, fontSize)) {
	box.x = x;
	box.y = y;
	texture= nullptr;
	this->text = text;
	this->style = style;
	this->fontSize = fontSize;
	this->color = color;
	//RemakeTexture();
}
Text::~Text(){
	if(texture != nullptr)
		SDL_DestroyTexture(texture);
	
}

void Text::Render(int cameraX, int cameraY){
	if(texture == nullptr)
		ErrorExit(__LINE__, "Texture not created(Texture is null)" ,__FILE__);

	SDL_Rect srcRect;
	srcRect.x= 0;
	srcRect.y= 0;
	srcRect.w= box.w;
	srcRect.h= box.h;
	SDL_Rect destRect= (SDL_Rect)box;

	if(SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &srcRect, &destRect)!=0 )
		ErrorExit(__LINE__, SDL_GetError() ,__FILE__);

} 
void Text::SetPos(int x, int y, bool centerX, bool centerY){
	//Vec2 center= Game::GetInstance().GetWindowDimensions();
	
	Vec2 center;
	SDL_GetWindowSize(Game::GetInstance().GetWindow(), (int*)&center.x, (int*)&center.y);
	center.x= *((int*)&center.x);
	center.y= *((int*)&center.y);


	if(centerX)
		box.x= (center.x-box.w)/2.0;
	else
		box.x= x;

	if(centerY)
		box.y= (center.y-box.h)/2.0;
	else
		box.y= y;

}
void Text::SetText(string text){
	this->text=text;
	RemakeTexture();
}
void Text::SetColor(SDL_Color color){
	this->color=color;
	RemakeTexture();
}
void Text::SetStyle(TextStyle style){
	this->style=style;
	RemakeTexture();

}
void Text::SetFontSize(int fontSize){
	this->fontSize=fontSize;
	RemakeTexture();
}

void Text::RemakeTexture(){

	if(texture != nullptr)
		SDL_DestroyTexture(texture);

	//font style
	SDL_Surface *surface;
	switch(style){
		case SOLID: surface = TTF_RenderText_Solid(font, text.c_str(), color);
					break;
		
		case SHADED:SDL_Color bgColor;
					bgColor= {0, 0, 0, 0};
					surface= TTF_RenderText_Shaded(font, text.c_str(), color, bgColor);
					break;
		
		case BLENDED:surface = TTF_RenderText_Blended(font, text.c_str(), color);
					break;
		
		default:break;
	}
	if(surface == NULL)
		ErrorExit(__LINE__, "Unable to load text " ,__FILE__);
		//std::cout << text << " tamanho: " << fontSize);
	
	texture = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), surface);
	if(texture == NULL)
		ErrorExit(__LINE__, "Failed to create texture from surface " ,__FILE__);

	SDL_FreeSurface(surface);
	//w and h may have changed. Get them!
	SDL_QueryTexture(texture, nullptr, nullptr, (int*)&box.w, (int*)&box.h);
	box.w= *((int*)&box.w);
	box.h= *((int*)&box.h);
}