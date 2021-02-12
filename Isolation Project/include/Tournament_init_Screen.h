#ifndef TOURNAMENT_INIT_SCREEN_H
#define TOURNAMENT_INIT_SCREEN_H
#include "Game_Screen.h"


class Tournament_init_Screen : public Game_Screen
{
    public:
        Tournament_init_Screen();
        ~Tournament_init_Screen();
        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);
        void checksprites_hover(sf::RenderWindow *win);
        void initQueue();
        static std::deque<int> tourny_players;


    protected:

    private:
        sf::Texture bg;
        sf::Texture back_btn;
        sf::Texture start_btn;
        sf::Sprite bgsprite;
        sf::Sprite back_btn_sprite;
        sf::Sprite start_btn_sprite;
        sf::String playerInput;
        sf::Text playerText;
        sf::Text infoText;
        sf::Font chubb_font;

};
//std::deque<int> Tournament_init_Screen::tourny_players;


#endif // TOURNAMENT_INIT_SCREEN_H
