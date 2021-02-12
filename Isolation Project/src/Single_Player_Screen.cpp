#include "Single_Player_Screen.h"
#include "GameEngine.h"
#include "Screen_Manager.h"
#include "SingleP_CharSelect_Screen.h"
#include "AI_Winner_Screen.h"
#include "Campaign_CharSelect_Screen.h"
/*
    the Screen for the mod of Ultimate AI vs Human
*/
Single_Player_Screen::Single_Player_Screen(std::string loc,int p1_score,int p2_score)
{
    Campaign_CharSelect_Screen::AI_level=3;
    play1_score=p1_score;
    play2_score=p2_score;
    image_loc=loc;
}

Single_Player_Screen::~Single_Player_Screen(){

}

void Single_Player_Screen::LoadContent(){
    single_bg.loadFromFile("Images/single_bg.png");
    human_player.loadFromFile(image_loc+".png");
    cp_player.loadFromFile("Images/ai_terminator.png");
    blue_sqr.loadFromFile("Images/blue_box.png");
    flag_p1.loadFromFile(image_loc + "_flag.png");
    flag_ai.loadFromFile("Images/terminator_flag.png");
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
void Single_Player_Screen::count_down(){
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

void Single_Player_Screen::setloc(){
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

void Single_Player_Screen::UnloadContent(){}

void Single_Player_Screen::Update(sf::RenderWindow &window,sf::Event event){
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
                                std::string winner_player="AI Player";
                                std::string winner_player_img="Images/ai_terminator.png";
                                play2_score+=1;
                                Campaign_CharSelect_Screen::AI_level=0;
                                Screen_Manager::GetInst().addscreen(new AI_Winner_Screen(winner_player,winner_player_img,play1_score,play2_score,image_loc));
                                return;
                            }
                        }
                    }
            }
        }
        if(back_btn_sprite.getGlobalBounds().contains(pos.x,pos.y)){
            Campaign_CharSelect_Screen::AI_level=0;
            Screen_Manager::GetInst().addscreen(new Main_Menu);
            return;
        }

    }
    if(myEngine->activePlayer){
        if(myEngine->AIplay()){
            setloc();
        }else{
            setloc();
            std::string winner_player="Humans";
            std::string winner_player_img=image_loc+".png";
            play1_score+=1;
            Campaign_CharSelect_Screen::AI_level=0;
            Screen_Manager::GetInst().addscreen(new AI_Winner_Screen(winner_player,winner_player_img,play1_score,play2_score,image_loc));
            return;
        }
    }

}

void Single_Player_Screen::Draw(sf::RenderWindow &window){
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
