#include "Bank.hpp"

Bank::Bank() {
    loadAccounts();
}

void Bank::loadAccounts() {
    ifstream file(csvFile);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        AccountRecord record;
        string temp;

        getline(ss, record.nombreTitular, ',');
        getline(ss, record.email, ',');
        getline(ss, record.password, ',');
        getline(ss, temp, ',');
        record.balanceCajaAhorro = stod(temp);
        getline(ss, temp, ',');
        record.cuentaCorrienteExists = stoi(temp);
        getline(ss, temp, ',');
        record.cuentaCorrienteBalance = stod(temp);

        accounts.push_back(record);
    }
    file.close();
}

void Bank::saveAccounts() const {
    ofstream file(csvFile, ios::trunc);
    for (const auto& record : accounts) {
        file << record.nombreTitular << ","
             << record.email << ","
             << record.password << ","
             << record.balanceCajaAhorro << ","
             << record.cuentaCorrienteExists << ","
             << record.cuentaCorrienteBalance << "\n";
    }
    file.close();
}

void Bank::signUp() {
    AccountRecord newAccount;
    cout << "Enter your name: ";
    cin >> newAccount.nombreTitular;
    cout << "Enter your email: ";
    cin >> newAccount.email;
    cout << "Enter your password: ";
    cin >> newAccount.password;
    cout << "Enter initial balance for Caja de Ahorro: ";
    cin >> newAccount.balanceCajaAhorro;

    newAccount.cuentaCorrienteExists = false;
    newAccount.cuentaCorrienteBalance = 0.0;

    accounts.push_back(newAccount);
    saveAccounts();
    cout << "Account created successfully!\n";
}

void Bank::logIn() {
    string email, password;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your password: ";
    cin >> password;

    for (auto& record : accounts) {
        if (record.email == email && record.password == password) {
            cout << "Login successful!\n";
            auto caja = make_shared<CajaDeAhorro>(record.balanceCajaAhorro, record.nombreTitular);
            shared_ptr<CuentaCorriente> cuentaCorriente = nullptr;

            if (record.cuentaCorrienteExists) {
                cuentaCorriente = make_shared<CuentaCorriente>(record.cuentaCorrienteBalance, record.nombreTitular);
            }

            displayMenu(caja, cuentaCorriente);

            record.balanceCajaAhorro = caja->balance;
            if (cuentaCorriente) {
                record.cuentaCorrienteBalance = cuentaCorriente->balance;
            }
            saveAccounts();
            return;
        }
    }
    cout << "Invalid email or password.\n";
}

void Bank::displayMenu(shared_ptr<CajaDeAhorro> caja, shared_ptr<CuentaCorriente> cuentaCorriente) {
    int choice;
    do {
        cout << "\n1. View Caja de Ahorro Info\n";
        cout << "2. Withdraw from Caja de Ahorro\n";
        cout << "3. Create Cuenta Corriente\n";
        if (cuentaCorriente) {
            cout << "4. View Cuenta Corriente Info\n";
            cout << "5. Withdraw from Cuenta Corriente\n";
        }
        cout << "0. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                caja->mostrarInfo();
                break;
            case 2: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                try {
                    caja->retirar(amount);
                } catch (const exception& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3:
                if (!cuentaCorriente) {
                    cuentaCorriente = make_shared<CuentaCorriente>(caja);
                    cout << "Cuenta Corriente created successfully!\n";
                } else {
                    cout << "Cuenta Corriente already exists.\n";
                }
                break;
            case 4:
                if (cuentaCorriente) cuentaCorriente->mostrarInfo();
                break;
            case 5:
                if (cuentaCorriente) {
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    try {
                        cuentaCorriente->retirar(amount);
                    } catch (const exception& e) {
                        cout << e.what() << endl;
                    }
                }
                break;
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}
