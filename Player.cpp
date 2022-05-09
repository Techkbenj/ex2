#include "Player.h"

const int DEFAULT_LEVEL = 1;
const int DEFAULT_COINS = 0;
const int MAX_LEVEL = 10;

bool Player::isNegative(int number)
{
    return (number < 0);
}

Player::Player(string name, int maxHp, int force) :
    m_name(name), m_level(DEFAULT_LEVEL), m_coins(DEFAULT_COINS)
{   
    if(isNegative(force))
    {
        m_force = DEFAULT_FORCE;
    }
    else
    {
        m_force = force;
    }
    if(isNegative(maxHp))
    {
        m_maxHp = DEFAULT_MAX_HP;
    }
    else
    {
        m_maxHp = maxHp;
    }
    m_hp = maxHp;
}

Player::Player(const Player& player)
{
    m_name = player.m_name;
    m_level = player.m_level;
    m_force = player.m_force;
    m_maxHp = player.m_maxHp;
    m_hp = player.m_maxHp;
    m_coins = player.m_coins;
}

Player& Player::operator=(const Player& player)
{
    if (this == &player) {
		return *this;
	}
    m_name = player.m_name;
    m_level = player.m_level;
    m_force = player.m_force;
    m_maxHp = player.m_maxHp;
    m_hp = player.m_maxHp;
    m_coins = player.m_coins;
    return *this;
}

void Player::printInfo()
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_hp, m_coins);
}

void Player::levelUp()
{
    if (m_level < MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel()
{
    return m_level;
}

void Player::buff(int addForce)
{
    if(!isNegative(addForce))
    {
        m_force += addForce;
    }
}

void Player::heal(int health)
{
    if(!isNegative(health))
    {
        m_hp += health;
    }
    if (m_hp > m_maxHp)
    {
        m_hp = m_maxHp;
    }
}

void Player::damage(int hitPoints)
{
    if(!isNegative(hitPoints))
    {
        m_hp -= hitPoints;
    }
    if (m_hp < 0)
    {
        m_hp = 0;
    }
}

bool Player::isKnockedOut()
{
    return (m_hp == 0);
}

void Player::addCoins(int coins)
{
    if(!isNegative(coins))
    {
        m_coins += coins;
    }
}

bool Player::pay(int coins)
{
    if(isNegative(coins))
    {
        return false;
    }
    if (m_coins >= coins)
    {
        m_coins -= coins;
        return true;
    }
    return false;
}

int Player::getAttackStrength()
{
    return m_level + m_force;
}