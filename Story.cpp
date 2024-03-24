#include "Story.h"
#include <chrono>
#include <iostream>
#include <thread>

std::map<double, std::vector<std::string>> story_data{
    // Introduction
    {0.01,
     {"You awaken in a dimly lit chamber, the cold stone floor chilling your skin as you struggle to remember how you "
      "got here. The room is small, barely illuminated by flickering torches mounted on the walls. Dust dances in the "
      "dim light, revealing the passage of time in forgotten layers. You notice intricate carvings etched into the "
      "stone walls, depicting scenes of ancient battles and long-forgotten legends."}},
    {0.02,
     {"With a sense of urgency, you rise to your feet and take stock of your surroundings. The chamber is adorned with "
      "strange symbols and mysterious artifacts, each whispering secrets of a bygone era. A faint scent of incense "
      "hangs in the air, mingling with the musty odor of age-old manuscripts. You spot a tarnished mirror in one "
      "corner, its surface reflecting not your image, but shadows of memories long lost."}},
    {0.03,
     {"As you explore further, your fingers brush against the rough texture of a weathered parchment. Unfolding it "
      "with care, you find a cryptic message written in faded ink: 'Seek the truth in the heart of Alcia, where "
      "shadows "
      "dance and secrets lie buried. Beware the whispers of the night, for they may lead you astray.' The words send "
      "a shiver down your spine, awakening a primal instinct urging you to uncover the mysteries that lie ahead."}},
    {0.04,
     {"With no memory of how you arrived here or who you are, you resolve to decipher the enigmatic message. The "
      "weight "
      "of uncertainty hangs heavy on your shoulders as you step out into the bustling streets of Alcia. The city "
      "pulsates "
      "with life and intrigue, its cobblestone paths winding through a tapestry of cultures and secrets waiting to be "
      "unraveled."}}};

Story::Story(double current_index) : f_current_story_index(current_index)
{
}

void Story::output_story_part()
{
    auto string_vector_story = story_data[f_current_story_index];
    for (auto &string_to_print : string_vector_story)
    {
        std::istringstream words(string_to_print);
        std::string word;
        size_t lineLength = 0;
        const int maxWidth = 80;

        while (words >> word)
        {
            if (lineLength + word.length() >= maxWidth)
            {
                std::cout << std::endl;
                lineLength = 0;
            }
            for (char &char_to_print : word)
            {
                std::cout << char_to_print << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                if (char_to_print == '.')
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(250));
                }
            }
            std::cout << " ";
            lineLength += word.length() + 1;
        }
        std::cout << std::endl;
    }
    f_current_story_index += 0.01;
}
