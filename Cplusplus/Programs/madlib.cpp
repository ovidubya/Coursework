#include <iostream>
using namespace std;

// vars used for the madlib program
string instructorName;
string myName;
string foodName;
int number;
string adjective;
string aColor;
string animalName;

int main()
{
    // prompts user for the instructors name
    cout << "Enter the name of the instructor\n";
    cin >> instructorName;

    // prompts user for his or her name
    cout << "Enter your name\n";
    cin >> myName;

    // prompts user for the name of a food
    cout << "Enter a food\n";
    cin >> foodName;

    // prompts user for a number between 100 and 120
    cout << "Enter a number between 100 and 120\n";
    cin >> number;

    //prompts user for an adjective
    cout << "Enter a adjective\n";
    cin >> adjective;

    // prompts user for the name of a color
    cout << "Enter a color\n";
    cin >> aColor;

    //prompts user for the name of an animal
    cout << "Enter an animal\n";
    cin >> animalName;


    //inputs vars that the user wrote down to this message
    cout << "Dear Professor " << instructorName << ",\n\n"; // indent two spaces with \n\n
    cout << "I am sorry that I am unable to turn in my homework at this time." <<endl;
    cout << "First, I ate a rotten " << foodName << ", which made me turn " <<aColor << " and\n";
    cout<< "extremely ill. I came down with a fever of " << number << ".\n";
    cout << "Next, my " << adjective << " pet " << animalName << " must have smelled the remains\n";
    cout << "of the " << foodName << " on my homework, because he ate it. I am currently\n";
    cout << "rewriting my homework and hope you will accept it late.\n\n"; //indent two spaces with \n\n
    cout << "Sincerely,\n" << myName;


    return 0;
}
