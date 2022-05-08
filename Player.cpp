#include "Player.h"

const int default_level = 1;
const int default_coins = 0;
const int max_level = 10;

Player::Player(std::string name, int maxHp, int force)
{
    m_name = name;
    m_level = default_level;
    m_force = force;
    m_maxHp = maxHp;
    m_hp = maxHp;
    m_coins = default_coins;
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
    if (this == &player)
    {
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
    char* name = new char[int(m_name.length())];
    for (int i = 0; i < int(m_name.length()); i++)
    {
        name[i] = m_name[i];
    }
    printPlayerInfo(name, m_level, m_force, m_hp, m_coins);
}

void Player::levelUp()
{
    if (m_level < max_level)
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
    m_force += addForce;
}

void Player::heal(int health)
{
    m_hp += health;
    if (m_hp > m_maxHp)
    {
        m_hp = m_maxHp;
    }
}

void Player::damage(int hitPoints)
{
    m_hp -= hitPoints;
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
    m_coins += coins;
}

bool Player::pay(int coins)
{
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