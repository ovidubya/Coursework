//#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Rational
{
    //Overloading the << and >> operators
    friend istream& operator>>(istream&, Rational&);
    friend ostream& operator<<(ostream&, Rational&);
public:

    /**
        Constructors
    **/
    Rational(int wholeNumber)
    {
        numerator = wholeNumber;
        denominator = 1;
        actualValue();
    }
    Rational(int newNumerator, int newDenominator)
    {
        numerator = newNumerator;
        denominator = newDenominator;
        actualValue();
    }
    Rational()
    {
        numerator = 0;
        denominator = 1;
        actualValue();
    }

    /**
       Functions
    **/
    void actualValue()
    {
        realValue = (float)numerator / (float)denominator;
    }
    float getActualValue() const
    {
        return realValue;
    }
    int getNumerator() const
    {
        return numerator;
    }
    int getDenominator() const
    {
        return denominator;
    }
    void setNumerator(int x)
    {
        numerator = x;
    }
    void setDenominator(int x)
    {
        denominator = x;
    }
    void normalization()
    {
        if(numerator == denominator) // 4/4 or 6/6 means that it is 1/1
        {
            numerator = 1;
            denominator = 1;
        }
        else if(numerator < 0 && denominator < 0) // -1/-2  means that it is postive 1/2
        {
            numerator = numerator * -1;
            denominator = denominator * -1;
        }
        else if(numerator > 0 && denominator < 0) //2/-1   inverses and makes it -2/1   same thing.
        {
            numerator = numerator * -1;
            denominator = denominator * -1;
        }

        else if(numerator % 2 == 0 && denominator % 2 == 0) //both top and bottom are divisible by 2
        {
            while(numerator % 2 == 0 && denominator % 2 == 0)
            {
                numerator = numerator / 2;
                denominator = denominator / 2;
                normalization();
            }
        }
        else if(numerator % 3 == 0 && denominator % 3 == 0) // both top and bottom are divisible by 3
        {
            while(numerator % 3 == 0 && denominator % 3 == 0)
            {
                numerator = numerator / 3;
                denominator = denominator / 3;
                normalization();
            }
        }
    }
    /**
       Overloading Operators
    **/

    Rational operator*(const Rational&);
    Rational operator/(const Rational&);
    string operator==(const Rational&);
    string operator<(const Rational&);
    Rational operator+(const Rational&);
    Rational operator-(const Rational&);
    string operator<=(const Rational&);
    string operator>(const Rational&);
    string operator>=(const Rational&);

private:
    float realValue; // the divsion part of the rational number
    int numerator;
    int denominator;
};

/**
   Overloading the greater than equal or too operator,
**/
string Rational::operator>=(const Rational& parameter)
{
    if((getActualValue() > parameter.getActualValue()) || getActualValue() == parameter.getActualValue())
    {
        return "TRUE";
    }
    else
    {
        return "FALSE";
    }
}

/**
   Overloading the greater than operator,
**/
string Rational::operator>(const Rational& parameter)
{
    if(getActualValue() > parameter.getActualValue())
    {
        return "TRUE";
    }
    else
    {
        return "FALSE";
    }
}

/**
   Overloading the less than or equal too operator,
**/
string Rational::operator<=(const Rational& parameter)
{
    if((getActualValue() < parameter.getActualValue()) || //if a is less than b or a is equal to b, RETURN TRUE!
       (getActualValue() == parameter.getActualValue()))
    {
        return "TRUE";
    }
    else //else return false
    {
        return "FALSE";
    }
}

/**
   Overloading the less than operator,
**/
string Rational::operator<(const Rational& parameter)
{
    if(getActualValue() < parameter.getActualValue())
    {
        return "TRUE";
    }
    else
    {
        return "FALSE";
    }
}

/**
   Overloading the equalily operator,
**/
string Rational::operator==(const Rational& parameter)
{
    if((numerator * parameter.denominator) == (denominator * parameter.numerator))
    {
        return "TRUE";
    }
    else
    {
        return "FALSE";
    }
}

/**
   Overloading the product operator,
**/
Rational Rational::operator*(const Rational& parameter)
{
    Rational temp;
    temp.numerator = numerator * parameter.numerator;
    temp.denominator = denominator * parameter.denominator;
    return temp;
}

/**
   Overloading the division operator,
**/
Rational Rational::operator/(const Rational& parameter)
{
    Rational temp;
    temp.numerator = numerator * parameter.denominator;
    temp.denominator = denominator * parameter.numerator;
    return temp;
}

/**
   Overloading the addition operator,
**/
Rational Rational::operator+(const Rational& parameter)
{
    Rational temp;
    temp.numerator = (numerator * parameter.denominator) + (denominator * parameter.numerator);
    temp.denominator = denominator * parameter.denominator;
    return temp;


}

/**
   Overloading the subtraction operator,
**/
Rational Rational::operator-(const Rational& parameter)
{
    Rational temp;
    temp.numerator = (numerator * parameter.denominator) - (denominator * parameter.numerator);
    temp.denominator = denominator * parameter.denominator;
    return temp;


}

istream& operator>>(istream& input, Rational& num)
{
   char unused;

   input >> num.numerator >> unused >> num.denominator;
   num.actualValue();
   return input;
}
ostream& operator<<(ostream& output, Rational& num)
{
   output << num.numerator << "/" << num.denominator;

   return output;
}




int main()
{
    Rational a;
    Rational b;
    cout<< "Enter the first rational number:";
    cin >> a;
    cout << "Enter the second rational number:";
    cin >>b;
    cout << "The normalized form of both the rational number is as follows" << endl;
    a.normalization();
    b.normalization();
    cout << a << endl;
    cout << b << endl;
    cout<<endl;
    //Checks if the two rational numbers are equal
    string aEqualB = a == b;
    cout << a << " == " << b << ": " << aEqualB << endl;

    //Checks if a is less than b
    string aLessThanB = a < b;
    cout << a << " < " << b << ": " << aLessThanB << endl;

    //Checks is a is than or equal to b
    string aLessThanOrEqual = a <= b;
    cout << a << " <= " << b << ": " << aLessThanOrEqual << endl;

    //Checks if a greater than b
    string aGreaterB = a > b;
    cout << a << " > " << b << ": " << aGreaterB << endl;

    //Checks if a greater than or equal to b
    string aGreaterEqualB = a >= b;
    cout << a << " >= " << b << ": " << aGreaterEqualB << endl;

    //Arthmetic

    //Multiply the rational number a to b
    Rational answer1 = a * b;
    answer1.normalization();
    cout << a << " * " << b << ": The answer is " << answer1 <<endl;

    //Add the rational number a and b
    answer1 = a + b;
    answer1.normalization();
    cout << a << " + " << b << ": The answer is " << answer1 <<endl;

    //Subtract the rational number a from b
    answer1 = a - b;
    answer1.normalization();
    cout << a << " - " << b << ": The answer is " << answer1 <<endl;

    //Divide the rational number a and b
    answer1 = a / b;
    answer1.normalization();
    cout << a << " / " << b << ": The answer is " << answer1 <<endl;

    return 0;
}
