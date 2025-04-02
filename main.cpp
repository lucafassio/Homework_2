#include <iostream>
#include "Ej1/timer.hpp"
#include "Ej1/funcs.hpp"

#include "Ej2/student.hpp"
#include "Ej2/course.hpp"
#include "Ej2/funcs.hpp"

#include "Ej3/number.hpp"
#include "Ej3/entero.hpp"
#include "Ej3/real.hpp"
#include "Ej3/complejo.hpp"
#include "Ej3/tests.hpp"

#include "Ej4/test.hpp"

using namespace std;

int main(){
   int option;
   while (true){
      try{ 
         cout << endl << "========== Homework 2 - Luca Fassio ==========" << endl;
         cout << endl << "Choose an option:" << endl
            << "1. Timer" << endl
            << "2. Courses" << endl
            << "3. Numbers" << endl
            << "4. Bank account" << endl 
            << "5. Exit" << endl;
         cout << endl << "> ";
         cin >> option;
         switch (option){
            case 1: timer_console(); break;
            case 2: course_console(); break;
            case 3: number_console(); break;
            case 4: bank_tests(); break;
            case 5: return 0;
            default: throw invalid_argument("Invalid option."); break;
         }
      }
      catch (invalid_argument &e){
         cout << e.what() << endl;
      }
      catch (...){
         cout << "Unexpected error" << endl;
      }
   }
   return 0;
}