#include "sampletestUtils.h"
#include "snake_and_ladder.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Game* snake_and_ladder = NULL; 

void test_create_snake_and_ladder_game(){
	snake_and_ladder = createGame(2);
	ASSERT(snake_and_ladder->jumps[8] == 29 && snake_and_ladder->jumps[18] == 6);
}

// void test_add_3_players_Ajit_Jaideep_Gaurav(){
// 	addPlayers(snake_and_ladder);
// 	ASSERT(areEqual(snake_and_ladder->player[0].name, "Ajit")==0);
// }

void test_print_randome_value_of_dice(){
	int value = dice();
	printf("%d\n",value );getchar();
	ASSERT(value < 7);
}

void test_play_the_game(){
	int numberOfPlayers;
	printf("Enter number of players\n");
	scanf("%d",&numberOfPlayers);
	snake_and_ladder = createGame(numberOfPlayers);
	addPlayers(snake_and_ladder);
	startGame(snake_and_ladder);
	ASSERT(1);
}