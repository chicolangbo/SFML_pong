#include "stdafx.h"
#include "ScenePong.h"
#include "Ball.h"
#include "Reflector.h"
#include "SpriteGo.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "Framework.h"
#include "TextGo.h"

ScenePong::ScenePong()
	: Scene(SceneId::Title), isStart(false), lifePoint(3), scorePoint(0)
{
	// 폰트 tuple 생성
	// 로드, 언로드는 Scene에서 실행됨
	resources.push_back(std::make_tuple(ResourceTypes::Font, "fonts/DS-DIGI.ttf"));
}

void ScenePong::Init()
{
	Release();

	// 생성자에서 해주면 안됨 => 이유???
	AddGo(new Ball("Ball"));
	AddGo(new Reflector("Reflector"));
	AddGo(new TextGo("Score", "fonts/DS-DIGI.ttf"));
	AddGo(new TextGo("ScorePoint", "fonts/DS-DIGI.ttf"));
	AddGo(new TextGo("Life", "fonts/DS-DIGI.ttf"));
	AddGo(new TextGo("LifePoint", "fonts/DS-DIGI.ttf"));

	for (auto go : gameObjects)
	{
		go->Init();
	}

	isStart = false;
	lifePoint = 3;
	scorePoint = 0;
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

	// 스코어
	TextGo* score = (TextGo*)FindGo("Score");
	score->text.setString("Score: ");
	score->text.setFillColor(sf::Color::White);
	score->text.setCharacterSize(60);
	score->SetPosition(20.f, 20.f);

	sf::FloatRect pad1 = score->text.getGlobalBounds();
	std::string scoreNum = std::to_string(scorePoint);

	TextGo* scorePoint = (TextGo*)FindGo("ScorePoint");
	scorePoint->text.setString(scoreNum);
	scorePoint->text.setFillColor(sf::Color::White);
	scorePoint->text.setCharacterSize(60);
	scorePoint->SetPosition(pad1.left + pad1.width + 15.f, 20.f);


	// 라이프
	TextGo* life = (TextGo*)FindGo("Life");
	life->text.setString("Life: ");
	life->text.setFillColor(sf::Color::White);
	life->text.setCharacterSize(60);
	life->SetPosition(pad1.left + pad1.width + 100.f, 20.f);

	sf::FloatRect pad2 = life->text.getGlobalBounds();
	std::string lifeNum = std::to_string(lifePoint);

	TextGo* lifeText = (TextGo*)FindGo("LifePoint");
	lifeText->text.setString(lifeNum);
	lifeText->text.setFillColor(sf::Color::White);
	lifeText->text.setCharacterSize(60);
	lifeText->SetPosition(pad2.left + pad2.width + 20.f, 20.f);

	// 볼, 리플렉터
	auto ballGo = (Ball*)FindGo("Ball");
	auto reflectorGo = (Reflector*)FindGo("Reflector");

	// 로컬좌표
	reflectorGo->reflector.setSize(sf::Vector2f(200.f, 20.f));
	reflectorGo->reflector.setFillColor(sf::Color::Blue);
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
	auto ballPos = (Ball*)FindGo("Ball");
	auto reflectorPos = (Reflector*)FindGo("Reflector");

	Scene::Update(dt);
	MoveReflector(dt);
	ScoreUpdate();
	CheckCollide();

	if (!isStart)
	{
		Attatch();
	}
}

void ScenePong::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void ScenePong::Attatch()
{
	auto ballPos = (Ball*)FindGo("Ball");
	auto reflectorPos = (Reflector*)FindGo("Reflector");

	sf::Vector2f currentPos = reflectorPos->GetPosition();
	ballPos->SetPosition(currentPos.x, currentPos.y - 20.f);
}

void ScenePong::CheckCollide()
{
	sf::Vector2f screenSize = FRAMEWORK.GetWindowSize();

	auto ballPos = (Ball*)FindGo("Ball");
	sf::FloatRect ballSize = ballPos->ball.getGlobalBounds();
	auto reflectorPos = (Reflector*)FindGo("Reflector");
	sf::FloatRect refSize = reflectorPos->reflector.getGlobalBounds();

	if (ballSize.left+ballSize.width >= screenSize.x)
	{
		ballPos->direction.x = -ballPos->direction.x;
		scorePoint++;
	}
	if (ballSize.left <= 0.f)
	{
		ballPos->direction.x = -ballPos->direction.x;
		scorePoint++;
	}
	if (ballSize.top <= 0.f)
	{
		ballPos->direction.y = -ballPos->direction.y;
		scorePoint++;
	}

	// 바닥 충돌
	if (ballSize.top + ballSize.height >= screenSize.y)
	{
		lifePoint--;
		isStart = false;
	}

	// reflector와 충돌
	if (ballSize.intersects(refSize))
	{
		ballPos->direction.y = -ballPos->direction.y;
	}

	ballPos->ball.move(ballPos->direction);
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
	else if (INPUT_MGR.GetKeyDown(sf::Keyboard::Space))
	{
		isStart = true;
	}
}

void ScenePong::ScoreUpdate() // 보류
{
	std::string scoreNum = std::to_string(this->scorePoint);
	TextGo* scorePoint = (TextGo*)FindGo("ScorePoint");
	scorePoint->text.setString(scoreNum);

	std::string lifeNum = std::to_string(lifePoint);
	TextGo* lifeText = (TextGo*)FindGo("LifePoint");
	lifeText->text.setString(lifeNum);

	if (lifePoint <= 0)
	{
		lifePoint = 3;
		this->scorePoint = 0;
	}
}