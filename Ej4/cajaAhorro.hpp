#ifndef CAJA_AHORRO_H
#define CAJA_AHORRO_H

#include "account.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class CuentaCorriente;

class CajaDeAhorro: public Account{
    private:
        int counter=0;
        static const int MAX_SHOWS=2;
        static const int PENALTY=20;
        
    public:
        CajaDeAhorro(double balanceInicial, string titular);

        void retirar(double cantidad) override;
        void mostrarInfo() override;
        friend class CuentaCorriente;
};

#endif // CAJA_AHORRO_H