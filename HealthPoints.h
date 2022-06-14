//
// Created by teich on 23/05/2022.
//

#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H
#include <ostream>
using std::ostream;
const int STARTING_HP = 100;

class HealthPoints {
public:
    /*
     * C'tor of HealthPoints class
     *
     * @param hp - the current and max hp.
     * @return
     *      A new instance of HealthPoints
    */
    HealthPoints(int hp = STARTING_HP);

    /*
     * d'tor of HealthPoints class
     *
     * @param
     * @return
    */
    ~HealthPoints() = default;

    /*
     * overload operator =
     *
     * @param  another hp object
     * @return
     *      A reference to a copy of hp
    */
    HealthPoints& operator=(const HealthPoints&) = default;

    /*
     * copy C'tor of HealthPoints class
     *
     * @param hp- to be copied
     * @return
     *      A copy instance of hp
    */
    HealthPoints (const HealthPoints&) = default;

    /*
     * Operator + increase the argument passed to the amount of hp the player had
     *
     * @param int hp - the amount will increase to the hp
     * @return
     *      HealthPoints object after increasing
    */
    friend HealthPoints operator+(int hp, HealthPoints healthPoints);

    HealthPoints operator+(int hp);
    /*
     * Operator - decrease the argument passed to the amount of hp the player had
     *
     * @param int hp - the amount will decrease from the hp
     * @return
     *      HealthPoints object after decreasing
    */
    HealthPoints operator-(int hp) const;


    /*
     * Operator + increase the argument passed to the amount of hp the player had
     *
     * @param int hp - the amount will increase to the hp
     * @return
     *      this
    */
    HealthPoints& operator+=(int hp);

    /*
     * Operator - decrease the argument passed to the amount of hp the player had
     *
     * @param int hp - the amount will decrease from the hp
     * @return
     *      this
    */
    HealthPoints& operator-=(int hp);

    /*
     * Operator !=
     *
     * @param HealthPoints
     * @return
     *      true - if this_hp != other_hp
     *      false - if this_hp == other_hp
    */
    bool operator!=(HealthPoints other_hp) const;

    /*
     * Operator <=
     *
     * @param HealthPoints
     * @return
     *      true - if this_hp <= other_hp
     *      false - if this_hp > other_hp
    */
    bool operator<=(HealthPoints other_hp) const;


    /*
     * Operator >=
     *
     * @param HealthPoints
     * @return
     *      true - if this_hp >= other_hp
     *      false - if this_hp < other_hp
    */
    bool operator>=(HealthPoints other_hp) const;


    /*
     * Operator >
     *
     * @param HealthPoints
     * @return
     *      true - if this_hp > other_hp
     *      false - if this_hp <= other_hp
    */
    bool operator>(HealthPoints other_hp) const;


    /*
    * Operator == compare between two HealthPoints
    *
    * @param HealthPoints
    * @return
    *      true - if this_hp == other_hp
    *      false - if this_hp != other_hp
    *
    */
    friend bool operator==(HealthPoints hp, HealthPoints other_hp);


    /*
    * Operator <
    *
    * @param HealthPoints
    * @return
    *      true - if this_hp < other_hp
    *      false - if this_hp >= other_hp
    */
    friend bool operator<(HealthPoints hp, HealthPoints other_hp);


    /*
     * Operator << for ostream
     *
     * @param ostream type
     * @param hp - to send to ostream
     * @return
     *      ostream after changes
    */
    friend ostream& operator<<(std::ostream& os, const HealthPoints& hp);

    class InvalidArgument {};

private:
    int m_hp;
    int m_max_hp;
};

#endif //EX3_HEALTHPOINTS_H
