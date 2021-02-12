#include "Gif_Loader.h"
/*
    Encapsulating the Loading of the GIFS for Entire GUI
*/
Gif_Loader::Gif_Loader(std::string dir,std::string im, int count,int f_time)
{
    for(int i=0;i<count;i++){
        sf::Texture temp;

        std::ostringstream s0;
        s0<<i;
        std::string s (dir + "/" + im );
        temp.loadFromFile( s+s0.str()+".png");
        container.push_back(temp);
    }
    this->f_time=f_time;
}

Gif_Loader::Gif_Loader(){}
sf::Texture Gif_Loader::next(){
    if(aclock.getElapsedTime().asMilliseconds() > f_time){
      currentIndex = (currentIndex+1)%container.size();
      aclock.restart();
    }
    return container[currentIndex];
}
Gif_Loader::~Gif_Loader(){}
