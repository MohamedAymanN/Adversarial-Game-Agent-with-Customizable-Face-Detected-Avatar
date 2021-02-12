#ifndef STARTGAME_SCREEN_H
#define STARTGAME_SCREEN_H
#include "Game_Screen.h"


class StartGame_Screen : public Game_Screen
{
    public:
        StartGame_Screen();
        ~StartGame_Screen();
        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);
        void checksprites_hover(sf::RenderWindow *win);

    protected:

    private:
        sf::Texture bg;
        sf::Texture back_btn;
        sf::Texture quickplay_btn;
        sf::Texture quickplay_hover;
        sf::Texture tournement_btn;
        sf::Texture tournement_hover;
        sf::Texture campaign_btn;
        sf::Texture campaign_hover;
        sf::Texture rl_btn;
        sf::Sprite bgsprite;
        sf::Sprite back_btn_sprite;
        sf::Sprite quickplay_btn_sprite;
        sf::Sprite tournement_btn_sprite;
        sf::Sprite campaign_btn_sprite;
        sf::Sprite rl_btn_sprite;
};

#endif // STARTGAME_SCREEN_H
