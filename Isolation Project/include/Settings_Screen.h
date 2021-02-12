#ifndef SETTINGS_SCREEN_H
#define SETTINGS_SCREEN_H
#include "Game_Screen.h"


class Settings_Screen : public Game_Screen
{
    public:
        Settings_Screen();
        ~Settings_Screen();
        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);

    protected:

    private:
        sf::Texture back_btn;
        sf::Sprite back_btn_sprite;
};

#endif // SETTINGS_SCREEN_H
