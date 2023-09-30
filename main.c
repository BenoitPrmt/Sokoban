#include "inc/sokoban.h"

int main()
{
    printf("Starting the game...\n\n");

    // Creating the game structure
    game sokoban;
    init_game(&sokoban);

    // Launching the game loop
    game_loop(&sokoban);

    // Printing game results
    if(check_win(&sokoban) == 1)
    {
        printf("GG, you won !\n");
    }
    else if(check_loss(&sokoban) == -1)
    {
        printf("You lose...\n");
    }

    // Free the map
    int i = 0;
    while(sokoban.map[i] != NULL)
    {
        free(sokoban.map[i]);
        i++;
    }
    free(sokoban.map);

    exit(0);
}
