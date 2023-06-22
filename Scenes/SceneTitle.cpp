#include "stdafx.h"
#include "SceneTitle.h"
#include "SceneMgr.h"
#include "InputMgr.h"

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