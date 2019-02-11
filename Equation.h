#ifndef EQUATION_H
#define EQUATION_H
#include <vector>
#include <string>
#include "Linear_Expression.h"

class Equation{

    protected:
        bool w_rat;
        bool w_cruz;
        bool w_dist;
        unsigned short int no_terms_l;
        unsigned short int no_terms_r;
        std::vector<linearExpression> left_member;
        std::vector<linearExpression> right_member;
        std::vector<rationalNumber>& numbers;
        std::string str_representation;
    public:
         Equation(bool w_rat ,bool w_cruz, bool w_dist,std::vector<rationalNumber>& numbers);

         bool with_cruz();
         bool with_dist();
         bool with_rat();
         unsigned short int get_no_terms_l();
         unsigned short int get_no_terms_r();
         void build_str();

         void set_no_terms_l(unsigned short int n);

         void set_no_terms_r(unsigned short int n);

         virtual void build_members(unsigned int(& sequence)[10],rationalNumber& root){}

         std::string get_str();


};

#endif // EQUATION_H
