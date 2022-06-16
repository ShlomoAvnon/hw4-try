//
// Created by shlom on 09/06/2022.
//

#include "Dragon.h"

Dragon::Dragon():
        Card(CardType::Battle, CardStats(D_FORCE, D_HP_LOSS, IRRELEVANT, IRRELEVANT, IRRELEVANT, D_LOOT), "Dragon")
{}

void Dragon::print(ostream &os) const
{
    printCardDetails(os, m_name);
    printMonsterDetails(os, D_FORCE, D_HP_LOSS, D_LOOT, true);
    printEndOfCardDetails(os);
}

void Dragon::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= m_stats.force) {
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName() ,this->m_name);
    }
    else {
        player.damage(m_stats.hpLossOnDefeat);
        printLossBattle(player.getName(), this->m_name);
    }
}
