#include "stdafx.h"
#include "Reflector.h"
#include "InputMgr.h"

Reflector::Reflector(const std::string n)
	: GameObject(n), originalPos(1280.f / 2.f, 720.f - 100.f), currentPos(originalPos), direction(1, 0), speed(500.f)
{
	reflector.setSize(sf::Vector2f(200.f,10.f));
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
	originalPos = { 1280.f / 2.f, 720.f - 100.f };
	reflector.setPosition(originalPos);
}

void Reflector::Release()
{
}

void Reflector::Reset()
{
}

void Reflector::Update(float dt)
{
	if (INPUT_MGR.GetKey(sf::Keyboard::Key::Left))
	{
		direction.x = -1.f;
		currentPos.x += direction.x * speed * dt;
	}
	else if (INPUT_MGR.GetKey(sf::Keyboard::Key::Right))
	{
		direction.x = 1.f;
		currentPos.x += direction.x * speed * dt;
	}
	reflector.setPosition(currentPos);
}

void Reflector::Draw(sf::RenderWindow& window)
{
	window.draw(reflector);
}
