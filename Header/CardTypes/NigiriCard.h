#pragma once
#pragma once
#include "../Card.h"
#include <string>

using namespace std;
enum NigiriType {
	Egg, Squid, Salmon
};

class NigiriCard : public Card {
	public:
	NigiriCard(NigiriType type);

	CardType type() const;
	string str() const;

	private:
	NigiriType type
};