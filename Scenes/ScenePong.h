#pragma once
#include "Scene.h"

class ScenePong :
    public Scene
{
private:
	bool isAttatch;

public:
	ScenePong();
	virtual ~ScenePong() override = default;

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void Attatch();

	void CheckCollide();
};

