#ifndef TOURNY_CHARSELECTP2_SCREEN_H
#define TOURNY_CHARSELECTP2_SCREEN_H
#include "Game_Screen.h"


class Tourny_CharSelectP2_Screen : public Game_Screen
{
    public:
        Tourny_CharSelectP2_Screen(std::string img_loc);
        ~Tourny_CharSelectP2_Screen();
        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);

    protected:

    private:
        std::string img_loc1;
        sf::Texture bg;
        sf::Texture back_btn;
        sf::Texture prev_btn;
        sf::Texture bala7a_player;
        sf::Texture trump_player;
        sf::Texture kim_player;
        sf::Texture sadam_player;
        sf::Texture sharron_player;
        sf::Texture putin_player;

        sf::Sprite bg_sprite;
        sf::Sprite back_btn_sprite;
        sf::Sprite prev_btn_sprite;
        sf::Sprite bala7a_player_sprite;
        sf::Sprite trump_player_sprite;
        sf::Sprite kim_player_sprite;
        sf::Sprite sadam_player_sprite;
        sf::Sprite sharron_player_sprite;
        sf::Sprite putin_player_sprite;
};

#endif // TOURNY_CHARSELECTP2_SCREEN_H
