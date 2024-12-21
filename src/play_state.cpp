#include "play_state.h"
#include "game_data.h"
#include "consts.h"
#include "camera.h"
#include <raylib.h>
#include <iostream>


namespace Game {
    PlayState::PlayState() {
        type = PLAY;
    }

    PlayState::~PlayState() {

    }

    void PlayState::enter(GameData* game_data) {
        Camera::get_instance()->init_camera_offset(game_data->player->position);

    }

    void PlayState::render(GameData* game_data) {
        GameState::render(game_data);

    }


    void PlayState::update(GameData* game_data) {

        if(IsKeyDown(KEY_A))  {
            game_data->player->turn_left();
            game_data->player->add_position((Vector2){0.0f, -PLAYER_SPEED}, game_data);
        }

        if(IsKeyDown(KEY_D))  {
            game_data->player->turn_right();
            game_data->player->add_position((Vector2){0.0f, PLAYER_SPEED}, game_data);
        }


        if(IsKeyDown(KEY_W))  {
            game_data->player->turn_forward();
            game_data->player->add_position((Vector2){PLAYER_SPEED , 0.0f}, game_data);
        }


        if(IsKeyDown(KEY_S))  {
            game_data->player->turn_backward();
            game_data->player->add_position((Vector2){-PLAYER_SPEED , 0.0f}, game_data);
        }

        bool key_release = IsKeyReleased(KEY_A) || 
             IsKeyReleased(KEY_D) ||
             IsKeyReleased(KEY_W) ||
             IsKeyReleased(KEY_S);


        if(key_release) 
            game_data->player->set_idle();


        // follow code
    
        Vector3 player_pos = game_data->player->position;

        if(Camera::get_instance()->did_player_move(player_pos))
            Camera::get_instance()->follow(player_pos);
        

        GameState::update(game_data);

    }



    void PlayState::exit(GameData* game_data) {

    }

}

