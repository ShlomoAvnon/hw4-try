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
#include "utilities.h"
#include <fstream>
#include "Exception.h"
#include <memory>
using namespace std;
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
const string CARDS_STR[8] = {"Goblin", "Vampire", "Dragon", "Merchant", "Treasure", "Pitfall", "Barfight", "Fairy"};
const string PLAYERS_STR[3] = {"Rogue", "Wizard", "Fighter"};
const int NOT_A_CARD = -1;
const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 6;
const int NON_LOSERS_QUEUES = 2;

int indexOfCard(string str);
Card& intToCard(int i);
Player& intToPlayer(int i, string str, string type);
bool checkNumber(string str);
void printBack(Queue<Player*> queue, int& i);

Mtmchkin::Mtmchkin(const std::string fileName) {
    ifstream source(fileName);
    string cardType;
    if(source.fail()){
        string a ="5";
        throw DeckFileFormatError(a);
        cout<<"Error in opening file!"<<endl;
        ///TO DO: throw Exception while error in name file or in opening
    }
    string str_numOfCards;
    while(getline(source,cardType)){
        for(int i=0; i<NUM_OF_CARDS; i++)
            if(!CARDS_STR[i].compare(cardType))
                m_cardsQueue.pushBack(&intToCard(i));
        }
    //creates a cards queue


    //string line;
    /*for(int i=0; i<NUM_OF_CARDS; i++) {
        m_cardsQueue.pushBack(&intToCard(i));
    }*/

    //gets the team size

    string str_numOfPlayers;
    int numOfPlayers;
    printStartGameMessage();
    bool isValid;
    do {
        printEnterTeamSizeMessage();
        cin >> str_numOfPlayers;
        isValid = checkNumber(str_numOfPlayers);
        if (isValid){
            numOfPlayers = std::stoi(str_numOfPlayers);
        }
        if (numOfPlayers < MIN_PLAYERS || numOfPlayers > MAX_PLAYERS) {
            printInvalidTeamSize();
        }
    } while (numOfPlayers < MIN_PLAYERS || numOfPlayers > MAX_PLAYERS || !isValid);

    //check the validity of the name and the roll
    string name;
    string type;
    for (int i = 0; i < numOfPlayers; ++i) {
        printInsertPlayerMessage();
        {
            cin >> name;
            cin >> type;
            if (name.length() >= MAX_CHARACTER) {
                i--;
                printInvalidName();
            } else {

                for (int p = 0; p < NUM_OF_PLAYERS; ++p) {
                    if (!(PLAYERS_STR[p].compare(type))) {
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
}


Player& intToPlayer(int i, string name, string type)
{
    switch (i) {
        case (ROGUE): {
            unique_ptr<Rogue> rogue(new Rogue(name, type));
            return *rogue;
        }
        case (WIZARD): {
            unique_ptr<Wizard> wizard(new Wizard(name, type));
            return *wizard;
        }
    }
    /// TO DO - what happening while the type of the card is non of them?

    unique_ptr<Fighter> fighter(new Fighter(name, type));
    return *fighter;
}

Card& intToCard(int i)
{
    switch (i) {
        case (GOBLIN): {
            unique_ptr<Goblin> goblin(new Goblin());
            return *goblin;
        }
        case (VAMPIRE): {
            unique_ptr<Vampire> vampire(new Vampire());
            return *vampire;
        }
        case (DRAGON): {
            unique_ptr<Dragon> dragon(new Dragon());
            return *dragon;
        }
        case (MERCHANT): {
            unique_ptr<Merchant> merchant(new Merchant());
            return *merchant;
        }
        case (TREASURE): {
            unique_ptr<Treasure> treasure(new Treasure());
            return *treasure;
        }
        case (PITFALL): {
            unique_ptr<Pitfall> pitfall(new Pitfall());
            return *pitfall;
        }
        case (BARFIGHT): {
            unique_ptr<Barfight> barfight(new Barfight());
            return *barfight;
        }
    }
    /// TO DO - what happening while the type of the card is non of them?

    unique_ptr<Fairy> fairy(new Fairy());
    return *fairy;
}


void Mtmchkin::playRound()
{
    int activePlayers = m_playersQueue.size();
    printRoundStartMessage(m_roundCount);
    for(int j=0; j<activePlayers; j++)
    {
        /// TO DO: arrange the applyEncounter
        printTurnStartMessage(m_playersQueue.front()->getName());
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
    printLeaderBoard();
    m_roundCount++;
}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundCount;
}

bool Mtmchkin::isGameOver() const {
    return (m_winnersPlayers.size()+ m_losersPlayers.size()==m_numOfPlayers);
}

Mtmchkin::~Mtmchkin() {
    while(!m_losersPlayers.isEmpty())
    {
        delete m_losersPlayers.front();
        m_losersPlayers.popFront();
    }
    while(!m_cardsQueue.isEmpty())
    {
        delete m_cardsQueue.front();
        m_cardsQueue.popFront();
    }
    while(!m_winnersPlayers.isEmpty())
    {
        delete m_winnersPlayers.front();
        m_winnersPlayers.popFront();
    }
    while(!m_winnersPlayers.isEmpty())
    {
        delete m_winnersPlayers.front();
        m_winnersPlayers.popFront();
    }
    while (!m_playersQueue.isEmpty())
    {
        delete m_playersQueue.front();
        m_playersQueue.popFront();
    }
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int i=1;
    //bool changeQueue = true;
    Queue<Player*> tmpQueue = m_winnersPlayers;
    for(int j = 0; j<NON_LOSERS_QUEUES; j++){
        while(!tmpQueue.isEmpty()){
            printPlayerLeaderBoard(i, *tmpQueue.front());
            tmpQueue.popFront();
            i++;
        }
        tmpQueue = m_playersQueue;
    }
    tmpQueue = m_losersPlayers;
    printBack(tmpQueue, i);

}

void printBack(Queue<Player*> queue, int& i)
{
    if(queue.isEmpty())
        return;
    Player* player = queue.front();
    queue.popFront();
    printBack(queue, i);
    printPlayerLeaderBoard(i, *player);
    i++;
}