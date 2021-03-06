#ifndef WINNER_SCREEN_H
#define WINNER_SCREEN_H
#include "Game_Screen.h"
#include "Gif_Loader.h"

class Winner_Screen : public Game_Screen
{
    public:
        Winner_Screen(std::string name,std::string loc,int play1_score,int play2_score,std::string loc1,std::string loc2);
        ~Winner_Screen();
        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);

    protected:

    private:
        std::string winner_name;
        std::string winner_img;
        int player1_score;
        int player2_score;
        std::string image_loc_p1;
        std::string image_loc_p2;

        sf::Font chubb_font;
        sf::Text winner_text;

        sf::Texture win_pic;
        Gif_Loader *gf;


        sf::Sprite win_pic_sprite;
        sf::Sprite bg_sprite;
        sf::Texture l;

        sf::Texture back_btn;
        sf::Sprite back_btn_sprite;

        sf::Texture playagain_btn;
        sf::Sprite playagain_btn_sprite;


};

#endif // WINNER_SCREEN_H
