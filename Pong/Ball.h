#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
private:

	float speed;
	sf::Vector2f speedRange;
	sf::Vector2f originalPos; // ���� ȭ�鿡���� ��ü ��ġ

	float accumTime; // dt ���� �ð�

public:
	sf::CircleShape ball;
	sf::Vector2f direction; // ��ü�� ����(�̵� ���� X)
	sf::Vector2f currentPos; // ���� ��ġ

	Ball(const std::string n = "");
	virtual ~Ball();

	virtual void SetName(const std::string& n) override;

	virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(const sf::Vector2f p) override;

	virtual void SetOrigin(Origins origin) override;
	virtual void SetOrigin(float x, float y) override;

	virtual void Init() override;	// ������ new ����
	virtual void Release() override;	// �Ҹ��� delete ����

	virtual void Reset() override;	// �� ����

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

};

