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
void Number_console(){
    cout << "========== Ej 3: Number ==========" << endl;
    int selected;
    while (true){
        try{
            cout << endl
                << "1. Create a new number" << endl
                << "2. Add two numbers" << endl
                << "3. Subtract two numbers" << endl
                << "4. Multiply two numbers" << endl
                << "5. Print number" << endl
                << "6. Exit" << endl;
            cin >> selected;
            if (cin.fail()){
                cin.clear();
                cin.ignore(9999,'\n');
                throw invalid_argument("Invalid input.");
            }
            switch (selected){
                case 1: {
                    int type;
                    cout << "Select a type of number:" << endl
                        << "1. Entero" << endl
                        << "2. Real" << endl
                        << "3. Complejo" << endl;
                    cin >> type;
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(9999,'\n');
                        throw invalid_argument("Invalid input.");
                    }
                    float n, c=0;
                    cout << "Number: ";
                    cin >> n;
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(9999,'\n');
                        throw invalid_argument("Invalid input.");
                    }
                    if (type==3){
                        cout << "Complex part: ";
                        cin >> c;
                        if (cin.fail()){
                            cin.clear();
                            cin.ignore(9999,'\n');
                            throw invalid_argument("Invalid input.");
                        }
                    }
                    if (type==1) Entero(n);
                    else if (type==2) Real(n);
                    else if (type==3) Complejo(n, c);
                    else throw invalid_argument("Invalid type of number.");
                    break;
                }
                case 2: {
                    // Add two numbers
                    break;
                }
                case 3: {
                    // Subtract two numbers
                    break;
                }
                case 4: {
                    // Multiply two numbers
                    break;
                }
                case 5: {
                    // Print number
                    break;
                }
                case 6:
                    return;
            }
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
}