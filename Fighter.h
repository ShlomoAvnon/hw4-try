//
// Created by teich on 09/06/2022.
//

#include "Player.h"


#ifndef PLAYER_CPP_FIGHTER_H
#define PLAYER_CPP_FIGHTER_H

class Fighter : public Player{
public:
    Fighter(const string name, const string type, int hp = MAX_HP, int force = STARTING_FORCE);
    int getAttackStrength() const override;
    ~Fighter()=default;

};

#endif //PLAYER_CPP_FIGHTER_H
