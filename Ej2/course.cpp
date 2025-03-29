#include "course.hpp"

#define MAX_CAPACITY 20

struct qualif{
    int grade;
    Course* course;

    qualif(int grade, Course* course): grade(grade), course(course) {}
};

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

bool Student::operator<(const Student& other) const {
    return this->name < other.get_student_name();
}

Course::Course(string name):
    students(), name(name)
{}

//Hago un shallow copy ya que me interesa duplicar el curso pero que apunte a los mismos objetos de estudiantes.
//Como los estudiantes estan almacenados en un vector de shared_ptr, se copia el vector por lo que apunta a
//los mismo lugares de memoria, no se duplican los estudiantes.
Course::Course(shared_ptr<Course> c):
    students(c->students), name(c->name + "_copy")
{}

string Course::get_course_name() const {
    return this->name;
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
            i++;
            return;
        }
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

ostream& operator<<(ostream& os, const shared_ptr<Student> e){
    os  << "Name: " << e->get_student_name() << ", "
        << "ID: " << e->get_id() << ", "
        << "average: " << e->get_avg();
    return os;
}

shared_ptr<Student> create_student(vector<shared_ptr<Student>> &students){
    int ID;
    cout << "ID: ";
    cin >> ID;
    if (cin.fail()){
        cin.clear();
        cin.ignore(9999,'\n');
        throw invalid_argument("Invalid input.");
    }
    cout << students.size() << endl;
    for (auto& s : students)
        if (s->get_id()==ID) return s;
    string name;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    shared_ptr<Student> student=make_shared<Student>(name, ID);
    students.push_back(student);
    return student;
}

void create_course_case(vector<Course> &courses){
    string name;
    cout << "Course name: ";
    cin.ignore();
    getline(cin, name);
    for (Course c : courses)
        if (c.get_course_name()==name) throw invalid_argument("Course already exists.");
    courses.push_back(Course(name));
}

void remove_course_case(vector<Course> &courses){
    show_courses_case(courses);
    string name;
    cout << "Select a course: ";
    cin.ignore();
    getline(cin, name);
    for (int i=0; i<(int)courses.size(); i++)
        if (courses[i].get_course_name()==name){
            courses.erase(courses.begin()+i);
            return;
        }
    throw runtime_error("Course doesnt exists."); 
}

void show_courses_case(vector<Course> &courses){
    if (!courses.size()) throw runtime_error("No courses available.");
    cout << "Courses list:" << endl;
    for (int i=0; i<(int)courses.size(); i++)
        cout << "- " << courses[i].get_course_name() << endl;
}

void copy_course_case(vector<Course> &courses){
    show_courses_case(courses);
    string name;
    cout << "Select a course: ";
    cin.ignore();
    getline(cin, name);
    for (Course& c : courses)
        if (c.get_course_name()==name){
            courses.push_back(Course(make_shared<Course>(c)));
            return;
        }
    throw runtime_error("Course doesnt exists.");
}

void add_student_case(vector<Course> &courses, vector<shared_ptr<Student>> &students){
    show_courses_case(courses);
    string course;
    cout << "Select a course: ";
    cin.ignore();
    getline(cin, course);
    for (Course& c : courses)
        if (c.get_course_name()==course){
            shared_ptr<Student> s=create_student(students);
            c.add_student(s);
            return;
        }
    throw runtime_error("Course doesnt exists.");
}

void remove_student_case(vector<Course> &courses){
    show_courses_case(courses);
    string course;
    cout << "Select a course: ";
    cin.ignore();
    getline(cin, course);
    for (Course c : courses)
        if (c.get_course_name()==course){
            int ID;
            cout << "ID: ";
            cin >> ID;
            if (cin.fail()){
                cin.clear();
                cin.ignore(9999,'\n');
                throw invalid_argument("Invalid input.");
            }
            c.take_student(ID);
            return;
        }
    throw runtime_error("Course doesnt exists.");    
}

void find_student_case(vector<Course> &courses){
    show_courses_case(courses);
    string course;
    cout << "Select a course: ";
    cin.ignore();
    getline(cin, course);
    for (Course c : courses)
        if (c.get_course_name()==course){
            int ID;
            cout << "ID: ";
            cin >> ID;
            if (cin.fail()){
                cin.clear();
                cin.ignore(9999,'\n');
                throw invalid_argument("Invalid input.");
            }
            if (c.exists(ID)) cout << "Student " << ID << " is part of this course." << endl;
            else cout << "Student " << ID << " is not part of this course." << endl;
            return;
        }
    throw runtime_error("Course doesnt exists.");
}

void capacity_case(vector<Course> &courses){
    show_courses_case(courses);
    string course;
    cout << "Select a course: ";
    cin.ignore();
    getline(cin, course);
    for (Course c : courses)
        if (c.get_course_name()==course){
            if (c.is_full()) cout << "Course is full." << endl;
            else cout << "There are " << c.place_remaining() << " places remaining" << endl;
            return;
        }
    throw runtime_error("Course doesnt exists.");
}

void get_students_list_case(vector<Course> &courses){
    show_courses_case(courses);
    string course;
    cout << "Select a course: ";
    cin.ignore();
    getline(cin, course);
    for (Course& c : courses)
        if (c.get_course_name()==course){
            c.students_list();
            return;
        }
    throw runtime_error("Course doesnt exists.");
}

void course_console(){
    cout << "========== Ej 2: Course ==========" << endl;
    vector<Course> courses;
    vector<shared_ptr<Student>> students;
    int selected;
    while (true){
        try{
            cout << endl
                << "1. Create a new course" << endl
                << "2. Delete a course" << endl
                << "3. Courses list" << endl
                << "4. Copy a course" << endl
                << "5. Add a student to a course" << endl
                << "6. Remove a student from a course" << endl
                << "7. Find a student in a course" << endl
                << "8. Check course capacity" << endl
                << "9. Get students list" << endl                
                << "10. Exit" << endl;
            cout << endl << "> ";
            cin >> selected;
            if (cin.fail()){
                cin.clear();
                cin.ignore(9999,'\n');
                throw invalid_argument("Invalid option.");
            }  
            switch (selected){
            case 1: create_course_case(courses); break;
            case 2: remove_course_case(courses); break;
            case 3: show_courses_case(courses); break;
            case 4: copy_course_case(courses); break;
            case 5: add_student_case(courses, students); break;
            case 6: remove_student_case(courses); break;
            case 7: find_student_case(courses); break;
            case 8: capacity_case(courses); break;
            case 9: get_students_list_case(courses); break;
            case 10: return;
            default: throw invalid_argument("Invalid option.");
            }
        }
        catch(exception &e){
            cout << e.what() << endl;
        }
    }
}