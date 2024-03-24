#pragma once
#include <map>
#include <string>
#include <vector>

class Story
{
  public:
    Story(double current_index = 0.01);

    void output_story_part();

  private:
    double f_current_story_index;
};
