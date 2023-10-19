/*
Name: Abdul Moez Akbar
Student number = 20258267
Header file
*/

#pragma once
#ifndef FRACTION_20AMA12_H_
#define FRACTION_20AMA12_H_

#include <iostream>
#include <string>

using namespace std;

class Fraction
{
private:
    // private variables
    int Numerator;
    int Denominator;
    int gcd(int n, int m); // greatest common divisor function

public:
    Fraction(); // constructor without any arguments
    Fraction(int); // constructor with one argument
    Fraction(int, int); // constructor with two arguments

    int numerator() const; // returns numerator
    int denominator() const; // returns denominator

    // unary operators
    Fraction operator-();     // Negation sign
    Fraction operator++(int); // post-increment
    Fraction &operator++();   // pre-increment

    // binary operators
    friend Fraction operator+(const Fraction &a, const Fraction &b); //Addition
    friend Fraction operator-(const Fraction &a, const Fraction &b); // Subtraction
    friend Fraction operator*(const Fraction &a, const Fraction &b); // Multiplication
    friend Fraction operator/(const Fraction &a, const Fraction &b); // Division
    Fraction &operator+=(const Fraction &a); // Addition and assignment

    // comparison operators
    friend bool operator<(const Fraction &a, const Fraction &b); // Less than
    friend bool operator<=(const Fraction &a, const Fraction &b); // Less than or equal
    friend bool operator==(const Fraction &a, const Fraction &b); // equal to
    friend bool operator!=(const Fraction &a, const Fraction &b); // Not equal to
    friend bool operator>=(const Fraction &a, const Fraction &b); // Greater than or equal
    friend bool operator>(const Fraction &a, const Fraction &b); // Greater than

    friend ostream &operator<<(ostream &out, const Fraction &a); // Output to ostream
    friend istream &operator>>(istream &in, Fraction &a); // Input from istream
};

class FractionException
{
    string errorMessage;

public:
    FractionException(const string &message); // constructor
    string what();                            // returns error message
};

#endif