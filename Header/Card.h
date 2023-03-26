#pragma once

#include <string>
#include <vector>

enum CardType {
    MakiRoll, Tempura, Sashimi, Dumplings, Nigiri
};

class Card {
    public:
    virtual CardType type() const = 0;
};
