#include "AI_Winner_Screen.h"
#include "Screen_Manager.h"
#include "Main_Menu.h"
#include "Single_Player_Screen.h"
#include "HighscoreEngine.h"
#include <windows.h>
/*
    - This class hold the logic and presentation for Displaying the winner screen in the GUI
    - Much more presentation than logic and algorithms
*/
AI_Winner_Screen::AI_Winner_Screen(std::string name,std::string loc,int play1_score,int play2_score,std::string loc1)
{
    gf=new Gif_Loader("Images/Winner","winner",3,50);
    winner_name=name;
    winner_img=loc;
    this->player1_score=play1_score;
    this->player2_score=play2_score;
    image_loc_p1=loc1;
}

AI_Winner_Screen::~AI_Winner_Screen(){}


void AI_Winner_Screen::LoadContent(){

    win_pic.loadFromFile(winner_img);
    win_pic_sprite.setTexture(win_pic);
    win_pic_sprite.setScale(2,2);
    win_pic_sprite.setPosition(500,630);
    bg_sprite.setPosition(0,0);

    chubb_font.loadFromFile("Fonts/Chunkfive.otf");
    winner_text.setFont(chubb_font);
    winner_text.setString(winner_name);
    winner_text.setCharacterSize(120);
    winner_text.setPosition(380,115);
    winner_text.setColor(sf::Color::Blue);
    winner_text.setOutlineColor(sf::Color::White);
    winner_text.setOutlineThickness(2);

    back_btn.loadFromFile("Images/back_btn.png");
    back_btn_sprite.setTexture(back_btn);
    back_btn_sprite.setPosition(10,840);

    playagain_btn.loadFromFile("Images/playagain_btn.png");
    playagain_btn_sprite.setTexture(playagain_btn);
    playagain_btn_sprite.setPosition(230,840);

    addscore_btn.loadFromFile("Images/addscore_btn.png");
    addscore_btn_sprite.setTexture(addscore_btn);
    addscore_btn_sprite.setPosition(630,840);

    playerText.setFont(chubb_font);
    infoText.setFont(chubb_font);

    infoText.setString("Please Type Your Name");
    infoText.setPosition(690,690);

    playerText.setColor(sf::Color::Red);
    playerText.setOutlineColor(sf::Color::White);
    playerText.setOutlineThickness(2);
    playerText.setString(".....");
    playerText.setPosition(840,760);



}
void AI_Winner_Screen::UnloadContent(){}
void AI_Winner_Screen::Update(sf::RenderWindow &window,sf::Event event){
    l = gf->next();
    bg_sprite.setTexture(l);
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if((back_btn_sprite).getGlobalBounds().contains(mouse)){
                Screen_Manager::GetInst().addscreen(new Main_Menu);
                return;
        }else if((playagain_btn_sprite).getGlobalBounds().contains(mouse)){
                Screen_Manager::GetInst().addscreen(new Single_Player_Screen(image_loc_p1,player1_score,player2_score));
                return;
        }else if((addscore_btn_sprite).getGlobalBounds().contains(mouse)){
            HighscoreEngine *scoreWritter= new HighscoreEngine;
            (writePerm) ? (scoreWritter->writeFile(playerInput,this->player1_score) ) : 1;
            writePerm=0;
            return;
        }
    }else if (event.type == sf::Event::TextEntered){



        if(event.text.unicode == 8){
            playerInput=playerInput.substring(0,playerInput.getSize()-1);
        }else{
            playerInput +=event.text.unicode;
        }
        playerText.setString(playerInput);
        sf::sleep(sf::milliseconds(100));
        return;
    }
}
void AI_Winner_Screen::Draw(sf::RenderWindow &window){

    window.draw(bg_sprite);
    window.draw(win_pic_sprite);
    window.draw(winner_text);
    window.draw(back_btn_sprite);
    window.draw(playagain_btn_sprite);
    if(writePerm){
        window.draw(addscore_btn_sprite);
        window.draw(infoText);
        window.draw(playerText);

    }


}

