#include "stdafx.h"
#include "Framework.h"

void Framework::Init(int width, int height, const char* title)
{
	window.create(sf::VideoMode(width, height), title);
}

void Framework::Release()
{
}

void Framework::Update(float dt)
{
}

void Framework::Draw()
{

}

void Framework::Run()
{
    Init(1280, 720, "SFML Works!");
    clock.restart();
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Update(dt);

        window.clear();
        Draw();
        window.display();
    }
    Release();
}
