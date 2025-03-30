#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;
class Student;

class Course{
    private:
        string name;
        vector<shared_ptr<Student>> students;

    public:
        Course(string name);
        Course(shared_ptr<Course> c);
        string get_course_name() const;
        vector<shared_ptr<Student>> get_students() const;
        void add_student(shared_ptr<Student> s);
        void take_student(int ID);
        bool exists(int ID);
        bool is_full();
        int place_remaining() const;
        void students_list() const;
        bool operator<(const Course& other) const;
};

#endif //COURSE_H