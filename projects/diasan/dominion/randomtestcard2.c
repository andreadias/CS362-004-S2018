// randomtestcard2.c
//
// Andrea Dias
// 5/13/18
// CS 362-400 Spring 2018
// Random Testing Great Hall Card



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
    int i, j;
    
    initializeGame(2, k, 100, state);

    memcpy(teststate, state, sizeof(struct gameState));

    printf("--------------------- Testing Card: GREAT HALL  ----------------------\n");

    cardEffect(great_hall, choice1, choice2, choice3, teststate, handPos, &bonus);
    
    int currentPlayer = whoseTurn(state); 
    

    for (i = 0; i < 1; i++) { 
    	for (j = 0; j < 25000; j++) {
    
    		int randNum1 = rand() % 15;
    		int randNum2 = rand() % 15;
    		int randNumA = rand() % 15;
    		int randNumV = rand() % 15;
       
    		if (randNum1 == (state->handCount[currentPlayer] + plusOne) 
    			&& randNum2 == (state->deckCount[currentPlayer] - plusOne)
    			&& randNumA == (state->numActions + plusOne)
    			&& randNumV == (scoreFor(currentPlayer, state) + plusOne)) {
 
    			
    			printf("Cards in Hand = %d, Expected = %d\n", randNum1, state->handCount[currentPlayer] + plusOne);
   			 	printf("Cards in Deck = %d, Expected = %d\n", randNum2, state->deckCount[currentPlayer] - plusOne);
   			 	printf("Number of Actions = %d, Expected = %d\n", randNumA, state->numActions + plusOne);
   			 	printf("Victory Points = %d, Expected = %d\n", randNumV, scoreFor(currentPlayer, state) + plusOne);
				break;
				}
    
			}
		}    


 
  	printf("--------------------- Testing Cards in Play --------------------- \n");
	for (i = 0; i < 1; i++) { 
    	for (j = 0; j < 250000; j++) {
    	
    	
    	    int randNum3 = rand() % 50;
    		int randNum4 = rand() % 50;
    		int randNum5 = rand() % 50;

    		
	 		if (randNum3 == state->supplyCount[estate] 
	  				&& randNum4 == state->supplyCount[duchy]
	  				&& randNum5 == state->supplyCount[province] ) {

	
    			printf("# of Estate Cards = %d, Expected = %d\n", randNum3, state->supplyCount[estate]);
  			 	//myAssert(teststate->supplyCount[estate], state->supplyCount[estate]);
 				printf("# of Duchy Cards = %d, Expected = %d\n", randNum4, state->supplyCount[duchy]);
 				//myAssert(teststate->supplyCount[duchy], state->supplyCount[duchy]);
  				printf("# of Province Cards = %d, Expected = %d\n", randNum5, state->supplyCount[province]);
  				//myAssert(teststate->supplyCount[province], state->supplyCount[province]);
 
				break;
				}
			}
		}
	
	
		for (i = 0; i < 1; i++) { 
    		for (j = 0; j < 250000; j++) {
	
	    		int randNum6 = rand() % 50;
    			int randNum7 = rand() % 50;
    			int randNum8 = rand() % 50;
	
		  		if (randNum6 == state->supplyCount[copper]
	  					&& randNum7 == state->supplyCount[silver]
	  					&& randNum8 == state->supplyCount[gold]) {
	
	
	 			printf("# of Copper Cards = %d, Expected = %d\n", randNum6, state->supplyCount[copper]);
  				//myAssert(teststate->supplyCount[copper], state->supplyCount[copper]);
  				printf("# of Silver Cards = %d, Expected = %d\n", randNum7, state->supplyCount[silver]);
  				//myAssert(teststate->supplyCount[silver], state->supplyCount[silver]);
  				printf("# of Gold Cards = %d, Expected = %d\n", randNum8, state->supplyCount[gold]);   
  				//myAssert(teststate->supplyCount[gold], state->supplyCount[gold]);   
  				break;
	
	}}}
	
    
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