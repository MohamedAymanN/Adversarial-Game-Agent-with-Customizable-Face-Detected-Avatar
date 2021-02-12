#ifndef GIF_LOADER_H
#define GIF_LOADER_H
#include "Game_Screen.h"
#include <bits/stdc++.h>
class Gif_Loader : public Game_Screen
{
    public:
        Gif_Loader(std::string,std::string, int count,int f_time);
        Gif_Loader();
        ~Gif_Loader();
        sf::Texture next();
         std::vector<sf::Texture> container;
    protected:

    private:
        int currentIndex=0;
        int f_time;
        sf::Clock aclock;

};

#endif // GIF_LOADER_H
