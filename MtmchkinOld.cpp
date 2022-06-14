//
// Created by teich on 04/05/2022.
//

#include "MtmchkinOld.h"

MtmchkinOld::MtmchkinOld(const char *playerName, const Card *cardsArray, int numOfCards):
    m_player(Player(playerName)),
    m_cardsArray(new Card[numOfCards]),
    m_numOfCards(numOfCards),
    m_gameStatus(GameStatus::MidGame),
    m_currentCard(cardsArray[0]),
    m_currentIndex(0)
{
    for (int i = 0; i < numOfCards; ++i) {
        m_cardsArray[i] = cardsArray[i];
    }
}

void MtmchkinOld::playNextCard()
{
    if(m_gameStatus==GameStatus::MidGame) {
        m_currentCard.printInfo();
        m_currentCard.applyEncounter(m_player);
        m_player.printInfo();
        m_currentCard = m_cardsArray[++m_currentIndex % m_numOfCards];
        updateStatus(m_gameStatus);
    }
}
bool MtmchkinOld::isOver() const
{
    return (m_player.isKnockedOut() || m_player.getLevel()==MAX_LEVEL);
}


GameStatus MtmchkinOld::getGameStatus() const
{
    return m_gameStatus;
}


void MtmchkinOld::updateStatus(GameStatus gameStatus)
{
    if (m_player.isKnockedOut()){
        m_gameStatus = GameStatus::Loss;
    }
    else if(m_player.getLevel()==MAX_LEVEL) {
        m_gameStatus = GameStatus::Win;
    }
}

MtmchkinOld::~MtmchkinOld()
{
    delete[] m_cardsArray;
}

