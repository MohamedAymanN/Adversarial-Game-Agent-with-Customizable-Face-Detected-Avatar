#include "Main_Menu.h"
#include "Screen_Manager.h"
#include "Credits_Screen.h"
#include "Settings_Screen.h"
#include "StartGame_Screen.h"
#include "Howtop_Screen.h"
#include<iostream>
/*
    The Entrance Screen For the Game
*/
using namespace std;

Main_Menu::Main_Menu(){

    gf=new Gif_Loader("Images/Mainmenu","Mainmenu",8,70);
}

Main_Menu::~Main_Menu(){}

void Main_Menu::LoadContent(){

    bg_sprite.setPosition(0,0);


    title.loadFromFile("Images/title.png");
    str_btn.loadFromFile("Images/str_btn.png");
    str_btn_hover.loadFromFile("Images/str_btn_hover.png");
    howtop_btn.loadFromFile("Images/howtop_btn.png");
    howtop_btn_hover.loadFromFile("Images/howtop_btn_hover.png");
    credits_btn.loadFromFile("Images/credit_btn.png");
    credits_btn_hover.loadFromFile("Images/credit_btn_hover.png");
    highscore_btn.loadFromFile("Images/highscore_btn.png");
    highscore_btn_hover.loadFromFile("Images/highscore_btn_hover.png");
    exit_btn.loadFromFile("Images/exit_btn.png");
    exit_btn_hover.loadFromFile("Images/exit_btn_hover.png");



   // initializing the sprites textures and position

    title_sprite.setTexture(title);
    title_sprite.setScale(1.2,1.2);
    title_sprite.setPosition(180,40);




    str_btn_sprite.setPosition(430,200);

    howtop_btn_sprite.setPosition(420,350);

    credits_btn_sprite.setPosition(480,650);

    highscore_btn_sprite.setPosition(460,500);

    exit_btn_sprite.setPosition(540,800);



}

void Main_Menu::UnloadContent(){

}

void Main_Menu::checksprites(sf::RenderWindow *win){
        //check if a sprite is clicked
        sf::Vector2f mouse = win->mapPixelToCoords(sf::Mouse::getPosition(*win));

        if(str_btn_sprite.getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new StartGame_Screen);
            return;

        }else if(settings_btn_sprite.getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Settings_Screen);
            return;
        }else if(credits_btn_sprite.getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Credits_Screen);
            return;
        }else if(exit_btn_sprite.getGlobalBounds().contains(mouse)){
            win->close();
        }else if(howtop_btn_sprite.getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Howtop_Screen);
            return;
        }


}

void Main_Menu::checksprites_hover(sf::RenderWindow *win){
    sf::Vector2f mouse = win->mapPixelToCoords(sf::Mouse::getPosition(*win));

    //Check if a sprite is hovered or not.
    if(str_btn_sprite.getGlobalBounds().contains(mouse)){
        str_btn_sprite.setTexture(str_btn_hover);
    }else{
        str_btn_sprite.setTexture(str_btn);
    }

    if(settings_btn_sprite.getGlobalBounds().contains(mouse)){
        settings_btn_sprite.setTexture(settings_btn_hover);

    }else{
        settings_btn_sprite.setTexture(settings_btn);
    }

    if(credits_btn_sprite.getGlobalBounds().contains(mouse)){
        credits_btn_sprite.setTexture(credits_btn_hover);
    }
    else{
        credits_btn_sprite.setTexture(credits_btn);

    }
    if(exit_btn_sprite.getGlobalBounds().contains(mouse)){
        exit_btn_sprite.setTexture(exit_btn_hover);
    }

    else{
        exit_btn_sprite.setTexture(exit_btn);
    }
    if(howtop_btn_sprite.getGlobalBounds().contains(mouse)){
        howtop_btn_sprite.setTexture(howtop_btn_hover);
    }

    else{
        howtop_btn_sprite.setTexture(howtop_btn);
    }
    if(highscore_btn_sprite.getGlobalBounds().contains(mouse)){
        highscore_btn_sprite.setTexture(highscore_btn_hover);
    }

    else{
        highscore_btn_sprite.setTexture(highscore_btn);
    }


}


void Main_Menu::Update(sf::RenderWindow &window,sf::Event event){
    //Responsible for updating the window
    l = gf->next();
    bg_sprite.setTexture(l);
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        checksprites(&window);
    }
    try{
        checksprites_hover(&window);
    }catch(exception& e){


    }
}

void Main_Menu::Draw(sf::RenderWindow &window){
    //Draws the sprites to the screen
    window.draw(bg_sprite);
    window.draw(title_sprite);
    window.draw(str_btn_sprite);
    window.draw(howtop_btn_sprite);
    window.draw(credits_btn_sprite);
    window.draw(highscore_btn_sprite);
    window.draw(exit_btn_sprite);
}
