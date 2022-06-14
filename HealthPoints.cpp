//
// Created by teich on 23/05/2022.
//

#include "HealthPoints.h"

HealthPoints::HealthPoints(int hp):
m_hp(hp),
m_max_hp(hp)
{
    if(m_max_hp<=0){
        throw InvalidArgument();
    }
}

HealthPoints& HealthPoints::operator+=(int hp)
{
    if (m_hp+hp<=m_max_hp){
        if (m_hp+hp<0)
        {
            m_hp=0;
        }
        else
        {
            m_hp+=hp;
        }
    }
    else{
        m_hp=m_max_hp;
    }
    return *this;
}




HealthPoints& HealthPoints::operator-=(int hp)
{
    if (m_hp-hp>0)
        if (m_hp-hp>m_max_hp)
            m_hp=m_max_hp;
        else
        {
            m_hp-=hp;
        }
    else{
        m_hp=0;
    }
    return *this;
}

HealthPoints HealthPoints::operator-(int hp) const {
    HealthPoints result(*this);
    if (m_hp - hp > 0){
        return (result -= hp);
    }
    else{
        return result -= m_hp;
    }
}

HealthPoints HealthPoints::operator+(int hp) {
    return hp + *this;
}

HealthPoints operator+(int hp, HealthPoints healthPoints)
{
    if (healthPoints.m_hp+hp <= healthPoints.m_max_hp){
        HealthPoints result(healthPoints);
        return  (result += hp);
    }
    else{
        return HealthPoints(healthPoints.m_max_hp);
    }
}

bool HealthPoints::operator>=(HealthPoints other_hp) const
{
    return other_hp <= *this;
}

bool HealthPoints::operator>(HealthPoints other_hp) const
{
    return other_hp<*this;
}

bool operator==(HealthPoints hp, HealthPoints other_hp)
{
    return hp.m_hp==other_hp.m_hp;
}

bool operator<(HealthPoints hp, HealthPoints other_hp)
{
    return hp.m_hp<other_hp.m_hp;
}

ostream& operator<<(std::ostream& os, const HealthPoints& hp)
{
    return os << hp.m_hp << "(" << hp.m_max_hp<< ")";
}

bool HealthPoints::operator!=(HealthPoints other_hp) const
{
    return !(*this == other_hp);
}

bool HealthPoints::operator<=(HealthPoints other_hp) const
{
    return !(other_hp < *this);
}






