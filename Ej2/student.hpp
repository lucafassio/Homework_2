#ifndef STUDENT_H
#define STUDENT_H

#include "course.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct qualif{
  int grade;
  Course* course;

  qualif(int grade, Course* course): grade(grade), course(course) {}
};

class Student{
    private:
        string name;
        int ID;
        
    public:
        vector<qualif> courses;
        Student(string name, int ID);
        string get_student_name() const;
        int get_id() const;
        float get_avg() const;
        void add_course(int nota, Course* course);
        bool operator<(const Student& other) const;
};

ostream& operator<<(ostream& os, const shared_ptr<Student> e);

#endif //STUDENT_H