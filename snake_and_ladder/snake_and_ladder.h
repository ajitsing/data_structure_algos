#include <stdio.h>
#include "linkedlist.h"

typedef struct{
	char name[20];
	int position;
}Player;

typedef struct{
	int jumps[101];
	Player *player;
	int numberOfPlayers;

}Game;

Game* createGame(int numberOfPlayers);
int areEqual(char* a, char* b);
void addPlayers(Game* snake_and_ladder);
int dice();
void startGame(Game* snake_and_ladder);