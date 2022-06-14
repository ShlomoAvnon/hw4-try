//
// Created by shlom on 09/06/2022.
//

#include "Card.h"

#ifndef PLAYER_CPP_DRAGON_H
#define PLAYER_CPP_DRAGON_H

const int D_FORCE=25;
const int D_HP_LOSS=MAX_HP;
const int D_LOOT=1000;

class Dragon : public Card{
public:
    Dragon();
    ~Dragon() override =default;

    void applyEncounter(Player& player) const override;


protected:
    void print(ostream &os) const override;

};



#endif //PLAYER_CPP_DRAGON_H
