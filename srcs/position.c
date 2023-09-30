#include <time.h>
#include "../inc/sokoban.h"

int compare_positions(position pos1, position pos2)
{
    if(pos1.pos_y == pos2.pos_y)
    {
        if(pos1.pos_x == pos2.pos_x)
        {
            return(1); // the same
        }
        else
        {
            return(-1); // not the same
        }
    }
    else
    {
        return(-1); // not the same
    }
}

void init_positions(game * sokoban)
{
    srand(time(NULL));

    int victory = rand() % 100;
    int box = rand() % 100;
    int player = rand() % 100;

    sokoban->victory.pos_y = victory / 10;
    sokoban->victory.pos_x = victory % 10;

    sokoban->box.pos_y = box / 10;
    sokoban->box.pos_x = box % 10;

    if(sokoban->box.pos_y == 0)
    {
        sokoban->box.pos_y = 1;
    }
    else if(sokoban->box.pos_y == 99)
    {
        sokoban->box.pos_y = 98;
    }

    if(sokoban->box.pos_x == 0)
    {
        sokoban->box.pos_x = 1;
    }
    else if(sokoban->box.pos_x == 99)
    {
        sokoban->box.pos_x = 98;
    }

    sokoban->player.pos_y = player / 10;
    sokoban->player.pos_x = player % 10;
}
