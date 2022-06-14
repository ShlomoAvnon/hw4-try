//
// Created by shlom on 09/06/2022.
//

#include "Player.h"

#ifndef PLAYER_CPP_ROGUE_H
#define PLAYER_CPP_ROGUE_H

class Rogue : public Player{
public:
    Rogue(const string name, const string type, int hp = MAX_HP, int force = STARTING_FORCE);
    void addCoins(int n) override;
    ~Rogue()=default;
};

#endif //PLAYER_CPP_ROGUE_H
