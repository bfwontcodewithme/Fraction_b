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
#define DEC_LIM 1000;
namespace ariel{
    class Fraction{
        private:
            int denominator;
            int numerator;
        public:

            Fraction(int num=0): numerator(num),denominator(1) {}
            Fraction(int num, int den): numerator(num), denominator(den){
                if(den == 0){
                    throw std::invalid_argument("Denominator must not be zero");   
                }    
                auto gcd = std::__gcd(num,den);
                this->denominator = den/gcd;
                this->numerator = num/gcd;
            }
            Fraction(double num){
                    int n_frac = 0;
                    int d_frac = DEC_LIM; //limit of 3 after the point
                    double num_rem = num - floor(num);
                    if(floor(num) == ceil(num)){
                        this->denominator = 1;
                        this->numerator = (int)num;
                    } //if d is integar return fraction d/1
                    n_frac = (int(floor(num)))*d_frac + (int(num_rem*d_frac));
                    int gcd = std::__gcd(n_frac,d_frac);
                    this->denominator = d_frac/gcd;
                    this->numerator = n_frac/gcd;
            }
            int getDenominator()const{ return denominator;}
            int getNumerator()const{ return numerator; }

            
            /*unary operators---------------------------------------------------

            prefix --> action on original, return new frac equal to original after action)*/
            Fraction& operator--(){
                this->numerator = (this->numerator-this->denominator);
                return (*this);
            }          
            Fraction& operator++(){
                this->numerator = (this->numerator+this->denominator);
                return (*this);
            } //add if not minize or n=d
            
            /*postfix --> action on original, return new frac equal to original before*/
            const Fraction operator--(int);       
            const Fraction operator++(int);


            friend Fraction minimizeFraction(const Fraction& frac);
            friend Fraction decimal2frac(double num);
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
            friend Fraction operator+(const Fraction& frac1,double num);
            friend Fraction operator-(const Fraction& frac1,double num);
            friend Fraction operator*(const Fraction& frac1,double num);
            friend Fraction operator/(const Fraction& frac1,double num);
            //friend Fraction operator+(double num,const Fraction& frac1){return frac1+num;}
            friend Fraction operator-(double num,const Fraction& frac1){return frac1-num;}
            friend Fraction operator*(double num,const Fraction& frac1){return frac1*num;}
            friend Fraction operator/(double num,const Fraction& frac1){return frac1/num;}
            friend bool operator==(const Fraction& frac1,double num);
            friend bool operator>(const Fraction& frac1,double num);
            friend bool operator<(const Fraction& frac1,double num);
            friend bool operator>=(const Fraction& frac1,double num);
            friend bool operator<=(const Fraction& frac1,double num);
            //friend global ip operator - in pdf
            friend std::ostream& operator<<(std::ostream& output, const Fraction& frac);
            friend std::istream& operator>>(std::istream& input, Fraction& frac);
    };
}

#endif