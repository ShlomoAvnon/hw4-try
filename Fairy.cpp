//
// Created by teich on 09/06/2022.
//

#include "Fairy.h"

Fairy::Fairy():
        Card(CardType::Battle, CardStats(IRRELEVANT, IRRELEVANT, IRRELEVANT, F_HEAL, IRRELEVANT, IRRELEVANT), "Fairy")
{}

void Fairy::applyEncounter(Player &player) const {
    if(player.m_type == "Wizard") {
        player.heal(m_stats.heal);
    }
}


void Fairy::print(ostream &os) const
{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}
