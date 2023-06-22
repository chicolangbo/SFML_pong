#include "stdafx.h"
#include "Scene.h"

Scene::Scene(SceneId id) : sceneId(id)
{

}

Scene::~Scene()
{
	Release();
}

void Scene::Init()
{

}

void Scene::Release()
{

}

void Scene::Enter()
{

}

void Scene::Exit()
{

}

void Scene::Update(float dt)
{
}

void Scene::Draw(sf::RenderWindow& window)
{
}
