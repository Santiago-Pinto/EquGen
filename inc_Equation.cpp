#include "inc_Equation.h"
#define MAX_DENOMINATOR 10



incEquation::incEquation(bool w_rat ,bool w_cruz, bool w_dist,std::vector<rationalNumber>& numbers):
                         Equation(w_rat ,w_cruz,w_dist, numbers){
    //ctor
}

void incEquation::build_members(unsigned int(& sequence)[10],rationalNumber& root){
    unsigned int random_n;
    unsigned int roots[10];

    select_roots(roots);

    for (int i = 0; i < no_terms_l; ++i){
        random_n = sequence[i];
        left_member.push_back(linearExpression(numbers[random_n], numbers[roots[i]], w_dist,w_cruz));
    }

    for (int i = 0; i < no_terms_r; ++i){
        random_n = sequence[i+5];
        right_member.push_back(linearExpression(numbers[random_n], numbers[roots[i+5]], w_dist,w_cruz));
    }
}



void incEquation::select_roots(unsigned int (&vec)[10]){
    unsigned int index,j,max_numerator;
    j = 0;
    if (!w_rat)
        max_numerator = 300;
    else
        max_numerator = 10;
    short int it_trhld = 0; //Used to prevent long/infinite loops if either the numerator o denominator goes to high.
    rationalNumber coef_sum(0,1); //Voy a controlar que tan feo escala la fraccion  con esto
    while (j < 10){ // Worst case posible: equation gets 10 terms.
        index = static_cast<unsigned int>(rand() % numbers.size());//static_cast<unsigned int>(rand() % static_cast<int>(numbers.size()));//static_cast<unsigned int>(rand() % 3);
        if (!w_rat && numbers[index].isRational())
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
