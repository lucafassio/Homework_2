#include "number.hpp"
#include "entero.hpp"

Entero::Entero(int n):
    num(n)
{}

int Entero::get_value() const {
    return this->num;
}

void Entero::set_value(int n){
    this->num=n;
}

string Entero::toString() const {
    return to_string(static_cast<int>(this->num));
}

void Entero::plus(const Number& n){
    //convierto el Numero en entero.
    const Entero* e=dynamic_cast<const Entero*>(&n);
    if (e) this->set_value(this->get_value()+e->get_value());

    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Int expected.");
}

void Entero::minus(const Number& n){
    //convierto el Numero en entero.
    const Entero* e=dynamic_cast<const Entero*>(&n);
    if (e) this->set_value(this->get_value()-e->get_value());

    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Int expected.");
}

void Entero::times(const Number& n){
    //convierto el Numero en entero.
    const Entero* e=dynamic_cast<const Entero*>(&n);
    if (e) this->set_value(this->get_value()*e->get_value());

    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Int expected.");
}