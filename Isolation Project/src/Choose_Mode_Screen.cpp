#include "Choose_Mode_Screen.h"
#include "Main_Menu.h"
#include "Screen_Manager.h"
#include "Single_Player_Screen.h"
#include "Multi_Player_Screen.h"
#include "SingleP_CharSelect_Screen.h"
#include "MultiP_CharSelectP1_Screen.h"
/*
    The screen For choosing single or multi-player in the quick game mode
*/
Choose_Mode_Screen::Choose_Mode_Screen(){}

Choose_Mode_Screen::~Choose_Mode_Screen(){}

void Choose_Mode_Screen::checksprites_hover(sf::RenderWindow *win){
    sf::Vector2f mouse = win->mapPixelToCoords(sf::Mouse::getPosition(*win));

    if((single_btn_sprite).getGlobalBounds().contains(mouse)){
        single_btn_sprite.setTexture(single_btn_hover);
    }else{
        single_btn_sprite.setTexture(single_btn);
    }

    if((multi_btn_sprite).getGlobalBounds().contains(mouse)){
        multi_btn_sprite.setTexture(Multi_btn_hover);
    }else{
        multi_btn_sprite.setTexture(Multi_btn);
    }


}
void Choose_Mode_Screen::LoadContent(){

    bg.loadFromFile("Images/bg.jpg");
    back_btn.loadFromFile("Images/back_btn.png");
    single_btn.loadFromFile("Images/single_btn.png");
    single_btn_hover.loadFromFile("Images/single_btn_hover.png");
    Multi_btn.loadFromFile("Images/multi_btn.png");
    Multi_btn_hover.loadFromFile("Images/multi_btn_hover.png");

    bgsprite.setTexture(bg);
    bgsprite.setTextureRect(sf::IntRect(0,0,1200,950));

    back_btn_sprite.setTexture(back_btn);
    single_btn_sprite.setTexture(single_btn);
    multi_btn_sprite.setTexture(Multi_btn);

    back_btn_sprite.setPosition(10,840);
    single_btn_sprite.setPosition(380,330);
    multi_btn_sprite.setPosition(400,530);

}

void Choose_Mode_Screen::UnloadContent(){}

void Choose_Mode_Screen::Update(sf::RenderWindow &window,sf::Event event){
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if((back_btn_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Main_Menu);
        }else if((single_btn_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new SingleP_CharSelect_Screen);
        }else if((multi_btn_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new MultiP_CharSelectP1_Screen);
        }
    }
    checksprites_hover(&window);


}

void Choose_Mode_Screen::Draw(sf::RenderWindow &window){
    window.draw(bgsprite);
    window.draw(back_btn_sprite);
    window.draw(single_btn_sprite);
    window.draw(multi_btn_sprite);
}
