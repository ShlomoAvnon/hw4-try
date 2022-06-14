//
// Created by shlom on 09/06/2022.
//
#include "Pitfall.h"

Pitfall::Pitfall():
        Card(CardType::Pitfall, CardStats(IRRELEVANT, P_HP_LOSS, IRRELEVANT, IRRELEVANT, IRRELEVANT, IRRELEVANT), "Pitfall")
{}

void Pitfall::applyEncounter(Player &player) const {
    if(player.m_type != "Rogue") {
        player.damage(m_stats.hpLossOnDefeat);
    }
}


void Pitfall::print(ostream &os) const
{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}

