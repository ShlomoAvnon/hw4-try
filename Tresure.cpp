//
// Created by shlom on 09/06/2022.
//
#include "Treasure.h"

Treasure::Treasure():
        Card(CardType::Treasure, CardStats(IRRELEVANT, IRRELEVANT, IRRELEVANT, IRRELEVANT, IRRELEVANT, T_LOOT), "Treasure")
{}

void Treasure::applyEncounter(Player &player) const {
    player.addCoins(m_stats.loot);
    printTreasureMessage();
}


void Treasure::print(ostream &os) const
{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}
