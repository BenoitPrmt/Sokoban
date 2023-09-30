#ifndef __SOKOBAN_H__
#define __SOKOBAN_H__

/* INCLUDES */
#include <stdlib.h> // malloc, free, exit, rand and system
#include <stdio.h> // printf and scanf
#include <string.h> // strlen, strcpy and strcmp
#include <unistd.h> // sleep

/* DATA STRUCTURES */

struct s_pos {
    int pos_y;
    int pos_x;
};

typedef struct s_pos position;

struct s_game {
    char **map;
    position box;
    position player;
    position victory;
};

typedef struct s_game game;

/* FUNCTIONS */

// position.c
void init_positions(game * sokoban);
int compare_positions(position pos1, position pos2);

// map.c
void print_map(char **map);
void init_map(game *game);
void update_map(game * sokoban);
void update_map_player(game * sokoban);
void update_map_box(game * sokoban);
void update_map_victory(game * sokoban);

// moves.c
void move_up(game * sokoban);
void move_down(game * sokoban);
void move_left(game * sokoban);
void move_right(game * sokoban);
void move_box(game * sokoban, char * move);
void handle_move(game * sokoban, char * move);
void ask_for_move(game * sokoban);

// game.c
void init_game(game * sokoban);
int check_win(game * sokoban);
int check_loss(game * sokoban);
void game_loop(game * sokoban);
void refresh(game * sokoban);

#endif //__SOKOBAN_H__
