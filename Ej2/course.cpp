#include "course.hpp"

#define MAX_CAPACITY 20

struct qualif{
    int grade;
    Course* course;

    qualif(int grade, Course* course): grade(grade), course(course) {}
};

Student::Student(string name, int ID):
    name(name), ID(ID), courses()
{}

string Student::get_name() const {
    return name;
}

int Student::get_id() const {
    return ID;
}

float Student::get_avg() const {
    int sum=0;
    for (qualif course : this->courses) sum+=course.grade;
    return sum/(float)courses.size();
}

void Student::add_course(int grade, Course* course){
    courses.push_back(qualif(grade, course));
}

bool Student::operator<(const Student& other) const {
    return this->name < other.get_name();
}

Course::Course(string name):
    students(), name(name)
{}

void Course::add_student(Student s){
    if (is_full()) throw invalid_argument("Course is full.");
    if (this->exists(s.get_id())) throw invalid_argument("ID taken.");
    
    int grade;
    cout << s.get_name() << "'s grade: ";
    cin >> grade;

    s.add_course(grade, this);
    this->students.push_back(s); 
}

void Course::take_student(int ID){
    for (int i=0; i<(int)students.size(); i++)
        if (this->students[i].get_id()==ID){
            this->students.erase(this->students.begin()+i);
            return;
        }
    throw runtime_error("Student doesnt exists.");       
}

bool Course::exists(int ID){
    for (Student s : this->students)
        if (s.get_id()==ID) return true;
    return false;
}

bool Course::is_full(){
    return this->students.size()==MAX_CAPACITY;
}

int Course::place_remaining() const {
    return MAX_CAPACITY - this->students.size();
}

void Course::students_list() const {
    vector<Student> vec=this->students;
    if (!vec.size()) {cout << "Course is empty."; return;}
    sort(vec.begin(), vec.end());
    cout << "List of students in " << this->name << " (" << vec.size() << " people)" << endl;
    for (Student e : vec)
        cout << e << endl;
}

ostream& operator<<(ostream& os, const Student& e){
    os  << "Name: " << e.get_name() << ", "
        << "ID: " << e.get_id() << ", "
        << "average: " << e.get_avg();
    return os;
}

Student create_student(){
    string name;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    int ID;
    cout << "ID: ";
    cin >> ID;
    return Student(name, ID);
}

void remove_case(Course &course){
    int ID;
    cout << "ID: ";
    cin >> ID;
    course.take_student(ID);
}

void find_case(Course &course){
    int ID;
    cout << "ID: ";
    cin >> ID;
    if (course.exists(ID)) cout << "Student " << ID << " is part of this course." << endl;
    else cout << "Student " << ID << " is not part of this course." << endl;
}

void capacity_case(Course &course){
    if (course.is_full()) cout << "Course is full." << endl;
    else cout << "There are " << course.place_remaining() << " places remaining" << endl;
}

void course_console(){
    Course course("Paradigmas");
    int selected;
    while (true){
        try{
            cout << endl << "========== Ej 2: Course ==========" << endl;
            cout << "1. Add student\n2. Remove student\n3. Find student\n4. Check capacity\n5. Get students\n6. Exit" << endl;
            cin >> selected;
            if (cin.fail()){
                cin.clear();
                cin.ignore(9999,'\n');
                throw invalid_argument("Invalid option.");
            }  

            switch (selected){
            case 1: course.add_student(create_student()); break;
            case 2: remove_case(course); break;
            case 3: find_case(course); break;
            case 4: capacity_case(course); break;
            case 5: course.students_list(); break;
            case 6: return;
            default: throw invalid_argument("Invalid option.");
            }
        }
        catch(exception &e){
            cout << e.what() << endl;
        }
    }
}