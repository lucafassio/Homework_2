#include "number.hpp"

Entero::Entero(int n):
    num(n)
{}

int Entero::get_value() const {
    return this->num;
}

void Entero::set_value(int n){
    this->num=n;
}

void Entero::print_value() const {
    cout << this->num << endl;
}

void Entero::plus(Entero n){
    this->set_value(this->get_value()+n.get_value());
}

void Entero::plus(Real n){
    this->set_value(this->get_value()+n.get_value());
}

void Entero::minus(Entero n){
    this->set_value(this->get_value()-n.get_value());
}

void Entero::minus(Real n){
    this->set_value(this->get_value()-n.get_value());
}

void Entero::times(Entero n){
    this->set_value(this->get_value()*n.get_value());
}

void Entero::times(Real n){
    this->set_value(this->get_value()*n.get_value());
}

Real::Real(float n):
    num(n)
{}

float Real::get_value() const {
    return this->num;
}

void Real::set_value(int n){
    this->num=n;
}

void Real::print_value() const {
    cout << this->num << endl;
}

void Real::plus(Real n){
    this->set_value(this->get_value()+n.get_value());
}

void Real::plus(Entero n){
    this->set_value(this->get_value()+n.get_value());
}

void Real::minus(Real n){
    this->set_value(this->get_value()-n.get_value());
}

void Real::minus(Entero n){
    this->set_value(this->get_value()-n.get_value());
}

void Real::times(Real n){
    this->set_value(this->get_value()*n.get_value());
}

Complejo::Complejo(Real r, Real c):
    real(r), complex(c)
{}

float Complejo::get_real() const {
    return this->real.get_value();
}

float Complejo::get_complex() const {
    return this->complex.get_value();
}

void Complejo::set_real(float n){
    this->real=Real(n);
}

void Complejo::set_complex(float n){
    this->complex=Real(n);
}

void Complejo::print_value() const {
    if (this->real.get_value()!=0) cout << this->real.get_value();
    else {cout << this->complex.get_value() << "i" << endl; return;}
    if (this->complex.get_value()>0) cout << " + " << this->complex.get_value() << "i";
    if (this->complex.get_value()<0) cout << " - " << abs(this->complex.get_value()) << "i";
    cout << endl;
}

void Complejo::plus(Complejo n){
    this->set_real(this->get_real()+n.get_real());
    this->set_complex(this->get_complex()+n.get_complex());
}

void Complejo::minus(Complejo n){
    this->set_real(this->get_real()-n.get_real());
    this->set_complex(this->get_complex()-n.get_complex());
}

void Complejo::times(Complejo n){
    this->set_real(this->get_real()*n.get_real()-this->get_complex()*n.get_complex());
    this->set_complex(this->get_real()*n.get_complex()+this->get_complex()*n.get_real());
    cout << "a " << this->get_real() << endl;
    cout << "a " << this->get_complex() << endl;
    cout << "a " << n.get_real() << endl;
    cout << "a " << n.get_complex() << endl;
    cout << "a " << this->get_real()*n.get_complex() << endl;
    cout << "a " << n.get_real()*this->get_complex() << endl;
    cout << "a " << this->get_real()*n.get_complex()+this->get_complex()*n.get_real() << endl;
}

void Numero(){

}
