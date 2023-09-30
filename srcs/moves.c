#include "../inc/sokoban.h"

void move_box(game * sokoban, char * move)
{
    if(compare_positions(sokoban->player, sokoban->box) == 1)
    {
        if(strcmp(move, "up") == 0)
        {
            if(sokoban->box.pos_y > 0)
            {
                sokoban->box.pos_y--;
            }
        }
        else if(strcmp(move, "down") == 0)
        {
            if(sokoban->box.pos_y < 9)
            {
                sokoban->box.pos_y++;
            }
        }
        else if(strcmp(move, "left") == 0)
        {
            if(sokoban->box.pos_x > 0)
            {
                sokoban->box.pos_x--;
            }
        }
        else if(strcmp(move, "right") == 0)
        {
            if(sokoban->box.pos_x < 9)
            {
                sokoban->box.pos_x++;
            }
        }
    }
}

void move_up(game * sokoban)
{
    if(sokoban->player.pos_y > 0) // if the player is not already on top of the map
    {
        position tmp;
        tmp.pos_y = sokoban->player.pos_y - 1;
        tmp.pos_x = sokoban->player.pos_x;

        sokoban->player.pos_y = sokoban->player.pos_y - 1;
        
        move_box(sokoban, "up");
    }
}

void move_down(game * sokoban)
{
    if(sokoban->player.pos_y < 9) // if the player is not already on the bottom of the map
    {
        position tmp;
        tmp.pos_y = sokoban->player.pos_y + 1;
        tmp.pos_x = sokoban->player.pos_x;

        sokoban->player.pos_y = sokoban->player.pos_y + 1;

        move_box(sokoban, "down");
    }
}

void move_left(game * sokoban)
{
    if(sokoban->player.pos_x > 0) // if the player is not already on the left of the map
    {
        position tmp;
        tmp.pos_y = sokoban->player.pos_y;
        tmp.pos_x = sokoban->player.pos_x - 1;

        sokoban->player.pos_x = sokoban->player.pos_x - 1;

        move_box(sokoban, "left");
    }
}

void move_right(game * sokoban)
{
    if(sokoban->player.pos_x < 9) // if the player is not already on the right of the map
    {
        position tmp;
        tmp.pos_y = sokoban->player.pos_y;
        tmp.pos_x = sokoban->player.pos_x + 1;

        sokoban->player.pos_x = sokoban->player.pos_x + 1;

        move_box(sokoban, "right");
    }
}

void handle_move(game * sokoban, char * move)
{
    if (strcmp(move, "up") == 0 || strcmp(move, "u") == 0)
    {
        move_up(sokoban);

    } else if (strcmp(move, "down") == 0 || strcmp(move, "d") == 0)
    {
        move_down(sokoban);

    } else if (strcmp(move, "left") == 0 || strcmp(move, "l") == 0)
    {
        move_left(sokoban);

    } else if (strcmp(move, "right") == 0 || strcmp(move, "r") == 0)
    {
        move_right(sokoban);
    }
}

void ask_for_move(game * sokoban)
{
    // print_map(sokoban->map);

    char* next_move;
    printf("Where do you want to move ?  up/u | down/d | left/l | right/r : ");
    scanf("%s", next_move);

    handle_move(sokoban, next_move);
}