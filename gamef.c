#include <stdio.h>
#include <stdlib.h>
#include "basef.h"
#include "gamef.h"



int howManyPlayers()
{
    int nPlayers;
    while(1)
    {
        char frase[] = "Quanti giocatori?: ";
        printf("%s",frase);
        nPlayers = intInput(frase);
        if(nPlayers == 1 || nPlayers == 2)
        {
            //1 or 2 player stuff
            return nPlayers;
        }
        else
        {
            printf("1 o 2 giocatori!\n");
        }
    }
}

//controlla se uno dei due giocatori ha vinto
int checkWin(int arrayLine[9])
{

    static int listOfWins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}}; //tutte le combinazioni
    for(int i = 0; i < 8; i++)
    {
        int result = arrayLine[listOfWins[i][0]]*arrayLine[listOfWins[i][1]]*arrayLine[listOfWins[i][2]];
        if(result == 1)        // 1*1*1 = 1 (tutte "><")
        {
            printf("vince giocatore 1!\n");
            return 1;
        }
        else if (result == 8)  // 2*2*2 = 8 (tutte "()")
        {
            printf("vince giocatore 2!\n");
            return 1;
        }
    }
    return 0;

}

//prende l'input se compreso fra 1 e 9
int getInput()
{
    int hasInput = 1;
    int input = 0;
    char messaggioUtente[] = "inserisci casella: ";

    while(hasInput)
    {
        printf("%s",messaggioUtente);
        input = intInput(messaggioUtente);
        if (input >= 1 && input <= 9)
        {
            hasInput = 0;
        }
        else
        {
            printf("inserisci un numero da 1 a 9.\n");
        }
}

    return input;
}



//chiede al'utente se vuole uscire dal programma
int endGame()
{
    char userInput;
    do
    {
        printf("vuoi continuare a giocare?(S/N): ");
        userInput = charInput();

    }while (userInput != 'S' && userInput != 's' && userInput != 'N' && userInput != 'n');
    return (userInput != 'N' && userInput != 'n');
}


