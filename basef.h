#ifndef BASEF_H_INCLUDED
#define BASEF_H_INCLUDED

typedef struct{
    int grigliaTris[9]; //le caselle del tris
    int gridSpot;       //la casella selezionata
    int turn;           //il turno
    int nPlayers;       //numero giocatori
}GAMEDATA;



void prinTris(int griglia[]);
int intInput(char message[]);
char charInput();
GAMEDATA allZero();


#endif // BASEF_H_INCLUDED
