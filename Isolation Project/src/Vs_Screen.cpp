#include "Vs_Screen.h"
#include<iostream>
#include "Screen_Manager.h"
#include "Tournament_init_Screen.h"
#include "Tourny_CharSelectP1_Screen.h"
#include<string>
#include<sstream>
/*
    The screen That declare The IDs of the Player Participating in the next round of the game
*/
int Vs_Screen::firstP=0;
int Vs_Screen::secondP=0;

Vs_Screen::Vs_Screen()
{
    firstP=Tournament_init_Screen::tourny_players.front();
    Tournament_init_Screen::tourny_players.pop_front();

    secondP=Tournament_init_Screen::tourny_players.front();
    Tournament_init_Screen::tourny_players.pop_front();


}

Vs_Screen::~Vs_Screen(){}


void Vs_Screen::LoadContent(){
    bg.loadFromFile("Images/bg.jpg");
    continue_btn.loadFromFile("Images/continue_btn.png");

    continue_btn_sprite.setTexture(continue_btn);
    continue_btn_sprite.setPosition(500,600);

    bgsprite.setTexture(bg);
    bgsprite.setTextureRect(sf::IntRect(0,0,1200,950));

    chubb_font.loadFromFile("Fonts/Chunkfive.otf");

    first_player.setFont(chubb_font);
    second_player.setFont(chubb_font);

    std::stringstream stringF,stringS;

    std::string f;
    std::string s;

    stringF<< firstP;
    stringF >> f;

    stringS << secondP;
    stringS >> s;

    first_player.setString("Player " + f);
    first_player.setPosition(260,400);

    second_player.setString("Player " + s);
    second_player.setPosition(260,600);

}

void Vs_Screen::UnloadContent(){}

void Vs_Screen::Update(sf::RenderWindow &window,sf::Event event){
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if((continue_btn_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Tourny_CharSelectP1_Screen);
        }
    }


}
void Vs_Screen::Draw(sf::RenderWindow &window){
    window.draw(bgsprite);
    window.draw(first_player);
    window.draw(second_player);
    window.draw(continue_btn_sprite);

}
