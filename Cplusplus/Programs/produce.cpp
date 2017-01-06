#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Produce
{
public:
    static int numberOfBoxs; // number of how many boxes user made
    Produce()
    {
        //users package that he gets to take home
        box[0] = "";
        box[1] = "";
        box[2] = "";

        //user choices that he can use for pacakge
        choice[0] = "Broccoli";
        choice[1] = "Tomato";
        choice[2] = "Kiwi";
        choice[3] = "Kale";
        choice[4] = "Tomatillo";

    }
    void selectBox() //randomly selects choices and puts in the box
    {
        box[0] = choice[rand() % 5];
        box[1] = choice[rand() % 5];
        box[2] = choice[rand() % 5];
    }
    void printBox() //prints the details in the box
    {
        cout<<box[0] + "\n" + box[1] + "\n" + box[2] + "\n";
    }
    void printChoices() //prints teh details in the choices
    {
        for(int i = 0; i < (sizeof(choice) / sizeof(choice[0])); i++)
        {
            cout << i << + ": " << + "" + choice[i] << endl;
        }
    }

    string getItem(int index) //returns an item from the choice array
    {
        return choice[index];
    }
    void setBox(int boxItem, int choiceItem) // sets the box index using the choice index
    {
        box[boxItem] = choice[choiceItem];
    }

    int getNumberOfBoxs() //return how many boxes were made
    {
        return numberOfBoxs;
    }
    int incrementNumberOfBoxs() //adds 1 for each box that was made
    {
        numberOfBoxs = numberOfBoxs + 1;
    }
private:
    string choice[5]; //choices of veggies and fruits
    string box[3];    //box containing a mix of choices
};


int Produce::numberOfBoxs = 0; //intialized to zero

int main()
{
    srand(time(0));
    while(true)
    {
        Produce produceObj; //creates a box
        produceObj.incrementNumberOfBoxs(); //increments the number of boxes


        cout<<"Hi! We just made a box for you! The contents inside the box are..." <<endl;
        produceObj.selectBox(); //randomizes the box
        produceObj.printBox(); //prints it

        char theirAnswer;
        cout<<"\nAre you happy with the following box? (Y/n)"<<endl;
        cin >> theirAnswer;

        if(tolower(theirAnswer) == 'n') //if no than they can choose and make their own box using their avaible choices
        {
            cout<<"Ok here are your choices:"<<endl;
            produceObj.printChoices();
            int itemNumber;

            /**
            prompts the user to enter ints that represent items in
            the choice array and stores it in the box array
            **/

            cout<<"Enter a number (that represents an item) for your first selection for your box!"<<endl;
            cin >> itemNumber;
            produceObj.setBox(0, itemNumber);

            cout<<"Enter a number (that represents an item) for your second selection for your box!"<<endl;
            cin >> itemNumber;
            produceObj.setBox(1, itemNumber);

            cout<<"Enter a number (that represents an item) for your third selection for your box!"<<endl;
            cin >> itemNumber;
            produceObj.setBox(2, itemNumber);

            //Prints out their box that they chose
            cout<<"The contents inside your box is..."<<endl;
            produceObj.printBox();

            //prompts the user if they want to make another box, if they do than the loop will be reset
            //if not than not, show the user how many boxes he has made and break out of the loop.
            char theirSecondAnswer;
            cout<<"Would you like to make another box?"<<endl;
            cin>>theirSecondAnswer;
            if(tolower(theirSecondAnswer) == 'n')
            {
                cout<<"Great! These are how many boxes you have made!" << endl;
                cout<< produceObj.getNumberOfBoxs()<< endl;
                break;
            }
            else
            {
                //continue with loop
            }
        }
        else if(tolower(theirAnswer) == 'y') //if they were happy with the randomized box
        {
            //prompt user if they would like another one
            char theirThirdAnswer;
            cout << "Great! Would you like to make another box? (Y/n) " <<endl;
            cin >> theirThirdAnswer;

            if(tolower(theirThirdAnswer) == 'n') //if no, than show how many they have made and break out of loop
            {
                cout<<"Great! These are how many boxes you have made!" << endl;
                cout<< produceObj.getNumberOfBoxs()<< endl;
                break;
            }
            else
            {
                //go back to make a new box!
            }
        }

    }

    return 0;
}









