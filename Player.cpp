//
// Created by teich on 04/05/2022.
//
#include "Player.h"

Player::Player(const string name, const string type, int hp, int force):
    m_name(name),
    m_type(type),
    m_maxHP(hp),
    m_hp(m_maxHP),
    m_force(force),
    m_level(STARTING_LEVEL),
    m_coins(STARTING_COINS)
{
    if(hp<=0){
        m_maxHP=MAX_HP;
    }
    if(force<=0){
        m_force=STARTING_FORCE;
    }
}

void Player::levelUp()
{
    if (m_level!=MAX_LEVEL) {
        ++m_level;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int n)
{
    // work also when get number smaller than Zero, for the Vampire
    m_force+=n;
}

void Player::heal(int n)
{
    if (n>0) {
        if (m_hp + n <= m_maxHP) {
            m_hp += n;
        } else {
            m_hp = m_maxHP;
        }
    }
}

void Player::damage(int n)
{
    if(n>0) {
        if (m_hp - n >= 0) {
            m_hp -= n;
        } else {
            m_hp = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
    return m_hp == 0;
}

void Player::addCoins(int n)
{
    if (n>0) {
        m_coins += n;
    }
}

bool Player::pay(int n)
{
    if(n>m_coins){
        return false;
    }
    else if(n>0){
        m_coins-=n;
    }
    return true;
}

int Player::get_money() {
    return m_coins;
}


int Player::getAttackStrength() const
{
    return m_level + m_force;
}
