#ifndef Howtop_Screen_H
#define Howtop_Screen_H
#include "Game_Screen.h"

class Howtop_Screen : public Game_Screen
{
    public:
        Howtop_Screen();
        ~Howtop_Screen();
        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);

    protected:

    private:
        sf::Texture bg;
        sf::Sprite bg_sprite;
        sf::Texture back_btn;
        sf::Sprite back_btn_sprite;
};

#endif // Howtop_Screen_H
