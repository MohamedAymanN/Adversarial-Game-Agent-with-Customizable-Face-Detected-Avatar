#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include "Game_Screen.h"
#include "Gif_Loader.h"
#include <SFML/Audio.hpp>

class Main_Menu : public Game_Screen
{
    public:
        Main_Menu();
        ~Main_Menu();

        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);
        void checksprites(sf::RenderWindow *win);
        void checksprites_hover(sf::RenderWindow *win);

    protected:
    private:
        sf::Texture l;
        sf::Texture Bkg;
        sf::Texture title;
        sf::Texture str_btn;
        sf::Texture str_btn_hover;
        sf::Texture howtop_btn;
        sf::Texture howtop_btn_hover;
        sf::Texture settings_btn;
        sf::Texture settings_btn_hover;
        sf::Texture highscore_btn;
        sf::Texture highscore_btn_hover;
        sf::Texture credits_btn;
        sf::Texture credits_btn_hover;
        sf::Texture exit_btn;
        sf::Texture exit_btn_hover;
        //Background Image Sprite
        sf::Sprite bgsprite;
        sf::Sprite bg_sprite;
        //Title Sprite
        sf::Sprite title_sprite;
        //Start Button Sprite
        sf::Sprite str_btn_sprite;
        //How to Play Button Sprite
        sf::Sprite howtop_btn_sprite;
        //Settings Button Sprite
        sf::Sprite settings_btn_sprite;
        //Credits Button Sprite
        sf::Sprite credits_btn_sprite;
        //High score Button Sprite
        sf::Sprite highscore_btn_sprite;
        //Exit Button Sprite
        sf::Sprite exit_btn_sprite;

        Gif_Loader *gf;
};

#endif // MAIN_MENU_H
