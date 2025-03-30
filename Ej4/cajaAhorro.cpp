#include "account.hpp"
#include "cajaAhorro.hpp"

CajaDeAhorro::CajaDeAhorro(double balanceInicial, const string& titular): 
    Account(balanceInicial, titular)
{}

void CajaDeAhorro::retirar(double ammount){
    if (ammount<=0) throw invalid_argument("Negative withdrawal amount.");
    if (ammount>balance) throw invalid_argument("Insufficient funds. Current balance: $" + to_string(balance));
    this->balance-=ammount;
}

void CajaDeAhorro::mostrarInfo(){
    cout << "Account Holder: " << this->titularCuenta << endl;
    cout << "Account Type: Savings Bank" << endl;
    cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    this->counter++;
    if (this->counter>this->MAX_SHOWS){
        this->balance-=this->PENALTY;
        cout << "The query limit has been exceeded. A $" << this->PENALTY << " penalty will be charged" << endl;
        cout << "New Balance: $" << balance << endl;
    }
}
