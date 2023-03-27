#pragma once
#include "../Card.h"
#include <string>
using namespace std;

class TempuraCard : public Card {
	public:
	TempuraCard();

	CardType type() const;
	string str() const;

	private:
};