#include "Fraction.hpp"
#include <bits/stdc++.h>
#include <algorithm>
using namespace ariel;

/*
    fraction are created and changed to reduced form is needed in the contractor 
    every method return the fraction with minimize action
*/


/* return new fraction after adding 1 to original */
const Fraction ariel::Fraction::operator--(int)
{
    //  1 equals (denominator / denominator)
    auto n = this->numerator-this->denominator;
    auto d = this->denominator;
    return minimizeFraction(Fraction(n,d));
}
/* return new fraction after adding 1 to original */
const Fraction ariel::Fraction::operator++(int)
{
    auto n = this->numerator+this->denominator;
    auto d = this->denominator;
    return minimizeFraction(Fraction(n,d));
}
/*
input fraction, if can be reduced return the reduced form
if already reduced form return new fraction equal to original     
*/
Fraction ariel::minimizeFraction(const Fraction& frac1)
{
    //get gcd(n,d) then divide by it to get the reduced form
    //if  gcd(n,d) = 1  already in reduced form return itself, if not divide by the gcd.
    int gcd = std::__gcd(a.numerator,a.denominator);
    if(gcd == 1) return a;
    else{
        auto n = a.numerator/gcd;
        auto d = a.denominator/gcd;
        return Fraction(n,d);
        }
}

/* input double output the equal improper fraction */
Fraction ariel::decimal2frac(double f)
{
    int n,d = 1000; //limit of 3 after the point
    double f_rem;
    if(floor(f) == ceil(f)) return Fraction(d,1); //if d is integar return fraction d/1
    /* 
        seperate double to int and decimal.
        the denominator for double is 1000 (reason above),
        the numernator is decimal conveted to int + the whole part times 1000
    */
    std::modf(f,&f_rem);
    n = floor(f)*d + (int(f_rem*d));
    return Fraction(n,d);
}

// binary op frac vs frac

Fraction ariel::operator+(const Fraction& frac1, const Fraction& frac2)
{
    // if equals -simple addition
    if(frac1.denominator == frac2.denominator) {return minimizeFraction(Fraction(frac1.numerator+frac2.numerator, frac1.denominator));}
    // if not equals finding gcd and multiply to get a common denominator
    auto gcd = std::__gcd(frac1.denominator,frac2.denominator);
    if(gcd == 1){
        auto common_d = frac1.denominator * frac2.denominator;
        auto common_n = frac1.numerator*frac2.denominator +frac1.denominator*frac2.numerator;
        return minimizeFraction(Fraction(common_n,common_d));
    }
    else {
        auto mul_2 = frac1.denominator/gcd;
        auto mul_1 = frac2.denominator/gcd;
        auto common_n = frac1.numerator*mul_1 + frac2.denominator*mul_2;
        auto common_d = frac1.denominator*mul_1;
        return minimizeFraction(Fraction(common_n,common_d));
    } 
}

Fraction ariel::operator-(const Fraction& frac1, const Fraction& frac2)
{
    if(frac1.denominator == frac2.denominator) {return minimizeFraction(Fraction(frac1.numerator-frac2.numerator, frac1.denominator));}
    // if not equals finding gcd and multiply to get a common denominator
    auto gcd = std::__gcd(frac1.denominator,frac2.denominator);
    if(gcd == 1){
        auto common_d = frac1.denominator * frac2.denominator;
        auto common_n = frac1.numerator*frac2.denominator +frac1.denominator*frac2.numerator;
        return minimizeFraction(Fraction(common_n,common_d));
    }
    else {
        auto mul_2 = frac1.denominator/gcd;
        auto mul_1 = frac2.denominator/gcd;
        auto common_n = frac1.numerator*mul_1 - frac2.denominator*mul_2;
        auto common_d = frac1.denominator*mul_1;
        return minimizeFraction(Fraction(common_n,common_d));
    }
}

Fraction ariel::operator*(const Fraction& frac1, const Fraction& frac2)
{
    auto d = frac1.denominator*frac2.denominator;
    auto n = frac1.numerator*frac2.numerator;
    return minimizeFraction(Fraction(n,d));
}

Fraction ariel::operator/(const Fraction& frac1, const Fraction& frac2)
{
    //multiply a with inverse b
    auto n = frac1.numerator*frac2.denominator;
    auto d = frac1.denominator*frac2.numerator;
    return minimizeFraction(Fraction(n,d));
}

bool ariel::operator==(const Fraction& frac1, const Fraction& frac2)
{
    /* sending to get reduced form ,if already is then returned the same */
    auto frac1_m = minimizeFraction(frac1);
    auto frac2_m = minimizeFraction(frac2);
    /* comparing the members of reduced form */
    if(frac1_m.denominator ==frac2_m.denominator && frac1_m.numerator == frac2_m.numerator) return true;
    else return false;
}

bool ariel::operator>(const Fraction& frac1, const Fraction& frac2)
{
    auto frac1_m = minimizeFraction(frac1);
    auto frac2_m = minimizeFraction(frac2);
    auto gcd = std::__gcd(frac1_m.denominator, frac2_m.denominator);
    auto mul_f2 = frac1_m.denominator/gcd;
    auto mul_f1 = frac2_m.denominator/gcd;
    if(frac1_m.numerator*mul_f1 > frac2_m.numerator*mul_f2) return true;
    else return false;
}

bool ariel::operator<(const Fraction& frac1, const Fraction& frac2)
{
    auto frac1_m = minimizeFraction(frac1);
    auto frac2_m = minimizeFraction(frac2);
    auto gcd = std::__gcd(frac1_m.denominator, frac2_m.denominator);
    auto mul_f2 = frac1_m.denominator/gcd;
    auto mul_f1 = frac2_m.denominator/gcd;
    if(frac1_m.numerator*mul_f1 < frac2_m.numerator*mul_f2) return true;
    else return false;
}

bool ariel::operator>=(const Fraction& frac1, const Fraction& frac2)
{
    if(frac1 > frac2 || frac1 == frac2) return true;
    else return false;
}

bool ariel::operator<=(const Fraction& frac1, const Fraction& frac2)
{
    if(frac1 < frac2 || frac1 == frac2) return true;
    else return false;
}

// binary op double vs fraction --> using the decimal2fraction and fvf operators 

Fraction ariel::operator+(const Fraction& frac1, double num)
{
    return Fraction(frac1 + Fraction(decimal2frac(num)));
}

Fraction ariel::operator-(const Fraction& frac1, double num)
{
    return Fraction(frac1 - Fraction(decimal2frac(num)));
}

Fraction ariel::operator*(const Fraction& frac1, double num)
{
    return Fraction(frac1 * Fraction(decimal2frac(num)));
}

Fraction ariel::operator/(const Fraction& frac1, double num)
{
    return Fraction(frac1 / Fraction(decimal2frac(num)));
}

bool ariel::operator==(const Fraction& frac1, double num)
{
    if(frac1 == decimal2frac(num)) return true;
    else return false;
}

bool ariel::operator>(const Fraction& frac1, double num)
{
    if(frac1 > decimal2frac(num)) return true;
    else return false;
}

bool ariel::operator<(const Fraction& frac1, double num)
{
    if(frac1 < decimal2frac(num)) return true;
    else return false;
}

bool ariel::operator>=(const Fraction& frac1, double num)
{
    if(frac1 >= decimal2frac(num)) return true;
    else return false;
}

bool ariel::operator<=(const Fraction& frac1, double num)
{
    if(frac1 <= decimal2frac(num)) return true;
    else return false;
}

std::ostream &ariel::operator<<(std::ostream &output, const Fraction& frac2)
{
    // TODO: insert return statement here
    return output;
}

std::istream &ariel::operator>>(std::istream &input, Fraction &b)
{
    // TODO: insert return statement here
    return input;
}
