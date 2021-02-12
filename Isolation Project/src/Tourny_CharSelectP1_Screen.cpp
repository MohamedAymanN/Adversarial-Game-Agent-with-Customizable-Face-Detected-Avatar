#include "Tourny_CharSelectP1_Screen.h"
#include "Screen_Manager.h"
#include "Main_Menu.h"
#include "Tourny_CharSelectP2_Screen.h"
/*
    Choose the Avatar for Player 1 in the tournament
*/
Tourny_CharSelectP1_Screen::Tourny_CharSelectP1_Screen(){}

Tourny_CharSelectP1_Screen::~Tourny_CharSelectP1_Screen(){}

void Tourny_CharSelectP1_Screen::LoadContent(){
    bg.loadFromFile("Images/SingleP_selection_bg.png");
    back_btn.loadFromFile("Images/back_btn.png");
    prev_btn.loadFromFile("Images/prev_btn.png");
    bala7a_player.loadFromFile("Images/select_bala7a.png");
    kim_player.loadFromFile("Images/select_kim.png");
    putin_player.loadFromFile("Images/select_putin.png");
    sadam_player.loadFromFile("Images/select_sadam.png");
    sharron_player.loadFromFile("Images/select_sharon.png");
    trump_player.loadFromFile("Images/select_trump.png");

    bg_sprite.setTexture(bg);
    bg_sprite.setTextureRect(sf::IntRect(0,0,1200,950));

    back_btn_sprite.setTexture(back_btn);
    back_btn_sprite.setPosition(110,840);

    prev_btn_sprite.setTexture(prev_btn);
    prev_btn_sprite.setPosition(10,840);

    bala7a_player_sprite.setTexture(bala7a_player);
    bala7a_player_sprite.setPosition(170,220);

    kim_player_sprite.setTexture(kim_player);
    kim_player_sprite.setPosition(350,220);

    putin_player_sprite.setTexture(putin_player);
    putin_player_sprite.setPosition(700,220);

    sadam_player_sprite.setTexture(sadam_player);
    sadam_player_sprite.setPosition(880,220);

    sharron_player_sprite.setTexture(sharron_player);
    sharron_player_sprite.setPosition(350,520);

    trump_player_sprite.setTexture(trump_player);
    trump_player_sprite.setPosition(700,520);



}

void Tourny_CharSelectP1_Screen::UnloadContent(){}

void Tourny_CharSelectP1_Screen::Update(sf::RenderWindow &window,sf::Event event){
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if((bala7a_player_sprite).getGlobalBounds().contains(mouse)){
            system("D:");
            system("cd D:\\Fall 18\\ECEN-501\\Projects\\Isolation\ Project\\src");
            system("py \"D:\\Fall\ 18\\ECEN-501\\Projects\\Isolation\ Project\\src\\FD_Gui.py\" 1");
            Screen_Manager::GetInst().addscreen(new Tourny_CharSelectP2_Screen("Images/pf1"));
        }else if((kim_player_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Tourny_CharSelectP2_Screen("Images/kim_player"));
        }else if((putin_player_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Tourny_CharSelectP2_Screen("Images/putin_player"));
        }else if((sadam_player_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Tourny_CharSelectP2_Screen("Images/sadam_player"));
        }else if((sharron_player_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Tourny_CharSelectP2_Screen("Images/sharon_player"));
        }else if((trump_player_sprite).getGlobalBounds().contains(mouse)){
            Screen_Manager::GetInst().addscreen(new Tourny_CharSelectP2_Screen("Images/trump_player"));
        }
    }

}

void Tourny_CharSelectP1_Screen::Draw(sf::RenderWindow &window){
    window.draw(bg_sprite);
    window.draw(bala7a_player_sprite);
    window.draw(kim_player_sprite);
    window.draw(putin_player_sprite);
    window.draw(sadam_player_sprite);
    window.draw(sharron_player_sprite);
    window.draw(trump_player_sprite);
}

