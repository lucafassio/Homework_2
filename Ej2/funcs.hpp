#ifndef COURSE_FUNCS_H
#define COURSE_FUNCS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;
class Course;
class Student;

shared_ptr<Student> create_student(vector<Student> &students);

void create_course_case(vector<Course> &courses);

void remove_course_case(vector<Course> &courses);

void clean_students(Course& c, string name);

void show_courses_case(vector<Course> &courses);

void add_student_case(vector<Course> &courses, vector<Student> &students);

void remove_student_case(vector<Course> &courses);

void find_student_case(vector<Course> &courses);

void capacity_case(vector<Course> &courses);

void get_students_list_case(vector<Course> &courses);

void course_console();

#endif //COURSE_FUNCS_H