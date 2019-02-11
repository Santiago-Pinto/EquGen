#include "Rational_Number.h"
#include <cmath>
using std::min;
using std::max;
using std::string;
using std::to_string;

void rationalNumber::simplify(){
    //gcd = Greatest common divisor
    int gcd;
    for (gcd = abs(min(numerator,denominator)); gcd > 1; --gcd){
        if ((numerator % gcd == 0) && (denominator % gcd == 0)){
            numerator = numerator / gcd;
            denominator = denominator / gcd;
        }
    }
}

/***************** PUBLIC METHODS***************/
rationalNumber::rationalNumber(int numerator,int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
    sign = (numerator * denominator >= 0);
    simplify();
    if (denominator == 1)
        type = 'e'; //Integer number
    else{
        type = 'r'; //Rational number
    }
}


rationalNumber rationalNumber::operator+(const rationalNumber& other){
    if (this->denominator == other.denominator)
        this->numerator += other.numerator;
    else {
        this->numerator = numerator*other.denominator + other.numerator*denominator;
        this->denominator = denominator*other.denominator;
    }
    this->sign = (numerator * denominator >= 0);
    simplify();
    return *this;
}

rationalNumber rationalNumber::operator-(const rationalNumber& other){
    if (this->denominator == other.denominator)
        numerator -= other.numerator;
    else {
        this->numerator = numerator*other.denominator - other.numerator*denominator;
        this->denominator = denominator*other.denominator;
    }
    this->sign = (numerator * denominator >= 0);
    simplify();
    return *this;
}


rationalNumber rationalNumber::operator*(const rationalNumber& other){
    rationalNumber result(numerator * other.numerator,
                          denominator * other.denominator);
    this->sign = (numerator * denominator >= 0);
    simplify();
    return result;
}

rationalNumber rationalNumber::operator/(const rationalNumber& other){
    numerator = numerator * other.denominator;
    denominator = denominator * other.numerator;
    sign = (numerator * denominator >= 0);
    simplify();
    return *this;
}


void rationalNumber::operator=(const rationalNumber& other){

    this->numerator = other.numerator;
    this->denominator = other.denominator;
    this->sign = other.sign;
}

bool rationalNumber::operator== (const rationalNumber& other){

    return ((this->numerator == other.numerator) && (this->denominator == other.denominator));
}

string rationalNumber::get_numerator(){
    int a = numerator;
    int b = abs(a);
    string s = to_string(b);
    return s;
}

string rationalNumber::get_denominator(){
    return to_string(abs(this->denominator));
}

string rationalNumber::get_sign_str(){
    if (sign)
        return "+";
    return "-";
}

bool rationalNumber::get_sign(){
    return sign;
}

string rationalNumber::get_str(){
    simplify();
    // 1 if non-negative number
    if (numerator == 0)
        return " ";

    if (abs(denominator) == 1){
        return get_numerator();
    }

    return "\\frac{" + get_numerator() + "}{" + get_denominator() + "}";
}



bool rationalNumber::isRational(){
    return this->type == 'r';
}

