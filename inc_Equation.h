#ifndef INC_EQU_H
#define INC_EQU_H
#include "Equation.h"

class incEquation: public Equation{

    private:
        void select_roots(unsigned int (&roots)[10]);
    public:
        incEquation(bool w_rat ,bool w_cruz, bool w_dist, std::vector<rationalNumber>& numbers);
        void build_members(unsigned int(& sequence)[10],rationalNumber& root);

};
#endif // INC_EQU_H
