#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

namespace Game {
    struct GameState;
    struct GameData;

    class StateMachine {

        public:
            virtual ~StateMachine();
            static StateMachine* get_instance();
            void change(GameState* new_state, GameData* game_data);

            GameState* current_state;


        private:
            StateMachine();
            static StateMachine* instance;
    };
};


#endif
