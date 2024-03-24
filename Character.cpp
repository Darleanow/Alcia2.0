#include "Character.h"

Character::Character(std::string name, int health, int attack) : s_name(name), m_health(health), m_attack(attack)
{
}

void Character::attack(Character &target)
{
    target.take_damage(m_attack);
}

void Character::take_damage(int amount)
{
    m_health -= amount;
}

std::string Character::get_name()
{
    return s_name;
}

std::vector<int> Character::get_stats()
{
    return {m_health, m_attack};
}
