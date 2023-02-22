#include <stdio.h>
#include <stdlib.h>
#include "basef.h"
#include "gamef.h"
#include "computer.h"

int main()
{

    GAMEDATA trisData = allZero();
    printf("giochiamo a tris!");
    printf("\n");
    int gameLoop = 1;
    while(gameLoop)
    {
        if (trisData.nPlayers == 0)  //quanti giocatori?
        {
            trisData.nPlayers = howManyPlayers();
            prinTris(trisData.grigliaTris);
        }
        if(trisData.nPlayers == 1 && trisData.turn%2 == 1)  //turno del computer (se nPlayers == 2 è sempre il turno di un giocatore)
        {
            trisData.gridSpot = computerInput(trisData.grigliaTris);
        }
        else                                                //turno del giocatore
        {
            trisData.gridSpot = getInput();
        }
        if (trisData.grigliaTris[trisData.gridSpot-1] == 0)
        {
            printf("giocatore %d, spot %d\n",trisData.turn%2+1, trisData.gridSpot);
            trisData.grigliaTris[trisData.gridSpot-1] = trisData.turn%2+1;
            trisData.turn++;
            prinTris(trisData.grigliaTris);
            if(checkWin(trisData.grigliaTris))
            {
                if(gameLoop=endGame())
                {
                    trisData = allZero();
                }
            }
        }
        else
        {
            printf("inserisci una posizione valida\n");
        }
        if (trisData.turn == 9)
        {
            printf("pareggio!\n");
            if(gameLoop=endGame())
            {
                trisData = allZero();
            }
        }

    }
}
