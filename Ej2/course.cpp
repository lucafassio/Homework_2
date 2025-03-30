#include "funcs.hpp"
#include "student.hpp"
#include "course.hpp"

#define MAX_CAPACITY 20

Course::Course(string name):
    students(), name(name)
{}

/*
 * Hago un shallow copy ya que me interesa duplicar el curso pero que apunte a los mismos objetos de estudiantes.
 * Como los estudiantes estan almacenados en un vector de shared_ptr, se copia el vector por lo que apunta a
 * los mismo lugares de memoria, no se duplican los estudiantes.
 */
Course::Course(shared_ptr<Course> c):
    students(c->students), name(c->name + "_copy")
{}

string Course::get_course_name() const {
    return this->name;
}

vector<shared_ptr<Student>> Course::get_students() const {
    return this->students;
}

void Course::add_student(shared_ptr<Student> s){
    if (is_full()) throw invalid_argument("Course is full.");
    if (this->exists(s->get_id())) throw invalid_argument("Student already exists in this course.");
    
    int grade;
    cout << s->get_student_name() << "'s grade: ";
    cin >> grade;

    s->add_course(grade, this);
    this->students.push_back(s); 
}

void Course::take_student(int ID){
    int i=0;
    for (auto& s : this->students){
        if (s->get_id()==ID){
            this->students.erase(this->students.begin()+i);
            return;
        }
        i++;
    }        
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
    vector<shared_ptr<Student>> vec=this->students;
    if (!vec.size()) {cout << "Course is empty." << endl; return;}
    sort(vec.begin(), vec.end());
    cout << "List of students in " << this->name << " (" << vec.size() << " people)" << endl;
    for (auto& e : vec)
        cout << e << endl;
}

bool Course::operator<(const Course& other) const {
    return this->name < other.get_course_name();
}