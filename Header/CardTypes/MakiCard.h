#pragma once
#include "../Card.h"
#include <string>
using namespace std;

class MakiCard : public Card {
	public:
	MakiCard(int makiCount);

	CardType type() const;
	string str() const;

	private:
	int makiCount;
};