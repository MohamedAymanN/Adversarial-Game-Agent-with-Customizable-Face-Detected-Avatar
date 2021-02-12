#include "Tourny_Winner_Screen.h"
#include "Screen_Manager.h"
#include "Main_Menu.h"
/*
    The screen At which The Tournament Winner is declared :D
*/
Tourny_Winner_Screen::Tourny_Winner_Screen()
{
    gf=new Gif_Loader("Images/tourny","tourny",121,50);
}

Tourny_Winner_Screen::~Tourny_Winner_Screen(){}


void Tourny_Winner_Screen::LoadContent(){


    bg_sprite.setPosition(0,0);


    back_btn.loadFromFile("Images/back_btn.png");
    back_btn_sprite.setTexture(back_btn);
    back_btn_sprite.setPosition(10,840);




}
void Tourny_Winner_Screen::UnloadContent(){}

void Tourny_Winner_Screen::Update(sf::RenderWindow &window,sf::Event event){
    l = gf->next();
    bg_sprite.setTexture(l);
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if((back_btn_sprite).getGlobalBounds().contains(mouse)){
                Screen_Manager::GetInst().addscreen(new Main_Menu);
        }
    }
}
void Tourny_Winner_Screen::Draw(sf::RenderWindow &window){

    window.draw(bg_sprite);
    window.draw(back_btn_sprite);


}
