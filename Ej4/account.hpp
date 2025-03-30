#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Account{
    protected:
        double balance;
        string titularCuenta;

    public:
        Account(double balanceInicial, const string& titular);
        double get_balance() const;
        void depositar(double cantidad);

        virtual void retirar(double cantidad) = 0;
        virtual void mostrarInfo() = 0;
        friend class Bank;
};

#endif // ACCOUNT_H