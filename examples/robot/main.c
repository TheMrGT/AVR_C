// Command processor for Robot arm
//This program takes user input and turns it into commands for
//the robot arm to use. Currently the user must enter a command, 
//a joint, a direction and distance for every command. 


//git test
#include <stdio.h>
#include <string.h>
#include "uart.h"
#include "readLine.h"

#define MAX_BUFFER 30
#define MAX_TOKENS (MAX_BUFFER/2)
#define MAX_DELIMS 1

//Array limits for movement instructions
#define max_cmd_len 5 //4 letter command 
#define max_jointcmd_len 7 //ie: joint1
#define max_dircmd_len 3 //1,0,-1
#define max_discmd_len 5 //up to 9999+1

int main(void) {    

    init_serial();
    char input[MAX_BUFFER + 1] = {};
    char delims[MAX_DELIMS + 1] = {" "};
    puts("ROBOT APP TEST");

    printf("Enter the name of command followed by joint, direction, and distance");
    printf("\nSeperate with a space");
    printf("\n(EX: move joint1 -1 750)\n");

    uint8_t num_char = readLine(input, MAX_BUFFER);

    printf("You entered %i characters\n", num_char);

    for (uint8_t out_char=0; out_char<num_char; out_char++)
    {
        printf("%c", input[out_char]);
    }
    printf("\n");

    // break input line into tokens
    char *tokens[MAX_TOKENS];
    uint8_t index = 0;
    tokens[index] = strtok(input, delims);
    while ( (tokens[index] != NULL) && (index < MAX_TOKENS - 1) ) {
        index++;
        tokens[index] = strtok(NULL, delims);
    }
    uint8_t tokens_found = index;

    printf("The %i tokens parsed are:\n", tokens_found);
    printf("index token\n");
    for (index=0; index<tokens_found; index++)
    {
        printf("%5i %s\n", index, tokens[index]);

    }
//movement
    char movCmd[max_cmd_len]={};
    strncpy(movCmd, tokens[0], max_cmd_len);
    printf("Movement command is: %s\n",movCmd);
//joints
    char jointCmd[max_jointcmd_len] = {};
    strncpy(jointCmd, tokens[1], max_jointcmd_len);
    printf("Joint command is: %s\n",jointCmd);
//direction
    char dirCmd[max_dircmd_len]={};
    strncpy(dirCmd, tokens[2], max_dircmd_len);
    printf("Direction command is: %s\n",dirCmd);
//distance
    char disCmd[max_discmd_len]={};
    strncpy(disCmd, tokens[3], max_discmd_len);
    printf("Distance command is: %s\n",disCmd);
}
