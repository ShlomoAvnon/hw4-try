//
// Created by teich on 09/06/2022.
//
#include "Mtmchkin.h"
#include "Queue.h"
#include "Card.h"
#include "Goblin.h"
#include "Vampire.h"
#include "Dragon.h"
#include "Merchant.h"
#include "Treasure.h"
#include "Pitfall.h"
#include "Barfight.h"
#include "Fairy.h"
#include "Player.h"
#include "Wizard.h"
#include "Rogue.h"
#include "Fighter.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
const int MAX_LENGTH = 16;
const int NUM_OF_CARDS = 8;
const int GOBLIN = 0;
const int VAMPIRE = 1;
const int DRAGON = 2;
const int MERCHANT = 3;
const int TREASURE = 4;
const int PITFALL = 5;
const int BARFIGHT = 6;
const int FAIRY = 7;
const int ROGUE = 0;
const int WIZARD = 1;
const int FIGHTER = 2;
const int MAX_CHARACTER = 15;
const int NUM_OF_PLAYERS = 3;
const char SPACE = ' ';
const string CARDS_STR[8] = {"Goblin", "Vampire", "Dragon", "Treasure", "Pitfall", "Barfight", "Fairy"};
const string PLAYERS_STR[3] = {"Rogue", "Wizard", "Fighter"};
const int NOT_A_CARD = -1;
const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 6;

int indexOfCard(string str);
Card& intToCard(int i);
Player& intToPlayer(int i, string str, string type);
bool checkNumber(string str);

static Queue<Card> m_cardsQueue;
static Queue<Player> m_playersQueue;
static Queue<Player> m_winnersPlayers;

Mtmchkin::Mtmchkin() {
    /*ifstream source(fileName);
    string cardType;
    if(source.fail()){
        cout<<"Error in opening file!"<<endl;
        ///TO DO: throw Exception while error in name file or in opening
    }
    getline(source,cardType);
    //creates a cards queue*/
    string CARDS[8] = {"Goblin", "Vampire", "Dragon", "Merchant", "Treasure", "Pitfall", "Barfight", "Fairy"};


    //string line;
    for(int i=0; i<NUM_OF_CARDS; i++) {
        m_cardsQueue.pushBack(&intToCard(i));
    }

    //gets the team size

    string str_numOfPlayers;
    int numOfPlayers;
    printStartGameMessage();
    bool isValid;
    /*do {
        printEnterTeamSizeMessage();
        cin >> str_numOfPlayers;
        isValid = checkNumber(str_numOfPlayers);
        if (isValid){
            numOfPlayers = std::stoi(str_numOfPlayers);
        }
        if (numOfPlayers < 2 || numOfPlayers > 6) {
            printInvalidTeamSize();
        }
    } while (numOfPlayers < 2 || numOfPlayers > 6 || !isValid);*/

    //check the validity of the name and the roll
    string name;
    string type;
    numOfPlayers=2;
    for (int i = 0; i < numOfPlayers; ++i) {
        printInsertPlayerMessage();
        {
            name= "shlomo";
            type ="Rogue";
            if (i=1) {
                name= "Roi";
                type ="Fighter";
            }
            /*if (name.length() >= MAX_CHARACTER) {
                i--;
                printInvalidName();
            } else {
                Player *player;*/
                for (int p = 0; p < NUM_OF_PLAYERS; ++p) {
                    if (!(PLAYERS_STR[p].compare(type))) {
                        //*player = intToPlayer(p, name, type);
                        m_playersQueue.pushBack(&(intToPlayer(p, name, type)));
                        break;
                    }
                    if (p == NUM_OF_PLAYERS-1) {
                        i--;
                        printInvalidClass();
                    }
                }
            }
        }
    }
//}


Player& intToPlayer(int i, string name, string type)
{
    switch (i) {
        case (ROGUE): {
            Rogue *rogue = new Rogue(name, type);
            return *rogue;
        }
        case (WIZARD): {
            Wizard *wizard = new Wizard(name, type);
            return *wizard;
        }
    }
    /// TO DO - what happening while the type of the card is non of them?

    Fighter *fighter = new Fighter(name, type);
    return *fighter;
}

Card& intToCard(int i)
{
    switch (i) {
        case (GOBLIN): {
            Goblin *goblin = new Goblin();
            return *goblin;
        }
        case (VAMPIRE): {
            Vampire *vampire = new Vampire();
            return *vampire;
        }
        case (DRAGON): {
            Dragon *dragon = new Dragon();
            return *dragon;
        }
        case (MERCHANT): {
            Merchant *merchant = new Merchant();
            return *merchant;
        }
        case (TREASURE): {
            Treasure *treasure = new Treasure();
            return *treasure;
        }
        case (PITFALL): {
            Pitfall *pitfall = new Pitfall();
            return *pitfall;
        }
        case (BARFIGHT): {
            Barfight *barfight = new Barfight();
            return *barfight;
        }
    }
    /// TO DO - what happening while the type of the card is non of them?

    Fairy *fairy = new Fairy();
    return *fairy;
}



/*bool checkNumber1(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}*/

void Mtmchkin::playRound()
{
    int activePlayers = m_playersQueue.size();
    for(int j=0; j<activePlayers; j++)
    {
        printRoundStartMessage(m_roundCount);
        /// TO DO: arrange the applyEncounter
        Card* currentCard = m_cardsQueue.front();
        currentCard->applyEncounter(*m_playersQueue.front());
        m_cardsQueue.popFront();
        m_cardsQueue.pushBack(currentCard);

        // checking if player win
        if (m_playersQueue.front()->getLevel()==MAX_LEVEL)
        {
            m_winnersPlayers.pushBack(m_playersQueue.front());
            m_playersQueue.popFront();
        }
            // checking if player lost
        else if (m_playersQueue.front()->isKnockedOut()) {
            m_losersPlayers.pushBack(m_playersQueue.front());
            m_playersQueue.popFront();
        }
            // else - the player continue to play
        else {
            m_playersQueue.pushBack(m_playersQueue.front());
            m_playersQueue.popFront();
        }
        // checking if game over
        if(!isGameOver())
            printGameEndMessage();
    }

    m_roundCount++;
}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundCount;
}

bool Mtmchkin::isGameOver() const {
    return (m_winnersPlayers.size()+ m_losersPlayers.size()==m_numOfPlayers);
}

//Mtmchkin::~Mtmchkin() {
    /// TO DO: understand how to delete all the memory!

//}
