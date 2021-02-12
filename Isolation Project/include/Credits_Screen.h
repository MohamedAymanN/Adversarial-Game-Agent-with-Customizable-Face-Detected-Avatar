#ifndef CREDITS_SCREEN_H
#define CREDITS_SCREEN_H
#include "Game_Screen.h"


class Credits_Screen : public Game_Screen
{
    public:
        Credits_Screen();
        ~Credits_Screen();

        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);

    protected:

    private:
        sf::Texture bg;
        sf::Texture back_btn;
        sf::Sprite bgsprite;
        sf::Sprite back_btn_sprite;
};

#endif // CREDITS_SCREEN_H
