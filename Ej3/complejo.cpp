#include "number.hpp"
#include "complejo.hpp"

Complejo::Complejo(float r, float c):
    real(r), complex(c)
{}

float Complejo::get_real() const {
    return this->real;
}

float Complejo::get_complex() const {
    return this->complex;
}

void Complejo::set_real(float n){
    this->real=n;
}

void Complejo::set_complex(float n){
    this->complex=n;
}

void Complejo::toString() const {
    //la complejidad de los prints solo es porque me pone nervioso que se escriban mal los '+' y '-'.
    if (this->get_real()!=0) cout << to_string(this->get_real()).substr(0, to_string(this->get_real()).find(".")+3);
    else {
        cout << to_string(this->get_complex()).substr(0, to_string(this->get_complex()).find(".")+3) << "i" << endl;
        return;
    }
    if (this->get_complex()>0) cout << " + " << to_string(this->get_complex()).substr(0, to_string(this->get_complex()).find(".")+3) << "i";
    if (this->get_complex()<0) cout << " - " << to_string(abs(this->get_complex())).substr(0, to_string(abs(this->get_complex())).find(".")+3) << "i";
    cout << endl;
}

void Complejo::plus(const Number& n){
    //convierto el Numero en complejo.
    const Complejo* c=dynamic_cast<const Complejo*>(&n);
    if (c){
        this->set_real(this->get_real()+c->get_real());
        this->set_complex(this->get_complex()+c->get_complex());
    }
    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Imaginary number expected.");
}

void Complejo::minus(const Number& n){
    //convierto el Numero en complejo.
    const Complejo* c=dynamic_cast<const Complejo*>(&n);
    if (c){
        this->set_real(this->get_real()-c->get_real());
        this->set_complex(this->get_complex()-c->get_complex());
    }
    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Imaginary number expected.");
}

void Complejo::times(const Number& n){
    //convierto el Numero en complejo.
    const Complejo* c=dynamic_cast<const Complejo*>(&n);
    if (c){
        float new_real=this->get_real()*c->get_real()-this->get_complex()*c->get_complex();
        this->set_complex(this->get_real()*c->get_complex()+this->get_complex()*c->get_real());
        this->set_real(new_real);
    }
    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Imaginary number expected.");
}