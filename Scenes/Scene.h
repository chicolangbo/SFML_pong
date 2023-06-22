#pragma once
class Scene
{
protected:
	SceneId sceneId;

	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
public:
	Scene(SceneId id = SceneId::None);
	virtual ~Scene();

	virtual void Init();
	virtual void Release();

	virtual void Enter();
	virtual void Exit();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

};