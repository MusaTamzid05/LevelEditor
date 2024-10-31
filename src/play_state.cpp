#include "play_state.h"
#include "game_data.h"
#include "consts.h"
#include <raylib.h>


namespace Game {
    PlayState::PlayState() {
        type = PAUSE;
    }

    PlayState::~PlayState() {

    }

    void PlayState::enter(GameData* game_data) {

    }

    void PlayState::render(GameData* game_data) {
        GameState::render(game_data);

    }


    void PlayState::update(GameData* game_data) {

        if(IsKeyDown(KEY_A))  {
            game_data->player->turn_left();
            game_data->player->add_position((Vector2){0.0f, -PLAYER_SPEED});
        }

        if(IsKeyDown(KEY_D))  {
            game_data->player->turn_right();
            game_data->player->add_position((Vector2){0.0f, PLAYER_SPEED});
        }


        if(IsKeyDown(KEY_W))  {
            game_data->player->turn_forward();
            game_data->player->add_position((Vector2){PLAYER_SPEED , 0.0f});
        }


        if(IsKeyDown(KEY_S))  {
            game_data->player->turn_backward();
            game_data->player->add_position((Vector2){-PLAYER_SPEED , 0.0f});
        }

        bool key_release = IsKeyReleased(KEY_A) || 
             IsKeyReleased(KEY_D) ||
             IsKeyReleased(KEY_W) ||
             IsKeyReleased(KEY_S);


        if(key_release) 
            game_data->player->set_idle();

        GameState::update(game_data);
    }



    void PlayState::exit(GameData* game_data) {

    }

}

