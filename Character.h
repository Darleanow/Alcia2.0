#pragma once
#include <string>
#include <vector>

class Character
{
  public:
    Character(std::string name, int health, int attack);

    void attack(Character &target);
    void take_damage(int amount);
    std::string get_name();
    std::vector<int> get_stats();

  private:
    std::string s_name;
    int m_health;
    int m_attack;
};
