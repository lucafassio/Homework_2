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

void Number::toString() const {
    cout << to_string(this->num) << endl;
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

//=====Entero=====//
void Entero::toString() const {
    cout << to_string(static_cast<int>(this->num)) << endl;
}

//=====Real=====//
void Real::toString() const {
    cout << to_string(this->num).substr(0, to_string(this->num).find(".")+3) << endl;
}


//=====Complejo=====//
float Complejo::get_complex() const {
    return this->complex;
}

void Complejo::set_complex(float n){
    this->complex=n;
}

void Complejo::toString() const {
    //la complejidad de los prints solo es porque me pone nervioso que se escriban mal los '+' y '-'.
    if (this->get_value() != 0) cout << to_string(this->get_value()).substr(0, to_string(this->get_value()).find(".")+3);
    else {
        cout << to_string(this->get_complex()).substr(0, to_string(this->get_complex()).find(".")+3) << "i" << endl;
        return;
    }
    if (this->get_complex() > 0) cout << " + " << to_string(this->get_complex()).substr(0, to_string(this->get_complex()).find(".")+3) << "i";
    if (this->get_complex() < 0) cout << " - " << to_string(abs(this->get_complex())).substr(0, to_string(abs(this->get_complex())).find(".")+3) << "i";
    cout << endl;
}

void Complejo::plus(const Number& n){
    //convierto el numero en complejo.
    const Complejo* c = dynamic_cast<const Complejo*>(&n);
    if (c){
        this->set_value(this->get_value() + c->get_value());
        this->set_complex(this->get_complex() + c->get_complex());
    }
    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Imaginary number expected.");
}

void Complejo::minus(const Number& n){
    //convierto el numero en complejo.
    const Complejo* c = dynamic_cast<const Complejo*>(&n);
    if (c){
        this->set_value(this->get_value() - c->get_value());
        this->set_complex(this->get_complex() - c->get_complex());
    }
    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Imaginary number expected.");
}

void Complejo::times(const Number& n){
    //convierto el numero en complejo.
    const Complejo* c = dynamic_cast<const Complejo*>(&n);
    if (c){
        float new_real = this->get_value() * c->get_value() - this->get_complex() * c->get_complex();
        this->set_complex(this->get_value() * c->get_complex() + this->get_complex() * c->get_value());
        this->set_value(new_real);
    }
    //si falla el if, se esta tratando operar con otro tipo.
    else throw invalid_argument("Imaginary number expected.");
}

//=====Console=====//
void Number_console() {
    cout << "========== Ej 3: Number ==========" << endl;
    //Inicializa la semilla para números aleatorios.
    srand(static_cast<unsigned>(time(0)));

    try {
        //Agarro dos valores aleatorios e inicializo como Enteros.
        int entero1 = rand() % 500;
        int entero2 = rand() % 500;
        Entero e1(entero1);
        Entero e2(entero2);
        
        cout << endl << "class Enteros:" << endl;
        cout << "First random number: ";
        e1.toString();
        cout << "Second random number: ";
        e2.toString();

        //Sumo los dos enteros y muestro el resultado.
        cout << e1.get_value() << " + " << e2.get_value() << " = ";
        e1.plus(e2);
        e1.toString();

        //Devuelvo e1 a su valor original.
        e1.set_value(entero1);

        //Resto los dos enteros y muestro el resultado.
        cout << e1.get_value() << " - " << e2.get_value() << " = ";
        e1.minus(e2);
        e1.toString();

        //Devuelvo e1 a su valor original.
        e1.set_value(entero1);

        //Multiplico los dos enteros y muestro el resultado.
        cout << e1.get_value() << " x " << e2.get_value() << " = ";
        e1.times(e2);
        e1.toString();

        //Agarro dos valores aleatorios e inicializo como Reales.
        float real1 = static_cast<float>(rand() % 5000) / 10.0f;
        float real2 = static_cast<float>(rand() % 5000) / 10.0f;
        Real r1(real1);
        Real r2(real2);

        cout << endl << "class Real:" << endl;
        cout << "First random number: ";
        r1.toString();
        cout << "Second random number: ";
        r2.toString();

        // Sumo los dos reales y muestro el resultado.
        cout << r1.get_value() << " + " << r2.get_value() << " = ";
        r1.plus(r2);
        r1.toString();

        // Devuelvo r1 a su valor original.
        r1.set_value(real1);

        // Resto los dos reales y muestro el resultado.
        cout << r1.get_value() << " - " << r2.get_value() << " = ";
        r1.minus(r2);
        r1.toString();

        // Devuelvo r1 a su valor original.
        r1.set_value(real1);

        // Multiplico los dos reales y muestro el resultado.
        cout << r1.get_value() << " x " << r2.get_value() << " = ";
        r1.times(r2);
        r1.toString();

        //Agarro cuatro valores aleatorios e inicializo como Complejos.
        float real_part1 = static_cast<float>(rand() % 500) / 10.0f;
        float imag_part1 = static_cast<float>(rand() % 500) / 10.0f;
        float real_part2 = static_cast<float>(rand() % 500) / 10.0f;
        float imag_part2 = static_cast<float>(rand() % 500) / 10.0f;
        Complejo c1(real_part1, imag_part1);
        Complejo c2(real_part2, imag_part2);

        cout << endl << "class Complejo:" << endl;
        cout << "First random complex number: ";
        c1.toString();
        cout << "Second random complex number: ";
        c2.toString();

        // Sumo los dos complejos y muestro el resultado.
        cout << "(" << c1.get_value() << " + " << c1.get_complex() << "i) + ("
             << c2.get_value() << " + " << c2.get_complex() << "i) = ";
        c1.plus(c2);
        c1.toString();

        // Devuelvo c1 a su valor original.
        c1.set_value(real_part1);
        c1.set_complex(imag_part1);

        // Resto los dos complejos y muestro el resultado.
        cout << "(" << c1.get_value() << " + " << c1.get_complex() << "i) - ("
             << c2.get_value() << " + " << c2.get_complex() << "i) = ";
        c1.minus(c2);
        c1.toString();

        // Devuelvo c1 a su valor original.
        c1.set_value(real_part1);
        c1.set_complex(imag_part1);

        // Multiplico los dos complejos y muestro el resultado.
        cout << "(" << c1.get_value() << " + " << c1.get_complex() << "i) * ("
             << c2.get_value() << " + " << c2.get_complex() << "i) = ";
        c1.times(c2);
        c1.toString();

    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}