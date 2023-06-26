#include "stdafx.h"
#include "ScenePong.h"
#include "Ball.h"
#include "Reflector.h"
#include "SpriteGo.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "Framework.h"

ScenePong::ScenePong()
	: Scene(SceneId::Title), isAttatch(true)
{
}

void ScenePong::Init()
{
	Release();

	AddGo(new Ball("Ball"));
	AddGo(new Reflector("Reflector"));

	for (auto go : gameObjects)
	{
		go->Init();
	}

	Attatch();
}

void ScenePong::Release()
{
	for (auto go : gameObjects)
	{
		//go->Release();
		delete go;
	}
}

void ScenePong::Enter()
{
	Scene::Enter();

	auto findGo = (Ball*)FindGo("Ball");

	sf::Vector2f centerPos = FRAMEWORK.GetWindowSize();
	centerPos.x *= 0.5f;
	centerPos.y *= 0.5f;

	findGo->ball.setRadius(15.f);
	findGo->ball.setPosition(centerPos);
	findGo->ball.setFillColor(sf::Color::Red);

	//findGo->SetPosition(centerPos);
	//findGo->SetOrigin(Origins::MC); // 사이즈 기준으로 잡히기 때문에 texture를 바꿀 때마다 setOrigin해줘야 함
}

void ScenePong::Exit()
{
	Scene::Exit();
}

void ScenePong::Update(float dt)
{
	if (INPUT_MGR.GetKey(sf::Keyboard::Key::Space))
	{
		Scene::Update(dt);
	}
	CheckCollide();

}

void ScenePong::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void ScenePong::Attatch()
{
	isAttatch = true;
	auto ballPos = (Ball*)FindGo("Ball");
	auto reflectorPos = (Reflector*)FindGo("Reflector");

	sf::Vector2f pos = reflectorPos->reflector.getPosition();
	ballPos->ball.setPosition(pos.x,pos.y-10.f);
}

void ScenePong::CheckCollide()
{
	sf::Vector2f screenSize = FRAMEWORK.GetWindowSize();

	auto ballPos = (Ball*)FindGo("Ball");
	sf::FloatRect ballSize = ballPos->ball.getGlobalBounds();
	auto reflectorPos = (Reflector*)FindGo("Reflector");

	if (ballSize.left+ballSize.width >= screenSize.x)
	{
		ballPos->direction.x = -ballPos->direction.x;
	}
	if (ballSize.left <= 0.f)
	{
		ballPos->direction.x = -ballPos->direction.x;
	}
	if (ballSize.top <= 0.f)
	{
		ballPos->direction.y = -ballPos->direction.y;
	}
	if (ballSize.top + ballSize.height >= screenSize.y)
	{
		ballPos->direction.y = -ballPos->direction.y;
	}
}
