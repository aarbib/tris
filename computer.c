#include <stdio.h>
#include <stdlib.h>
#include "basef.h"
#include "gamef.h"


int foundTwo(int arrayLine[9])
{

    int first, second, third;

    int listAlmostWins[24][3] = {
        {0,1,2},{1,2,0},{0,2,1},
        {3,4,5},{4,5,3},{3,5,4},
        {6,7,8},{7,8,6},{6,8,7},
        {0,3,6},{3,6,0},{0,6,3},
        {1,4,7},{4,7,1},{1,7,4},
        {2,5,8},{5,8,2},{2,8,5},
        {0,4,8},{4,8,0},{0,8,4},
        {2,4,6},{4,6,2},{2,6,4}
    };

    for (int i = 1; i<24; i++)
    {
        first =  listAlmostWins[i][0];
        second= listAlmostWins[i][1];
        third = listAlmostWins[i][2];
        if (arrayLine[first] == arrayLine[second] && arrayLine[first] != 0 && arrayLine[third] == 0)
        {
            return third;
        }
    }
    return 0;

}

int computerInput(int grid[9])
{

    printf("giocatore 2: computer ");
    int spot = foundTwo(grid);
    while(grid[spot] != 0)
    {
        spot++;
    }
    return spot+1;
}

