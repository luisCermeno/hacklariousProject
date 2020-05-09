
//Code por hacklarious projects
//libraries
#include <iostream>
using namespace std;

#include <cstdlib>
#include <ctime>

//defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void updateSequence(int nTurn, int nHands,int skill, int rightOrLeft, int* sequence);

//main program

//user compilingInfo



int main()
{
    //compilation info
    cout << "Editor(s) used: VScode 1.45.00\n"; 
    cout << "Compiler(s) used: Apple clang version 11.0.3 (clang-1103.0.32.59)\n"; 
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
    //Data
    int nHands = 8; // number of playing hands
    int sequence[nHands]; //the flow of the game, it has 7 elements and the element that is zero indicates whose turn is
    int i; //just a variable for loops
    int nTurn; //the hand number whose turn is (from 0 to 7)
    int rightOrLeft; // direction of the flow, 1 is right, -1 is left;
    int skill;

    srand(time(0)); //seed the ramdom number generator
    //int skill = rand() % 3;

    nTurn = 6;  
    skill = 2;
    rightOrLeft = 1;
    
    updateSequence(nTurn, nHands, skill, rightOrLeft, sequence);
    
    //test: show sequence
    for (i = 0; i < nHands; i++)
    {
        cout << sequence[i];
    }
    cout << endl;
    //test: show sequence



}//main

void updateSequence(int nTurn, int nHands, int skill, int rightOrLeft, int* sequence)
{
    int i;
    int nextTurn;

    for (i = 0; i < nHands ; i++)
    {
        sequence[i] = 0;
    }

    switch (skill)
    {
        case 0: //goes to the next player reversing the flow
            if (nTurn == 0 && rightOrLeft == 1) sequence[7] = 1; //the case if its the end of the array and the flow goes right
            else if (nTurn == 7 && rightOrLeft == -1) sequence[0] = 1; // the case if its the beginning of the array and the flow goes left
            else sequence[nTurn - rightOrLeft] = 1; // general case
            rightOrLeft = rightOrLeft + 2 * (-rightOrLeft); // updates the direction of the flow
            break;
        case 1: //goes to the next player in the direction of flow
            if (nTurn == 0 && rightOrLeft == -1) sequence[7] = 1;
            if (nTurn == 7 && rightOrLeft ==1) sequence[0] = 1;
            else sequence[nTurn + rightOrLeft] = 1;
            break;
        case 2: // skips 1 player in the direction of flow
            if (nTurn == 0 && rightOrLeft == -1) sequence[6] = 1;
            else if (nTurn == 7 && rightOrLeft == 1) sequence[1] = 1;
            else if (nTurn == 1 && rightOrLeft == -1) sequence[7] = 1;
            else if (nTurn == 6 && rightOrLeft == 1) sequence[0] = 1;
            else sequence[nTurn + 2*rightOrLeft] = 1;
    }


}

