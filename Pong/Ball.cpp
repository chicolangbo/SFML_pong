#include "stdafx.h"
#include "Ball.h"

Ball::Ball(const std::string n)
	: GameObject(n), speed(500.f), direction(0.3,-0.3), originalPos(1280/2, 720/2), currentPos(1280 / 2, 720 / 2)
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
	originalPos = { 0,0 };
	ball.setPosition(originalPos);
	/*ball.setOrigin(Origins::MC);*/ // �Ǻ����� ���� �߽����� �⺻ ���õ�
}

void Ball::Release()
{
}

void Ball::Reset()
{
}

void Ball::Update(float dt)
{
	currentPos += direction;
	// currentPos += direction * speed * dt;  
	// �ӵ� * ���� ������ ���� ��� �ð� => ������ ���� �̵� �Ÿ� ����
	ball.setPosition(currentPos);
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(ball);
}
