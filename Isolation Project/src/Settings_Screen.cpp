#include "Settings_Screen.h"
#include "Main_Menu.h"
#include "Screen_Manager.h"
/*
    not implemented
    supposed to container the setting of the game
*/
Settings_Screen::Settings_Screen(){}

Settings_Screen::~Settings_Screen(){}

void Settings_Screen::LoadContent(){
    back_btn.loadFromFile("Images/back_btn.png");

    back_btn_sprite.setTexture(back_btn);

    back_btn_sprite.setPosition(10,840);

}

void Settings_Screen::UnloadContent(){}

void Settings_Screen::Update(sf::RenderWindow &window,sf::Event event){
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if((back_btn_sprite).getGlobalBounds().contains(mouse)){
                Screen_Manager::GetInst().addscreen(new Main_Menu);
        }
    }


}

void Settings_Screen::Draw(sf::RenderWindow &window){
    window.draw(back_btn_sprite);
}
