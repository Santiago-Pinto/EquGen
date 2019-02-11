#include "Linear_Expression.h"
#include <time.h>
using std::string;


void linearExpression::set_first_format(){  //a(x-root)/b  == \frac{a\left(x-root\right)}{b}
    if (a.get_denominator() ==  "1")
        set_second_format();//Solucion para salir del paso
    else {
        if (atoi(a.get_numerator().c_str()) == 1){
             if (!a.get_sign())
                str_representation += "-\\frac{(x" + root.get_sign_str() + root.get_str() + ")}";
             else
                str_representation += "\\frac{x" + root.get_sign_str() + root.get_str() + "}";
           str_representation += "{" + a.get_denominator() + "}";
        }
        else {
           if (!a.get_sign()){
               //Negative slope
                str_representation = a.get_sign_str() + "\\frac{";
                str_representation += a.get_numerator() + "\\left(x" + root.get_sign_str()
                                                                                    + root.get_str() + "\\right)}";
           } else {
                str_representation += "\\frac{" + a.get_numerator() + "\\left(x" + root.get_sign_str()
                                                                                             + root.get_str() + "\\right)}";
           }
                str_representation += "{" + a.get_denominator() + "}";
        }
    }
}

void linearExpression::set_second_format(){ //mx + b (polynomial form)
    if (!a.get_sign())
        str_representation += "-";

    if( (a.get_numerator () != "1") || (a.get_denominator() != "1"))
        str_representation += a.get_str();

    rationalNumber aux = a*root;// Operator '+' modifies the slope, so it's better to save it.

    str_representation += "x " + (aux).get_sign_str() + (aux).get_str();
}

void linearExpression::set_third_format(){ //a\left(\frac{x}{b}-\frac{sol}{b}\right)  = a(x/b - root/b)
    if (!a.get_sign())
            str_representation += "-";
    rationalNumber aux(1,atoi(a.get_denominator().c_str()));
    if (a.get_numerator() != "1")
        str_representation += a.get_numerator();
    if (a.get_denominator() != "1")
        str_representation +=  "\\left(\\frac{x}{" + a.get_denominator() + "}";
    else
        str_representation += "\\left(x";


    rationalNumber result = root*aux;
    if (result.get_denominator() != "1")
        str_representation += root.get_sign_str() +"\\frac{" + result.get_numerator() + "}{" + result.get_denominator() + "}\\right)";
    else
        str_representation += root.get_sign_str() + result.get_numerator() + "\\right)";
}


void linearExpression::set_fourth_format(){ //\frac{1}{b}\left(ax-asol\right) = 1/b*(ax - a*root)

    if (a.get_denominator() == "1")
       set_second_format();
    else{
        if(!a.get_sign())
            str_representation += "-";
        str_representation += "\\frac{1}{" + a.get_denominator() + "}\\left(";

        if(a.get_numerator() != "1")
          str_representation += a.get_numerator();

        rationalNumber aux(atoi(a.get_numerator().c_str()),1);
        str_representation +=  "x" + (aux*root).get_sign_str() + (aux*root).get_str() + "\\right)";
    }
}

void linearExpression::set_fifth_format(){ //\frac{\left(ax-\frac{a.rootnum}{rootden}\right)}{b}\:
                                           //\frac{a\left(x-root\right)}{b}

    if (a.get_denominator() ==  "1")
        set_second_format();//Solucion para salir del paso
    else {
        if (atoi(a.get_numerator().c_str()) == 1){
             if (!a.get_sign())
                str_representation += "+\\frac{(x" + root.get_sign_str() + root.get_str() + ")}";
             else
                str_representation += "\\frac{x" + root.get_sign_str() + root.get_str() + "}";
           str_representation += "{" + a.get_denominator() + "}";
        }
        else {
           if (!a.get_sign()){
               //Negative slope
                rationalNumber aux (-atoi(a.get_numerator().c_str()),1);
                aux = aux*root;
                str_representation = "+\\frac{\\left(" + a.get_sign_str();
                str_representation += a.get_numerator() + "x" + aux.get_sign_str()
                                                                          + aux.get_str() + "\\right)}";
           } else {
                rationalNumber aux (atoi(a.get_numerator().c_str()),1);
                aux = aux*root;
                str_representation += "\\frac{\\left(" + a.get_numerator() + "x" + aux.get_sign_str()
                                                                                             + aux.get_str() + "\\right)}";
           }
                str_representation += "{" + a.get_denominator() + "}\\:";
        }
    }

}


/********************************PUBLIC METHODS********************************/


linearExpression::linearExpression(rationalNumber& a,
                                   rationalNumber& root,bool w_dist, bool w_cruz):a(a),root(root),
                                   w_dist(w_dist), w_cruz(w_cruz){
}

bool linearExpression::get_slope_sign(){
    return a.get_sign();
}


void linearExpression::set_str(int form, bool w_dist, bool w_cruz){
    if(!w_dist)
        form = 2; // Force polynomial format

    if(w_cruz)
        form = 8;
    switch (form){

        case 1://: //a(x-root)/b
                {
                    set_first_format();
                    break;
                }
        case 2: case 3://Expanded version mx + b (polynomial form)
                {
                    set_second_format();
                    break;
                }
        case 4: case 5: //a\left(\frac{x}{b}-\frac{sol}{b}\right)  = a(x/b - root/b)
                {
                    set_third_format();
                    break;
                }
        case 6: case 7: //\frac{1}{b}\left(ax-asol\right) = 1/b*(ax - a*root)
                    set_fourth_format();
                    break;
        case 8: case 9://\frac{\left(ax-\frac{a.rootnum}{rootden}\right)}{b}\:
                       //\frac{a\left(x-root\right)}{b}
                    set_fifth_format();
                    break;
    }
}

string linearExpression::get_str(){
    unsigned int form = rand() % 9 + 1;
    set_str(form, w_dist, w_cruz);
    return this->str_representation;
}


linearExpression linearExpression::operator +(const linearExpression& other){
        
        //linearExpression result(a + other.a,root,w_dist,w_cruz);
        //return result;
}

