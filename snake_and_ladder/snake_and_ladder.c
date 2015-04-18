#include "snake_and_ladder.h"
#include <string.h>
#include <time.h>

Game* createGame(int numberOfPlayers){
	int i;
	Game* snake_and_ladder = (Game*) malloc(sizeof(Game));
	snake_and_ladder->player = (Player*) malloc(sizeof(Player) * numberOfPlayers);
	snake_and_ladder->numberOfPlayers = numberOfPlayers;

	for (i = -1; i != 101; i++)snake_and_ladder->jumps[i] = -1;

	snake_and_ladder->jumps[8] = 29;
	snake_and_ladder->jumps[14] = 39;
	snake_and_ladder->jumps[26] = 43;
	snake_and_ladder->jumps[36] = 77;
	snake_and_ladder->jumps[50] = 94;
	snake_and_ladder->jumps[62] = 81;

	snake_and_ladder->jumps[97] = 21;
	snake_and_ladder->jumps[92] = 67;
	snake_and_ladder->jumps[85] = 54;
	snake_and_ladder->jumps[70] = 34;
	snake_and_ladder->jumps[53] = 2;
	snake_and_ladder->jumps[33] = 10;
	snake_and_ladder->jumps[18] = 6;

	return snake_and_ladder;
}

int areEqual(char* a, char* b){
	return strcmp(a,b);
}

void addPlayers(Game* snake_and_ladder){
	int i;
	for (i = 0; i < snake_and_ladder->numberOfPlayers; i++){
		printf("Enter the name of %d player\n",i );
		scanf("%s",snake_and_ladder->player[i].name);
	}
}

int dice(){
	int long long  random = 14729907655;
	srand(time(NULL));
	while(random > 14729907653)random = rand();
	return (random % 6 + 1);
}

void startGame(Game* snake_and_ladder){
	int i,diceNumber,countSix = 0,flag = 0;

	for (i = 0; i < snake_and_ladder->numberOfPlayers; i++){
		snake_and_ladder->player[i].position = -1;
	}

	for (i = 0; ;i++){

		if(i == snake_and_ladder->numberOfPlayers)i=0;
		printf("=========================================================>\n%s's turn press ENTER to roll the dice\n",snake_and_ladder->player[i].name );getchar();
		diceNumber = dice();
		printf("dice number: %d\n",diceNumber );getchar();

		if(snake_and_ladder->player[i].position == -1 && diceNumber == 6){
			flag = 1;
			snake_and_ladder->player[i].position = 0;
			printf("%s can proceed now\n",snake_and_ladder->player[i].name );getchar();
		}

		if(flag ==0 && snake_and_ladder->player[i].position != -1 && (snake_and_ladder->player[i].position + diceNumber) <= 100)snake_and_ladder->player[i].position += diceNumber;
			
		if(snake_and_ladder->jumps[snake_and_ladder->player[i].position] != -1){
			if(snake_and_ladder->player[i].position < snake_and_ladder->jumps[snake_and_ladder->player[i].position] ){
				printf("	==>Ladder from %d to %d\n\n",snake_and_ladder->player[i].position,snake_and_ladder->jumps[snake_and_ladder->player[i].position]);
			}
			else printf("	<==Snake from %d to %d\n\n",snake_and_ladder->player[i].position,snake_and_ladder->jumps[snake_and_ladder->player[i].position]);
			snake_and_ladder->player[i].position = snake_and_ladder->jumps[snake_and_ladder->player[i].position];
		}

		if(snake_and_ladder->player[i].position == 100){
			printf("Congratulations\n%s won the match\n",snake_and_ladder->player[i].name );
			break;
		}

		printf("%s is on %d position\n=========================================================>",snake_and_ladder->player[i].name,snake_and_ladder->player[i].position );getchar();

		if(diceNumber == 6 && flag == 0){
			i--;
			continue;
		}

		flag = 0;
	}
}