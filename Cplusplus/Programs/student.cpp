#include <iostream>

using namespace std;

class Student1
{
public:

    Student1(string newName, int newNumClasses)
    {
        name = newName;
        numClasses = newNumClasses;
        // classList[newNumClasses];

        counter = 0; //used to fill the array of classes
    }
    void addClass(string className)
    {
        classList[counter] = className; //student can add classes by using the counter
        counter++;

    }
    void reset()
    {
        for(int i = 0; i < (sizeof(classList) / sizeof(classList[0]));i++) //sets the classes in the array to ""
        {
            classList[i] = "";
        }

        counter = 0;
    }
    void displayClasses()
    {
         for(int i = 0; i < (sizeof(classList) / sizeof(classList[0]));i++) //iterates through the classList
         {
            cout<<classList[i]<<endl;
         }
    }
    string returnName()
    {
        return name;
    }
    void setName(string n)
    {
        name = n;
    }
    int returnClasses()
    {
        return numClasses;
    }
    string returnClassList(int i)
    {
        return classList[i];
    }

private:
    string name; //name of student
    int numClasses; // number of how many classes
    string classList[5]; //set the number of classes to 5
    int counter; //used to keep track of classes entered


};

int main()
{
    string newNameStudent; //name for the student


    cout<< "Enter a name for the student:" <<endl;
    getline(cin, newNameStudent);
    Student1 stud(newNameStudent, 5); //sets the number of classes to 5 and sets the new name for the student


    while(true)
    {
        int classCounter = 5; //5 Max, will decrement once student adds to the list
        while(classCounter != 0) // No more adding no more spots
        {
            string data; //class name
            cout << "Enter class names for " << stud.returnName() <<" [MAX "<<classCounter <<"]" << "\n";

            getline(cin, data);
            stud.addClass(data); //adds to the array
            cout << "Student enrolled in: " << data << endl; //shows user what he enrolled in

            classCounter--; // 1 Less class availble

        }

        cout << "\n\nStudent's classes enrolled in are:"<<endl;
        stud.displayClasses(); //displays the classes

        //prompts user if he wants to add new classes to the student.
        char theirAnswer;
        cout<< "Would you like to enter the student's data again? (Y/n)" <<endl;
        cin >> theirAnswer;

        if(tolower(theirAnswer) == 'n') //If no, than breaks out of loop
        {
            break;
        }
        else //if yes, than reset the student object
        {
            stud.reset();
        }

    }

    return 0;
}
