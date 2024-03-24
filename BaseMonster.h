#pragma once
#include "Character.h"
#include <string>

enum class MonsterType
{
    AstralLeviathans,
    ShadowRequiem,
    VerdantGuardians,
    LuminousEidolons,
    RuneboundSpecters,
    DuskfangSerpents
};

class BaseMonster : public Character
{
  public:
    BaseMonster(std::string name, int health, int attack);
};
