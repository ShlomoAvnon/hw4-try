//
// Created by shlom on 09/06/2022.
//
#include "Card.h"

#ifndef CARD_CPP_MERCHANT_H
#define CARD_CPP_MERCHANT_H
class Merchant : public Card{
public:
    Merchant();
    ~Merchant() override =default;

    void applyEncounter(Player& player) const override;

protected:
    void print(ostream &os) const override;


};

#endif //CARD_CPP_MERCHANT_H
