#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"

using namespace std;

class Player {
    private:
    string _name;
    int _totalScore;
    vector<Card*> _tableau;

    public:
    Player();
    void addCardToTableau( Card* card );
    void clearTableau();
    void printTableau();
    int calculateRoundScore( const vector<Card*>& otherTableau );
    string getName() const;
    string getCardDescription( int index ) const;
};

#endif
