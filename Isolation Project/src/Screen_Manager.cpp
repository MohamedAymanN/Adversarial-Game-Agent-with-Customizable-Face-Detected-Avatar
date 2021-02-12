#include "Screen_Manager.h"
/*
    responsible for holding the instance of the active screen
*/
Game_Screen *currscreen, *newscreen;

Screen_Manager &Screen_Manager::GetInst(){
    static Screen_Manager object;
    return object;

}

Screen_Manager::Screen_Manager()
{

}

Screen_Manager::~Screen_Manager()
{

}

void Screen_Manager::initiate(){
    currscreen=new Main_Menu();
}

void Screen_Manager::LoadContent(){
    currscreen->LoadContent();
}

void Screen_Manager::Update(sf::RenderWindow &window,sf::Event event){
    currscreen->Update(window,event);
}

void Screen_Manager::Draw(sf::RenderWindow &Window){
    currscreen->Draw(Window);
}

void Screen_Manager::addscreen(Game_Screen *scrn){
    currscreen->UnloadContent();
    //delete currscreen;
    currscreen=scrn;
    LoadContent();
}
