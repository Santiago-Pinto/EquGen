#ifndef EQUATION_FACTORY_H
#define EQUATION_FACTORY_H
#include "det_Equation.h"
#include "ind_Equation.h"
#include "inc_Equation.h"

class equationFactory{


  public:
    static Equation* create(int type,bool w_rat ,bool w_cruz, bool w_dist, std::vector<rationalNumber>& numbers){
        Equation* equ;
        switch (type){
            case 1:
                equ = new detEquation(w_rat,w_cruz,w_dist,numbers);
                break;
            case 2:
                equ = new indEquation(w_rat,w_cruz,w_dist,numbers);
                break;
            case 3:
                equ = new incEquation(w_rat,w_cruz,w_dist,numbers);
                break;
        }
    }

};

#endif // EQUATION_FACTORY_H
