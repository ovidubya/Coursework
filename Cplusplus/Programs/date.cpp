
#include <iostream>

using namespace std;

class invalidMonth
{
    //exception classes to be used.
};

class invalidDay
{
   //exception class to be used
};
class Date
{
private:
    int month;
    int day;
    int year;
    string months[13]; //contains all the names of the months

public:
    Date()
    {
        //sets it to the first day of the first year of the first month
        month = 1;
        day = 1;
        year = 1;
    }
    Date(int newDay, int newMonth, int newYear)
    {
        year = newYear;
        month = newMonth;
        day = newDay;
        months[0] = "SuperSecretMonth"; //no such month exist, just filling empty space
        months[1] = "January";
        months[2] = "February";
        months[3] = "March";
        months[4] = "April";
        months[5] = "May";
        months[6] = "June";
        months[7] = "July";
        months[8] = "August";
        months[9] = "September";
        months[10] = "October";
        months[11] = "November";
        months[12] = "December";
    }
    int getYear()
    {
        return year;
    }
    int getMonth()
    {
        return month;
    }
    int getDay()
    {
        return day;
    }
    void setYear(int newYear)
    {
        year = newYear;
    }
    void setMonth(int newMonth)
    {
        month = newMonth;
    }
    void printFormat1() //  prints in this format  12/25/13
    {
        cout<<month<<"/"<<day<<"/"<<year<<endl;
    }
    void printFormat2() // prints in this format   Decemeber 25, 2013
    {
        string monthString = months[month];
        cout<<monthString + " " << day <<", " << year <<endl;
    }
    void printFormat3() // prints in this format 25 December 2013
    {
        cout<<day<< " " + months[month] << " " << year << endl;
    }


};

int main()
{
    int userYear, userMonth, userDay; //vars for the user
    cout<<"Enter a year"<<endl;
    cin>>userYear; //year cannot be invalid
    while(true)
    {
    try
    {
        cout<<"Enter a month"<<endl;
        cin>>userMonth;
        if(userMonth < 1 || userMonth > 12) // month less than one or greater than 12
        {
            throw invalidMonth(); //throws exception
        }
    }
    catch(invalidMonth)
    {
        cout<< "Invalid month" <<endl; //prints message and than breaks
        break;
    }

    try
    {
        cout<<"Enter a day"<<endl;
        cin>>userDay;
        if(userDay < 1 || userDay > 31) //day greater than 31 or less than 1
        {
            throw invalidDay(); //throws exception
        }
        Date object(userDay, userMonth, userYear); //creates an object with the vars from the user
        cout<<"FORMAT 1: " <<endl; //prints in three different formats
        object.printFormat1();
        cout<<"FORMAT 2: " <<endl;
        object.printFormat2();
        cout<<"FORMAT 3: " <<endl;
        object.printFormat3();
    }
    catch(invalidDay) //catches error
    {
        cout<< "Invalid day" <<endl; //prints error message than breaks
        break;
    }
    }


    return 0;
}

