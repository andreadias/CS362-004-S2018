// cardtest2.c
//
// Andrea Dias
// 4/29/18
// CS 362-400 Spring 2018
// Testing Great Hall Card



#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void myAssert(int a, int b){
	if (a != b) {
		printf("***Test fails! You did not get the intended result***\n");
	}
}

int main() {

    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    int handPos = 0;
    struct gameState *state, *teststate;
    
    struct gameState myGame, myTestGame;
    state = &myGame;
    teststate = &myTestGame;
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    int plusTwo = 2;
    int plusOne = 1;
    
    initializeGame(2, k, 100, state);

    memcpy(teststate, state, sizeof(struct gameState));

    printf("--------------------- Testing Card: GREAT HALL  ----------------------\n");

    cardEffect(great_hall, choice1, choice2, choice3, teststate, handPos, &bonus);
    
    int currentPlayer = whoseTurn(state); 

    
    printf("------------ GREAT HALL: +1 Card, +1 Action, +1 Victory -----------\n");
    printf("Cards in Hand = %d, Expected = %d\n", teststate->handCount[currentPlayer], state->handCount[currentPlayer] + plusOne);
    myAssert(teststate->handCount[currentPlayer], state->handCount[currentPlayer] + plusOne);
    
    printf("Cards in Deck = %d, Expected = %d\n", teststate->deckCount[currentPlayer] + plusTwo, state->deckCount[currentPlayer] - plusOne);
	myAssert(teststate->deckCount[currentPlayer] + plusTwo, state->deckCount[currentPlayer] - plusOne);
	
	printf("Number of Actions = %d, Expected = %d\n", teststate->numActions, state->numActions + plusOne);
	myAssert(teststate->numActions, state->numActions + plusOne);
	printf("Victory Points = %d, Expected = %d\n", scoreFor(currentPlayer, teststate), scoreFor(currentPlayer, state) + plusOne);
	myAssert(scoreFor(currentPlayer, teststate), scoreFor(currentPlayer, state) + plusOne);

 
  	printf("--------------------- Testing Cards in Play --------------------- \n");
    printf("# of Estate Cards = %d, Expected = %d\n", teststate->supplyCount[estate], state->supplyCount[estate]);
    myAssert(teststate->supplyCount[estate], state->supplyCount[estate]);
 	printf("# of Duchy Cards = %d, Expected = %d\n", teststate->supplyCount[duchy], state->supplyCount[duchy]);
 	myAssert(teststate->supplyCount[duchy], state->supplyCount[duchy]);
  	printf("# of Province Cards = %d, Expected = %d\n", teststate->supplyCount[province], state->supplyCount[province]);
  	myAssert(teststate->supplyCount[province], state->supplyCount[province]);
  	printf("# of Copper Cards = %d, Expected = %d\n", teststate->supplyCount[copper], state->supplyCount[copper]);
  	myAssert(teststate->supplyCount[copper], state->supplyCount[copper]);
  	printf("# of Silver Cards = %d, Expected = %d\n", teststate->supplyCount[silver], state->supplyCount[silver]);
  	myAssert(teststate->supplyCount[silver], state->supplyCount[silver]);
  	printf("# of Gold Cards = %d, Expected = %d\n", teststate->supplyCount[gold], state->supplyCount[gold]);   
  	myAssert(teststate->supplyCount[gold], state->supplyCount[gold]); 

    
    return 0;

}

/****

REFACTORED CODE:

int refactorGreatHall(int card, struct gameState *state, int handPos) {

	int currentPlayer = whoseTurn(state);
      
      //+1 Card regular.. added second drawCard statement
      drawCard(currentPlayer, state);
      drawCard(currentPlayer, state); //added this statement for refactor
			
      //+1 Actions
      state->numActions++;
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;

***/