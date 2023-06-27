#include "stdafx.h"
#include "Reflector.h"
#include "InputMgr.h"
#include "Framework.h"

Reflector::Reflector(const std::string n)
	: GameObject(n), direction(1.f, 0.f)
{
}

Reflector::~Reflector()
{
}

void Reflector::SetName(const std::string& n)
{
}

void Reflector::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	reflector.setPosition(x, y);
}

void Reflector::SetPosition(const sf::Vector2f p)
{
	position = p;
	reflector.setPosition(p);
}

void Reflector::SetOrigin(Origins origin)
{
	GameObject::SetOrigin(origin);
	if (this->origin != Origins::CUSTOM)
	{
		Utils::SetOrigin(reflector, origin);
	}
}

void Reflector::SetOrigin(float x, float y)
{
	reflector.setOrigin(x, y);
}

void Reflector::Init()
{
}

void Reflector::Release()
{
}

void Reflector::Reset()
{
}

void Reflector::Update(float dt)
{
}

void Reflector::Draw(sf::RenderWindow& window)
{
	window.draw(reflector);
}
