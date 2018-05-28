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


    initializeGame(2, k, 40, state);
    memcpy(teststate, state, sizeof(struct gameState));
    
    printf("Testing getCost(): \n");
        
    printf("CURSE cost: %d, expected: %d \n", getCost(curse), 0);
    assert(getCost(curse) == 0);
	printf("ESTATE cost: %d, expected: %d \n", getCost(estate), 2);
	assert(getCost(estate) == 2);
	printf("DUCHY cost: %d, expected: %d \n", getCost(duchy), 5);
	assert(getCost(duchy) == 5);
	printf("PROVINCE cost: %d, expected: %d \n", getCost(province), 8);
	assert(getCost(province) == 8);
	printf("COPPER cost: %d, expected: %d \n", getCost(copper), 0);
	assert(getCost(copper) == 0);
	printf("SILVER cost: %d, expected: %d \n", getCost(silver), 3);
	assert(getCost(silver) == 3);
	printf("GOLD cost: %d, expected: %d \n", getCost(gold), 6);
	assert(getCost(gold) == 6);
	printf("ADVENTURER cost: %d, expected: %d \n", getCost(adventurer), 6);
	assert(getCost(adventurer) == 6);
	printf("COUNCIL ROOM cost: %d, expected: %d \n", getCost(council_room), 5);
	assert(getCost(council_room) == 5);
	printf("FEAST cost: %d, expected: %d \n", getCost(feast), 4);
	assert(getCost(feast) == 4);
	printf("GARDENS cost: %d, expected: %d \n", getCost(gardens), 4);
	assert(getCost(gardens) == 4);
	printf("MINE cost: %d, expected: %d \n", getCost(mine), 5);
	assert(getCost(mine) == 5);
	printf("REMODEL cost: %d, expected: %d \n", getCost(remodel), 4);
	assert(getCost(remodel) == 4);
	printf("SMITHY cost: %d, expected: %d \n", getCost(smithy), 4);
	assert(getCost(smithy) == 4);
	printf("VILLAGE cost: %d, expected: %d \n", getCost(village), 3);
	assert(getCost(village) == 3);
	printf("BARON cost: %d, expected: %d \n", getCost(baron), 4);
	assert(getCost(baron) == 4);
	printf("GREAT HALL cost: %d, expected: %d \n", getCost(great_hall), 3);
	assert(getCost(great_hall) == 3);
	printf("MINION cost: %d, expected: %d \n", getCost(minion), 5);
	assert(getCost(minion) == 5);
	printf("STEWARD cost: %d, expected: %d \n", getCost(steward), 3);
	assert(getCost(steward) == 3);
	printf("TRIBUTE cost: %d, expected: %d \n", getCost(tribute), 5);
	assert(getCost(tribute) == 5);
	printf("REMODEL cost: %d, expected: %d \n", getCost(remodel), 4);
	assert(getCost(remodel) == 4);
	printf("AMBASSADOR cost: %d, expected: %d \n", getCost(ambassador), 3);
	assert(getCost(ambassador) == 3);
	printf("CUTPURSE cost: %d, expected: %d \n", getCost(cutpurse), 4);
	assert (getCost(cutpurse) == 4);
	printf("EMBARGO cost: %d, expected: %d \n", getCost(embargo), 2);
	assert (getCost(embargo) == 2);
	printf("OUTPOST cost: %d, expected: %d \n", getCost(outpost), 5);
	assert(getCost(outpost) == 5);
	printf("SALVAGER cost: %d, expected: %d \n", getCost(salvager), 4);
	assert(getCost(salvager) == 4);
	printf("SEA HAG cost: %d, expected: %d \n", getCost(sea_hag), 4);
	assert(getCost(sea_hag) == 4);
	printf("TREASURE MAP cost: %d, expected: %d \n", getCost(treasure_map), 4);
	assert(getCost(treasure_map) == 4);
	
	printf("All tests passed!\n");
	
    return 0;
}


