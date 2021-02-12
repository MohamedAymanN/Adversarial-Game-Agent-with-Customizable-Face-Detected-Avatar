#include "Credits_Screen.h"
#include "Main_Menu.h"
#include "Screen_Manager.h"
/*
    This is our Screen 😁😁😁😁😁😁😁 the credits for the creators of the Project
*/
Credits_Screen::Credits_Screen(){}

Credits_Screen::~Credits_Screen(){}

void Credits_Screen::LoadContent(){
    bg.loadFromFile("Images/Credits.png");
    back_btn.loadFromFile("Images/back_btn.png");

    bgsprite.setTexture(bg);
    back_btn_sprite.setTexture(back_btn);

    bgsprite.setTextureRect(sf::IntRect(0,0,1200,950));
    back_btn_sprite.setPosition(10,840);

}

void Credits_Screen::UnloadContent(){}

void Credits_Screen::Update(sf::RenderWindow &window,sf::Event event){
    //Responsible for Updating the Window
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if((back_btn_sprite).getGlobalBounds().contains(mouse)){
                Screen_Manager::GetInst().addscreen(new Main_Menu);
        }
    }

}

void Credits_Screen::Draw(sf::RenderWindow &window){
    //Responsible for Drawing to the screen
    window.draw(bgsprite);
    window.draw(back_btn_sprite);
}
