#include <string>
#include "Queue.h"
#include "Player.h"
#include "Card.h"

#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    

    Mtmchkin(const Mtmchkin&) = delete;
    Mtmchkin& operator=(const Mtmchkin& other) = delete;
    ~Mtmchkin();

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    int m_roundCount;
    int m_numOfPlayers;
    Queue<Player*> m_losersPlayers;
    Queue<Card*> m_cardsQueue;
    Queue<Player*> m_playersQueue;
    Queue<Player*> m_winnersPlayers;

};



#endif /* MTMCHKIN_H_ */
