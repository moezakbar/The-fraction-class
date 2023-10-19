/*
Name: Abdul Moez Akbar
Student number = 20258267
*/

#include "fraction_20ama12.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// function to find greatest common divisor
int Fraction ::gcd(int n, int m)
{
    // check to see if m evenly divides n
    if (m <= n && n % m == 0)
    {
        return m;
    }
    // swap m and n if n is greater than m
    else if (n < m)
    {
        return gcd(m, n);
    }
    // calculate gcd by calling the function with m and the remainder of n divided by m
    else
    {
        return gcd(m, n % m);
    }
};

// default constructor
Fraction ::Fraction() : Numerator(0), Denominator(1) {}

// constructor with single argument
Fraction ::Fraction(int a) : Numerator(a), Denominator(1) {}

// constructor with two arguments
Fraction ::Fraction(int a, int b)
{
    // check if denominator is 0
    if (b == 0)
    {
        throw FractionException("Denominator of a fraction cannot be 0!");
    }

    // calculate gcd of fraction
    int GCD = gcd(abs(a), abs(b));
    // check if denominator is negative
    if (b < 0)
    {
        // make numerator negative and denominator positive
        Numerator = -(a / GCD);
        Denominator = -(b / GCD);
    }
    else
    {
        Numerator = a / GCD;
        Denominator = b / GCD;
    }
}

// accessor for numerator
int Fraction ::numerator() const
{
    return Numerator;
}

// accessor for denominator
int Fraction ::denominator() const
{
    return Denominator;
}

// Negate
Fraction Fraction ::operator-()
{
    return Fraction(-Numerator, Denominator);
}

// post increment
Fraction Fraction::operator++(int)
{
    Fraction temp = *this;
    Numerator += Denominator;
    return temp;
}

// pre increment
Fraction &Fraction::operator++()
{
    Numerator += Denominator;
    return *this;
}

// add
Fraction operator+(const Fraction &a, const Fraction &b)
{
    // check if denominator is same
    if (a.denominator() == b.denominator())
    {
        // add numerators
        return Fraction(a.numerator() + b.numerator(), a.denominator());
    }
    else
    {
        return Fraction((a.numerator() * b.denominator()) + (b.numerator() * a.denominator()), a.denominator() * b.denominator());
    }
}

// subtract
Fraction operator-(const Fraction &a, const Fraction &b)
{
    // check if denominators same
    if (a.denominator() == b.denominator())
    {
        // subtract numerators
        return Fraction(a.numerator() - b.numerator(), a.denominator());
    }
    else
    {
        return Fraction((a.numerator() * b.denominator()) - (b.numerator() * a.denominator()), a.denominator() * b.denominator());
    }
}

// multiply
Fraction operator*(const Fraction &a, const Fraction &b)
{
    return Fraction(a.numerator() * b.numerator(), a.denominator() * b.denominator());
}

// divide
Fraction operator/(const Fraction &a, const Fraction &b)
{
    // cross multiply
    return Fraction(a.numerator() * b.denominator(), a.denominator() * b.numerator());
}

Fraction &Fraction::operator+=(const Fraction &a)
{
    // check if denominators same
    if (denominator() == a.denominator())
    {
        // update numerator variable
        Numerator = numerator() + a.numerator();
        // update denominator variable
        Denominator = denominator();
    }
    else
    {
        // update numerator and denominator variables by finding common denominator
        Numerator = (numerator() * a.denominator()) + (a.numerator() * denominator());
        Denominator = denominator() * a.denominator();
    }

    return *this;
}

// less than
bool operator<(const Fraction &a, const Fraction &b)
{
    return ((a.numerator() * b.denominator()) < (b.numerator() * a.denominator()));
}

// lss than or equal
bool operator<=(const Fraction &a, const Fraction &b)
{
    return ((a.numerator() * b.denominator()) <= (b.numerator() * a.denominator()));
}

// equal to
bool operator==(const Fraction &a, const Fraction &b)
{
    if ((a.numerator() == b.numerator()) && (a.denominator() == b.denominator()))
    {
        return true;
    }

    return false;
}

// not equal to
bool operator!=(const Fraction &a, const Fraction &b)
{
    if ((a.numerator() != b.numerator()) || (a.denominator() != b.denominator()))
    {
        return true;
    }

    return false;
}

// greater than or equal
bool operator>=(const Fraction &a, const Fraction &b)
{
    return ((a.numerator() * b.denominator()) >= (b.numerator() * a.denominator()));
}

// greater than
bool operator>(const Fraction &a, const Fraction &b)
{
    return ((a.numerator() * b.denominator()) > (b.numerator() * a.denominator()));
}

// output to ostream
ostream &operator<<(ostream &out, const Fraction &a)
{
    // output numerator, slash, and denominator
    out << a.numerator() << "/" << a.denominator();
    return out;
}

// input to istream
istream &operator>>(istream &in, Fraction &a)
{
    // Initialize numerator denominator
    int numerator, denominator;

    // Read the top (numerator)
    in >> numerator;

    // Check if there's a slash character
    if (in.peek() == '/')
    {
        char slash;
        // Read the slash character
        in >> slash;
        // Read the denominator
        in >> denominator;
        a = Fraction(numerator, denominator);
    }
    // if there is no denominator
    else {
        a = Fraction(numerator);
    }

    return in;
}

// For FractionException:
FractionException ::FractionException(const string &message) : errorMessage(message)
{
}
string FractionException ::what()
{
    return errorMessage;
}