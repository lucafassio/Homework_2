#include "funcs.hpp"
#include "student.hpp"
#include "course.hpp"

#define MAX_CAPACITY 20

Course::Course(string name):
    name(name), students()
{}

/*
 * Hago un shallow copy ya que me interesa duplicar el curso pero que apunte a los mismos objetos de estudiantes.
 * Como los estudiantes estan almacenados en un vector de shared_ptr, se copia el vector por lo que apunta a
 * los mismo lugares de memoria, no se duplican los estudiantes.
 */
Course::Course(shared_ptr<Course> c):
  name(c->name + "_copy"), students(c->students)
{}

string Course::get_course_name() const {
    return this->name;
}

vector<shared_ptr<Student>> Course::get_students() const {
    return this->students;
}

void Course::add_student(shared_ptr<Student> s){
    //chequeo si el curso esta lleno o si ya esta anotado.
    if (is_full()) throw invalid_argument("Course is full.");
    if (this->exists(s->get_id())) throw invalid_argument("Student already exists in this course.");
    
    //pido la nota del estudiante
    int grade;
    cout << s->get_student_name() << "'s grade: ";
    cin >> grade;

    //agrego el curso a la lista de notas del estudiante.
    s->add_course(grade, this);

    //agrego el estudiante al curso.
    this->students.push_back(s); 
}

void Course::take_student(int ID){
    int i=0;

    //busco el estudiante en el curso por legajo.
    for (auto& s : this->students){
        if (s->get_id()==ID){
            this->students.erase(this->students.begin()+i);
            return;
        }
        i++;
    }

    //si no lo encuentro, lanzo exception.
    throw runtime_error("Student doesnt exists.");       
}

bool Course::exists(int ID){
    for (auto& s : this->students)
        if (s->get_id()==ID) return true;
    return false;
}

bool Course::is_full(){
    return this->students.size()==MAX_CAPACITY;
}

int Course::place_remaining() const {
    return MAX_CAPACITY - this->students.size();
}

void Course::students_list() const {
    vector<shared_ptr<Student>> vec=students;

    //chequeo si el curso tiene estudiantes.
    if (!vec.size()) {cout << "Course is empty." << endl; return;}

    //ordeno el vector de estudiantes por nombre.
    sort(vec.begin(), vec.end(), [](const shared_ptr<Student>& a, const shared_ptr<Student>& b) {return a->get_student_name() < b->get_student_name();});
    cout << "List of students in " << this->name << " (" << vec.size() << " people)" << endl;
    for (auto& e : vec)
        cout << e << endl;
}

bool Course::operator<(const Course& other) const {
    if (name < other.get_course_name()) return true;
    else return false;
}