/*
 * Description: Rock-Paper-Scissors game against computer.
 * Copyright (C) Anjala Tamrakar - All rights reserved
 *
 * This project was done as a part of assignent to the course C-PROGRAMMING 2021. One of the courses of Highway 2 Code
 * training program organized by Kajaani Univesity of Applied Science.
 *
 * Date: May 20, 2021
 */


#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

/*
 * ask() function asks for an input from the user and returns an integer value representing the user's input.
 */
int ask()
{
    int userChoiceAsInt;
    char userChoiceAsChar;
    do{
        printf("\n(R)ock, (P)aper or (S)cissors?");
        scanf(" %c",&userChoiceAsChar); //added a blank space before to skip leading whitespace.
        //Source: https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
        
        userChoiceAsChar=tolower(userChoiceAsChar);//converted user choice into lowercase
        if ((userChoiceAsChar!= 'r') && (userChoiceAsChar!='p') && (userChoiceAsChar!='s'))// When user choses a wrong parameter the following statments are printed and the loop is continued
        {
            printf("WRONG CHOICE!!\n");
            printf("Enter your choice again.");
        }
        else
            break;// breaks the loop when a user chooses correct parameters
    } while (1); // loops forever
    
    // assigning character input to corresponding integer value as given in Rock-Paper-Scissors,part 2.
    if(userChoiceAsChar=='r')
    {
        userChoiceAsInt=1;
    }
    else if(userChoiceAsChar=='p')
    {
        userChoiceAsInt=2;
    }
    else
    {
        userChoiceAsInt=3;
    }
    
    return(userChoiceAsInt);// returns an integer value of corresponding user choice
}

// This function returns a random number between 1 to 3 everytime it is called.
int generate()
{
    int computersChoice;
    srand((unsigned)time(0));//srand initializes the random number based on time.
    computersChoice=(rand()%3)+1;//rand assigns random number of modulus 3 i.e, 0,1 and 2 and adding 1 so that the random number is 1,2 or 3 to the computers Choice
    return(computersChoice);
}

// This function checks whether the player wins, loses or the game is draw and returns the result as an integer.
int checkWin(int playerChoice, int computerChoice)
{
    int result;
    if(playerChoice==computerChoice)
        {
            result=0;
        }
    else if((playerChoice==1 && computerChoice==3)||(playerChoice==2 && computerChoice==1)||(playerChoice==3 && computerChoice==2))// Conditions for the user to win.
    {
        result=1;
    }
    else
    {
        result=-1;
    }
    return(result);
}

// printResult() function displays the outcome of a single round.
void printResult(int computerChoice, int result)
{
    if(result==0)
    {
        printf("Tie!\n");
    }
    else if(result==1)
    {
        printf("You win! ");
    }
     else if(result==-1)
     {
         printf("You lose! ");

     }
    if(result!=0)
    {
        if(computerChoice==1)
        {
            printf("Computer chose: Rock\n");
        }
        else if(computerChoice==2)
        {
            printf("\tComputer chose: Paper\n");
        }
        else if(computerChoice==3)
        {
            printf("\tComputer chose: Scissors\n");
        }
    }
}


int main(int argc, const char * argv[]) {
    int wins=0, computerWins=0,draw =0, computersChoice, rounds, userChoiceAsInt, result;
    
    printf("Welcome to Rock-Paper-Scissors game!\n");
    
    printf("How many rounds you wish to play? ");
    scanf("%d", &rounds);
    
    for(int i=1;i<=rounds;i++)//  loops till the given rounds are played.
    {
        userChoiceAsInt=ask();// function ask() is called and returned value is assigned to userChoiceAsInt.
        computersChoice= generate();// function generate() returns a random number between 1 to 3 which is assigned as computersChoice for the game.
        result= checkWin(userChoiceAsInt, computersChoice);
        // The number of win, draw and loses during the entire game are added to respective counters.
        if(result==0)
        {
            draw+=1;
        }
        else if(result==1)
        {
            wins+=1;
        }
        else if(result==-1)
        {
            computerWins+=1;
        }
        printResult(computersChoice,result);
    }
    //Display the ending conclusion of the game.
    printf("\n\n..the game ends..");
    printf("\nYou won %d/%d times.",wins,rounds);
    printf("\nThe computer won %d/%d times.",computerWins,rounds);
    printf("\nNumber of ties: %d\n",draw);
    
    return 0;
}
