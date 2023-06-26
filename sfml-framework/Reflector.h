#pragma once
#include "GameObject.h"

class Reflector :
    public GameObject
{
private:

public:
	sf::RectangleShape reflector;
	sf::Vector2f direction;

	Reflector(const std::string n = "");
	virtual ~Reflector();

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

