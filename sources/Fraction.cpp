#include "Fraction.hpp"
#include <bits/stdc++.h>
#include <algorithm>
using namespace ariel;

/*
    fraction are created and changed to reduced form is needed in the contractor 
    every method return the fraction with minimize action
*/


/* postfix, return new fracequal to original then sub 1 to original */
const Fraction ariel::Fraction::operator--(int)
{
    //  1 equals (denominator / denominator)
    auto n = this->numerator;
    auto d = this->denominator;
    this->numerator = this->numerator-this->denominator;
    return minimizeFraction(Fraction(n,d));
}
/* postfix, return new frac equal to original then adding 1 to original */
const Fraction ariel::Fraction::operator++(int)
{
    auto n = this->numerator;
    auto d = this->denominator;
    this->numerator = this->numerator+this->denominator;
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
    int gcd = std::__gcd(frac1.numerator,frac1.denominator);
    auto n_frac = frac1.numerator/gcd;
    auto d_frac = frac1.denominator/gcd;
    return Fraction(n_frac,d_frac);
}


// binary op frac vs frac

Fraction ariel::operator+(const Fraction& frac1, const Fraction& frac2)
{
    // if equals -simple addition
    if(frac1.denominator == frac2.denominator) {return minimizeFraction(Fraction(frac1.numerator+frac2.numerator, frac1.denominator));}
    // if not equals finding gcd and multiply to get a common denominator
    auto gcd = std::__gcd(frac1.denominator,frac2.denominator);
    auto mul_2 = std::abs(frac1.denominator/gcd);
    auto mul_1 = std::abs(frac2.denominator/gcd);
    auto common_n = frac1.numerator*mul_1 + frac2.numerator*mul_2;
    auto common_d = frac1.denominator*mul_1;
    return minimizeFraction(Fraction(common_n,common_d));
}

Fraction ariel::operator-(const Fraction& frac1, const Fraction& frac2)
{
    if(frac1.denominator == frac2.denominator) {return minimizeFraction(Fraction(frac1.numerator-frac2.numerator, frac1.denominator));}
    // if not equals finding gcd and multiply to get a common denominator
    auto gcd = std::__gcd(frac1.denominator,frac2.denominator);
    auto mul_2 = std::abs(frac1.denominator/gcd);
    auto mul_1 = std::abs(frac2.denominator/gcd);
    auto common_n = frac1.numerator*mul_1 - frac2.numerator*mul_2;
    auto common_d = frac1.denominator*mul_1;
    return minimizeFraction(Fraction(common_n,common_d));
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
    return Fraction(frac1 + Fraction(num));
}

Fraction ariel::operator-(const Fraction& frac1, double num)
{
    return Fraction(frac1 - Fraction(num));
}

Fraction ariel::operator*(const Fraction& frac1, double num)
{
    return Fraction(frac1 * Fraction(num));
}

Fraction ariel::operator/(const Fraction& frac1, double num)
{
    return Fraction(frac1 / Fraction(num));
}

bool ariel::operator==(const Fraction &frac1, double num)
{
    if(frac1 == Fraction(num)) return true;
    else return false;
}

bool ariel::operator>(const Fraction& frac1, double num)
{
    if(frac1 > Fraction(num)) return true;
    else return false;
}

bool ariel::operator<(const Fraction& frac1, double num)
{
    if(frac1 < Fraction(num)) return true;
    else return false;
}

bool ariel::operator>=(const Fraction& frac1, double num)
{
    if(frac1 >= Fraction(num)) return true;
    else return false;
}

bool ariel::operator<=(const Fraction& frac1, double num)
{
    if(frac1 <= Fraction(num)) return true;
    else return false;
}

std::ostream &ariel::operator<<(std::ostream &output, const Fraction& frac)
{
    // TODO: insert return statement here
    return output;
}

std::istream &ariel::operator>>(std::istream &input, Fraction &frac)
{
    // TODO: insert return statement here
    return input;
}
