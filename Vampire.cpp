//
// Created by shlom on 09/06/2022.
//
#include "Vampire.h"

Vampire::Vampire():
Card(CardType::Battle, CardStats(V_FORCE, V_HP_LOSS, IRRELEVANT, IRRELEVANT, V_BUFF, V_LOOT), "Vampire")
{}

void Vampire::print(ostream &os) const
{
    printCardDetails(os, m_name);
    printMonsterDetails(os, V_FORCE, V_HP_LOSS, V_LOOT, false);
    printEndOfCardDetails(os);
}

void Vampire::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= m_stats.force) {
        player.levelUp();
        player.addCoins(m_stats.loot);
        printWinBattle(player.getName() ,this->m_name);
    }
    else {
        player.damage(m_stats.hpLossOnDefeat);
        player.buff(m_stats.buff);
        printLossBattle(player.getName(), this->m_name);
    }
}
