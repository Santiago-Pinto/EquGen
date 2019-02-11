#ifndef RATIONAL_NUMBER_H_INCLUDED
#define RATIONAL_NUMBER_H_INCLUDED
#include <string>

class rationalNumber{
    private:
        int numerator;
        int denominator; // non-zero
        bool sign;
        void simplify();
        char type;
    public:
        rationalNumber(int numerator,int denominator);
        //Operators overload
        rationalNumber operator +(const rationalNumber& other);
        rationalNumber operator -(const rationalNumber& other);
        rationalNumber operator *(const rationalNumber& other);
        rationalNumber operator /(const rationalNumber& other);
        rationalNumber power(float exponent);
        rationalNumber root(float index);
        void operator=(const rationalNumber& other);
        bool operator== (const rationalNumber& other);
        //Returns string representation of the number
        //If sign_req=true also it tells the sign of the value, otherwise it
        //returns its absolute value
        std::string get_numerator();
        std::string get_denominator();
        std::string get_str();
        std::string get_sign_str();
        bool get_sign();
        bool isRational();
};

#endif // RATIONAL_NUMBER_H_INCLUDED
