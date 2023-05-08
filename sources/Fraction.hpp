#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <bits/stdc++.h>
/*
*
*
Class creating the object Fraction.
members of class are two integers.
favors to present fractions as improper fraction instead of mixed.
for every method the Fraction suppose to be in reduced form -- reduced in the constractor
*
*
*/
namespace ariel{
    class Fraction{
        private:
            int denominator;
            int numerator;
        public:

            Fraction(int num=0): numerator(num),denominator(1) {}
            Fraction(int num, int den): numerator(num), denominator(den){
                if(den == 0){
                    throw "Can't divide by 0";   
                }    
                auto gcd = std::__gcd(num,den);
                this->denominator = den/gcd;
                this->numerator = num/gcd;
            }
            Fraction(double dec){}
            ~Fraction(){}
            int const getDenominator(){ return denominator;}
            int const getNumerator(){ return numerator; }

            
            /*unary operators---------------------------------------------------

            prefix --> caliing ref adds one to the original*/
            Fraction& operator--(){
                this->numerator = (this->numerator-this->denominator);
                return (*this);
            }          
            Fraction& operator++(){
                this->numerator = (this->numerator+this->denominator);
                return (*this);
            } //add if not minize or n=d
            
            /*postfix --> calling copy ctor that adds one trturn copy (original not changed)*/
            const Fraction operator--(int);       
            const Fraction operator++(int);


            friend Fraction minimizeFraction(const Fraction &a);
            friend Fraction decimal2frac(double f);
            /*friend binary operators-----------------fraction vs. fraction-------------------------*/

            friend Fraction operator+(const Fraction& frac1,const Fraction& frac2);
            friend Fraction operator-(const Fraction& frac1,const Fraction& frac2);
            friend Fraction operator*(const Fraction& frac1,const Fraction& frac2);
            friend Fraction operator/(const Fraction& frac1,const Fraction& frac2);
            friend bool operator==(const Fraction& frac1,const Fraction& frac2);
            friend bool operator>(const Fraction& frac1,const Fraction& frac2);
            friend bool operator<(const Fraction& frac1,const Fraction& frac2);
            friend bool operator>=(const Fraction& frac1,const Fraction& frac2);
            friend bool operator<=(const Fraction& frac1,const Fraction& frac2);

            /*friend binary operators-----------------fraction vs. double---------------------------*/
            friend Fraction operator+(const Fraction& frac1,double b);
            friend Fraction operator-(const Fraction& frac1,double b);
            friend Fraction operator*(const Fraction& frac1,double b);
            friend Fraction operator/(const Fraction& frac1,double b);
            friend bool operator==(const Fraction& frac1,double b);
            friend bool operator>(const Fraction& frac1,double b);
            friend bool operator<(const Fraction& frac1,double b);
            friend bool operator>=(const Fraction& frac1,double b);
            friend bool operator<=(const Fraction& frac1,double b);
            //friend global ip operator - in pdf
            friend std::ostream& operator<<(std::ostream& output, const Fraction& frac1);
            friend std::istream& operator>>(std::istream& input, Fraction& frac1);
    };
}

#endif