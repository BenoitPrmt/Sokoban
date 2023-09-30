#include "../inc/sokoban.h"

void refresh(game * sokoban)
{
    sleep(1);
    system("clear");
    update_map(sokoban);
    print_map(sokoban->map);
}

int can_the_box_move_to_victory(game * sokoban)
{
    if(sokoban->box.pos_y == 0 && sokoban->victory.pos_y > 0) // stuck on top : fail
    {
        return(-1);
    }
    else if(sokoban->box.pos_y == 9 && sokoban->victory.pos_y < 9) // stuck on bottom : fail
    {
        return(-1);
    }
    else if(sokoban->box.pos_x == 0 && sokoban->victory.pos_x > 0) // stuck on left : fail
    {
        return(-1);
    }
    else if(sokoban->box.pos_x == 9 && sokoban->victory.pos_x < 9) // stuck on right : fail
    {
        return(-1);
    }

    return(1); // the box can still win
}

int check_win(game * sokoban)
{
    // check if the player has won
    if(compare_positions(sokoban->victory, sokoban->box) == 1)
    {
        // if the player has won, return 1
        return(1);
    }
    return(0);
    
}

int check_loss(game * sokoban)
{
    // check if the player has lost
    if(can_the_box_move_to_victory(sokoban) == -1)
    {
        // if the player has lost return -1
        return (-1);
    }
    return(0);
}

void game_loop(game * sokoban)
{
    refresh(sokoban);

    while(check_win(sokoban) != 1 && check_loss(sokoban) != -1)
    {
        ask_for_move(sokoban);
        refresh(sokoban);
    }
}

void init_game(game * sokoban)
{
    init_map(sokoban);
    init_positions(sokoban);
    update_map(sokoban);
}
