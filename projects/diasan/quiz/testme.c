#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>


char inputChar() 
{
    char charArray[33] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '(', '{', ']', ')', '}', ' '};
    int i = rand() % 33;
    return charArray[i];
}

char *inputString() 
{
     
    char charArray[5] = {'r', 'e', 's', 'e', 't'}; //array of 5 chars
    
    int one = rand() % 5;
    int two = rand() % 5;
    
    // do the swap to create randomness ex. retes vs reset
    char tmp = charArray[one];
    charArray[one] = charArray[two];
    charArray[two] = tmp;
    int i;
    
    char *stringArray = (char *) malloc(6); 
    for (i=0; i<5; i++)
        stringArray[i] = charArray[i];
    stringArray[5] = '\0';
    return stringArray;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);


    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
