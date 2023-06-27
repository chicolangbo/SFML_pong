#include "stdafx.h"
#include "Ball.h"
#include "Framework.h"

Ball::Ball(const std::string n)
	: GameObject(n), direction(0.2,-0.35)
{
}

Ball::~Ball()
{
}

void Ball::SetName(const std::string& n)
{
}

void Ball::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	ball.setPosition(position);
}

void Ball::SetPosition(const sf::Vector2f p)
{
	position = p;
	ball.setPosition(p);
}

void Ball::SetOrigin(Origins origin)
{
	GameObject::SetOrigin(origin);
	if (this->origin != Origins::CUSTOM)
	{
		Utils::SetOrigin(ball, origin);
	}
}

void Ball::SetOrigin(float x, float y)
{
	ball.setOrigin(x, y);
}

void Ball::Init()
{
	
}

void Ball::Release()
{
}

void Ball::Reset()
{
}

void Ball::Update(float dt)
{
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(ball);
}
