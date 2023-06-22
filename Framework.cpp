#include "stdafx.h"
#include "Framework.h"
#include "InputMgr.h"

void Framework::Init(int width, int height, const char* title)
{
	window.create(sf::VideoMode(width, height), title);
}

void Framework::Release()
{
}

void Framework::Update(float dt)
{
    if (INPUT_MGR.GetKeyDown(sf::Keyboard::A))
    {
        std::cout << "Down" << std::endl;
    }
    if (INPUT_MGR.GetKeyUp(sf::Keyboard::A))
    {
        std::cout << "Up" << std::endl;
    }
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

        INPUT_MGR.Clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            INPUT_MGR.Update(event);
        }
        Update(dt);

        window.clear();
        Draw();
        window.display();
    }
    Release();
}
