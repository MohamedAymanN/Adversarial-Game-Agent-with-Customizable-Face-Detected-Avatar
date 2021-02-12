#include <bits/stdc++.h>
#include "GameEngine.h"
using namespace std;

/*
  The GameEngine "logic and moves" for Multiplayer screen .
*/
GameEngine::GameEngine(int x, int y, bool start, char c1, char c2) : board( x, vector<char>(y,'0')) {
    this->x = x;
    this->y = y;
    player1 = c1;
    player2 = c2;
    activePlayer = start;
    currentPos1 = make_pair(0,y/2);
    currentPos2 = make_pair(x-1,y/2);
    board[currentPos1.first][currentPos1.second] = c1; // set position at the middle uppper of the board
    board[currentPos2.first][currentPos2.second] = c2; // set position at the middle uppper of the board
}
void GameEngine::printBoard(){
    cout << "   ";
    for (int i = 0; i < y; ++i)
    {
        cout << i << "   ";
    }
    cout << endl;
    for (int i = 0; i < x; ++i)
    {
        cout << i << "|";
        for (int j = 0; j < y; ++j)
        {
            cout << " " << board[i][j] << " |";
        }
        cout << endl;
    }
}
void GameEngine::getLegalMoves(set<pair<int,int> >& container, pair<int, int> pos){
	container.clear();
	int posx= pos.first;
	int posy= pos.second;

	if( posx + 1 < x && board[posx+1][posy] !=player1 && board[posx+1][posy] !=player2 ){
		if(posy + 1 < y && posy + 2 < y && board[posx+1][posy+1] !=player1 && board[posx+1][posy+1] !=player2 && board[posx+1][posy+2] == '0')
			container.insert( make_pair(posx+1, posy+2) );

		if(posy - 1 > -1 && posy-2 > -1 && board[posx+1][posy-1] !=player1 &&board[posx+1][posy-1] !=player2 && board[posx+1][posy-2] == '0')
			container.insert( make_pair(posx+1, posy-2) );

		if(posx+2 < x && posy+1 < y && board[posx+2][posy] !=player1 && board[posx+2][posy] !=player2 && board[posx+2][posy+1] == '0')
			container.insert( make_pair(posx+2, posy+1));

		if(posx+2 < x && posy-1 > -1 && board[posx+2][posy] !=player1 && board[posx+2][posy] !=player2 && board[posx+2][posy-1] == '0')
			container.insert( make_pair(posx+2, posy-1))	;
	}
	if( posx-1 > -1 && board[posx-1][posy] != player1 && board[posx-1][posy] != player2){
		if(posy + 1 < y && posy + 2 < y && board[posx-1][posy+1] !=player1 && board[posx-1][posy+1] !=player2 && board[posx-1][posy+2] == '0')
			container.insert( make_pair(posx-1, posy+2) );

		if(posy - 1 > -1 && posy-2 > -1 && board[posx-1][posy-1] !=player1 && board[posx-1][posy-1] !=player2  && board[posx-1][posy-2] == '0')
			container.insert( make_pair(posx-1, posy-2) );

		if(posx-2 > -1 && posy+1 < y && board[posx-2][posy] !=player1 && board[posx-2][posy] !=player2 && board[posx-2][posy+1] == '0')
			container.insert( make_pair(posx-2, posy+1));

		if(posx-2 > -1 && posy-1 > -1 && board[posx-2][posy] != player1 && board[posx-2][posy] != player2 && board[posx-2][posy-1] == '0')
			container.insert( make_pair(posx-2, posy-1))	;
	}
	if( posy + 1 < y && board[posx][posy+1] !=player1 && board[posx][posy+1] !=player2 ){
		if(posx + 1 < x && posx + 2 < x && board[posx+1][posy+1] !=player1 && board[posx+1][posy+1] !=player2 && board[posx+2][posy+1] == '0')
			container.insert( make_pair(posx+2, posy+1) );

		if(posx - 1 > -1 && posx-2 > -1 && board[posx-1][posy+1]!=player1 && board[posx-1][posy+1]!=player2 && board[posx-2][posy+1] == '0')
			container.insert( make_pair(posx-2, posy+1) );

		if(posy+2 < y && posx+1 < x && board[posx][posy+2] != player1 && board[posx][posy+2] != player2 && board[posx+1][posy+2] == '0')
			container.insert( make_pair(posx+1, posy+2));

		if(posy+2 < y && posx-1 > -1 && board[posx][posy+2] !=player1 && board[posx][posy+2] !=player2 && board[posx-1][posy+2] == '0')
			container.insert( make_pair( posx-1, posy+2))	;
	}
	if( posy-1 > -1 && board[posx][posy-1] != player1 && board[posx][posy-1] != player2){

		if(posx + 1 < x && posx + 2 < x && board[posx+1][posy-1] !=player1 && board[posx+1][posy-1] !=player2 && board[posx+2][posy-1] == '0')
			container.insert( make_pair( posx+2, posy-1) );

		if(posx - 1 > -1 && posx-2 > -1 && board[posx-1][posy-1] !=player1 && board[posx-1][posy-1] !=player2 && board[posx-2][posy-1] == '0')
			container.insert( make_pair(posx-2, posy-1) );

		if(posy-2 > -1 && posx+1 < x && board[posx][posy-2] !=player1 && board[posx][posy-2] !=player2 && board[posx+1][posy-2] == '0')
			container.insert( make_pair( posx+1, posy-2));

		if(posy-2 > -1 && posx-1 > -1 && board[posx][posy-2] != player1 && board[posx][posy-2] != player2 && board[posx-1][posy-2] == '0')
			container.insert( make_pair(posx-1, posy-2))	;
	}
}
bool GameEngine::move(pair<int, int> newCoord) {

    pair<int, int>& p = (activePlayer) ? currentPos1 : currentPos2;

	int x = newCoord.first;
	int y = newCoord.second;
	set<pair<int, int> > legalMoves;
	getLegalMoves(legalMoves, p);
	if(legalMoves.size() == 0)
        return 0;
    if( legalMoves.find(newCoord) != legalMoves.end() ){
        if(activePlayer){
            board[p.first][p.second] = 'g';
        }else{
            board[p.first][p.second] = 'f';
        }

        p = newCoord;
        if(activePlayer)
            board[p.first][p.second] = player1;
        else
            board[p.first][p.second] = player2;
        activePlayer = !activePlayer;
        return 1;
    }
    return 1;

}


