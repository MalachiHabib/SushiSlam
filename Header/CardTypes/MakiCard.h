#pragma once
#include "../Card.h"
#include <string>
using namespace std;

class MakiCard : public Card {
    public:
    MakiCard();

    CardType type() const;
};