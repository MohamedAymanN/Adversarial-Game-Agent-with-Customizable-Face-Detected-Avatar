#ifndef TOURNY_WINNER_SCREEN_H
#define TOURNY_WINNER_SCREEN_H
#include "Game_Screen.h"
#include "Gif_Loader.h"


class Tourny_Winner_Screen : public Game_Screen
{
    public:
        Tourny_Winner_Screen();
        ~Tourny_Winner_Screen();
        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);

    protected:

    private:
        Gif_Loader *gf;

        sf::Texture back_btn;
        sf::Sprite back_btn_sprite;

        sf::Sprite bg_sprite;
        sf::Texture l;
};

#endif // TOURNY_WINNER_SCREEN_H
