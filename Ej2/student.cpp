#include "funcs.hpp"
#include "student.hpp"
#include "course.hpp"

Student::Student(string name, int ID):
    name(name), ID(ID)
{}

string Student::get_student_name() const {
    return name;
}

int Student::get_id() const {
    return ID;
}

float Student::get_avg() const {
    float sum=0;
    for (qualif course : this->courses) sum+=course.grade;
    return sum/(float)courses.size();
}

void Student::add_course(int grade, Course* course){
    courses.push_back(qualif(grade, course));
}

bool operator<(const shared_ptr<Student>& a, const shared_ptr<Student>& b) {
    return a->get_student_name() < b->get_student_name();
}

ostream& operator<<(ostream& os, const shared_ptr<Student> e){
  os  << "Name: " << e->get_student_name() << ", "
      << "ID: " << e->get_id() << ", "
      << "average: " << e->get_avg();
  return os;
}