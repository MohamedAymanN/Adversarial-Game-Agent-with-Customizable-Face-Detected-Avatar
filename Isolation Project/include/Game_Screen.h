#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H
#include <SFML/Graphics.hpp>
#include "Input_Manager.h"
#include <deque>

class Game_Screen
{
    public:
        Game_Screen();
        ~Game_Screen();

        virtual void LoadContent();
        virtual void UnloadContent();
        virtual void Update(sf::RenderWindow &window,sf::Event event);
        virtual void Draw(sf::RenderWindow &window);


    protected:
        Input_Manager inp;


    private:

};

#endif // GAME_SCREEN_H
