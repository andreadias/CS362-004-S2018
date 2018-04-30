// cardtest3.c
//
// Andrea Dias
// 4/29/18
// CS 362-400 Spring 2018
// Testing Adventurer Card


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
    int numPlayers = 2;
    int discardedCard = 1;
    int three = 3;

    
    initializeGame(numPlayers, k, 40, state);
    initializeGame(numPlayers, k, 40, teststate);

    memcpy(teststate, state, sizeof(struct gameState));
    int currentPlayer = whoseTurn(state); 

    printf("------------------------- Testing Card: ADVENTURER  --------------------------\n");
    
    printf("---------- ADVENTURER: Reveal Cards From Deck Until Treasure ----------------\n");
    printf(" ---------------- Is Reached, Discard Revealed Cards -----------------------\n");
    
    printf(" ------------ BEFORE Adventurer Function Has Been Called -------------------\n");
    
    printf("Cards in Hand = %d, Expected = %d\n", teststate->handCount[currentPlayer], state->handCount[currentPlayer]);
    myAssert(teststate->handCount[currentPlayer], state->handCount[currentPlayer]);
    
    printf("Cards in Deck = %d, Expected = %d\n", teststate->deckCount[currentPlayer], state->deckCount[currentPlayer]);
	myAssert(teststate->deckCount[currentPlayer], state->deckCount[currentPlayer]);
	
	printf("Number of Actions = %d, Expected = %d\n", teststate->numActions, state->numActions);
	myAssert(teststate->numActions, state->numActions);
	
	printf("Discarded Cards = %d, Expected = %d\n", teststate->discardCount[currentPlayer], state->discardCount[currentPlayer]);
	myAssert(teststate->discardCount[currentPlayer], state->discardCount[currentPlayer]);
	
	printf("---------------------- Testing Cards in Play ---------------------- \n");
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



    cardEffect(adventurer, choice1, choice2, choice3, teststate, handPos, &bonus);
    cardEffect(adventurer, choice1, choice2, choice3, state, handPos, &bonus);
    
    

    printf(" ------------ AFTER Adventurer Function Has Been Called -------------------\n");
  
    
    printf("Cards in Hand = %d, Expected = %d\n", teststate->handCount[currentPlayer], state->handCount[currentPlayer]);
    myAssert(teststate->handCount[currentPlayer], state->handCount[currentPlayer]);
    
    printf("Cards in Deck = %d, Expected = %d\n", teststate->deckCount[currentPlayer] + discardedCard, state->deckCount[currentPlayer] + discardedCard);
	myAssert(teststate->deckCount[currentPlayer] + discardedCard, state->deckCount[currentPlayer] + discardedCard);
	
	printf("Number of Actions = %d, Expected = %d\n", teststate->numActions, state->numActions);
	myAssert(teststate->numActions, state->numActions);
	
	printf("Discarded Cards = %d, Expected = %d\n", teststate->discardCount[currentPlayer], state->discardCount[currentPlayer] + three);
	myAssert(teststate->discardCount[currentPlayer], state->discardCount[currentPlayer] + three);
	


  	printf("---------------------- Testing Cards in Play ---------------------- \n");
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

int refactorAdventurer(int card, struct gameState *state, int handPos) {
//turned (drawntreasure<2) into (drawntreasure<2)

  int cardDrawn;
  int drawntreasure=0;
  int currentPlayer = whoseTurn(state);
  int nextPlayer = currentPlayer + 1;
  int temphand[MAX_HAND];// moved above the if statement
  int z=0;// this is the counter for the temp hand
  if (nextPlayer > (state->numPlayers - 1)){
    nextPlayer = 0;
  
  
 while(drawntreasure>2){
	if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
	  shuffle(currentPlayer, state);
	}
	drawCard(currentPlayer, state);
	cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	  drawntreasure++;
	else{
	  temphand[z]=cardDrawn;
	  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
	  z++;
	}
      }
      while(z-1>=0){
	state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
	z=z-1;
      }
    }
      return 0;
 

***/