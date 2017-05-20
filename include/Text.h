#ifndef TEXT_H
#define TEXT_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "Rect.h"
#include <string>
using std::string;
enum TextStyle { SOLID, SHADED, BLENDED }; 


class Text
{
	public:
		Text(string fontFile, int fontSize, TextStyle style, string text, SDL_Color color, int x=0, int y=0);
		~Text();

		void Render(int cameraX=0, int cameraY=0);
		void SetPos(int x, int y, bool centerX, bool centerY);
		void SetText(string text);
		void SetColor(SDL_Color color);
		void SetStyle(TextStyle style);
		void SetFontSize(int fontSize);
	private:
		void RemakeTexture();
		TTF_Font* font;
		SDL_Texture* texture;

		string text;
		TextStyle style;
		int fontSize;
		SDL_Color color;
		Rect box;

};

#endif