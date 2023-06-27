#pragma once
#include "Scene.h"
#include "Blocks.h"

class ScenePong :
    public Scene
{
private:
	bool isStart;
	int lifePoint;
	int scorePoint;
	int blockCount;
	std::list<Blocks*> blockPool; // * 블록 객체 메모리풀
	std::list<Blocks*> blockActive; // * 활성화된 블록 객체

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
	void MoveReflector(float dt);
	void ScoreUpdate();
	void makeBlock();
};

