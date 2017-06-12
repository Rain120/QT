#ifndef CARD_H
#define CARD_H

typedef enum POINT {
    Card_start,     // 0
    Card_3,         //1
    Card_4,
    Card_5,
    Card_6,
    Card_7,
    Card_8,
    Card_9,
    Card_10,
    Card_J,
    Card_Q,
    Card_K,
    Card_A,
    Card_2,
    Card_SJ,   // 小王
    Card_BJ,   // 大王
    Card_end
}CardPoint_t;

typedef enum suit {
    Suit_start,
    Diamond,   // 方块
    Club,      // 梅花
    Heart,     // 红桃
    Spade,     // 黑桃
    Suit_end
}CardSuit_t;


class Card
{
public:
    Card(CardPoint_t point, CardSuit_t suit);

    CardPoint_t point() const;
    void setPoint(const CardPoint_t &point);

    CardSuit_t suit() const;
    void setSuit(const CardSuit_t &suit);

private:
    CardPoint_t _point;
    CardSuit_t _suit;

};

#endif // CARD_H
