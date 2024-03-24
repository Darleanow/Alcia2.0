// Alcia 2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Hero.h"
#include "MonsterFactory.h"
#include "Story.h"
#include <iostream>

int main()
{

    Hero hero("my_hero", 100, 10);

    MonsterFactory factory;
    auto monster = factory.create(MonsterType::AstralLeviathans);

    std::cout << hero.get_name() << std::endl;
    std::cout << monster.get_name() << std::endl;
    for (auto elem : monster.get_stats())
    {
        std::cout << elem << std::endl;
    }

    std::cout << std::endl << std::endl;

    Story story;
    story.output_story_part();

    std::cout << std::endl;
    story.output_story_part();
}
