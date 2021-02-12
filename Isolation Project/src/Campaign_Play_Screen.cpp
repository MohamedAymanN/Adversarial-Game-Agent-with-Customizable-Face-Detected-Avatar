#include "Campaign_Play_Screen.h"
#include "Single_Player_Screen.h"
#include "GameEngine.h"
#include "Screen_Manager.h"
#include "SingleP_CharSelect_Screen.h"
#include "AI_Winner_Screen.h"
#include "Tourny_Winner_Screen.h"
#include "Campaign_CharSelect_Screen.h"
#include <windows.h>
/*
    The Playing Screen for the Campaign Mode
*/
Campaign_Play_Screen::Campaign_Play_Screen(std::string loc)
{
    image_loc=loc;
}

Campaign_Play_Screen::~Campaign_Play_Screen(){}

void Campaign_Play_Screen::LoadContent(){
    single_bg.loadFromFile("Images/single_bg.png");
    human_player.loadFromFile(image_loc+".png");
    cp_player.loadFromFile(AI_images[Campaign_CharSelect_Screen::AI_level]);
    blue_sqr.loadFromFile("Images/blue_box.png");
    flag_p1.loadFromFile(image_loc + "_flag.png");
    flag_ai.loadFromFile("Images/shit.png");
    back_btn.loadFromFile("Images/back_btn.png");
    countd_font.loadFromFile("Fonts/Chunkfive.otf");


    single_bg_sprite.setTexture(single_bg);
    single_bg_sprite.setTextureRect(sf::IntRect(0,0,1200,950));

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
    turn_text.setString("You");
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

    human_player_sprite.setTexture(human_player);

    cp_player_sprite.setTexture(cp_player);

    setloc();



}
void Campaign_Play_Screen::count_down(){
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

void Campaign_Play_Screen::setloc(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            char temp=board[i][j];
            if(temp=='2'){
                cp_player_sprite.setPosition(loc[i][j].first,loc[i][j].second);
            }else if(temp=='1'){
                human_player_sprite.setPosition(loc[i][j].first,loc[i][j].second);
            }else if(temp=='f'){
                    spr[i][j].setTexture(flag_p1);
            }else if(temp=='g'){
                    spr[i][j].setTexture(flag_ai);
            }
            spr[i][j].setPosition(box_loc[i][j].first - 130,box_loc[i][j].second);


        }
    }
}

void Campaign_Play_Screen::UnloadContent(){}

void Campaign_Play_Screen::Update(sf::RenderWindow &window,sf::Event event){
    count_down();
    inp.Update(window,event);
    sf::Vector2i pos=sf::Mouse::getPosition(window);
    if(inp.mouse_left_clicked()){

        for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                    if(spr[i][j].getGlobalBounds().contains(pos.x,pos.y)){
                        if(!(myEngine->activePlayer)){
                            if(myEngine->humanPlay(i,j)){
                                setloc();
                            }else{
                                setloc();
                                Campaign_CharSelect_Screen::AI_level=0;
                                MessageBoxA(NULL, "You lost :( ,better luck next time", "Ma3luuuuuuush", MB_OK | MB_ICONEXCLAMATION);
                                Screen_Manager::GetInst().addscreen(new Main_Menu);
                                return;
                            }
                        }
                    }
            }
        }
        if(back_btn_sprite.getGlobalBounds().contains(pos.x,pos.y)){
            Screen_Manager::GetInst().addscreen(new Main_Menu);
            return;
        }

    }
    if(myEngine->activePlayer){
        if(myEngine->AIplay()){
            setloc();
        }else{
            setloc();
            if(Campaign_CharSelect_Screen::AI_level < 3){
                MessageBoxA(NULL, "You Won Get Ready", "WINNER!!!", MB_OK | MB_ICONEXCLAMATION);
                Campaign_CharSelect_Screen::AI_level++;
                Screen_Manager::GetInst().addscreen(new Campaign_Play_Screen(image_loc));
                return;
            }else{
                Campaign_CharSelect_Screen::AI_level=0;
                Screen_Manager::GetInst().addscreen(new Tourny_Winner_Screen);
                return;
            }


        }
    }

}

void Campaign_Play_Screen::Draw(sf::RenderWindow &window){
    window.draw(single_bg_sprite);

    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            window.draw(spr[i][j]);
        }
    }
    window.draw(human_player_sprite);
    window.draw(cp_player_sprite);
    window.draw(back_btn_sprite);
    window.draw(countd_text);
    window.draw(score_text);
    window.draw(turn_text);

}

