class Camera
{
public:
	Camera();
	void Follow(GameObject* newFocus);
	void Unfollow();
	void Update(float dt);
	~Camera();
private:
	Vec2 pos;
	Vec2 speed;
	GameObject* focus;
};