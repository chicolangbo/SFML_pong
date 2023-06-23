#include "stdafx.h"
#include "Utils.h"

std::random_device Utils::rd;
std::mt19937 Utils::gen(Utils::rd());


int Utils::RandomRange(int min, int maxExclude)
{
    std::uniform_int_distribution<> dist(min, maxExclude -1);
    return dist(gen);
    //return gen() % (maxExclude - min) + min;
}

float Utils::RandomRange(float min, float max)
{
    std::uniform_real_distribution<> dist(min, max);
    return (float)dist(gen);
}

void Utils::SetOrigin(sf::Sprite& sprite, Origins origin)
{
    SetOrigin(sprite, origin, sprite.getLocalBounds());
}

void Utils::SetOrigin(sf::Text& text, Origins origin)
{
    SetOrigin(text, origin, text.getLocalBounds());
}

void Utils::SetOrigin(sf::Shape& shape, Origins origin)
{
    SetOrigin(shape, origin, shape.getLocalBounds());
}

// Text �� Sprite�� ���ڸ� �Ѱܹ޾� �ǹ��� �缳��
void Utils::SetOrigin(sf::Transformable& obj, Origins origin, const sf::FloatRect& rect)
{
    sf::Vector2f originPos(rect.width, rect.height);
    originPos.x *= ((int)origin % 3) * 0.5f;
    originPos.y *= ((int)origin / 3) * 0.5f;
    obj.setOrigin(originPos);
}
