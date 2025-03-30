#include "account.hpp"

Account::Account(double balanceInicial, const string& titular): 
    balance(balanceInicial), titularCuenta(titular) 
{}

double Account::get_balance() const {
    return balance;
}

void Account::depositar(double cantidad){
    if (cantidad > 0) balance += cantidad;
    else throw invalid_argument("Negative deposit amount.");
}