#include "stdafx.h"
#include "SceneTitle.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "SpriteGo.h"
#include "Framework.h"

SceneTitle::SceneTitle() : Scene(SceneId::Title)
{
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/cloud.png"));
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/bee.png"));
}

void SceneTitle::Init()
{
	Release();

	AddGo(new SpriteGo("Cloud"));

	for (auto go : gameObjects)
	{
		go->Init();
	}
}

void SceneTitle::Release()
{
	for (auto go : gameObjects)
	{
		//go->Release();
		delete go;
	}
}

void SceneTitle::Enter()
{
	Scene::Enter();

	SpriteGo* findGo = (SpriteGo*)FindGo("Cloud");
	findGo->sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/cloud.png"));

	sf::Vector2f centerPos = FRAMEWORK.GetWindowSize();
	centerPos.x *= 0.5f;
	centerPos.y *= 0.5f;

	findGo->SetPosition(centerPos);
	findGo->SetOrigin(Origins::MC); // 사이즈 기준으로 잡히기 때문에 texture를 바꿀 때마다 setOrigin해줘야 함
}

void SceneTitle::Exit()
{
	Scene::Exit();
}

void SceneTitle::Update(float dt)
{
	Scene::Update(dt);

	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneId::Game);
	}
}

void SceneTitle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}