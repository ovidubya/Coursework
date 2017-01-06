#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //scores for the players start at 0
    int playerOneScore = 0;
    int playerTwoScore = 0;

    while(true)
    {
        char playerOneInput;
        char playerTwoInput;

        //player 1 enters input
        cout  << "Player 1: Please enter either (R)ock, (P)aper, or (S)cissors:\n";
        cin >> playerOneInput;
        playerOneInput = tolower(playerOneInput); //converts the their answer to uppercase

        //player 2 enters input
        cout << "Player 2: Please enter either (R)ock, (P)aper, or (S)cissors:\n";
        cin >> playerTwoInput;
        playerTwoInput = tolower(playerTwoInput); //converts the their answer to uppercase

        if(playerOneInput == playerTwoInput) //Tie game
        {
            cout << "\nNobody wins\n" << endl;
        }

        //Possiblites for Player 2 to win

        if((tolower(playerOneInput) == 'r' && tolower(playerTwoInput) == 'p') ||
            (tolower(playerOneInput) == 'p' && tolower(playerTwoInput) == 's') ||
           (tolower(playerOneInput) == 's' && tolower(playerTwoInput) == 'r'))
        {
            cout << "\nPlayer 2 is the winner!" << endl;
            playerTwoScore++;
        }

        //Possiblites for Player 1 to win

        if((tolower(playerOneInput) == 'r' && tolower(playerTwoInput) == 's') ||
            (tolower(playerOneInput) == 'p' && tolower(playerTwoInput) == 'r') ||
           (tolower(playerOneInput) == 's' && tolower(playerTwoInput) == 'p'))
        {
            cout << "\nPlayer 1 is the winner!" << endl;
            playerOneScore++;
        }

        //Tells the user what the score is so far and prompts to play again or quit
        cout << "Score after this play:\n\n" << "Player 1: " << playerOneScore << "\nPlayer 2: " << playerTwoScore << endl;

        cout << "\n\nThanks!\n Play again? Y/y continues, other quits.";
        char theirAnswer;
        cin >> theirAnswer;
        if(tolower(theirAnswer) == 'y') // play again
        {
            //The loop will reset :)
        }
        else { //quit
            break;
        }
    }
}
