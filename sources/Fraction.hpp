#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <bits/stdc++.h>

namespace ariel{
    class Fraction{
        private:

            double denominator;
            double numerator;
        public:

            Fraction(double n=0): denominator(1), numerator(n) {}
            Fraction(double n, double d): denominator(d), numerator(n);
            double getDominator(){ return denominator;}
            double getNumerator(){ return numerator; }
            Fraction minimizeFraction(); //return reduced form of fraction if possible

            
            /*unary operators---------------------------------------------------

            prefix --> caliing ref adds one to the original*/
            Fraction& operator--(){
                this->numerator = (this->getNumerator()-1);
                return (*this);}          
            Fraction& operator++(){
                this->numerator = (this->getNumerator()+1);
                return (*this);} //add if not minize or n=d
            
            /*postfix --> calling copy ctor that adds one trturn copy (original not changed)*/
            const Fraction operator--(int);       
            const Fraction operator++(int);



            /*friend binary operators------------------------------------------*/

            friend Fraction operator+(const Fraction& a,const Fraction& b);
            friend Fraction operator-(const Fraction& a,const Fraction& b);
            friend Fraction operator*(const Fraction& a,const Fraction& b);
            friend Fraction operator/(const Fraction& a,const Fraction& b);
            friend bool operator==(const Fraction& a,const Fraction& b);
            friend bool operator>(const Fraction& a,const Fraction& b);
            friend bool operator<(const Fraction& a,const Fraction& b);
            friend bool operator>=(const Fraction& a,const Fraction& b);
            friend bool operator<=(const Fraction& a,const Fraction& b);

            //friend global ip operator - in pdf
            friend std::ostream& operator<<(std::ostream& output, const Fraction& b);
            friend std::istream& operator>>(std::istream& input, Fraction& b);
    };
}

#endif