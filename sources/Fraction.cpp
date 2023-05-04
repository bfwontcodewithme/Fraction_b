#include "Fraction.hpp"
using namespace ariel;


const Fraction ariel::Fraction::operator--(int)
{
    return Fraction();
}

const Fraction ariel::Fraction::operator++(int)
{
    return Fraction();
}

Fraction ariel::operator+(const Fraction &a, const Fraction &b)
{
    return Fraction();
}

Fraction ariel::operator-(const Fraction &a, const Fraction &b)
{
    return Fraction();
}

Fraction ariel::operator*(const Fraction &a, const Fraction &b)
{
    return Fraction();
}

Fraction ariel::operator/(const Fraction &a, const Fraction &b)
{
    return Fraction();
}

bool ariel::operator==(const Fraction &a, const Fraction &b)
{
    return false;
}

bool ariel::operator>(const Fraction &a, const Fraction &b)
{
    return false;
}

bool ariel::operator<(const Fraction &a, const Fraction &b)
{
    return false;
}

bool ariel::operator>=(const Fraction &a, const Fraction &b)
{
    return false;
}

bool ariel::operator<=(const Fraction &a, const Fraction &b)
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
