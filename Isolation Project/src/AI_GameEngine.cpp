#include <bits/stdc++.h>
#include "AI_GameEngine.h"
#include "Campaign_CharSelect_Screen.h"
/*
class name: AI_gameEngine
manage The Computer Player Logic With different Levels of AI.
Level 1: Random Player
    Select A random Move From the Legal moves of the Computer Player
Level 2: Greedy Player
    improved over the random in that It realize whether the next move will result in a win Condition or lose.
Level 3: Limited MinMax
    It the minMax algorithm Which is a recursive tree based algorithm that creates a virtual board game in which it keeps playing for the AI then
    plays ideally for the human and after reaching a certain depth in the game tree , it returns the best move so far based on board evaluation function
Level 4: Unlimited MinMax optimized with Alpha-beta pruning Algorithm
    Do the same as the limited until a true winning or losing condition has been satisfied then Chose the best move.
*/
using namespace std;
static int depth = 0;

Move AI_GameEngine::greedyPlayer(vector<vector<char>>& AIboard) {
    Move m1;
    set<pair<int, int> > legalMoves;
    pair<int,int>& p = currentPos1;
    pair<int, int> holder = currentPos1;
    getLegalMoves(legalMoves, p);
    int tempMoveScore =  -100000; // initial score which indicate the worst case unless its overwritten
    for(auto cos : legalMoves) {
        int i=cos.first;
        int j=cos.second;
        AIboard[i][j] = player1;
        p = cos;
        int score = legalMoves.size();
        if(score>tempMoveScore){ // if score is higher than the previous score it over-rides the current best move
            m1.x = i;
            m1.y = j;
            tempMoveScore = score;
        }
        p = holder;
        AIboard[i][j] = '0';
        }
    return m1;
}


Move AI_GameEngine::randomPlayer() {
    Move m1;
    pair<int, int> newCoord;
    set<pair<int, int> > legalMovesP1;
    pair<int, int> &p1 = this->currentPos1;
    this->getLegalMoves(legalMovesP1, p1);
    int size = legalMovesP1.size();
    if(legalMovesP1.size() ==0){
        return m1;
    }
    int num = rand() % size;
    Move list[size];

    int x=0;
    for (auto cos : legalMovesP1) {
        int i = cos.first;
        int j = cos.second;
        m1.x = i;
        m1.y = j;
        list[x] = m1;
        x++;
    }

    Move m2=list[num];
    return m2;
}

AI_GameEngine::AI_GameEngine(int x, int y, bool start, char c1, char c2) : board( x, vector<char>(y,'0')) {
    this->x = x;
    this->y = y;
    player1 = c1;
    player2 = c2;
    activePlayer = start;
    currentPos1 = make_pair(3,4);
    currentPos2 = make_pair(3,2);
    board[currentPos1.first][currentPos1.second] = c1; // set position at the middle uppper of the board
    board[currentPos2.first][currentPos2.second] = c2; // set position at the middle uppper of the board
}
void AI_GameEngine::printBoard(){
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
void AI_GameEngine::getLegalMoves(set<pair<int,int> >& container, pair<int, int> pos){
    // it calculate all the possible legal moves from the given position "the moves are the same as for the knight in chess"
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
		// cout << "LOL";
		// cout << "LOL";
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

bool AI_GameEngine::move(pair<int, int> newCoord) {
    //modify the board based on a given move which has been verified to be legal
    pair<int, int>& p = (activePlayer) ? currentPos1 : currentPos2;

	int x = newCoord.first;
	int y = newCoord.second;
	set<pair<int, int> > legalMoves;
	getLegalMoves(legalMoves, p);
	if(legalMoves.size() == 0){
        activePlayer = !activePlayer; //switch the player turn
        return 0;
	}
    if( legalMoves.find(newCoord) != legalMoves.end() ){ //verify the move is legal
        cout << "GOT here" << activePlayer << endl;

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

bool AI_GameEngine::gameOver(int depth){
    // return true if the Game is over "one of the player does not have a move" false otherwise.
    pair<int, int>& p = (activePlayer) ? currentPos1 : currentPos2;
	set<pair<int, int>> vlegalMoves;
	getLegalMoves(vlegalMoves,p);
	if(depth == 0 || vlegalMoves.size() == 0){
		return true;
	}
	return false;
}
int maxima=0;

Move AI_GameEngine::minimax(vector<vector<char>>& AIboard,int depth) {
    //limited MinMax as described above
	int bestMoveScore = -100000; // worst score possible losing.
	Move bestMove;
	set<pair<int, int> > legalMoves;

	pair<int,int>& p = currentPos1;
	pair<int, int> holder = currentPos1;
	getLegalMoves(legalMoves, p);

	//case its one only &&
	bestMove.x = -1;
	bestMove.y = -1;



 	//cos for co-ordinates of possible moves
 	int maxMaxima=0;
	for(auto cos : legalMoves) {
        maxima=0;
		int i=cos.first;
		int j=cos.second;
		if (AIboard[i][j] == '0' ){
			AIboard[i][j] = player1;
			currentPos1 = cos;
			int tempMoveScore = minSearch(AIboard,depth-1); // the recursion initiation
			if (maxima>=maxMaxima && tempMoveScore >= bestMoveScore ) { //if the new move score is better than prev best update best and move
			    maxMaxima=maxima;
				bestMoveScore = tempMoveScore;
				bestMove.x = i;
				bestMove.y = j;
			}
			currentPos1 = holder;
			AIboard[i][j] = '0';
		}
	}

	return bestMove;
}
//their is a mutual recursive between maxSearch and minSearch each one of them play optimal for the opponent or the AI player.
int AI_GameEngine::maxSearch(vector<vector<char>>& AIboard,int depth) {
    // max function returns the best move for the AI player
	if(gameOver(depth))
		return scoreEval();
	Move bestMove;

	pair<int, int> &p =  currentPos1 ;
	pair<int, int> holder = currentPos1;
	set<pair<int, int> > legalMoves;
    getLegalMoves(legalMoves,p);
	int bestMoveScore = -1000000;
	for(auto cos : legalMoves) {
		int i=cos.first;
		int j=cos.second;
		if (AIboard[i][j] == '0' ){
			AIboard[i][j] = player1;
			currentPos1 = cos;
			int bestMoveScore = max(minSearch(AIboard,depth-1),bestMoveScore); //call the function min to switch the turn

			currentPos1 = holder;

			AIboard[i][j] = '0';
		}
	}

	return bestMoveScore;
}
int AI_GameEngine::minSearch(vector<vector<char>>& AIboard,int depth) {
    // min function returns the best move for the opponent player
	if(gameOver(depth)){
        maxima++;
		return scoreEval();
	}
	Move bestMove;

	pair<int, int>& p = currentPos2;
	pair<int, int> holder = currentPos2;
	set<pair<int, int> > legalMoves;
    getLegalMoves(legalMoves,p);
	int bestMoveScore = 1000000;
	for(auto cos : legalMoves) {
		int i=cos.first;
		int j=cos.second;
		if (AIboard[i][j] == '0' ){
			AIboard[i][j] = player2;
			currentPos2 = cos;
			int bestMoveScore = min(maxSearch(AIboard,depth-1),bestMoveScore);

			currentPos2 = holder;
			AIboard[i][j] = '0';
		}
	}

	return bestMoveScore;
}

int AI_GameEngine::scoreEval(){
    // return the score of the board based on my legal move vs enemy legal move
    set<pair<int, int> > legalMoves;
    set<pair<int, int> > legalMoves1;

    pair<int, int>& p = (activePlayer) ? currentPos1 : currentPos2;
    pair<int, int>& p1 = !(activePlayer) ? currentPos1 : currentPos2;
    getLegalMoves(legalMoves,p);
    getLegalMoves(legalMoves1,p1);

    if(legalMoves.size()==0){
        return -100000;
    }
    return ((legalMoves.size()) -(legalMoves1.size()));


}

bool AI_GameEngine::AIplay(){
    //Control which AI version is gonna run based on the game mode
    Move m1;
    switch(Campaign_CharSelect_Screen::AI_level){

    case 0:
        m1=this->randomPlayer();
        break;
    case 1:
        m1=this->greedyPlayer(board);
        break;
    case 2:
        m1 =this->minimax(board,3);
        break;
    case 3:
        m1 =this-> myMinimax();
        break;
    }

    pair<int, int> newCoord;

    newCoord= make_pair (m1.x,m1.y);
    if(!(this ->move(newCoord))){
        return 0;
    }
    return 1;
}
bool AI_GameEngine::humanPlay(int x,int y){
    pair<int, int> newCoord;
    newCoord= make_pair (x,y);
    if(!(this ->move(newCoord))){
        return 0;
    }
    return 1;
}
void AI_GameEngine::obstacleMaker(int x,int y){
    board[x][y] = 'x';
}
Move AI_GameEngine::myMinimax(){
    // this is the unlimited version of MinMax with Alpha beta optimization
	bool win = 0;
	Move bestMove;
	set< pair<int,int> > legalMoves;
	pair<int,int> holder = currentPos1;
	getLegalMoves(legalMoves, holder);
	bestMove.x = legalMoves.begin()->first;
	bestMove.y = legalMoves.begin()->second; // initializer for bestMove
	if (legalMoves.size() == 1) {
			return bestMove;
	}
	for( auto move : legalMoves){
		currentPos1 = make_pair(move.first, move.second);
		this->board[move.first][move.second] = player1;
		if(!myMinSearch()){
		    //the Alpha-Beta optimization
		    // it stop the function from processing all the other tree branches if it already can win with what is available
			bestMove.x = move.first;
			bestMove.y = move.second;
			win = 1;
			this->board[move.first][move.second] = '0';
			currentPos1 = holder;
			break;
		}
		this->board[move.first][move.second] = '0';
		currentPos1 = holder;
	}

	return bestMove;
}
//their is a mutual recursive between MymaxSearch and MyminSearch each one of them play optimal for the opponent or the AI player.
bool AI_GameEngine::myMinSearch(){
	static int depth = 0;
	depth++;
	bool minWin = 0;
	set< pair<int,int> > legalMoves;
	pair<int,int> holder = currentPos2;
	getLegalMoves(legalMoves, holder);

	if(legalMoves.size() == 0){

		depth--;
		return minWin; // game Ended At Human Turn
	}
	for( auto move : legalMoves){
		currentPos2 = make_pair(move.first, move.second);
		this->board[move.first][move.second] = player2;
		if(!myMaxSearch()){
            // same implementation of alpha-beta as in myMinMax
			minWin = 1;
			this->board[move.first][move.second] = '0';
			currentPos2 = holder;
			break;
		}
		this->board[move.first][move.second] = '0';
		currentPos2 = holder;
	}
	return minWin;

}
bool AI_GameEngine::myMaxSearch(){
	bool maxWin = 0;
	set< pair<int,int> > legalMoves;
	pair<int,int> holder = currentPos1;
	getLegalMoves(legalMoves, holder);
	if(legalMoves.size() == 0){
		return maxWin; // game Ended At AI rule
	}
	for( auto move : legalMoves){
		currentPos1 = move;

		this->board[move.first][move.second] = player1;
		bool x = myMinSearch();
		if(x == 0){
			maxWin = 1;
			this->board[move.first][move.second] = '0';
			currentPos1 = holder;
			break;
		}
		this->board[move.first][move.second] = '0';
		currentPos1 = holder;
	}
	return maxWin;
}
