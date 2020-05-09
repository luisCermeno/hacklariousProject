
//Code por hacklarious projects
//libraries
#include <iostream>
using namespace std;

#include <cstdlib>
#include <ctime>

//defined data types
//NONE

//Special compiler dependent definitions
#ifdef _WIN32 
#include <windows.h> 
#else 
#include <unistd.h> 
#endif 

//global constants/variables
//NONE

//Programmer defined functions
int userInput(int nTurn, bool& lost);
void gameLog(int nTurn, int skill);
int updateSequence(int nTurn, int nHands,int skill, int rightOrLeft, int* sequence);
void showSequence(int nHands, int* sequence);

//main program
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
    int nTurn; //the hand number whose turn is (from 0 to 7)
    int rightOrLeft; // direction of the flow, 1 is right, -1 is left;
    int skill; //type of tap by the user, 0 is two taps reversing, 1 is a single tap, 2 is three taps skipping one player.
    int i; //just a variable for loops
    bool lost = false; //is true when user loses
    srand(time(0)); //seeds the ramdom number generator
    
    //initial values
    cout << "You will start the game with your left hand. The flow starts to you right!" << endl;
    nTurn = 0;  //stars with sequende element 0: the user left hand
    rightOrLeft = 1; //flow starts going to the right
    //initial values

    //GAME CORE
    while (!lost)
    {
        //User input
        skill = userInput(nTurn, lost);
        if (lost) break;
        cout << endl;

        //Show game log
        gameLog(nTurn, skill);

        //*Play processing
        rightOrLeft = updateSequence(nTurn,nHands,skill,rightOrLeft,sequence); //updates rightOrLeft: direction of flow and array sequence
        for (i = 0; i < nHands ; i++) if (sequence[i] == 1) nTurn = i; //updates nTurn: whos turn is for the next play.

        //*UI: Show game sequence to the user
        showSequence(nHands, sequence);
        cout << endl;

        //Time between plays
        //pause for one  second 
        #ifdef _WIN32 
        Sleep(1000); // 1 second
        #else 
        sleep(1); // 1 second
        #endif 
    }
}//main


int userInput(int nTurn, bool& lost) //MUST BE CASE INDEPENDAT
{
    int skill;
    string keyStroke;
    switch (nTurn)
    {
        case 0:
            cout << "It's your turn: ";
            getline(cin,keyStroke);
            if (keyStroke == "aa") skill = 0; //tapping the table twice reverses the flow
            else if (keyStroke == "a") skill = 1; // tapping the table once just passes the turn to the next player
            else if (keyStroke == "aaa") skill = 2; // tapping the table three times skips one player
            else
            {
            cout << "You lost!" << endl;
            lost = true;
            }
            break;
        case 3:
            cout << "It's your turn: ";
            cin >> keyStroke;
            cin.ignore(1000,10); 
            if (keyStroke == "dd") skill = 0; //tapping the table twice reverses the flow
            else if (keyStroke == "d") skill = 1; // tapping the table once just passes the turn to the next player
            else if (keyStroke == "ddd") skill = 2; // tapping the table three times skips one player
            else 
            {
            cout << "You lost!" << endl;
            lost = true;
            }
            break;
        default: skill = rand() % 3; //computer generates a random skill to play
    }
    return skill;
}


int updateSequence(int nTurn, int nHands, int skill, int rightOrLeft, int* sequence)
{
    int i;
    for (i = 0; i < nHands ; i++) sequence[i] = 0;
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
    return rightOrLeft;
}

void showSequence(int nHands, int* sequence)
{
    cout << "The flow goes : ";
    for (int i = 0; i < nHands; i++)
    {
        cout << sequence[i];
    }
    cout << endl;
}

void gameLog(int nTurn, int skill)
{
    switch (nTurn)
    {
        case 0:
            cout << "Your left hand has";
            break;
        case 1:
            cout << "Bot1 (right hand) has";
            break;
        case 2:
            cout << "Bot2 (left hand) has";
            break;
        case 3:
            cout << "Your right hand has";
            break;
        case 4:
            cout << "Bot3 (left hand) has";
            break;
        case 5:
            cout << "Bot2 (right hand) has";
            break;
        case 6:
            cout << "Bot1 (left hand) has";
            break;
        case 7:
            cout << "Bot3 (right hand) has";
            break;
    }
    switch (skill)
    {
        case 0:
            cout << " tapped the table twice. Flow is reversing!" << endl;
            break;
        case 1:
            cout << " tapped the table once." << endl;
            break;
        case 2:
            cout << " tapped the table three times. One player is being skipped!" << endl;
    }
}