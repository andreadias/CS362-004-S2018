// randomtestadventurer.c
//
// Andrea Dias
// 5/13/18
// CS 362-400 Spring 2018
// Random Testing Adventurer Card


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

/*
void myAssert(int a, int b){
	if (a != b) {
		printf("***** Test fails! You did not get the intended result *****\n");
	}
}
*/

int main() {

    struct gameState *state, *teststate;  
    struct gameState myGame, myTestGame;
    state = &myGame;
    teststate = &myTestGame;
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    int numPlayers = 2;
    int cardDrawn = 0;
    int drawntreasure = 0;
    int card;
    int discard = 0;
    srand(time(NULL));

     
    initializeGame(numPlayers, k, 40, state);
    initializeGame(numPlayers, k, 40, teststate);

    memcpy(teststate, state, sizeof(struct gameState));
    int currentPlayer = whoseTurn(teststate); 
    
    
  	int cardArray[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, 
   		remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager,
   		sea_hag, treasure_map};  
    
    char *nameArray[27] = {"CURSE", "ESTATE", "DUCHY", "PROVINCE", "COPPER", "SILVER", "GOLD", "ADVENTURER", "COUNCIL ROOM",
			"FEAST", "GARDENS", "MINE", "REMODEL", "SMITHY", "VILLAGE", "BARON", "GREAT HALL", "MINION", "STEWARD", 
			"TRIBUTE", "AMBASSADOR", "CUTPURSE", "EMBARGO", "OUTPOST", "SALVAGER", "SEA HAG", "TREASURE MAP"};
    

    printf("------------------------- Testing Card: ADVENTURER  --------------------------\n");

    
    printf("Hand Count: %d, Expected: %d\n", state->handCount[currentPlayer], teststate->handCount[currentPlayer]);
    //myAssert(state->handCount[currentPlayer], teststate->handCount[currentPlayer]);

	while(drawntreasure < 2) {

		card = rand() % 27;
		cardDrawn = cardArray[card];
		
		printf("Card Drawn: %s\n", nameArray[cardDrawn]);
	
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
			printf("You drew a treasure card!\n");
	 		drawntreasure++;
	 		}
	 	
		else {
			discard++;
			state->discard[currentPlayer][state->discardCount[currentPlayer]]++;
			}
	}

	printf("Discarded Count %d, Expected: %d\n", discard, state->discard[currentPlayer][state->discardCount[currentPlayer]++]);
	//myAssert(state->discard[currentPlayer][state->discardCount[currentPlayer]++], discard);
	printf("Hand Count: %d, Expected: %d\n", state->handCount[currentPlayer] + drawntreasure, teststate->handCount[currentPlayer] + drawntreasure);
	//myAssert(state->handCount[currentPlayer] + drawntreasure, teststate->handCount[currentPlayer] + drawntreasure);

    return 0;

}
