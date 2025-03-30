#include "account.hpp"
#include "cuentaCorriente.hpp"

CuentaCorriente::CuentaCorriente(double balanceInicial, string titular): 
    Account(balanceInicial, titular), caja_ahorro(nullptr)
{}

CuentaCorriente::CuentaCorriente(shared_ptr<CajaDeAhorro> caja): 
    Account(0, caja->titularCuenta), caja_ahorro(move(caja)) 
{}

void CuentaCorriente::retirar(double ammount){
    if (ammount<=0) throw invalid_argument("Negative withdrawal amount.");
    if (ammount<=this->balance) this->balance-=ammount;
    else {
        if (this->caja_ahorro){
            try{
                this->caja_ahorro->retirar(ammount-this->balance);
                this->balance=0;
            }
            catch(invalid_argument& e){
                cout 
                    << "Insuficient founds." << endl
                    << "Current account balance: $" << this->balance << endl
                    << "Savings account balance: $" << this->caja_ahorro->balance << endl
                    << "Total balance: $" << this->balance + this->caja_ahorro->balance << endl
                    << "Withdrawal amount: $" << ammount << endl;
            }
        }
        else throw invalid_argument("Insufficient funds. Current balance: $" + to_string(this->balance));
    }
    
}

void CuentaCorriente::mostrarInfo(){
    cout << "Account Holder: " << this->titularCuenta << endl;
    cout << "Account Type: Current Account" << endl;
    cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
}
