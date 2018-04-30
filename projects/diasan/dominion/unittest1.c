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

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

void myAssert(int a, int b){
	if (a != b) {
		printf("***Test fails! You did not get the intended result***\n");
	}

}

int main() {
    int i;
    int numPlayer = 2;
    int player, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    /*
    struct gameState *state, *teststate;
    struct gameState myGame, myTestGame;
    state = &myGame;
    teststate = &myTestGame;
    */
    int count = 5;
    // arrays of all curses, estates, duchys, provinces, great halls
    int curses[count];
    int estates[count];
    int duchys[count];
    int provinces[count];
    int great_halls[count];
    int score = -1;
    for (i = 0; i < count; i++)
    {
        curses[i] = curse;
        estates[i] = estate;
        duchys[i] = duchy;
        provinces[i] = province;
        great_halls[i] = great_hall;
    }

    printf ("TESTING scoreFor():\n");
    for (player = 0; player < numPlayer; player++)
    {
        for (handCount = 1; handCount <= count; handCount++)
        {

 /************************** curses *************************/      

#if (NOISY_TEST == 1)
				printf("\n");
                printf("Test player %d with %d victory cards.\n", player, handCount);
#endif
                initializeGame(numPlayer, k, 100, &G); // initialize a new game
                G.handCount[player] = handCount;                 // set the number of cards on hand

                
                memcpy(G.hand[player], curses, sizeof(int) * handCount); // set all the cards to curse

                score = scoreFor(player, &G);
#if (NOISY_TEST == 1)
                printf("curse score = %d, expected = %d\n", score, handCount * -1);
#endif
                myAssert(score, handCount * -1); // check if the score is correct
                

 /************************** estates *************************/               
           
                          
                memcpy(G.hand[player], estates, sizeof(int) * handCount); // set all the cards to estates
                memcpy(G.discard[player], estates, sizeof(int) * handCount); // set all the cards to estates
                score = scoreFor(player, &G);
#if (NOISY_TEST == 1)
                printf("estates score = %d, expected = %d\n", score, handCount * 1);
#endif
                myAssert(score, handCount * 1); // check if the score is correct
                
 /************************** duchys *************************/               
   
                memcpy(G.hand[player], duchys, sizeof(int) * handCount); // set all the cards to duchys
                memcpy(G.discard[player], duchys, sizeof(int) * handCount); // set all the cards to duchys
                score = scoreFor(player, &G);
#if (NOISY_TEST == 1)
                printf("duchys score = %d, expected = %d\n", score, handCount * 3);
#endif
                myAssert(score, handCount * 3); // check if the score is correct
   
/************************** provinces *************************/               

                
                memcpy(G.hand[player], provinces, sizeof(int) * handCount); // set all the cards to provinces
                memcpy(G.discard[player], provinces, sizeof(int) * handCount); // set all the cards to provinces
                score = scoreFor(player, &G);
#if (NOISY_TEST == 1)
                printf("provinces score = %d, expected = %d\n", score, handCount * 6);
#endif
                myAssert(score, handCount * 6); // check if the score is correct    
                
/************************** great halls *************************/               

                
                memcpy(G.hand[player], great_halls, sizeof(int) * handCount); // set all the cards to great halls
                memcpy(G.discard[player], great_halls, sizeof(int) * handCount); // set all the cards to great halls
                score = scoreFor(player, &G);
#if (NOISY_TEST == 1)
                printf("great halls score = %d, expected = %d\n", score, handCount * 1);
#endif
                myAssert(score, handCount * 1); // check if the score is correct              

 			
            
        }
    }

    return 0;
}

