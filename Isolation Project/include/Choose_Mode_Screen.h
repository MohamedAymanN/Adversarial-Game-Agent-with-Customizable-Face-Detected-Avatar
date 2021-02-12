#ifndef CHOOSE_MODE_SCREEN_H
#define CHOOSE_MODE_SCREEN_H
#include "Game_Screen.h"


class Choose_Mode_Screen : public Game_Screen
{
    public:
        Choose_Mode_Screen();
        ~Choose_Mode_Screen();
        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);
        void checksprites_hover(sf::RenderWindow *win);

    protected:

    private:
        sf::Texture bg;
        sf::Texture back_btn;
        sf::Texture single_btn;
        sf::Texture single_btn_hover;
        sf::Texture Multi_btn;
        sf::Texture Multi_btn_hover;
        sf::Sprite bgsprite;
        sf::Sprite back_btn_sprite;
        sf::Sprite single_btn_sprite;
        sf::Sprite multi_btn_sprite;
};

#endif // CHOOSE_MODE_SCREEN_H
