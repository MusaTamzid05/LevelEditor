#include "game_data.h"

namespace Game {
    void GameData::remove_inactive_objects() {
        std::vector<unsigned int> remove_indexes;

        for(unsigned int i = 0; i < game_objects.size(); i += 1) { 
            if(!game_objects[i]->active)
                remove_indexes.push_back(i);
        }

        for(unsigned int index : remove_indexes) 
            game_objects.erase(
                    game_objects.begin() + index
                    );
        

    }



}
