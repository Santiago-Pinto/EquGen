#ifndef LINEAR_EXPRESSION_H_INCLUDED
#define LINEAR_EXPRESSION_H_INCLUDED
#include "Rational_Number.h"

class linearExpression{
    private:
        // Required attributes to express the linear expression in its
        //factored form
        rationalNumber& a; //slope-pendiente
        rationalNumber& root;
        std::string str_representation;
        bool w_dist;
        bool w_cruz;

        /**Private methods**/
        void set_str(int form, bool w_dist, bool w_cruz);

        void set_first_format();
        void set_second_format();
        void set_third_format();
        void set_fourth_format();
        void set_fifth_format();

    public:
        linearExpression(rationalNumber& a, rationalNumber& root, bool w_dist, bool w_cruz);
        std::string get_str();
        bool get_slope_sign();

        //Operators overload
        linearExpression operator +(const linearExpression& other);
};


#endif // LINEAR_EXPRESSION_H_INCLUDED
