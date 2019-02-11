#include "Generator.h"
#include <fstream>
#include <cstring>
#include <time.h>
#define PATH "input.txt"
#define MAX_DENOMINATOR 10
using std::string;
using std::ifstream;
using std::ofstream;
typedef unsigned short int usint_t;

#include <iostream>
using namespace std;

void Generator::load(){
    ifstream input;
    input.open(PATH);
    string numerator, denominator;
    char type;

    while (input >> type){
        switch(type){
            case 'r': //Rational Number
               {
                      input >> numerator;
                      input >> denominator;
                      numbers.push_back(rationalNumber(atoi(numerator.c_str()), atoi(denominator.c_str())));
                      break;
               }
            case 'e': //Integer Number
                {
                      input >> numerator;
                      numbers.push_back(rationalNumber(atoi(numerator.c_str()), 1));
                      break;
                }
        }
    }
    input.close();
}

rationalNumber Generator::parse(string solution){
    string numerator, denominator;
    size_t match = solution.find("/");
    if (match !=  string::npos){ //Check if it is rational
        numerator = solution.substr(0, match);
        denominator = solution.substr(match + 1);
        rationalNumber number(-atoi(numerator.c_str()), atoi(denominator.c_str()));
        return number;
    }
    // Integer solution
    return rationalNumber(-atoi(solution.c_str()),1);
}


/**** Coefficient selection ****/

void Generator::select_coefficients_ds(unsigned int (&vec)[10], Equation* const equ){
    /**Determinate system**/
    unsigned int index,j,max_numerator;
    j = 0;
    if (!equ->with_rat())
        max_numerator = 300;
    else
        max_numerator = 10;
    short int it_trhld = 0; //Used to prevent long/infinite loops if either the numerator o denominator goes to high.
    rationalNumber coef_sum(0,1); //Voy a controlar que tan feo escala la fraccion  con esto
    while (j < 10){ // Worst case posible: equation gets 10 terms.
        index = static_cast<unsigned int>(rand() % numbers.size());//static_cast<unsigned int>(rand() % static_cast<int>(numbers.size()));//static_cast<unsigned int>(rand() % 3);
        if (!equ->with_rat() && numbers[index].isRational())
            continue;
        coef_sum = coef_sum + numbers[index]; //.add(numbers[index]); //+ numbers[index];
        if ((abs(atoi((coef_sum).get_denominator().c_str())) < MAX_DENOMINATOR) &&
            (abs(atoi((coef_sum).get_numerator().c_str())) < max_numerator)){
            /**El denominador es menor a MAX_DENOMINATOR y el numerador es menor a max_numerator (Valores arbitrarios)**/
            vec[j] = index;
            ++j;
        } else {
            //Dio un denominador feo
            coef_sum = coef_sum - numbers[index];
            ++it_trhld;
            if(it_trhld > 10000 && j > 0){
                //Solution if an "ugly" fraction appears too many times
                --j;
                it_trhld = 0;
            }
        }
    }
}



rationalNumber Generator::select_is(unsigned int(&vec)[10], int offset, usint_t no_terms,Equation* const equ){
    /**Indeterminate system**/
    unsigned int index,j,max_numerator;
    j = 0;
    if (!equ->with_rat())
        max_numerator = 300;
    else
        max_numerator = 30;
    short int it_trhld = 0; //Used to prevent long/infinite loops if either the numerator or denominator goes to high.
    rationalNumber coef_sum(0,1); //Voy a controlar que tan feo escala la fraccion  con esto
    while (j < no_terms){
        index = static_cast<unsigned int>(rand() % numbers.size());//static_cast<unsigned int>(rand() % static_cast<int>(numbers.size()));//static_cast<unsigned int>(rand() % 3);
        if (!equ->with_rat() && numbers[index].isRational())
            continue;
        coef_sum = coef_sum + numbers[index];
        if ((abs(atoi((coef_sum).get_denominator().c_str())) < 0.5*MAX_DENOMINATOR) &&
            (abs(atoi((coef_sum).get_numerator().c_str())) < 0.5*max_numerator)){
            /**El denominador es menor a 1/2*MAX_DENOMINATOR y el numerador es menor a 1/2*max_numerator (Valores arbitrarios)**/
            vec[j+offset] = index;
            ++j;
        } else {
            //Dio un denominador feo
            coef_sum = coef_sum - numbers[index];// two*numbers[index];//(numbers[index] + numbers[index]);
            ++it_trhld;
            if(it_trhld > 10000 && j > 0){
                //Solution if an "ugly" fraction appears too many times
                --j;
                it_trhld = 0;
            }
        }
    }
    return coef_sum;
}

void Generator::select_coefficients_is(unsigned int(& vec)[10], Equation* const equ){

    rationalNumber coef_sum_l(0,1);
    rationalNumber coef_sum_r(0,1);

    do{
        coef_sum_l = select_is(vec,0,equ->get_no_terms_l(),equ);
        coef_sum_r = select_is(vec,5,equ->get_no_terms_r(),equ);
     }while(!(coef_sum_l == coef_sum_r));
}



void Generator::select_coefficients(unsigned int (&vec)[10], Equation* const equ){
    switch (cur_sys_type){

        case 1:
                {
                    select_coefficients_ds(vec, equ);
                    break;
                }
        case 2:
                {
                    select_coefficients_is(vec, equ);
                    break;
                }
        case 3:
                {
                    select_coefficients_is(vec,equ);//
                    break;
                }

    }
}

/*********************************************************************************************/


void Generator::build(std::string solution, Equation* const equ){
    unsigned int sequence[10];
    rationalNumber root = parse(solution);
    usint_t no_terms_l, no_terms_r;
    if (equ->with_cruz()){
        no_terms_l = no_terms_r = 1;
    } else {
        no_terms_l = rand() % 3 + 1;  // random from 1 to 4
        srand(static_cast<unsigned int>(time(nullptr)));
        no_terms_r = rand() % 3 + 1;
        srand(static_cast<unsigned int>(time(nullptr)));
    }
    equ->set_no_terms_l(no_terms_l);
    equ->set_no_terms_r(no_terms_r);
    select_coefficients(sequence, equ);
    equ->build_members(sequence,root);
    equ->build_str();
}

/*********************Public Methods ****************************/
Generator::Generator(){
    load();
}


string Generator::generate(std::string solution, bool w_rat, bool w_dist, bool w_cruz, int sys_type){

    this->cur_sys_type = sys_type;
    Equation* equ = equationFactory::create(sys_type,w_rat,w_cruz,w_dist,numbers);
    if (!equ){
        delete equ;
        return " ";
    }
    build(solution, equ);
    string equ_str = equ->get_str();
    delete equ;
    return equ_str;
}

