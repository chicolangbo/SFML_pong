#include "stdafx.h"
#include "SceneTitle.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"

SceneTitle::SceneTitle() : Scene(SceneId::Title)
{
}

void SceneTitle::Init()
{
	Scene::Init();
}

void SceneTitle::Release()
{
	Scene::Release();

}

void SceneTitle::Enter()
{
	Scene::Enter();
	RESOURCE_MGR.Load(ResourceTypes::Texture, "graphics/Cream Unicorn Cookie.png");

}

void SceneTitle::Exit()
{
	Scene::Exit();
	RESOURCE_MGR.Unload(ResourceTypes::Texture, "graphics/Cream Unicorn Cookie.png");

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

	sf::Sprite sprite;
	sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/Cream Unicorn Cookie.png"));
	window.draw(sprite);
}