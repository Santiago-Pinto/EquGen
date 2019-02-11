#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED
#include <vector>
#include <string>
#include "Linear_Expression.h"
#include "Rational_Number.h"
#include "Equation_Factory.h"
typedef unsigned short int usint_t;

class Generator{
    private:
        std::vector<rationalNumber> numbers;
        int cur_sys_type; //current system type 1 for determinate, 2 for indeterminate, 3 for incompatible
        //Loads the input file
        void load();
        //Builds the actual equation
        void build(std::string solution, Equation* const equ);

        void select_coefficients(unsigned int(& vec)[10], Equation* const equ);

        void select_coefficients_ds(unsigned int(& vec)[10], Equation* const equ);

        rationalNumber select_is(unsigned int(& vec)[10], int offset, usint_t no_terms,Equation* const equ);

        void select_coefficients_is(unsigned int(& vec)[10], Equation* const equ);


        rationalNumber parse(std::string solution);


    public:
        Generator();
        //Generates an equation based on the desired solution and flags
        std::string generate(std::string solution, bool w_rat, bool w_dist, bool w_cruz, int sys_type);
};

#endif // GENERATOR_H_INCLUDED
