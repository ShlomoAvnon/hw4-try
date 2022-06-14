//
// Created by shlom on 09/06/2022.
//

#include "Rogue.h"

Rogue::Rogue(const string name, const string type, int hp, int force) :
Player(name, type, hp, force)
{}


void Rogue::addCoins(int n)
{
    if (n>0) {
        m_coins += 2*n;
    }
}

