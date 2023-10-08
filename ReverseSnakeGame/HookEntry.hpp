#ifndef __HOOKENTRY_HPP__
#define __HOOKENTRY_HPP__

#include "InjectHooker.hpp"

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
#include <stdexcept>
#include <deque>
#include <functional>

#include "SnakeGame.hpp"


void Hello()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), L"我是标题");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}


typedef void(__cdecl* FUNCTION_TEST)(sf::Time&);
HOOK_TARGET(FUNCTION_TEST, SnakeGame__Update, 0x00407A60);

#define GEN_HOOKER GEN_HOOKER_FUNC(SnakeGame__Update);
#define UNGEN_HOOKER UNGEN_HOOKER_FUNC(SnakeGame__Update);

SnakeGame* pSnakeGame = nullptr;

void __cdecl DETOURFUNCION(SnakeGame__Update)(const sf::Time& deltaTime)
{
    //EXPAND_NOP_ASM_X10(1);

    __asm {
        mov pSnakeGame, ecx

        mov         eax, dword ptr[deltaTime]
        push        eax
        mov         edx, dword ptr[ecx]
        mov         eax, SnakeGame::update
        call        eax
    }
}

#endif // __HOOKENTRY_HPP__