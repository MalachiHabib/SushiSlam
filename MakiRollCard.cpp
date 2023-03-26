#include "makirollcard.h"

MakiRollCard::MakiRollCard( const MakiRollType& type ) : _makiRollType( type ), Card( CardType::MakiRoll ) {}

MakiRollCard::~MakiRollCard() {}

std::string MakiRollCard::str() const {
    std::string result;
    switch (_makiRollType) {
        case MakiRollType::ONE_ROLL:
            result = "Maki Roll (1)";
            break;
        case MakiRollType::TWO_ROLL:
            result = "Maki Roll (2)";
            break;
        case MakiRollType::THREE_ROLL:
            result = "Maki Roll (3)";
            break;
        default:
            result = "Unknown Maki Roll";
            break;
    }
    return result;
}
