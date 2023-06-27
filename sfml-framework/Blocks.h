#pragma once
#include "GameObject.h"
class Blocks :
    public GameObject
{
private:
public:
	sf::RectangleShape block;

	Blocks(const std::string n);
	virtual ~Blocks() override;

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

