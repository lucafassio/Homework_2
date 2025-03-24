#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct qualif;
class Course;

class Student{
    private:
        string name;
        int ID;
        vector<qualif> courses;
        
    public:
        Student(string name, int ID);
        string get_name() const;
        int get_id() const;
        float get_avg() const;
        void add_course(int nota, Course* course);
        bool operator<(const Student &other) const;
};

class Course{
    private:
        string name;
        vector<Student> students;

    public:
        Course(string name);
        void add_student(Student s);
        void take_student(int ID);
        bool exists(int ID);
        bool is_full();
        int place_remaining() const;
        void students_list() const;
};

ostream& operator<<(ostream& os, const Student& e);

Student create_student();

void remove_case(Course &course);

void find_case(Course &course);

void capacity_case(Course &course);

void course_console();

#endif //COURSE_H