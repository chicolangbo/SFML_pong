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
	: Scene(SceneId::Title)
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

	auto ballGo = (Ball*)FindGo("Ball");
	auto reflectorGo = (Reflector*)FindGo("Reflector");

	// 로컬좌표
	reflectorGo->reflector.setSize(sf::Vector2f(200.f, 20.f));
	reflectorGo->reflector.setFillColor(sf::Color::Yellow);
	reflectorGo->SetOrigin(Origins::MC);

	ballGo->ball.setRadius(10.f);
	ballGo->ball.setFillColor(sf::Color::Red);
	ballGo->SetOrigin(Origins::MC);

	// 월드좌표
	sf::Vector2f windowSize = FRAMEWORK.GetWindowSize();
	sf::Vector2f centerPos = { windowSize.x / 2.f, windowSize.y / 2.f };

	reflectorGo->SetPosition(centerPos.x, centerPos.y + 300.f);
	ballGo->SetPosition(reflectorGo->reflector.getPosition());
}

void ScenePong::Exit()
{
	Scene::Exit();
}

void ScenePong::Update(float dt)
{

	Scene::Update(dt);
	MoveReflector(dt);

	if (INPUT_MGR.GetKey(sf::Keyboard::Key::Space))
	{
		
	}
	CheckCollide();
}

void ScenePong::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void ScenePong::Attatch() // 보류
{
	auto ballPos = (Ball*)FindGo("Ball");
	auto reflectorPos = (Reflector*)FindGo("Reflector");

	
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
		//ballPos->direction.y = -ballPos->direction.y;
		ballPos->Init();
		Attatch();
	}
}

void ScenePong::MoveReflector(float dt)
{
	sf::Vector2f screenSize = FRAMEWORK.GetWindowSize();

	auto reflectorGo = (Reflector*)FindGo("Reflector");
	
	sf::FloatRect reflectorBound = reflectorGo->reflector.getGlobalBounds();

	if (INPUT_MGR.GetKey(sf::Keyboard::Left) && reflectorBound.left >= 0)
	{
		reflectorGo->direction = { -1.f, 0.f };
		sf::Vector2f refPos = reflectorGo->GetPosition();
		refPos += reflectorGo->direction * 500.f * dt;
		reflectorGo->SetPosition(refPos);
	}
	else if (INPUT_MGR.GetKey(sf::Keyboard::Right) && reflectorBound.left + reflectorBound.width <= screenSize.x)
	{
		reflectorGo->direction = { 1.f, 0.f };
		sf::Vector2f refPos = reflectorGo->GetPosition();
		refPos += reflectorGo->direction * 500.f * dt; // speed : 500.f
		reflectorGo->SetPosition(refPos);
	}
}

void ScenePong::ScoreUpdate() // 보류
{
}