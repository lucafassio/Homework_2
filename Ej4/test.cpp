#include "test.hpp"

void bank_tests(){
    cout << "========== Ej 4: Bank ==========" << endl;
    cout << endl;
    //creo dos cuentas de ejemplo, una con caja de ahorro y otra sin.
    auto savings=make_shared<CajaDeAhorro>(1000.0, "John Doe");
    CuentaCorriente current(savings);
    CuentaCorriente current2(1000.0, "Jane Doe");

    //muestro el balance de ambas cuentas.
    savings->mostrarInfo();
    cout << endl;
    current.mostrarInfo();
    cout << endl;
    current2.mostrarInfo();
    cout << endl;

    //pruebo a depositar en ambas cuentas
    cout << "Depositing $500 in savings account..." << endl;
    cout << "Depositing $1500 in current account..." << endl;
    cout << "Depositing $500 in current account without savings..." << endl;
    savings->depositar(500.0);
    current.depositar(1500.0);
    current2.depositar(500.0);
    cout << endl;
    
    //muestro el balance de ambas cuentas.
    savings->mostrarInfo();
    cout << endl;
    current.mostrarInfo();
    cout << endl;
    current2.mostrarInfo();
    cout << endl;

    //pruebo a retirar de ambas cuentas.
    cout << "Withdrawing $200 from savings account..." << endl;
    cout << "Withdrawing $200 from current account..." << endl;
    cout << "Withdrawing $200 from current account without savings..." << endl;
    try {
        savings->retirar(200.0);
        current.retirar(200.0);
        current2.retirar(200.0);
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    cout << endl;

    //muestro el balance de ambas cuentas luego de retirar.
    savings->mostrarInfo(); //como es la tercera vez que se muestra, se le aplicara la multa a partir de ahora.
    cout << endl;
    current.mostrarInfo();
    cout << endl;
    current2.mostrarInfo();
    cout << endl;

    //pruebo a retirar mas de lo que tengo en la caja de ahorro.
    cout << "Withdrawing $2000 from savings account..." << endl;
    try{
        savings->retirar(2000.0);
    }
    catch (const invalid_argument& e){
        cout << e.what() << endl;
    }

    //pruebo a retirar mas de lo que tengo en la cuenta corriente.
    cout << "Withdrawing $2000 from current account..." << endl;
    try{
        current.retirar(2000.0); //como esta linkeada a una caja de ahorro, se puede retirar.
    }
    catch (const invalid_argument& e){
        cout << e.what() << endl;
    }

    //pruebo a retirar mas de lo que tengo en la cuenta corriente sin caja de ahorro.
    cout << "Withdrawing $2000 from current account without savings..." << endl;
    try{
        current2.retirar(2000.0); //como esta no tiene caja de ahorro, no se puede retirar.
    }
    catch (const invalid_argument& e){
        cout << e.what() << endl;
    }
    cout << endl;

    //muestro el balance de ambas cuentas luego de retirar.
    savings->mostrarInfo(); 
    cout << endl;
    current.mostrarInfo();
    cout << endl;
    current2.mostrarInfo();
    cout << endl;

    //pruebo a retirar de la cuenta corriente con caja de ahorro mas de lo que tengo en total.
    cout << "Withdrawing $2000 from current account with savings..." << endl;
    try{
        current.retirar(2000.0);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    cout << endl;

    //muestro el balance de la cuenta corriente con caja de ahorro luego de retirar.
    current.mostrarInfo();
}