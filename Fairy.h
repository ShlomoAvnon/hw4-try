//
// Created by teich on 09/06/2022.
//

#include "Card.h"

#ifndef MTMCHKIN_H_FAIRY_H
#define MTMCHKIN_H_FAIRY_H

const int F_HEAL=10; /// TO DO: decrease 10 HP for everyone who not the Rogue

class Fairy : public Card{
public:
    Fairy();
    ~Fairy() override =default;

    void applyEncounter(Player& player) const override;


protected:
    void print(ostream &os) const override;

};


#endif //MTMCHKIN_H_FAIRY_H
