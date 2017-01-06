#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Ship
{
protected:
    string name; // name of ship
    int yearBuilt; // year of ship
public:
    Ship()
    {
        //no intialize
    }
    Ship(string newName, int newYear)
    {
        name = newName;
        yearBuilt = newYear;
        printDetails();
    }
    void setName(string newName) //mutator to set name
    {
        name = newName;
    }
    void setYear(int newYear) //mutator to set year
    {
        yearBuilt = newYear;
    }
    string getName() // getter to return name
    {
        return name;
    }
    int returnYear() // getter to return year
    {
        return yearBuilt;
    }
    void printDetails() // prints detials of ship
    {
        cout<<"Name of ship: " << name << "\nYear built : " << yearBuilt << endl;
    }
};

class CruizeShip: public Ship
{
private:
    int capacity; //capacity of how many passensgers
public:
    CruizeShip(string newName, int newYear, int newCapacity)
    {
        name = newName;
        yearBuilt = newYear;
        capacity = newCapacity;
        printDetails();
    }
    CruizeShip() // blank constuctor, set data via methods
    {

    }
    void setCapacity(int newCapacity) // set capacity
    {
        capacity = newCapacity;
    }

    void printDetails()
    {
        cout<<"Name of ship: " << name << "\nMaxium Passengers : " << capacity << endl;
    }

};

class CargoShip: public Ship
{
private:
    int capacityTon; //capacity of the cargo ship in tons
public:
    CargoShip(string newName, int newYear,int newTon) //constructor
    {
        capacityTon = newTon;
        name = newName;
        yearBuilt = newYear;
        printDetails();

    }
    CargoShip() //blank constructor, set by the methods
    {

    }
    void setTonCapacity(int newTon) //sets the capacity of the ship in tons
    {
        capacityTon = newTon;
    }
    void printDetails() //prints detials
    {
        cout<<"Name of ship: " << name << "\nMaxium Tons : " << capacityTon << endl;
    }
};

int main()
{
    /**
    Vars that we get from the user to make the ship objects
    **/

    //Regular Ship Data
    string shipName;
    int shipYear;

    //Cruise Ship Data
    string cruiseName;
    int cruiseYear;
    int cruiseCapacity;

    //Cargo Ship Data
    string cargoName;
    int cargoYear;
    int cargoCapacity;

    /**
    User inputs data
    **/
    cout<<"Enter the Name of the Ship: ";
    cin >> shipName;

    cout<<"Enter the year the Ship was built: ";
    cin >> shipYear;

    cout<<"Enter the Name of the Cruise Ship: ";
    cin >> cruiseName;

    cout<<"Enter the year the Cruise Ship was built: ";
    cin >> cruiseYear;

    cout<<"Enter the capacity of the Cruise Ship (in persons) ";
    cin >> cruiseCapacity;

    cout<<"Enter the Name of the Cargo Ship: ";
    cin >> cargoName;

    cout<<"Enter the year the Cargo Ship was built: ";
    cin >> cargoYear;

    cout<<"Enter the capacity of the Cargo Ship(in tonnage): ";
    cin >> cargoCapacity;


    /**
    Print via the intializtion of the object through their constructors
    **/
    cout<<endl;
    cout<<"Now printing objects via constructor:"<<endl;
    cout<<endl;

    Ship myShip(shipName, shipYear); //Regular Ship
    CruizeShip myCruizeShip(cruiseName, cruiseYear, cruiseCapacity); //Cruise Ship
    CargoShip myCargoShip(cargoName, cargoYear, cargoCapacity); // Cargo Ship
    cout<<endl;


    /**
    Print via the methods of the objects
    **/
    cout<<"Now printing objects using default constructor and methods: "<<endl;
    cout<<endl;

    Ship myShip2; //Regular Ship
    CruizeShip myCruizeShip2; // Cruise Ship
    CargoShip myCargoShip2; // Cargo Ship


    /**
    Sets the data from the previous user inputs via methods of the object.
    **/
    myShip2.setName(shipName);
    myShip2.setYear(shipYear);

    myCruizeShip2.setName(cruiseName);
    myCruizeShip2.setYear(cruiseYear);
    myCruizeShip2.setCapacity(cruiseCapacity);

    myCargoShip2.setName(cargoName);
    myCargoShip2.setYear(cargoYear);
    myCargoShip2.setTonCapacity(cargoCapacity);

    /**
    Prints via methods of the objects.
    **/
    myShip2.printDetails();
    cout<<endl;
    myCruizeShip2.printDetails();
    cout<<endl;
    myCargoShip2.printDetails();


    return 0;
}
