#include "Fraction.hpp"
#include <bits/stdc++.h>
using namespace ariel;

ariel::Fraction::Fraction(double n, double d)
{
    if(d == 0) throw "Can't divide by 0";
    if(floor(n) == ceil(n) && floor(d) == ceil(d)){         //rational numbers
        this->numerator = n;
        this->denominator = d;
    }
    //_r is the remainder. 0 in n&d int
    double n_r = n - floor(n);
    if(n_r){
        double n_n = floor(n)*1000 + n_r;
        double n_d = 1000;
    } 



    double d_r = d - floor(d);
    


}

Fraction ariel::Fraction::minimizeFraction()
{
    if(this->denominator % this->numerator ==0){

    }
    return Fraction();
}

const Fraction ariel::Fraction::operator--(int)
{
    auto n = this->numerator-1;
    auto d = this->denominator;
    //add is minimize or n=d
    return Fraction(n,d);
}

const Fraction ariel::Fraction::operator++(int)
{
    auto n = this->numerator+1;
    auto d = this->denominator;
    //add is minimize or n=d
    return Fraction(n,d);
}

Fraction ariel::operator+(const Fraction &a, const Fraction &b)
{
    if(a.denominator == b.denominator){
            auto d = a.denominator;
            auto n = a.numerator + b.numerator;
            //check if minimize
            return Fraction(n,d);
    }
    else if(a.denominator % b.denominator == 0){

    }
    else {}
    return Fraction();
}

Fraction ariel::operator-(const Fraction &a, const Fraction &b)
{
    if(a.denominator == b.denominator){
            auto d = a.denominator;
            auto n = a.numerator + b.numerator;
            //check if minimize
            return Fraction(n,d);
    }
    else if(a.denominator % b.denominator == 0){

    }
    else {}
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
