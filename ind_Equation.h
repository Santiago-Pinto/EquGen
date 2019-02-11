#ifndef IND_EQU_H
#define IND_EQU_H

#include "Equation.h"

class indEquation: public Equation{

    public:
        indEquation(bool w_rat ,bool w_cruz, bool w_dist, std::vector<rationalNumber>& numbers);
        void build_members(unsigned int(& sequence)[10],rationalNumber& root);

};

#endif // IND_EQU_H
