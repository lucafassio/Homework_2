#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#define MAX_CAPACITY 20;

class estudiante{
    private:
        string name;
        int legajo;
        float avg;
        
    public:
        estudiante(string name, int legajo, float avg);

        string get_name() const {
            return name;
        }

        int get_legajo() const {
            return legajo;
        }

        float get_avg() const {
            return avg;
        }

};

class Curso{
    private:
        string name;
        vector<estudiante> students;

    public:
        Curso(string name);

        void add_student(estudiante s){
            try{
                if (is_full()) throw invalid_argument("ERROR - El curso esta lleno.");
                students.push_back(s);
                return;
            }
            catch(invalid_argument &e){
                cout << e.what() << endl;
            }          
        }

        void take_student(int legajo){
            try{
                for (int i=0; i<(int)students.size(); i++)
                    if (students[i].get_legajo()==legajo) {
                        students.erase(students.begin()+i);
                        return;
                    }
                throw runtime_error("ERROR - No se ha encontrado el estudiante");
            } 
            catch(runtime_error &e){
                cout << e.what() << endl;
                return;
            }           
        }

        bool exists(int legajo){
            for (int i=0; i<(int)students.size(); i++)
                if (students[i].get_legajo()==legajo) return true;
            return false;
        }

        bool is_full(){
            return students.size()==MAX_CAPACITY;
        }

        void students_list() const {
            cout << "Lista de alumnos de " << name << endl;
            for (int i=0; i<(int)students.size(); i++)
                cout << "   " << i+1 << ". " << students[i].get_name() << endl;
        }
        
};
