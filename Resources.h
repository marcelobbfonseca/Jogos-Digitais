
#include <unordered_map>

class Resources
{
public:
	Resources();
	static SDL_Texture* GetImage(std::string file);
	static void ClearImages();
	~Resources();
private:
	static std::unordered map<std::string, SDL_Texture*> imageTable;	
};