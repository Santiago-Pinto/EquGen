#include "Equation.h"
using std::string;

Equation::Equation(bool w_rat, bool w_cruz, bool w_dist, std::vector<rationalNumber>& numbers):
w_rat(w_rat),w_cruz(w_cruz),w_dist(w_dist), numbers(numbers)
{
    //ctor
}


bool Equation::with_rat(){
    return this->w_rat;
}


bool Equation::with_cruz(){
    return this->w_cruz;
}

bool Equation::with_dist(){
    return this->w_dist;
}

unsigned short int Equation::get_no_terms_l(){
    return this->no_terms_l;
}

unsigned short int Equation::get_no_terms_r(){

    return this->no_terms_r;
}


void Equation::build_str(){
    for (unsigned int i = 0; i < left_member.size(); ++i){
        if (left_member[i].get_slope_sign() && (i > 0))
            str_representation += "+";
        str_representation += left_member[i].get_str();
    }
    str_representation += " = ";
    for (unsigned int i = 0; i < right_member.size(); ++i){
        if (right_member[i].get_slope_sign() && (i > 0))
            str_representation += "+";
        str_representation += right_member[i].get_str();
    }
}



void Equation::set_no_terms_l(unsigned short int n){

    this->no_terms_l = n;
}

void Equation::set_no_terms_r(unsigned short int n){

    this->no_terms_r = n;
}

string Equation::get_str(){

    return this->str_representation;
}
