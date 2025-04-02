#include "number.hpp"
#include "real.hpp"

Real::Real(float n):
    num(n)
{}

float Real::get_value() const {
    return this->num;
}

void Real::set_value(float n){
    this->num=n;
}

void Real::toString() const {
    cout << to_string(this->num).substr(0, to_string(this->num).find(".")+3) << endl;
}

void Real::plus(const Number& n){
    //convierto el Numero en real.
    const Real* r=dynamic_cast<const Real*>(&n);
    if (r) this->set_value(this->get_value()+r->get_value());

    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Int expected.");
}

void Real::minus(const Number& n){
    //convierto el Numero en real.
    const Real* r=dynamic_cast<const Real*>(&n);
    if (r) this->set_value(this->get_value()-r->get_value());

    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Int expected.");
}

void Real::times(const Number& n){
    //convierto el Numero en real.
    const Real* r=dynamic_cast<const Real*>(&n);
    if (r) this->set_value(this->get_value()*r->get_value());

    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Int expected.");
}