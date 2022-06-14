//
// Created by shlom on 09/06/2022.
//
#include "Card.h"

#ifndef CARD_CPP_TREASURE_H
#define CARD_CPP_TREASURE_H

const int T_LOOT=10;

class Treasure : public Card{
public:
    Treasure();
    ~Treasure() override =default;

    void applyEncounter(Player& player) const override;


protected:
    void print(ostream &os) const override;
};
#endif //CARD_CPP_TREASURE_H
