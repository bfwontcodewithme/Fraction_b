#include "Fraction.hpp"
#include <bits/stdc++.h>
#include <algorithm>
using namespace ariel;

void check_overflow(const int num1, const int num2, bool mult = false)      //friend helped me
{
	int max_int = std::numeric_limits<int>::max();
	int min_int = std::numeric_limits<int>::min();

	bool overflow = (num1 > 0 && num2 > 0 && num2 > (max_int - num1)) || (num1 < 0 && num2 < 0 && num2 < (min_int - num1));
	bool underflow = (num2 > 0 && num1 < (min_int + num2)) || (num2 < 0 && num1 > (max_int + num2));

	if (mult) // if multiplication check
	{
		overflow = num1 > 0 && (max_int / num1) < num2;
		underflow = overflow; // doesn't matter
	}

	if (overflow || underflow)
		throw std::overflow_error{"operation has overflowed"};
}

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
    check_overflow(frac1.numerator, frac2.denominator,true);
    check_overflow(frac2.numerator, frac1.denominator, true);
    // if equals -simple addition
    if(frac1.denominator == frac2.denominator) {return minimizeFraction(Fraction(frac1.numerator+frac2.numerator, frac1.denominator));}
    // if not equals finding gcd and multiply to get a common denominator

    auto gcd = std::__gcd(frac1.denominator,frac2.denominator);
    if(gcd == 1){
        check_overflow(frac1.denominator,frac2.denominator, true);        
        auto common_d = frac1.denominator*frac2.denominator;
        auto common_n1 = frac1.numerator*frac2.denominator;
        auto common_n2 = frac2.numerator*frac1.denominator;
        check_overflow(common_n1,common_n2);
        check_overflow(common_n1 +common_n2,common_d);
        return minimizeFraction(Fraction(common_n1 +common_n2,common_d));
    }
    else {
        auto mul_2 = frac1.denominator/gcd;
        auto mul_1 = frac2.denominator/gcd;
        auto common_n1 = frac1.numerator*mul_1;
        auto common_n2 = frac2.numerator*mul_2;
        check_overflow(frac1.denominator, mul_1, true);
        auto common_d = frac1.denominator*mul_1;
        check_overflow(common_n1,common_n2);
        check_overflow(common_n1 +common_n2,common_d);
        return minimizeFraction(Fraction(common_n1+common_n2,common_d));
    }    
}

Fraction ariel::operator-(const Fraction& frac1, const Fraction& frac2)
{
    check_overflow(frac1.numerator, frac2.denominator,true);
    check_overflow(frac2.numerator, frac1.denominator, true);
    // if equals -simple addition
    if(frac1.denominator == frac2.denominator) {return minimizeFraction(Fraction(frac1.numerator-frac2.numerator, frac1.denominator));}
    // if not equals finding gcd and multiply to get a common denominator
    auto gcd = std::__gcd(frac1.denominator,frac2.denominator);
    if(gcd == 1){
        check_overflow(frac1.denominator,frac2.denominator, true);
        auto common_d = frac1.denominator*frac2.denominator;
        auto common_n1 = frac1.numerator*frac2.denominator;
        auto common_n2 = frac2.numerator*frac1.denominator;
        check_overflow(common_n1,common_n2);
        check_overflow(common_n1 -common_n2,common_d);
        return minimizeFraction(Fraction(common_n1- common_n2,common_d));
    }
    else {
        auto mul_2 = frac1.denominator/gcd;
        auto mul_1 = frac2.denominator/gcd;
        auto common_n1 = frac1.numerator*mul_1;
        auto common_n2 = frac2.numerator*mul_2;
        check_overflow(frac1.denominator, mul_1, true);
        auto common_d = frac1.denominator*mul_1;
        check_overflow(common_n1,common_n2);
        check_overflow(common_n1 -common_n2,common_d);
        return minimizeFraction(Fraction(common_n1-common_n2,common_d));
    } 
}

Fraction ariel::operator*(const Fraction& frac1, const Fraction& frac2)
{
    check_overflow(frac1.numerator, frac2.denominator,true);
    check_overflow(frac2.numerator, frac1.denominator, true);
    auto d = frac1.denominator*frac2.denominator;
    auto n = frac1.numerator*frac2.numerator;
    check_overflow(n,d);
    return minimizeFraction(Fraction(n,d));
}

Fraction ariel::operator/(const Fraction& frac1, const Fraction& frac2)
{
    //multiply a with inverse b
    if (frac2.getNumerator() == 0) throw std::runtime_error("Can't divide by 0");
    check_overflow(frac1.numerator, frac2.denominator,true);
    check_overflow(frac2.numerator, frac1.denominator, true);
    auto n = frac1.numerator*frac2.denominator;
    auto d = frac1.denominator*frac2.numerator;
    check_overflow(n,d);
    return minimizeFraction(Fraction(n,d));
}

bool ariel::operator==(const Fraction& frac1, const Fraction& frac2)
{
    if(frac1.denominator ==frac2.denominator && frac1.numerator == frac2.numerator) return true;
    auto gcd = std::__gcd(frac1.denominator,frac2.denominator);
    if(gcd == 1){
        auto common_n1 = frac1.numerator*frac2.denominator;
        auto common_n2 = frac2.numerator*frac1.denominator;
        return (common_n1 == common_n2);
    }
    else {
        auto mul_2 = frac1.denominator/gcd;
        auto mul_1 = frac2.denominator/gcd;
        auto common_n1 = frac1.numerator*mul_1;
        auto common_n2 = frac2.numerator*mul_2;
        return (common_n1 == common_n2);
    }
}

bool ariel::operator>(const Fraction& frac1, const Fraction& frac2)
{
    auto gcd = std::__gcd(frac1.denominator,frac2.denominator);
    if(gcd == 1){
        auto common_n1 = frac1.numerator*frac2.denominator;
        auto common_n2 = frac2.numerator*frac1.denominator;
        return (common_n1 > common_n2);
    }
    else {
        auto mul_2 = frac1.denominator/gcd;
        auto mul_1 = frac2.denominator/gcd;
        auto common_n1 = frac1.numerator*mul_1;
        auto common_n2 = frac2.numerator*mul_2;
        return (common_n1 > common_n2);
    }
}

bool ariel::operator<(const Fraction& frac1, const Fraction& frac2)
{
    auto gcd = std::__gcd(frac1.denominator,frac2.denominator);
    if(gcd == 1){
        auto common_n1 = frac1.numerator*frac2.denominator;
        auto common_n2 = frac2.numerator*frac1.denominator;
        return (common_n1 < common_n2);
    }
    else {
        auto mul_2 = frac1.denominator/gcd;
        auto mul_1 = frac2.denominator/gcd;
        auto common_n1 = frac1.numerator*mul_1;
        auto common_n2 = frac2.numerator*mul_2;
        return (common_n1 < common_n2);
    }
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

// binary op double vs fraction

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

    return output << frac.numerator << "/" << frac.denominator;;
}

std::istream &ariel::operator>>(std::istream &input, Fraction &frac)
{
    int num,den;
    input >> num >> den;
    if(den == 0){
        throw std::runtime_error("0 is not valid denominator");
    }
    if(!input){
        throw std::runtime_error("Missing second value");
    }
    frac.denominator = den;
    frac.numerator = num;

    return input;
}

