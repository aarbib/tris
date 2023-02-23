#include <stdio.h>
#include <stdlib.h>
#include "basef.h"

//stampa la griglia del tris e i suoi elementi
//int griglia[] contiene gli elementi
// 0 = "  "
// 1 = "><"
// 2 = "()"
void prinTris(int griglia[])
{
    const char layout[] =
        "+--+--+--+\n"
        "|%s|%s|%s|\n"
        "+--+--+--+\n"
        "|%s|%s|%s|\n"
        "+--+--+--+\n"
        "|%s|%s|%s|\n"
        "+--+--+--+\n";

    char simboli[9][3] = {
        "  ", "  ", "  ",
        "  ", "  ", "  ",
        "  ", "  ", "  "
    };

    for (int i = 0; i < 9; i++) {
        switch (griglia[i]) {
        case 0:
            break;
        case 1:
            simboli[i][0] = '>';
            simboli[i][1] = '<';
            break;
        case 2:
            simboli[i][0] = '(';
            simboli[i][1] = ')';
            break;
        default:
            printf("Codice nella griglia non supportato!");
            break;
        }
    }

    printf(layout,
        simboli[0], simboli[1], simboli[2],
        simboli[3], simboli[4], simboli[5],
        simboli[6], simboli[7], simboli[8]);
}

//prende come input solo e soltanto un intero
int intInput(char message[])
{
    char input[100];
    int num;

    while (1)
    {
        fgets(input, 100, stdin);
        if (sscanf(input, "%d", &num) == 1)
        {
            break;
        }
        printf("devi inserire un numero\n"); //in realt� pija pure altri interi ma shhh
        printf("%s",message);
    }

    return num; //ritorna un int
}

//prende come input solo e soltanto un char
char charInput()
{
    char input[100];
    char lett;

    while (1)
    {
        fgets(input, 100, stdin);
        if (sscanf(input, "%c", &lett) == 1)
        {
            break;
        }
        printf("vuoi continuare a giocare?(S/N): "); //in realt� prende tutti i char
    }

    return lett; //ritorna un char
}
//in entrambi i casi sta ad altre funzioni controllare se i dati inseriti sono utilizzabili
//queste funzioni servono solo a ottenere dei dati specifici come input e perch� scanf fa ridere i polli

//funzione brutta in culo che rende ogni valore in GAMEDATA 0
GAMEDATA allZero()
{
    GAMEDATA allNull;
    for(int i = 0; i < 9; i++){allNull.grigliaTris[i] = 0;}
    allNull.gridSpot = 0;
    allNull.turn = 0;
    allNull.nPlayers = 0;
    return allNull;
}
//non potevi fare GAMEDATA foo = {}? A QUANTO PARE NO

