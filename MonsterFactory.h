#pragma once
#include "BaseMonster.h"
#include <map>
#include <vector>

class MonsterFactory
{
  public:
    MonsterFactory();
    ~MonsterFactory();

    BaseMonster create(MonsterType e_monster_type);

  private:
    void register_monsters();

    // Helpers
    std::string format_name(MonsterType e_monster_name);

    std::map<MonsterType, std::vector<int>> map_registered_monsters;
};
