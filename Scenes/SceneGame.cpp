#include "stdafx.h"
#include "SceneGame.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"

SceneGame::SceneGame() : Scene(SceneId::Game)
{
}

void SceneGame::Init()
{
	Scene::Init();
}

void SceneGame::Release()
{
	Scene::Release();

}

void SceneGame::Enter()
{
	Scene::Enter();
	RESOURCE_MGR.Load(ResourceTypes::Texture, "graphics/Peppermint Cookie.png");

}

void SceneGame::Exit()
{
	Scene::Exit();
	RESOURCE_MGR.Unload(ResourceTypes::Texture, "graphics/Peppermint Cookie.png");

}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);
	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneId::Title);
	}

}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	sf::Sprite sprite;
	sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/Peppermint Cookie.png"));
	window.draw(sprite);

}
