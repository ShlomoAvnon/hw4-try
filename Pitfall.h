//
// Created by teich on 09/06/2022.
//
#include "Card.h"

#ifndef MTMCHKIN_H_PITFALL_H
#define MTMCHKIN_H_PITFALL_H

const int P_HP_LOSS=10; ///TO DO : when defeated by dragon the player is dead


class Pitfall : public Card {
public:
    Pitfall();
    ~Pitfall() = default;

    void applyEncounter(Player& player) const override;


protected:
    void print(ostream &os) const override;
};

#endif //MTMCHKIN_H_PITFALL_H
