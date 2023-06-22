#pragma once
#include "Singleton.h"

class Framework : public Singleton<Framework>
{
	friend Singleton<Framework>;

protected:
	Framework() = default;
	virtual ~Framework() override = default;

	sf::RenderWindow window;
	sf::Clock clock;

public:
	virtual void Init(int width, int height, const char* title);
	virtual void Release();
	virtual void Update(float dt);
	virtual void Draw();

	virtual void Run();
};

#define FRAMEWORK (Framework::Instance())