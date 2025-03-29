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
        
    public:
        vector<qualif> courses;
        Student(string name, int ID);
        string get_student_name() const;
        int get_id() const;
        float get_avg() const;
        void add_course(int nota, Course* course);
        bool operator<(const Student &other) const;
};

class Course{
    private:
        string name;
        vector<shared_ptr<Student>> students;

    public:
        Course(string name);
        string get_course_name() const;
        void add_student(Student& s);
        void take_student(int ID);
        bool exists(int ID);
        bool is_full();
        int place_remaining() const;
        void students_list() const;
};

ostream& operator<<(ostream& os, const Student& e);

Student create_student(vector<Student> &students);

void create_course_case(vector<Course> &courses);

void remove_course_case(vector<Course> &courses);

void show_courses_case(vector<Course> &courses);

void add_student_case(vector<Course> &courses, vector<Student> &students);

void remove_student_case(vector<Course> &courses);

void find_student_case(vector<Course> &courses);

void capacity_case(vector<Course> &courses);

void get_students_list_case(vector<Course> &courses);

void course_console();

#endif //COURSE_H