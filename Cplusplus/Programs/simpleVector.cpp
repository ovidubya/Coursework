//#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T>
class simpleVector
{
public:
    T& operator[](const int index); // operator to be overloaded

    ~simpleVector()
    {
        delete [] myArray; //deallocated the array
    }
    simpleVector(int x)
    {
        myArray = new T[x];
        size = x;
        counter = 0;
    }
    simpleVector()
    {
        myArray = NULL;
        size = 0;
    }
    simpleVector(const simpleVector<T> &copy)
    {
        counter = copy.getCounter(); //copies the object passed by the contructor its counter
        size = copy.getSize();      // its size
        myArray = new T[size];       // makes an array with the size
        for(int i = 0; i < size; i++)
        {
            myArray[i] = copy.returnElementAt(i);   //adds all the elements of the array via a loop
        }
    }
    T returnElementAt(int x) const //returns an element at index
    {
        return myArray[x];
    }
    void addElement(T addedElement) //adds an element
    {
        myArray[counter] = addedElement;
        counter++; //increments size
    }
    int getSize() const //returns size
    {
        return size;
    }
    void addingData() //this makes an temp element for the user to add
    {
        T element;
        getline(cin, element);
        //cin >> element;
        addElement(element);
    }
    int getCounter() const //returns counter
    {
        return counter;
    }
    void displayData() //displays conten
    {
        for(int i = 0; i < size; i++)
        {
            cout<<myArray[i]<<endl;
        }
    }
private:
    T *myArray;
    int size;
    int counter;

};
template <class T>
T& simpleVector<T>::operator[](const int index) // overloading the [] operator
{
    return myArray[index];
}


int main()
{

    /**
    User has three choices, either he can make an array of ints, doubles or strings depending on what number they choose.

    1 is ints
    2 is doubles
    3 is strings

    **/
    int theirInput=0;
    cout<<"Please enter what kind of data you would like to enter:"<<endl;
    cout<<"To enter integer's, press 1, to enter double's press 2,\nto enter strings, press 3"<<endl;
    cin>>theirInput;


    /**
    Option 1 -- The user chooses to make an array of ints
    **/
    if(theirInput == 1)
    {
        while(true)
        {
            //prompts user for the size of the array
            int theirSecondInput;
            cout<<"Please enter how many int's you want your object to store"<<endl;
            cin >> theirSecondInput;
            // makes size via constructor
            simpleVector<int> object(theirSecondInput);
            //lets the user to keep entering data until the counter has hit the size

            while(object.getCounter() != object.getSize()) //counter represents how many items and size represents the size of the array
            {
                cout<<"Enter data:\n"<<endl;
                object.addingData(); //prompts to enter data
            }
            /**
            Returns an index via function call
            **/
            cout<<"Enter a index to return a data"<<endl;
            int index;
            cin >> index;
            cout<<"The object at that index is " << object.returnElementAt(index)<<endl; //function call here

            /**
            Returns an index via overloaded operator '[]'
            **/
            cout<<"Enter another index to return a data"<<endl;
            cin>>index;
            cout<<"\nThe object at that index is " << object[index] <<endl; // overloaded operator call here

            /**
            Copy of the orginal object using the constructor
            **/
            simpleVector<int> copyObject(object);
            cout<<endl;

            //Prints out data
            cout<<"The contents in the array are:"<<endl;
            copyObject.displayData();

            //Prompts user to continute or quit
            cout<<"Would you like to enter data again? (Y/n)"<<endl;
            char answer;
            cin>>answer;
            if(tolower(answer) == 'y')
            {
                //awesome the loop will repeat
            }
            else
            {
                //Memory of the array will be dealocated.
                cout<<"Goodbye!"<<endl;
                break;
            }
        }
    }
    /**
    Option 2 -- The user chose to make an array of doubles
    **/
    if(theirInput == 2)
    {
        while(true)
        {
            //prompts user for the size of the array

            int theirSecondInput;
            cout<<"Please enter how many doubles you want your object to store"<<endl;
            cin >> theirSecondInput;
            //intializes object
            simpleVector<double> object(theirSecondInput);
            //prompts user to enter data until counter has hit the size
            while(object.getCounter() != object.getSize()) // counter represents how many items and size represents the size of the array
            {
                cout<<"Enter data:\n"<<endl;
                object.addingData();
            }
            //prints index via function call
            cout<<"Enter a index to return a data"<<endl;
            int index;
            cin >> index;
            cout<<"The object at that index is " << object.returnElementAt(index)<<endl;

            //prints index via overloaded operator
            cout<<"Enter another index to return a data"<<endl;
            cin>>index;
            cout<<"\nThe object at that index is " << object[index] <<endl;;

            //Copies the orignal object
            simpleVector<double> copyObject(object);
            cout<<endl;
            cout<<"The contents in the array are:"<<endl;
            //displays the data
            copyObject.displayData();
            //prompts user to enter data again
            cout<<"Would you like to enter data again? (Y/n)"<<endl;
            char answer;
            cin>>answer;
            if(tolower(answer) == 'y')
            {
                //awesome the loop will repeat
            }
            else
            {
                cout<<"Goodbye!"<<endl;
                break;
            }
        }
    }
    /**
    Option 3 -- The user chose to make an array of strings
    **/
    if(theirInput == 3)
    {
        while(true)
        {
            //prompts user for the size of the array
            int theirSecondInput;
            cout<<"Please enter how many strings you want your object to store"<<endl;
            cin >> theirSecondInput;
            //makes the object
            simpleVector<string> object(theirSecondInput);
            //asks user to keep prompting data until counter hits size

            while(object.getCounter() != object.getSize()) //counter represents how many items and size represents the size of the array
            {
                cout<<"Enter data:\n"<<endl;
                object.addingData();
            }

            cout<<"Awesome!"<<endl;
            //prints index via function call
            cout<<"Enter a index to return a data"<<endl;
            int index;
            cin >> index;
            cout<<"The object at that index is " << object.returnElementAt(index)<<endl;

            //prints index via overloaded operator
            cout<<"Enter another index to return a data"<<endl;
            cin>>index;
            cout<<"\nThe object at that index is " << object[index] <<endl;;

            //copies the orginal object into this this fake wannabe object
            simpleVector<string> copyObject(object);
            cout<<endl;
            //prints data
            cout<<"The contents in the array are:"<<endl;
            copyObject.displayData();
            //prompts user to enter new data or quit
            cout<<"Would you like to enter data again? (Y/n)"<<endl;
            char answer;
            cin>>answer;
            if(tolower(answer) == 'y')
            {
                //awesome the loop will repeat
            }
            else
            {
                cout<<"Goodbye!"<<endl;
                break;
            }

        }
    }
    return 0;

}
