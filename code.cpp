
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
    int rightOrLeft = 1; // direction of the flow, 1 is right, -1 is left;

    srand(time(0)); //seed the ramdom number generator
    //int skill = rand() % 3;


    nTurn = 0;
    int skill = 0;
    updateSequence(nTurn, nHands, skill, sequence);
    
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
    switch
    {
        case 0;
            nextTurn = -rightOrLeft; //double tap: reverses the flow
            break;

        
        case 1;
            nextTurn = 1;
            break;
        case 2;
            nextTurn = 2;

    }

    for (i = 0; i < nHands; i++)
    {
        sequence[i] = 0;
    }

    switch (skill)
    {
        case 0:
            if (nTurn == 0) sequence[7] = 1;
            else sequence[nTurn + nextTurn] = 1;
            rightOrLeft = rightOrLeft + 2 * (-rightOrLeft); // updates the direction of the flow
            break;
        case 1:
        case 2:
            if ((((nHands-1) - nTurn) - nextTurn) >= 0) sequence[nTurn + nextTurn] = 1; //detects if there is enough space to continue the flow
            else sequence[- (((nHands-1) - nTurn) - nextTurn) - 1] = 1;
    }



}

