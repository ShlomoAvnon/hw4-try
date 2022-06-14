//
// Created by teich on 09/06/2022.
//

#include "Card.h"

#ifndef MTMCHKIN_H_BARFIGHT_H
#define MTMCHKIN_H_BARFIGHT_H

const int BF_HP_LOSS=10; /// TO DO: decrease 10 HP for everyone who not the Rogue

class Barfight : public Card{
public:
    Barfight();
    ~Barfight() override =default;

    void applyEncounter(Player& player) const override;


protected:
    void print(ostream &os) const override;

};

#endif //MTMCHKIN_H_BARFIGHT_H
