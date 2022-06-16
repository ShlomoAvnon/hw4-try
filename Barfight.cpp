//
// Created by teich on 09/06/2022.
//

#include "Barfight.h"

Barfight::Barfight():
        Card(CardType::Battle, CardStats(IRRELEVANT, BF_HP_LOSS, IRRELEVANT, IRRELEVANT, IRRELEVANT, IRRELEVANT), "Barfight")
{}

void Barfight::applyEncounter(Player &player) const {
    bool isNotFighter = (player.getType() != "Fighter");
    if(isNotFighter) {
        player.damage(m_stats.hpLossOnDefeat);
    }
    printBarfightMessage(!isNotFighter);
}


void Barfight::print(ostream &os) const
{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}
