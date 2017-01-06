
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    /**
    The following creates a char array that will take all the data from the file one char at a time. Allocating 1024 bytes of memory
    **/
    int array_size = 1024;
    char * array = new char[array_size]; //making the array big
    int counter = 0; //used to increment through the array

    string symbolOne = "<"; //the symbol we will replace
    string symbolTwo = ">"; //the symbol we will replace
    string preHeader = "<PRE>"; //this string will be added to front of the file
    string preBacker = "</PRE>"; //this string will be added to the end of the file


    string longString; // This string will contain the .cpp file with all the symbols replaced
    string finalString; //this string will contain the .cpp file with all the symbols replaced AND with the preHeader and preBacker

    string outFile; // the user .cpp file that will be opened for interation
    cout<<"Enter the name of a the file you would like to edit:"<<endl;
    cin >> outFile; //the user enters a cpp file ie "test.cpp", "htmlCode.cpp"
    ifstream fin(outFile.c_str()); //converts the the std::string to null-terminated char pointers so that we can begin

    if(fin.is_open()) //if the file is able to open, then the program will work
    {
        /**
        The code below will take all the characters of the array One by One.
        **/
        while(!fin.eof() && counter < array_size) // itererates through the entire array
		{
			fin.get(array[counter]); //reading one character from file to array
			counter++; //incrementing the array
		}
		array[counter-1] = '\0'; //makes sure that the end of the array is stopped and not all the way to 1024


		/**
		The following code will take every chacacter from the array and put it in a string (this way we will be able
        to edit the string using replace() function).
		**/
		for(int m = 0; array[m] != '\0'; m++)
        {
            longString += array[m];
        }

        /**
        Replacing all the < and >
        **/
        while(true) //replacing the < symbol
        {
            int pos = longString.find(symbolOne); // will return the index of the position of a <. If there are none, than it returns -1
            if(pos != -1) // pos equals the index of a <
            {
                longString.replace(pos, symbolOne.length(), "&lt;"); //replaces the < with the following string
            }
            else //there are none, therfore break
            {
                break;
            }
        }
        while(true) //replacing the > symbol
        {
            int pos1 = longString.find(symbolTwo); //// will return the index of the position of a >. If there are none, than it returns -1
            if(pos1 != -1)
            {
                longString.replace(pos1, symbolTwo.length(), "&gt;"); //replaces the < with the following string
            }
            else //there are none therfore break,
            {
                break;
            }
        }
        /**
        Finishing touches by adding <PRE> before the .cpp file and </PRE> at the end
        **/
        finalString = preHeader + "\n" + longString + "\n" + preBacker; //glues the <PRE> and </PRE> to the longString
        fin.close();
        //converts the the file into a .html
        string outputFileHtml = outFile + ".html";

        ofstream fout(outputFileHtml.c_str());//the new html file
        for(int i = 0; finalString[i] != '\0'; i++) //rewrite the file with the final string
        {
            fout << finalString[i];
        }
    }
    return 0;
}
