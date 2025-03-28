#include "number.hpp"

Number::Number(float n):
    num(n)
{}

Entero::Entero(int n):
    Number(n)
{}

Real::Real(float n):
    Number(n)
{}

Complejo::Complejo(float r, float c):
    Number(r), complex(c)
{}

float Number::get_value() const {
    return this->num;
}

void Number::set_value(int n){
    this->num=n;
}

void Number::print_value() const {
    cout << this->num << endl;
}

void Number::plus(Number n){
    this->set_value(this->get_value()+n.get_value());
}

void Number::minus(Number n){
    this->set_value(this->get_value()-n.get_value());
}

void Number::times(Number n){
    this->set_value(this->get_value()*n.get_value());
}

float Complejo::get_complex() const {
    return this->complex;
}

void Complejo::set_complex(float n){
    this->complex=n;
}

void Complejo::print_value() const {
    if (this->get_value()!=0) cout << this->get_value();
    else {cout << this->get_complex() << "i" << endl; return;}
    if (this->get_complex()>0) cout << " + " << this->get_complex() << "i";
    if (this->get_complex()<0) cout << " - " << abs(this->get_complex()) << "i";
    cout << endl;
}

void Complejo::plus(Complejo n){
    this->set_value(this->get_value()+n.get_value());
    this->set_complex(this->get_complex()+n.get_complex());
}

void Complejo::minus(Complejo n){
    this->set_value(this->get_value()-n.get_value());
    this->set_complex(this->get_complex()-n.get_complex());
}

void Complejo::times(Complejo n){
    float new_real=this->get_value()*n.get_value()-this->get_complex()*n.get_complex();
    this->set_complex(this->get_value()*n.get_complex()+this->get_complex()*n.get_value());
    this->set_value(new_real);
}