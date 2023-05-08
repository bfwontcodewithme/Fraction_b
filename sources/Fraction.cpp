#include "Fraction.hpp"
#include <bits/stdc++.h>
#include <algorithm>
using namespace ariel;

/*
    fraction are created and changed to reduced form is needed in the contractor 
    instead of checking in the start of every method.
    and every method return the fraction with minimize action
*/
Fraction ariel::Fraction::minimizeFraction()
{
    //get gcd(n,d) then divide by it to get the reduced form
    //if  gcd(n,d) = 1  already in reduced form return itself, if not divide by the gcd.
    int gcd = std::__gcd(this->numerator,this->denominator);
    if(gcd == 1) return (*this);
    else{
        auto n = this->numerator/gcd;
        auto d = this->denominator/gcd;
        return Fraction(n,d);
    }
}

const Fraction ariel::Fraction::operator--(int)
{
    auto n = this->numerator-1;
    auto d = this->denominator;
    return Fraction(n,d).minimizeFraction();
}

const Fraction ariel::Fraction::operator++(int)
{
    auto n = this->numerator+1;
    auto d = this->denominator;
    return Fraction(n,d).minimizeFraction();
}

Fraction ariel::operator+(const Fraction &a, const Fraction &b)
{
    int n,d;
    if(a.denominator == b.denominator) {return Fraction(a.numerator+b.numerator, a.denominator).minimizeFraction();}
    //add case for gcd(a.denominator,b.denominator) != 1
    if(std::__gcd(n,d) == 1){
        auto common_d = a.denominator * b.denominator;
        auto common_n = a.numerator*b.denominator +a.denominator*b.numerator;
        return Fraction(common_n,common_d).minimizeFraction();
    }
    else {
         
    
    } 
    return Fraction();
}

Fraction ariel::operator-(const Fraction &a, const Fraction &b)
{

    return Fraction();
}

Fraction ariel::operator*(const Fraction &a, const Fraction &b)
{
    auto d = a.denominator*b.denominator;
    auto n = a.numerator*b.numerator;
    //add is minimize or n=d
    return Fraction(n,d);
}

Fraction ariel::operator/(const Fraction &a, const Fraction &b)
{
    return Fraction();
}

bool ariel::operator==(const Fraction &a, const Fraction &b)
{
    //minimize a
    //minimize b
    if(a.denominator ==b.denominator && a.numerator == b.numerator) return true;
    else return false;
}

bool ariel::operator>(const Fraction &a, const Fraction &b)
{
    //minimize a
    //minimize b

    return false;
}

bool ariel::operator<(const Fraction &a, const Fraction &b)
{
    //minimize a
    //minimize b
    return false;
}

bool ariel::operator>=(const Fraction &a, const Fraction &b)
{
    //minimize a
    //minimize b
    return false;
}

bool ariel::operator<=(const Fraction &a, const Fraction &b)
{
    //minimize a
    //minimize b
    return false;
}

Fraction ariel::operator+(const Fraction &a, double b)
{
    return Fraction();
}

Fraction ariel::operator-(const Fraction &a, double b)
{
    return Fraction();
}

Fraction ariel::operator*(const Fraction &a, double b)
{
    return Fraction();
}

Fraction ariel::operator/(const Fraction &a, double b)
{
    return Fraction();
}

bool ariel::operator==(const Fraction &a, double b)
{
    return false;
}

bool ariel::operator>(const Fraction &a, double b)
{
    return false;
}

bool ariel::operator<(const Fraction &a, double b)
{
    return false;
}

bool ariel::operator>=(const Fraction &a, double b)
{
    return false;
}

bool ariel::operator<=(const Fraction &a, double b)
{
    return false;
}

std::ostream &ariel::operator<<(std::ostream &output, const Fraction &b)
{
    // TODO: insert return statement here
    return output;
}

std::istream &ariel::operator>>(std::istream &input, Fraction &b)
{
    // TODO: insert return statement here
    return input;
}
