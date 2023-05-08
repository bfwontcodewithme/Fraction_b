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

            Fraction(int n=0): denominator(1), numerator(n) {}
            Fraction(int n, int d): denominator(d), numerator(n){
                if(d == 0) throw "Can't divide by 0";    
                int gcd = std::__gcd(n,d);
                this->denominator = d/gcd;
                this->numerator = n/gcd;
            }
            ~Fraction(){}
            int getDominator(){ return denominator;}
            int getNumerator(){ return numerator; }
            Fraction minimizeFraction(); //return reduced form of fraction if possible

            
            /*unary operators---------------------------------------------------

            prefix --> caliing ref adds one to the original*/
            Fraction& operator--(){
                this->numerator = (this->numerator-1);
                return (*this);
            }          
            Fraction& operator++(){
                this->numerator = (this->numerator+1);
                return (*this);
            } //add if not minize or n=d
            
            /*postfix --> calling copy ctor that adds one trturn copy (original not changed)*/
            const Fraction operator--(int);       
            const Fraction operator++(int);



            /*friend binary operators-----------------fraction vs. fraction-------------------------*/

            friend Fraction operator+(const Fraction& a,const Fraction& b);
            friend Fraction operator-(const Fraction& a,const Fraction& b);
            friend Fraction operator*(const Fraction& a,const Fraction& b);
            friend Fraction operator/(const Fraction& a,const Fraction& b);
            friend bool operator==(const Fraction& a,const Fraction& b);
            friend bool operator>(const Fraction& a,const Fraction& b);
            friend bool operator<(const Fraction& a,const Fraction& b);
            friend bool operator>=(const Fraction& a,const Fraction& b);
            friend bool operator<=(const Fraction& a,const Fraction& b);

            /*friend binary operators-----------------fraction vs. double---------------------------*/
            friend Fraction operator+(const Fraction& a,double b);
            friend Fraction operator-(const Fraction& a,double b);
            friend Fraction operator*(const Fraction& a,double b);
            friend Fraction operator/(const Fraction& a,double b);
            friend bool operator==(const Fraction& a,double b);
            friend bool operator>(const Fraction& a,double b);
            friend bool operator<(const Fraction& a,double b);
            friend bool operator>=(const Fraction& a,double b);
            friend bool operator<=(const Fraction& a,double b);
            //friend global ip operator - in pdf
            friend std::ostream& operator<<(std::ostream& output, const Fraction& b);
            friend std::istream& operator>>(std::istream& input, Fraction& b);
    };
}

#endif