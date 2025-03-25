#include <iostream>
#include "Ej1/timer.cpp"
#include "Ej2/course.cpp"
#include "Ej3/number.cpp"

using namespace std;

int main(){    
    Entero num(10);

    cout << num.get_value() << endl;
    num.set_value(15);
    num.print_value();

    Entero num2(20);
    num.plus(num2);

    num.print_value();

    Entero num3(80);
    num.minus(num3);

    num.print_value();

    Complejo cnum(-5, 2);
    cnum.print_value();

    Complejo cnum2(3, -6);
    cnum2.print_value();

    cnum.plus(cnum2);

    cnum.print_value();

    cnum.minus(cnum2);
    cnum.minus(cnum2);
    
    cnum.print_value();

    cnum.plus(cnum2);

    cnum.print_value();
    cnum2.print_value();

    cout << cnum.get_real() << endl;
    cout << cnum.get_complex() << endl;
    cout << cnum2.get_real() << endl;
    cout << cnum2.get_complex() << endl;
    cout << cnum.get_real()*cnum2.get_complex() << endl;
    cout << cnum2.get_real()*cnum.get_complex() << endl;
    cout << cnum.get_real()*cnum2.get_complex()+cnum.get_complex()*cnum2.get_real() << endl;
    
    cnum.times(cnum2);
    cnum.print_value();
}