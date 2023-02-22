#ifndef GAMEF_H_INCLUDED
#define GAMEF_H_INCLUDED

int howManyPlayers();
GAMEDATA gameSet(GAMEDATA trisData);
int getInput();
int checkWin(int arrayLine[9]);
int endGame();

#endif // GAMEF_H_INCLUDED
