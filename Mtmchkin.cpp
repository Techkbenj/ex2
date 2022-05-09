  //
// Created by itay on 06/05/2022.
//
#include "Mtmchkin.h"

const int MAX_LEVEL = 10;

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) :
        m_player(Player(std::string(playerName))), m_cards_array(new Card[numOfCards]),
        m_size(numOfCards), m_index(0), m_game_status(GameStatus::MidGame)
{
    for (int i=0;i<numOfCards;i++)
    {
        m_cards_array[i] = Card(cardsArray[i]);
    }
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards_array;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_game_status;
}

void Mtmchkin::playNextCard()
{
    Card playing_card = m_cards_array[m_index];
    playing_card.printInfo();
    playing_card.applyEncounter(m_player);
    if (m_player.getLevel() == MAX_LEVEL)
    {
        m_game_status = GameStatus::Win;
    }
    if (m_player.isKnockedOut())
    {
        m_game_status = GameStatus::Loss;
    }
    m_player.printInfo();
    m_index++;
    if (m_index == m_size)
    {
        m_index = 0;
    }
}

bool Mtmchkin::isOver() const
{
    if (GameStatus::MidGame == m_game_status)
    {
        return false;
    }
    return true;
}
