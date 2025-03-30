#ifndef CUENTA_CORRIENTE_H
#define CUENTA_CORRIENTE_H

#include "account.hpp"
#include "cajaAhorro.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory>

using namespace std;

class CuentaCorriente: public Account{
    private:
        shared_ptr<CajaDeAhorro> caja_ahorro;
        
    public:
        CuentaCorriente(double balanceInicial, string titular);
        CuentaCorriente(shared_ptr<CajaDeAhorro> caja);

        void retirar(double cantidad) override;
        void mostrarInfo()override;
};

#endif // CUENTA_CORRIENTE_H