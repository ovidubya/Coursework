#include <iostream>
#include <stdlib.h>

using namespace std;

int computerTurn(int computerTotalScore)
{
    computerTotalScore = 0; //score starts off at zero
    int LIMIT = 20; //once the computer goes past twenty, computer holds
    while(true) //loop for the computer to roll
    {
        int roll = rand() % 6 + 1; // roll dice value from 1-6
        if(roll == 1) //game over, computer total roll score is at zero
        {
            computerTotalScore = 0;
            break;
        }
        else
        {
            computerTotalScore = computerTotalScore + roll; //add to their total score
            if(computerTotalScore >= LIMIT) //if computer total score is more than or equal to the limit, turn over
            {
                break;
            }
        }
    }
    return computerTotalScore; //return their final score for the turn
}

int humanTurn(int humanTotalScore)
{
    humanTotalScore = 0; //score starts off at zero
    while(true) //loop for the computer to roll
    {
        char theirAnswer; // either R or H. R means roll, H means hold
        cout << "Please enter (R) to roll or (H) to hold" << endl;
        cin >> theirAnswer;
        theirAnswer = tolower(theirAnswer); //convert their answer to lowercase

        if(theirAnswer == 'h') // whatever the humanScore is now will be added
        {
            break;
        }
        if(theirAnswer == 'r')
        {
            int roll = rand() % 6 + 1; // roll from 1-6
            if(roll == 1) // if they hit a 1, then there score is at zero
            {
                humanTotalScore = 0;
                break;
            }
            else
            {
                humanTotalScore = humanTotalScore + roll; //adds to the count
                cout << "Roll count is at " << humanTotalScore; //tells the user what the total count is so far (potential points to be added to the score)
            }
        }
    }
    return humanTotalScore; //final score for the turn

}


int main()
{
    //their total score starts at zero, needs to be 100 or more to win
    int humanScoreResult = 0;
    int computerScoreResult = 0;
    while(true) //loop for the game
    {
        //Player Move
        humanScoreResult += humanTurn(0); ////add the score to the humanScoreResult
        cout << "Human score so far is: " << humanScoreResult << endl; //tells user what his total score is

        //Computer Move
        computerScoreResult += computerTurn(0); //add the score to the computerScoreResult
        cout << "Computers score so far is: " << computerScoreResult << endl; //tells user what the computer score result is


        if(humanScoreResult >= 100) //Human wins
        {
            cout << "Human win!" << endl;
            break;
        }
        if(computerScoreResult >= 100) //Computer wins
        {
            cout << "Computer win!" << endl;
            break;
        }
    }


}








