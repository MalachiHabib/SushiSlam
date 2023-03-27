#pragma once
#include "../Card.h"
#include <string>
using namespace std;

class SashimiCard : public Card {
	public:
	SashimiCard();

	CardType type() const;
	string str() const;

	private:
};