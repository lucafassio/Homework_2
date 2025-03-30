#include "number.hpp"

//=====Constructores=====//
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

//=====Number=====//
float Number::get_value() const {
    return this->num;
}

void Number::set_value(float n){
    this->num=n;
}

void Number::print_value() const {
    cout << this->num << endl;
}

void Number::plus(const Number& n){
    this->set_value(this->get_value()+n.get_value());
}

void Number::minus(const Number& n){
    this->set_value(this->get_value()-n.get_value());
}

void Number::times(const Number& n){
    this->set_value(this->get_value()*n.get_value());
}

//=====Complejo=====//
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

void Complejo::plus(const Number& n) {
    const Complejo* c = dynamic_cast<const Complejo*>(&n);
    if (c) {
        this->set_value(this->get_value() + c->get_value());
        this->set_complex(this->get_complex() + c->get_complex());
    } else {
        throw invalid_argument("Se esperaba un Complejo");
    }
}

void Complejo::minus(const Number& n) {
    const Complejo* c = dynamic_cast<const Complejo*>(&n);
    if (c) {
        this->set_value(this->get_value() - c->get_value());
        this->set_complex(this->get_complex() - c->get_complex());
    } else {
        throw invalid_argument("Se esperaba un Complejo");
    }
}

void Complejo::times(const Number& n) {
    const Complejo* c = dynamic_cast<const Complejo*>(&n);
    if (c) {
        float new_real = this->get_value() * c->get_value() - this->get_complex() * c->get_complex();
        this->set_complex(this->get_value() * c->get_complex() + this->get_complex() * c->get_value());
        this->set_value(new_real);
    } else {
        throw invalid_argument("Se esperaba un Complejo");
    }
}

//=====Console=====//
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

void Number_console() {
    srand(static_cast<unsigned>(time(0))); // Inicializar la semilla para números aleatorios

    try {
        cout << "Demostración de operaciones con números aleatorios:" << endl;

        // ===== Entero =====
        int entero1 = rand() % 100; // Número aleatorio entre 0 y 99
        int entero2 = rand() % 100;
        Entero e1(entero1);
        Entero e2(entero2);

        cout << "\nOperaciones con Enteros:" << endl;
        cout << "Primer número entero: ";
        e1.print_value();
        cout << "Segundo número entero: ";
        e2.print_value();

        e1.plus(e2);
        cout << "Suma: ";
        e1.print_value();

        e1.minus(e2);
        cout << "Resta: ";
        e1.print_value();

        e1.times(e2);
        cout << "Multiplicación: ";
        e1.print_value();

        // ===== Real =====
        float real1 = static_cast<float>(rand() % 1000) / 10.0f; // Número aleatorio entre 0.0 y 99.9
        float real2 = static_cast<float>(rand() % 1000) / 10.0f;
        Real r1(real1);
        Real r2(real2);

        cout << "\nOperaciones con Reales:" << endl;
        cout << "Primer número real: ";
        r1.print_value();
        cout << "Segundo número real: ";
        r2.print_value();

        r1.plus(r2);
        cout << "Suma: ";
        r1.print_value();

        r1.minus(r2);
        cout << "Resta: ";
        r1.print_value();

        r1.times(r2);
        cout << "Multiplicación: ";
        r1.print_value();

        // ===== Complejo =====
        float real_part1 = static_cast<float>(rand() % 100) / 10.0f; // Parte real aleatoria
        float imag_part1 = static_cast<float>(rand() % 100) / 10.0f; // Parte imaginaria aleatoria
        float real_part2 = static_cast<float>(rand() % 100) / 10.0f;
        float imag_part2 = static_cast<float>(rand() % 100) / 10.0f;

        Complejo c1(real_part1, imag_part1);
        Complejo c2(real_part2, imag_part2);

        cout << "\nOperaciones con Complejos:" << endl;
        cout << "Primer número complejo: ";
        c1.print_value();
        cout << "Segundo número complejo: ";
        c2.print_value();

        c1.plus(c2);
        cout << "Suma: ";
        c1.print_value();

        c1.minus(c2);
        cout << "Resta: ";
        c1.print_value();

        c1.times(c2);
        cout << "Multiplicación: ";
        c1.print_value();

    } catch (const exception& e) {
        cout << "Error inesperado: " << e.what() << endl;
    }
}