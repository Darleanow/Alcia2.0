#include "MonsterFactory.h"

MonsterFactory::MonsterFactory()
{
    register_monsters();
}

MonsterFactory::~MonsterFactory()
{
}

BaseMonster MonsterFactory::create(MonsterType e_monster_type)
{
    auto monster_display_name = format_name(e_monster_type);

    auto monster_stats = map_registered_monsters[e_monster_type];
    BaseMonster monster(monster_display_name, monster_stats.at(0), monster_stats.at(1));

    return monster;
}

std::string MonsterFactory::format_name(MonsterType e_monster_name)
{
    switch (e_monster_name)
    {
    case MonsterType::AstralLeviathans:
        return "Astral Leviathans";
    case MonsterType::DuskfangSerpents:
        return "Dusk fang Serpents";
    case MonsterType::LuminousEidolons:
        return "Luminous Eidolons";
    case MonsterType::RuneboundSpecters:
        return "RuneBound Specters";
    case MonsterType::VerdantGuardians:
        return "Verdant Guardians";
    case MonsterType::ShadowRequiem:
        return "Shadow Requiem";
    default:
        return "None";
    }
}

void MonsterFactory::register_monsters()
{
    map_registered_monsters = {{MonsterType::AstralLeviathans, {20, 5}},  {MonsterType::DuskfangSerpents, {40, 15}},
                               {MonsterType::LuminousEidolons, {60, 30}}, {MonsterType::RuneboundSpecters, {85, 50}},
                               {MonsterType::ShadowRequiem, {120, 80}},   {MonsterType::VerdantGuardians, {250, 145}}};
}
