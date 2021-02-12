#include "Tournament_Play_Screen.h"
#include "Vs_Screen.h"
#include "Tournament_init_Screen.h"
#include "GameEngine.h"
#include "Screen_Manager.h"
#include "Main_Menu.h"
#include "Winner_Screen.h"
#include "Tourny_Winner_Screen.h"
#include <windows.h>
#include <string>
#include <iostream>
/*
  The screen for managing A game in the Tournament
*/
Tournament_Play_Screen::Tournament_Play_Screen(std::string loc1,std::string loc2,int p1_score,int p2_score)
{
    play1_score=p1_score;
    play2_score=p2_score;
    image_loc_p1=loc1;
    image_loc_p2=loc2;
}

Tournament_Play_Screen::~Tournament_Play_Screen(){}

void Tournament_Play_Screen::LoadContent(){
    single_bg.loadFromFile("Images/single_bg.png");
    countd_font.loadFromFile("Fonts/Chunkfive.otf");
    back_btn.loadFromFile("Images/back_btn.png");
    player1_char.loadFromFile(image_loc_p1+".png");
    player2_char.loadFromFile(image_loc_p2+".png");
    blue_sqr.loadFromFile("Images/blue_box.png");
    black_sqr.loadFromFile("Images/black_box.png");
    green_sqr.loadFromFile("Images/green_box.png");
    flag_p1.loadFromFile(image_loc_p1 + "_flag.png");
    flag_p2.loadFromFile(image_loc_p2 + "_flag.png");


    countd_text.setFont(countd_font);
    countd_text.setString((minut+":"+sec));
    countd_text.setCharacterSize(40);
    countd_text.setPosition(1060,280);
    countd_text.setColor(sf::Color::Blue);

    std::string p1score (1,'0'+play1_score);
    std::string p2score (1,'0'+play2_score);

    score_text.setFont(countd_font);
    score_text.setString(p1score+" - "+p2score);
    score_text.setCharacterSize(40);
    score_text.setPosition(1055,115);
    score_text.setColor(sf::Color::Blue);

    turn_text.setFont(countd_font);
    turn_text.setString("Player 1");
    turn_text.setCharacterSize(23);
    turn_text.setPosition(1055,440);
    turn_text.setColor(sf::Color::Blue);

    single_bg_sprite.setTexture(single_bg);
    single_bg_sprite.setTextureRect(sf::IntRect(0,0,1200,950));

    back_btn_sprite.setTexture(back_btn);
    back_btn_sprite.setPosition(1070,840);

    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            spr[i][j].setTexture(blue_sqr);
        }

    }

    player1_char_sprite.setTexture(player1_char);

    player2_char_sprite.setTexture(player2_char);

    setloc();


}
void Tournament_Play_Screen::setloc(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            char temp=board[i][j];
            if(temp=='2'){
                player2_char_sprite.setPosition(loc[i][j].first,loc[i][j].second);
            }else if(temp=='1'){
                player1_char_sprite.setPosition(loc[i][j].first,loc[i][j].second);
            }else if(temp=='f'){
                    spr[i][j].setTexture(flag_p1);
            }else if(temp=='g'){
                    spr[i][j].setTexture(flag_p2);
            }
            spr[i][j].setPosition(box_loc[i][j].first - 130,box_loc[i][j].second);


        }
    }
}

void Tournament_Play_Screen::highlight_legal_moves(bool high){
    pair<int, int>*p;
    if(myEngine->activePlayer){
        p=&(myEngine->currentPos1);
        turn_text.setString("Player 2");
    }else{
        p=&(myEngine->currentPos2);
        turn_text.setString("Player 1");
    }
    if(high){
        myEngine->getLegalMoves(legal_moves,*p);
    }

    for(auto f : legal_moves) {
        int first=(f).first;
        int second=(f).second;

        if(high && myEngine->activePlayer){
            spr[first][second].setTexture(black_sqr);
        }else if(high && !(myEngine->activePlayer)){
            spr[first][second].setTexture(green_sqr);
        }
        else{
            spr[first][second].setTexture(blue_sqr);
        }

    }

}

void Tournament_Play_Screen::UnloadContent(){}

void Tournament_Play_Screen::count_down(){
    std::ostringstream fsec,fmin;
    timer=ceil(seconds_cd-(clock.getElapsedTime().asSeconds()));
    fsec<<timer;
    fmin<<min_cd;
    sec=fsec.str();
    minut=fmin.str();
    sec= sec.length()<2 ? "0"+sec : sec;
    countd_text.setString(minut+":"+sec);
    if(min_cd!=0 && timer==-1){
        clock.restart();
        min_cd--;
        seconds_cd=59;
    }

}
void Tournament_Play_Screen::Update(sf::RenderWindow &window,sf::Event event){
    count_down();
    inp.Update(window,event);
    sf::Vector2i pos=sf::Mouse::getPosition(window);

    highlight_legal_moves(true);
    if(inp.mouse_left_clicked()){
        for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                if(spr[i][j].getGlobalBounds().contains(pos.x,pos.y)){
                    if(!myEngine->move(make_pair(i,j))){
                        if(myEngine->activePlayer){
                            int firstwin=Vs_Screen::firstP;
                            std::string fwin;
                            sStream<<firstwin;
                            sStream>>fwin;
                            fwin="Player "+fwin;
                            MessageBoxA(NULL,fwin.c_str(),"The Winner is !!!", MB_OK | MB_ICONEXCLAMATION);
                            Tournament_init_Screen::tourny_players.push_back(firstwin);
                        }else{
                            int secondwin=Vs_Screen::secondP;
                            std::string swin;
                            sStream<<secondwin;
                            sStream>>swin;
                            swin="Player "+swin;
                            MessageBoxA(NULL, swin.c_str(),"The Winner is !!!", MB_OK | MB_ICONEXCLAMATION);
                            Tournament_init_Screen::tourny_players.push_back(secondwin);
                        }
                        if(Tournament_init_Screen::tourny_players.size()==1){
                            Tournament_init_Screen::tourny_players.pop_front();
                            Screen_Manager::GetInst().addscreen(new Tourny_Winner_Screen);
                        }else{
                            Screen_Manager::GetInst().addscreen(new Vs_Screen);
                        }

                        return;

                    }else{
                        highlight_legal_moves(false);
                        legal_moves.clear();
                    }
                    setloc();

                }
            }
        }
        if((back_btn_sprite).getGlobalBounds().contains(pos.x,pos.y)){
            Screen_Manager::GetInst().addscreen(new Main_Menu);
        }

    }
}

void Tournament_Play_Screen::Draw(sf::RenderWindow &window){
    window.draw(single_bg_sprite);
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
                window.draw(spr[i][j]);

        }
    }
    window.draw(player1_char_sprite);
    window.draw(player2_char_sprite);
    window.draw(back_btn_sprite);
    window.draw(countd_text);
    window.draw(score_text);
    window.draw(turn_text);
}

