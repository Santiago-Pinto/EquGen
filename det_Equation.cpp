#include "det_Equation.h"

detEquation::detEquation(bool w_rat ,bool w_cruz, bool w_dist, std::vector<rationalNumber>& numbers):
                         Equation(w_rat ,w_cruz,w_dist, numbers){
    //ctor
}


void detEquation::build_members(unsigned int(& sequence)[10],rationalNumber& root){
    unsigned int random_n;

    for (int i = 0; i < no_terms_l; ++i){
        random_n = sequence[i];
        left_member.push_back(linearExpression(numbers[random_n], root, w_dist,w_cruz));

    }

    for (int i = 0; i < no_terms_r; ++i){
        random_n = sequence[i+5];
        right_member.push_back(linearExpression(numbers[random_n], root, w_dist,w_cruz));

    }
}
