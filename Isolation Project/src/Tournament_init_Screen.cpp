#include "Tournament_init_Screen.h"
#include "Screen_Manager.h"
#include "Vs_Screen.h"
#include <windows.h>
#include<string>
#include<deque>
#include<SFML/System.hpp>
#include <ctime>
/*
    The screen For Entering the number of Participants in the tournament
*/
std::deque<int> Tournament_init_Screen::tourny_players;
Tournament_init_Screen::Tournament_init_Screen(){}

Tournament_init_Screen::~Tournament_init_Screen(){}

int myrandom(int i){
    std::time_t result = std::time(nullptr);
    std::asctime(std::localtime(&result));
    return result%i;
}

void Tournament_init_Screen::initQueue(){
    std::string currText=playerText.getString();
    std::stringstream convert(currText);
    int currNum;
    convert>>currNum;
    if(currNum>1){
        for(int i=1;i<=currNum;i++){
            tourny_players.push_back(i);
        }
        std::random_shuffle(tourny_players.begin(), tourny_players.end(),myrandom);
        Screen_Manager::GetInst().addscreen(new Vs_Screen);
        return;
    }else{
        MessageBoxA(NULL, "Please Enter a Number bigger than 1", "Watch Out, Watch Out", MB_OK | MB_ICONEXCLAMATION);
    }


}

void Tournament_init_Screen::LoadContent(){

    bg.loadFromFile("Images/bg.jpg");
    back_btn.loadFromFile("Images/back_btn.png");
    start_btn.loadFromFile("Images/starttour_btn.png");


    bgsprite.setTexture(bg);
    bgsprite.setTextureRect(sf::IntRect(0,0,1200,950));

    back_btn_sprite.setTexture(back_btn);
    start_btn_sprite.setTexture(start_btn);


    back_btn_sprite.setPosition(10,840);
    start_btn_sprite.setPosition(300,600);

    chubb_font.loadFromFile("Fonts/Chunkfive.otf");
    playerText.setFont(chubb_font);
    infoText.setFont(chubb_font);

    infoText.setString("Please Type The Specified Number Of Players");
    infoText.setPosition(260,400);

    playerText.setColor(sf::Color::Red);
    playerText.setOutlineColor(sf::Color::White);
    playerText.setOutlineThickness(2);
    playerText.setString(".....");
    playerText.setPosition(580,500);

}

void Tournament_init_Screen::UnloadContent(){}

void Tournament_init_Screen::Update(sf::RenderWindow &window,sf::Event event){
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if((back_btn_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Main_Menu);
            return;
        }else if((start_btn_sprite).getGlobalBounds().contains(mouse)){
            initQueue();
            return;
        }
    }else if (event.type == sf::Event::TextEntered){

        if(event.text.unicode>47 && event.text.unicode<58){
           playerInput +=event.text.unicode;
        }else if(event.text.unicode == 8){
            playerInput=playerInput.substring(0,playerInput.getSize()-1);
        }
        playerText.setString(playerInput);
        sf::sleep(sf::milliseconds(100));
        return;
    }

}

void Tournament_init_Screen::Draw(sf::RenderWindow &window){
    window.draw(bgsprite);
    window.draw(back_btn_sprite);
    window.draw(start_btn_sprite);
    window.draw(infoText);
    window.draw(playerText);
}
