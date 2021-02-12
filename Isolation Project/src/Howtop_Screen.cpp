#include "Howtop_Screen.h"
#include "Screen_Manager.h"
#include "Main_Menu.h"
/*
    Instruction on how to play the Game
*/
Howtop_Screen::Howtop_Screen(){}

Howtop_Screen::~Howtop_Screen(){}

void Howtop_Screen::LoadContent(){
    bg.loadFromFile("Images/howtoplay.png");
    back_btn.loadFromFile("Images/back_btn.png");

    bg_sprite.setTexture(bg);
    bg_sprite.setPosition(0,0);

    back_btn_sprite.setTexture(back_btn);
    back_btn_sprite.setPosition(10,840);


}

void Howtop_Screen::UnloadContent(){}

void Howtop_Screen::Update(sf::RenderWindow &window,sf::Event event){
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if((back_btn_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Main_Menu);
        }
    }
}

void Howtop_Screen::Draw(sf::RenderWindow &window){
    window.draw(bg_sprite);
    window.draw(back_btn_sprite);

}
