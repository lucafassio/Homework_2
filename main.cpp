#include <iostream>
#include "Ej1/timer.hpp"
#include "Ej2/funcs.hpp"
#include "Ej2/student.hpp"
#include "Ej2/course.hpp"
#include "Ej3/number.hpp"
#include "Ej3/entero.hpp"
#include "Ej3/real.hpp"
#include "Ej3/complejo.hpp"
#include "Ej3/console.hpp"
#include "Ej4/account.hpp"
#include "Ej4/Bank.hpp"

using namespace std;

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\nWelcome to the Bank System\n";
        cout << "1. Sign Up\n";
        cout << "2. Log In\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.signUp();
                break;
            case 2:
                bank.logIn();
                break;
            case 0:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}