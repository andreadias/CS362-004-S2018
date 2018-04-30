/* -----------------------------------------------------------------------
 * Used the testUpdateCoins.c file as a template for this code, as stated 
 * as being allowed in the Assignment 3 Assistance (2) page on Canvas
 * -----------------------------------------------------------------------
 */
 
  // Andrea Dias
// 4/29/18
// CS 362-400 Spring 2018

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


void myAssert(int a, int b){
	if (a != b) {
		printf("***Test fails! You did not get the intended result***\n");
	}


}

int main() {

    int k[10] = {adventurer, council_room, feast, gardens, mine ,remodel, smithy, village, baron, great_hall};

    struct gameState *state, *teststate;
    struct gameState myGame, myTestGame;
    state = &myGame;
    teststate = &myTestGame;
    int playerNum, testPlayerNum;

    initializeGame(2, k, 40, state);
    memcpy(teststate, state, sizeof(struct gameState));
    

    printf ("TESTING whoseTurn():\n");

	printf("Starting turn: \n");
	testPlayerNum = whoseTurn(teststate);
	playerNum = whoseTurn(state);
	printf("Whose turn is it? Player: %d\n", playerNum);
	myAssert(playerNum, testPlayerNum); //check if correct player is up
	
	printf("End of Player %d turn, Who is Next?\n", playerNum);
	endTurn(teststate); //end of players turn, should go to next player
	testPlayerNum = whoseTurn(teststate);
	playerNum = whoseTurn(teststate);
	printf("Player: %d\n", playerNum);
	myAssert(playerNum, testPlayerNum); //check if correct player is up
	
	printf("End of Player %d turn, Who is Next?\n", playerNum);
	endTurn(teststate); //end of players turn, should go to next player
	testPlayerNum = whoseTurn(teststate);
	playerNum = whoseTurn(teststate);
	printf("Player: %d\n", playerNum);
	myAssert(playerNum, testPlayerNum); //check if correct player is up
	
	printf("End of Player %d turn, Who is Next?\n", playerNum);
	endTurn(teststate); //end of players turn, should go to next player
	testPlayerNum = whoseTurn(teststate);
	playerNum = whoseTurn(teststate);
	printf("Player: %d\n", playerNum);
	myAssert(playerNum, testPlayerNum); //check if correct player is ups


    return 0;
}
