#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H
#include "Game_Screen.h"
#include "Main_Menu.h"

class Screen_Manager
{
    public:
        ~Screen_Manager();
        static Screen_Manager &GetInst();
        void initiate();
        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);
        void addscreen(Game_Screen *scrn);



    protected:
    private:
        Screen_Manager();
        Screen_Manager(Screen_Manager const&);
        void operator=(Screen_Manager const&);

};

#endif // SCREEN_MANAGER_H
