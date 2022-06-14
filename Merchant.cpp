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




Merchant::Merchant():
        Card(CardType::Battle, CardStats(IRRELEVANT, IRRELEVANT, IRRELEVANT, IRRELEVANT, IRRELEVANT), "Merchant")
{}

void Merchant::applyEncounter(Player &player) const {
    string strChoice;
    int numChoice;
    printStartGameMessage();
    bool isValid;
    /// To Do - it this the way to work with cout?
    printMerchantInitialMessageForInteractiveEncounter(cout ,player.m_name, player.get_money());
        cin >> strChoice;
        isValid = checkNumber(strChoice);
        if (isValid){
            numChoice = std::stoi(strChoice);
            switch (numChoice) {
                case BUY_NOTHING:
                    printMerchantSummary(cout, player.m_name, BUY_NOTHING, BUY_NOTHING);
                    break;
                case BUY_HP:
                    if(player.pay(PRICE_HP)) {
                        player.heal(MERCHANT_HEAL);
                        printMerchantSummary(cout, player.m_name, BUY_HP, PRICE_HP);

                    }
                    else{
                        printMerchantInsufficientCoins(cout);
                    }
                    break;
                case PRICE_BUFF:
                    if (player.pay(PRICE_BUFF)){
                        player.buff(MERCHANT_BUFF);
                        printMerchantSummary(cout, player.m_name, BUY_BUFF, PRICE_BUFF);
                    }
                    else{
                        printMerchantInsufficientCoins(cout);
                    }
                    break;
            }
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
