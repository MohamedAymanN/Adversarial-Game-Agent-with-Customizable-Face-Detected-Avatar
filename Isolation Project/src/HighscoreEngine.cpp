#include "HighscoreEngine.h"
/*
    // Storing the HighScores in a separated file
*/

int HighscoreEngine::writeFile(std::string name,int score) {
    std::ofstream myfile;
    myfile.open ("hiscores.txt",std::ios_base::app);
    myfile <<name<<" "<< score<<"\n";
    myfile.close();
    return 0;
}

HighscoreEngine::HighscoreEngine(){}
