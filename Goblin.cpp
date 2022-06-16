//
// Created by shlom on 09/06/2022.
//
#include "Goblin.h"

Goblin::Goblin():
Card(CardType::Battle, CardStats(G_FORCE, G_HP_LOSS, IRRELEVANT, IRRELEVANT, IRRELEVANT, G_LOOT), "Goblin")
{}

void Goblin::print(ostream &os) const
{
    printCardDetails(os, m_name);
    printMonsterDetails(os, G_FORCE, G_HP_LOSS, G_LOOT, false);
    printEndOfCardDetails(os);
}

void Goblin::applyEncounter(Player &player) const {
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
