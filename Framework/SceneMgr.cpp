#include "stdafx.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "ScenePong.h"

void SceneMgr::Init()
{
	if (!scenes.empty())
	{
		Release();
	}

	scenes.push_back(new ScenePong());

	for (auto scene : scenes)
	{
		scene->Init();
	}

	currentSceneId = startSceneId;
	currentScene = scenes[(int)currentSceneId];
	currentScene->Enter();
}

void SceneMgr::Release()
{
	if (scenes.empty())
		return;

	for (auto scene : scenes)
	{
		delete scene;
	}
	scenes.clear();

	currentSceneId = SceneId::None;
	currentScene = nullptr;
}

void SceneMgr::Update(float dt)
{
	currentScene->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	currentScene->Draw(window);
}

void SceneMgr::ChangeScene(SceneId id)
{
	currentScene->Exit();
	currentSceneId = id;
	currentScene = scenes[(int)currentSceneId];
	currentScene->Enter();
}
