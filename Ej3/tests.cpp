#include "tests.hpp"
#include "entero.hpp"
#include "real.hpp"
#include "complejo.hpp"

void number_console(){
    cout << "========== Ej 3: Number ==========" << endl;
    //inicializa la semilla para números aleatorios.
    srand(static_cast<unsigned>(time(0)));

    try {
        //agarro dos valores aleatorios e inicializo como Enteros.
        int entero1=rand()%500;
        int entero2=rand()%500;
        Entero e1(entero1);
        Entero e2(entero2);
        
        cout << endl << "class Enteros:" << endl;
        cout << "First random number: ";
        e1.toString();
        cout << "Second random number: ";
        e2.toString();

        //sumo los dos enteros y muestro el resultado.
        cout << e1.get_value() << " + " << e2.get_value() << " = ";
        e1.plus(e2);
        e1.toString();

        //devuelvo e1 a su valor original.
        e1.set_value(entero1);

        //resto los dos enteros y muestro el resultado.
        cout << e1.get_value() << " - " << e2.get_value() << " = ";
        e1.minus(e2);
        e1.toString();

        //devuelvo e1 a su valor original.
        e1.set_value(entero1);

        //multiplico los dos enteros y muestro el resultado.
        cout << e1.get_value() << " x " << e2.get_value() << " = ";
        e1.times(e2);
        e1.toString();

        //agarro dos valores aleatorios e inicializo como Reales.
        float real1=static_cast<float>(rand()%5000)/10.0f;
        float real2=static_cast<float>(rand()%5000)/10.0f;
        Real r1(real1);
        Real r2(real2);

        cout << endl << "class Real:" << endl;
        cout << "First random number: ";
        r1.toString();
        cout << "Second random number: ";
        r2.toString();

        //sumo los dos reales y muestro el resultado.
        cout << r1.get_value() << " + " << r2.get_value() << " = ";
        r1.plus(r2);
        r1.toString();

        //devuelvo r1 a su valor original.
        r1.set_value(real1);

        //resto los dos reales y muestro el resultado.
        cout << r1.get_value() << " - " << r2.get_value() << " = ";
        r1.minus(r2);
        r1.toString();

        //devuelvo r1 a su valor original.
        r1.set_value(real1);

        //multiplico los dos reales y muestro el resultado.
        cout << r1.get_value() << " x " << r2.get_value() << " = ";
        r1.times(r2);
        r1.toString();

        //agarro cuatro valores aleatorios e inicializo como Complejos.
        float real_part1=static_cast<float>(rand()%500)/10.0f;
        float imag_part1=static_cast<float>(rand()%500)/10.0f;
        float real_part2=static_cast<float>(rand()%500)/10.0f;
        float imag_part2=static_cast<float>(rand()%500)/10.0f;
        Complejo c1(real_part1, imag_part1);
        Complejo c2(real_part2, imag_part2);

        cout << endl << "class Complejo:" << endl;
        cout << "First random complex number: ";
        c1.toString();
        cout << "Second random complex number: ";
        c2.toString();

        //sumo los dos complejos y muestro el resultado.
        cout << "(" << c1.get_real() << " + " << c1.get_complex() << "i) + ("
             << c2.get_real() << " + " << c2.get_complex() << "i) = ";
        c1.plus(c2);
        c1.toString();

        //devuelvo c1 a su valor original.
        c1.set_real(real_part1);
        c1.set_complex(imag_part1);

        //resto los dos complejos y muestro el resultado.
        cout << "(" << c1.get_real() << " + " << c1.get_complex() << "i) - ("
             << c2.get_real() << " + " << c2.get_complex() << "i) = ";
        c1.minus(c2);
        c1.toString();

        //devuelvo c1 a su valor original.
        c1.set_real(real_part1);
        c1.set_complex(imag_part1);

        //multiplico los dos complejos y muestro el resultado.
        cout << "(" << c1.get_real() << " + " << c1.get_complex() << "i) * ("
             << c2.get_real() << " + " << c2.get_complex() << "i) = ";
        c1.times(c2);
        c1.toString();
    }
    catch (const exception& e){
        cout << e.what() << endl;
    }
}