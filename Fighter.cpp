//
// Created by teich on 09/06/2022.
//

#include "Fighter.h"

Fighter::Fighter(const string name, const string type, int hp, int force) :
Player(name, type, hp, force)
{}

int Fighter::getAttackStrength() const {
    return m_level + 2*m_force;
}

