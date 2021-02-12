#include "Winner_Screen.h"
#include "Screen_Manager.h"
#include "Main_Menu.h"
#include "Multi_Player_Screen.h"
/*
    the Screen For Declaring the winner in: quick play => multiPlayer Mode
*/
Winner_Screen::Winner_Screen(std::string name,std::string loc,int play1_score,int play2_score,std::string loc1,std::string loc2)
{
    gf=new Gif_Loader("Images/Winner","winner",3,50);
    winner_name=name;
    winner_img=loc;
    this->player1_score=play1_score;
    this->player2_score=play2_score;
    image_loc_p1=loc1;
    image_loc_p2=loc2;
}

Winner_Screen::~Winner_Screen(){}


void Winner_Screen::LoadContent(){

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
    playagain_btn_sprite.setPosition(430,840);





}
void Winner_Screen::UnloadContent(){}
void Winner_Screen::Update(sf::RenderWindow &window,sf::Event event){
    l = gf->next();
    bg_sprite.setTexture(l);
    inp.Update(window,event);
    if(inp.mouse_left_clicked()){
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if((back_btn_sprite).getGlobalBounds().contains(mouse)){
                Screen_Manager::GetInst().addscreen(new Main_Menu);
        }else if((playagain_btn_sprite).getGlobalBounds().contains(mouse)){
                Screen_Manager::GetInst().addscreen(new Multi_Player_Screen(image_loc_p1,image_loc_p2,player1_score,player2_score));
        }
    }
}
void Winner_Screen::Draw(sf::RenderWindow &window){

    window.draw(bg_sprite);
    window.draw(win_pic_sprite);
    window.draw(winner_text);
    window.draw(back_btn_sprite);
    window.draw(playagain_btn_sprite);


}
