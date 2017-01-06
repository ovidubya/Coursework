#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class Customer
{
protected:
    string name;
    int calls;
public:
    Customer()
    {
        //no data
    }
    Customer(string newName, int newCalls)
    {
        name = newName;
        calls = newCalls;
    }
    virtual double computeBill() //virtual function that will be overloaded by the premium as well
    {
        return 10.0 + ((double) calls) * .50;
    }
    string getName() //returns name
    {
        return name;
    }

};
class PremiumCustomer: public Customer
{
private:
    int minutes;
public:
    PremiumCustomer(string newName, int newCalls, int newMinutes) //3 data types since its premium memember
    {
        name = newName;
        calls = newCalls;
        minutes = newMinutes;
    }
    void setMinutesPerCall(int newMinutes)
    {
        minutes = newMinutes;
    }
    double computeBill() //formula for computing bill for a premium customer
    {
        return 20.0 + ((double) calls) * 0.05 + ((double) minutes) * 0.10;
    }

};

int main()
{
    srand(time(0)); //not sure what this is but if i dont have it than my rand() function will not work

    Customer* list[6];
    //basic members
    list[0] = new Customer("John Dough", 20);
    list[1] = new Customer("Bob Dough", 50);
    list[2] = new Customer("Chris Dough", 100);
    //premium members
    list[3] = new PremiumCustomer("Amanda Dough", 20, 60);
    list[4] = new PremiumCustomer("Oliva Dough", 50, 60);
    list[5] = new PremiumCustomer("Sophia Dough", 100, 60);


    //prints what each customer owes
    for(int i = 0; i < 6; i++)
    {
        cout << "Customer " << list[i]->getName() << " owes "
        << list[i]->computeBill() << " dollars." << endl;
    }
    delete [] list; //dealocated memeory

    cout<<"--------EXTRA CREDIT PART----------"<<endl;

    /**
    50 BASIC CUSTOMERS
    **/
    Customer* bigList[50];

    int randomCalls[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for(int j = 0; j < 50; j++)
    {
        int randomNumber = rand() % 10;
        bigList[j] = new Customer("x", randomCalls[randomNumber]);
    }
    double basicCustomerMoney = 0;

    for(int k = 0; k < 50; k++)
    {
        basicCustomerMoney += bigList[k]->computeBill();

    }
    cout<<"50 Basic Customers spent a month : " << basicCustomerMoney<<endl;
    delete [] bigList;


    /**
    50 PREMIUM CUSTOMERS
    **/
    PremiumCustomer* bigListTwo[50];
    int randomMinutes[7] = {2, 3, 4, 5, 6, 7, 8};
    for(int l = 0; l < 50; l++)
    {
        int randomCall = rand() % 10;
        int randomMinute = (rand() & 7) + 2;
        bigListTwo[l] = new PremiumCustomer("y", randomCalls[randomCall], randomMinute);
    }
    double premiumCustomerMoney = 0;
    for(int m = 0; m < 50; m++)
    {
        premiumCustomerMoney += bigListTwo[m]->computeBill();
    }

    /**
    RESULTS:
    **/
    cout<<"50 Premium customers spent a month: " << premiumCustomerMoney<<endl;
    delete [] bigListTwo;

    double percentage = (premiumCustomerMoney / basicCustomerMoney) * 100;
    cout<<"A basic customer pays %" << percentage << " more a month than a premium customer does"<<endl;


    return 0;
}
