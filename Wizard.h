//
// Created by teich on 09/06/2022.
//

#include "Player.h"


#ifndef PLAYER_CPP_WIZARD_H
#define PLAYER_CPP_WIZARD_H

class Wizard : public Player{
public:
    Wizard(const string name, const string type, int hp = MAX_HP, int force = STARTING_FORCE);
    void heal(int n) override;
    ~Wizard()=default;
};


#endif //PLAYER_CPP_WIZARD_H
