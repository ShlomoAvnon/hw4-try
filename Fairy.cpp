//
// Created by teich on 09/06/2022.
//

#include "Fairy.h"

Fairy::Fairy():
        Card(CardType::Battle, CardStats(IRRELEVANT, IRRELEVANT, IRRELEVANT, F_HEAL, IRRELEVANT, IRRELEVANT), "Fairy")
{}

void Fairy::applyEncounter(Player &player) const {
    bool isWizard = (player.getType() == "Wizard");
    if(isWizard) {
        player.heal(m_stats.heal);
    }
    printFairyMessage(isWizard);
}



void Fairy::print(ostream &os) const
{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}
