#ifndef MULTI_PLAYER_SCREEN_H
#define MULTI_PLAYER_SCREEN_H
#include "Game_Screen.h"
#include <string>
#include <utility>
#include <iostream>
#include<sstream>
#include<math.h>
#include "GameEngine.h"
using namespace std;

class Multi_Player_Screen : public Game_Screen
{
    public:
        Multi_Player_Screen(std::string img_loc_p1,std::string img_loc_p2,int p1_score=0,int p2_score=0);
        ~Multi_Player_Screen();
        void LoadContent();
        void UnloadContent();
        void Update(sf::RenderWindow &window,sf::Event event);
        void Draw(sf::RenderWindow &window);
        void setloc();
        void highlight_legal_moves(bool);
        void count_down();
    protected:

    private:
        int play1_score,play2_score;
        int timer;
        int min_cd=5,seconds_cd=0;
        sf::Clock clock;
        bool moving=false;
        int dx,dy;
        std::string minut="5",sec="00";
        int board_row=6,board_col=3;
        std::string image_loc_p1;
        std::string image_loc_p2;
        sf::Texture single_bg;
        sf::Texture player1_char;
        sf::Texture player2_char;
        sf::Texture blue_sqr;
        sf::Texture black_sqr;
        sf::Texture green_sqr;
        sf::Texture flag_p1;
        sf::Texture flag_p2;
        sf::Texture back_btn;

        sf::Font countd_font;
        sf::Text countd_text;
        sf::Text score_text;
        sf::Text turn_text;

        sf::Sprite single_bg_sprite;
        sf::Sprite player1_char_sprite;
        sf::Sprite player2_char_sprite;
        sf::Sprite blue_sqr_sprite;
        sf::Sprite back_btn_sprite;
        sf::Sprite spr[7][7];
        set<pair<int,int> >legal_moves;
        GameEngine *myEngine = new GameEngine(7,7,false,'2', '1');
        vector< vector<char> > &board = myEngine->board;



        pair<int,int> loc[7][7]={{make_pair(40,20),make_pair(190,20),make_pair(335,20),make_pair(480,20),make_pair(630,20),make_pair(775,20),make_pair(920,20)},
                                 {make_pair(40,150),make_pair(190,150),make_pair(335,150),make_pair(480,150),make_pair(630,150),make_pair(775,150),make_pair(920,150)},
                                 {make_pair(40,290),make_pair(190,290),make_pair(330,290),make_pair(480,290),make_pair(630,290),make_pair(780,290),make_pair(920,290)},
                                 {make_pair(40,420),make_pair(190,420),make_pair(330,420),make_pair(480,420),make_pair(630,420),make_pair(780,420),make_pair(920,420)},
                                 {make_pair(40,560),make_pair(190,560),make_pair(330,560),make_pair(480,560),make_pair(630,560),make_pair(780,560),make_pair(920,560)},
                                 {make_pair(40,690),make_pair(190,690),make_pair(330,690),make_pair(480,690),make_pair(630,690),make_pair(780,690),make_pair(920,690)},
                                 {make_pair(40,820),make_pair(190,820),make_pair(330,820),make_pair(480,820),make_pair(630,820),make_pair(780,820),make_pair(920,820)}};

        pair<int,int> box_loc[7][7]={{ make_pair(138.9,7.8), make_pair(286.7,7.8), make_pair(434.5,7.8), make_pair(582.3,7.8), make_pair(730.1,7.8), make_pair(877.9,7.8), make_pair(1025.7,7.8)},
                                    { make_pair(138.9,143.4), make_pair(286.7,143.4), make_pair(434.5,143.4), make_pair(582.3,143.4), make_pair(730.1,143.4), make_pair(877.9,143.4), make_pair(1025.7,143.4)},
                                    { make_pair(138.9,279.0), make_pair(286.7,279.0), make_pair(434.5,279.0), make_pair(582.3,279.0), make_pair(730.1,279.0), make_pair(877.9,279.0), make_pair(1025.7,279.0) },
                                    { make_pair(138.9,414.6), make_pair(286.7,414.6), make_pair(434.5,414.6), make_pair(582.3,414.6), make_pair(730.1,414.6), make_pair(877.9,414.6), make_pair(1025.7,414.6) },
                                    { make_pair(138.9,550.2), make_pair(286.7,550.2), make_pair(434.5,550.2), make_pair(582.3,550.2), make_pair(730.1,550.2), make_pair(877.9,550.2), make_pair(1025.7,550.2) },
                                    { make_pair(138.9,685.8), make_pair(286.7,685.8), make_pair(434.5,685.8), make_pair(582.3,685.8), make_pair(730.1,685.8), make_pair(877.9,685.8), make_pair(1025.7,685.8) },
                                    { make_pair(138.9,821.4), make_pair(286.7,821.4), make_pair(434.5,821.4), make_pair(582.3,821.4), make_pair(730.1,821.4), make_pair(877.9,821.4), make_pair(1025.7,821.4) }};


};

#endif // MULTI_PLAYER_SCREEN_H
