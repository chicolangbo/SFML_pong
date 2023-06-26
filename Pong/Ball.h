#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
private:

	float speed;
	sf::Vector2f speedRange;
	sf::Vector2f originalPos; // 시작 화면에서의 객체 위치

	float accumTime; // dt 누적 시간

public:
	sf::CircleShape ball;
	sf::Vector2f direction; // 객체의 방향(이동 방향 X)
	sf::Vector2f currentPos; // 현재 위치

	Ball(const std::string n = "");
	virtual ~Ball();

	virtual void SetName(const std::string& n) override;

	virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(const sf::Vector2f p) override;

	virtual void SetOrigin(Origins origin) override;
	virtual void SetOrigin(float x, float y) override;

	virtual void Init() override;	// 생성자 new 역할
	virtual void Release() override;	// 소멸자 delete 역할

	virtual void Reset() override;	// 값 세팅

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

};

