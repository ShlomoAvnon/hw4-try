//
// Created by shlom on 09/06/2022.
//

//
// Created by shlom on 09/06/2022.
//
#include "Merchant.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::cin;
using std::cout;
using std::getline;
bool checkNumber(string str);
const int BUY_NOTHING =0;
const int BUY_HP = 1;
const int BUY_BUFF = 2;
const int PRICE_HP = 5;
const int PRICE_BUFF = 10;
const int MERCHANT_HEAL = 1;
const int MERCHANT_BUFF = 1;
const int NOT_ENOUGH_MONEY = 0;



Merchant::Merchant():
        Card(CardType::Battle, CardStats(IRRELEVANT, IRRELEVANT, IRRELEVANT, IRRELEVANT, IRRELEVANT), "Merchant")
{}

void Merchant::applyEncounter(Player &player) const {
    string strChoice;
    int numChoice;
    printStartGameMessage();
    bool isValid = false;
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(), player.get_money());
    while (!isValid) {
        cin >> strChoice;
        isValid = checkNumber(strChoice);
        if (!isValid) {
            printInvalidInput();
        }
    }
    if (isValid) {
        numChoice = std::stoi(strChoice);
        int price;
        switch (numChoice) {
            case BUY_NOTHING:
                price = BUY_NOTHING;
                break;
            case BUY_HP:
                if (player.pay(PRICE_HP)) {
                    player.heal(MERCHANT_HEAL);
                    price = PRICE_HP;
                }
                else {
                    printMerchantInsufficientCoins(cout);
                    price = NOT_ENOUGH_MONEY;
                    numChoice=NOT_ENOUGH_MONEY;
                }
                break;
            case BUY_BUFF:
                if (player.pay(PRICE_BUFF)) {
                    player.buff(MERCHANT_BUFF);
                    price = PRICE_BUFF;
                }
                else {
                    printMerchantInsufficientCoins(cout);
                    price = NOT_ENOUGH_MONEY;
                    numChoice=NOT_ENOUGH_MONEY;
                }
                break;
        }
        printMerchantSummary(cout, player.getName(), numChoice, price);
    }
}



void Merchant::print(ostream &os) const
{
    printCardDetails(os, m_name);
    printEndOfCardDetails(os);
}


bool checkNumber(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
