#include "card.h"

Card::Card(CardPoint_t point, CardSuit_t suit) :
    _point(point), _suit(suit)
{
}

CardPoint_t Card::point() const
{
    return _point;
}

void Card::setPoint(const CardPoint_t &point)
{
    _point = point;
}
CardSuit_t Card::suit() const
{
    return _suit;
}

void Card::setSuit(const CardSuit_t &suit)
{
    _suit = suit;
}


