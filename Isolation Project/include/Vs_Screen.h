#ifndef VS_SCREEN_H
#define VS_SCREEN_H
#include "Game_Screen.h"

class Vs_Screen : public Game_Screen
{
    public:
        Vs_Screen();
        ~Vs_Screen();
        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);
        static int firstP,secondP;

    protected:

    private:
        sf::Texture bg;
        sf::Sprite bgsprite;

        sf::Texture continue_btn;
        sf::Sprite continue_btn_sprite;

        sf::Text first_player;
        sf::Text second_player;
        sf::Font chubb_font;


};

#endif // VS_SCREEN_H
