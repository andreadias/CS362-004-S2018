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

    int k[17] = {adventurer, council_room, feast, gardens, mine ,remodel, smithy, village, baron, great_hall, copper, silver, gold, curse, duchy, province, estate};
	char *c[] = {"adventurer", "council_room", "feast", "gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall", "copper", "silver", "gold", "curse", "duchy", "province", "estate"};

    struct gameState state, teststate;
    int numPlayer2 = 2;  
    int i;  
 
	int state1, state2;

 	initializeGame(numPlayer2, k, 100, &teststate); // initialize a new game
 	initializeGame(numPlayer2, k, 100, &state);
 	
 	printf ("TESTING supplyCount() for a 2 player game:\n");

 	    	
    for (i = 0; i < 16; i++)
    {

		state1 = supplyCount(k[i], &teststate);
		state2 = supplyCount(k[i], &state);		
	
	 	printf("\n");
	 	printf("%s: \n", c[i]);
		printf("Starting number of %s cards: %d, expected: %d\n", c[i], state1, state2);
				
		myAssert(state1, state2);
		
		teststate.supplyCount[k[i]]--;
	
		printf("Decrease %s supply by one: %d, expected: %d\n", c[i], teststate.supplyCount[k[i]], state.supplyCount[k[i]]-1);
	
		myAssert(teststate.supplyCount[k[i]], (state.supplyCount[k[i]]-1));
		
		teststate.supplyCount[k[i]]++;
		teststate.supplyCount[k[i]]++;
		teststate.supplyCount[k[i]]++;
	
		printf("Increase %s supply by three: %d, expected: %d\n", c[i], teststate.supplyCount[k[i]], state.supplyCount[k[i]]+2);
	
		myAssert(teststate.supplyCount[k[i]], (state.supplyCount[k[i]]+2));
	
		}


	
    return 0;
}


/*

int supplyCount(int card, struct gameState *state) {
  return state->supplyCount[card];
}
*/

