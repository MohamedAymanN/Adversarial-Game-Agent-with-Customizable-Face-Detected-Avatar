#ifndef AI_GAMEENGINE_H
#define AI_GAMEENGINE_H


#include <bits/stdc++.h>

using namespace std;
struct Move {
    int x=0;
    int y=0;
};
class AI_GameEngine
{
public:
    AI_GameEngine(int x, int y, bool start, char c1, char c2);
    ~AI_GameEngine();
    char player1;
    char player2;
    pair<int, int> currentPos1;
    pair<int, int> currentPos2;
    bool activePlayer;
    vector< vector<char> > board;
    int x,y;
    void getLegalMoves( set<pair<int,int> >&, pair<int,int>);
    void play();
    bool checkTermination(const vector<pair<int,int> >);
    bool move( pair<int, int>);
    void printBoard();
    int maxSearch(vector<vector<char>> &, int depth);
    int minSearch(vector<vector<char>> &, int depth);
    Move minimax(vector<vector<char>>&, int depth);
    bool gameOver(int depth);
    int scoreEval();
    bool moveai(pair<int, int> newCoord);
    bool AIplay();
    bool humanPlay(int x, int y);
    void obstacleMaker(int x, int y);
    Move myMinimax();
    bool myMinSearch();
    bool myMaxSearch();
    Move greedyPlayer(vector<vector<char>>& AIboard);
    Move randomPlayer();
protected:

private:



};

#endif // AI_GAMEENGINE_H
