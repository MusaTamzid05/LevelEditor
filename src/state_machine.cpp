#include "state_machine.h"
#include "game_state.h"
#include "game_data.h"


namespace Game {
    StateMachine* StateMachine::instance = nullptr;


    StateMachine::StateMachine() {

    }

    StateMachine::~StateMachine() {
    }

    StateMachine* StateMachine::get_instance() {
        if(instance == nullptr)
            instance = new StateMachine();

        return instance;

    }

    void StateMachine::change(GameState* new_state, GameData* game_data) {
        if(current_state != nullptr) {
            if(current_state->type == new_state->type)
                return;

            current_state->exit(game_data);;
        }

        current_state = new_state;
        current_state->enter(game_data);;


    }

}
