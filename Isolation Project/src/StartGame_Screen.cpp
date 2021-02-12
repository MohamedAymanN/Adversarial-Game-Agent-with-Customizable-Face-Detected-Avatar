#include "StartGame_Screen.h"
#include "Choose_Mode_Screen.h"
#include "Screen_Manager.h"
#include "Tournament_init_Screen.h"
#include "Campaign_CharSelect_Screen.h"
#include "RL_Screen.h"
/*
    The screen that hold all the Other modes
    Quick play: single player "Human VS AI" or multi-player "two human player"
    Campaign: the human player plays against All the AI ordered in their difficulty level
    Tournament: Create and manage A Tournament between multi Human player
*/
StartGame_Screen::StartGame_Screen(){}

StartGame_Screen::~StartGame_Screen(){}

void StartGame_Screen::checksprites_hover(sf::RenderWindow *win){
    sf::Vector2f mouse = win->mapPixelToCoords(sf::Mouse::getPosition(*win));

    if((quickplay_btn_sprite).getGlobalBounds().contains(mouse)){
        quickplay_btn_sprite.setTexture(quickplay_hover);
    }else{
        quickplay_btn_sprite.setTexture(quickplay_btn);
    }

    if((campaign_btn_sprite).getGlobalBounds().contains(mouse)){
        campaign_btn_sprite.setTexture(campaign_hover);
    }else{
        campaign_btn_sprite.setTexture(campaign_btn);
    }

    if((tournement_btn_sprite).getGlobalBounds().contains(mouse)){
        tournement_btn_sprite.setTexture(tournement_hover);
    }else{
        tournement_btn_sprite.setTexture(tournement_btn);
    }
}

void StartGame_Screen::LoadContent(){

    bg.loadFromFile("Images/bg.jpg");
    back_btn.loadFromFile("Images/back_btn.png");
    quickplay_btn.loadFromFile("Images/quickplay_btn.png");
    quickplay_hover.loadFromFile("Images/quickplay_btn_hover.png");

    campaign_btn.loadFromFile("Images/campaign_btn.png");
    campaign_hover.loadFromFile("Images/campaign_btn_hover.png");

    tournement_btn.loadFromFile("Images/Tournament_btn.png");
    tournement_hover.loadFromFile("Images/Tournament_btn_hover.png");

    rl_btn.loadFromFile("Images/RL_btn.png");


    bgsprite.setTexture(bg);
    bgsprite.setTextureRect(sf::IntRect(0,0,1200,950));

    back_btn_sprite.setTexture(back_btn);
    rl_btn_sprite.setTexture(rl_btn);


    back_btn_sprite.setPosition(10,840);
    quickplay_btn_sprite.setPosition(420,200);
    campaign_btn_sprite.setPosition(420,400);
    tournement_btn_sprite.setPosition(420,600);
    rl_btn_sprite.setPosition(420,800);

}

void StartGame_Screen::UnloadContent(){}

void StartGame_Screen::Update(sf::RenderWindow &window,sf::Event event){
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if((back_btn_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Main_Menu);
            return;
        }else if((quickplay_btn_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Choose_Mode_Screen);
            return;
        }else if((campaign_btn_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Campaign_CharSelect_Screen);
            return;
        }else if((tournement_btn_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Tournament_init_Screen);
            return;
        }else if((rl_btn_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new RL_Screen);
            return;
        }
    }
    try{
        checksprites_hover(&window);
    }catch(std::exception& e){

    }

}

void StartGame_Screen::Draw(sf::RenderWindow &window){
    window.draw(bgsprite);
    window.draw(back_btn_sprite);
    window.draw(quickplay_btn_sprite);
    window.draw(campaign_btn_sprite);
    window.draw(tournement_btn_sprite);
    window.draw(rl_btn_sprite);
}
