#pragma once

#include <string>

#include "Character.h"

class Hero : public Character
{
  public:
    Hero(std::string m_name, int m_health, int m_attack);
};
