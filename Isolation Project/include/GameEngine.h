#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <bits/stdc++.h>

using namespace std;
class GameEngine
{
    public:
        GameEngine(int x, int y, bool start, char c1, char c2);
        ~GameEngine();
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

    protected:

    private:
};

#endif // GAMEENGINE_H
