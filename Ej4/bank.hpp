#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include "cajaAhorro.hpp"
#include "cuentaCorriente.hpp"

using namespace std;

class Bank {
private:
    string csvFile = "accounts.csv";

    struct AccountRecord {
        string nombreTitular;
        string email;
        string password;
        double balanceCajaAhorro;
        bool cuentaCorrienteExists;
        double cuentaCorrienteBalance;
    };

    vector<AccountRecord> accounts;

    void loadAccounts();
    void saveAccounts() const;

public:
    Bank();
    void signUp();
    void logIn();
    void displayMenu(shared_ptr<CajaDeAhorro> caja, shared_ptr<CuentaCorriente> cuentaCorriente = nullptr);
};

#endif // BANK_H
