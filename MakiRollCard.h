#ifndef MAKIROLLCARD_H
#define MAKIROLLCARD_H

#include "Card.h"

class MakiRollCard : public Card {
    public:
    enum MakiRollType {
        ONE_ROLL, TWO_ROLL, THREE_ROLL
    };

    MakiRollCard( const MakiRollType& type );
    std::string str() const;
    virtual ~MakiRollCard() {};

    private:
    MakiRollType _makiRollType;
    string getTypeString() const;
};

#endif
