#ifndef DET_EQUATION_H
#define DET_EQUATION_H
#include "Equation.h"

class detEquation: public Equation{

    public:
        detEquation(bool w_rat ,bool w_cruz, bool w_dist,std::vector<rationalNumber>& numbers);
        void build_members(unsigned int(& sequence)[10],rationalNumber& root);

};

#endif // DET_EQUATION_H
