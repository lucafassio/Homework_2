#include "funcs.hpp"
#include "student.hpp"
#include "course.hpp"

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
          clean_students(courses[i], name);
          courses.erase(courses.begin()+i);
          return;
      }
  throw runtime_error("Course doesnt exists."); 
}

void clean_students(Course& c, string name){
  for (auto& s : c.get_students()){
      int i=0;
      for (auto& qualif : s->courses){
          if (qualif.course->get_course_name()==name){
              s->courses.erase(s->courses.begin()+i);
              break;
          }
          i++;
      }
  }
}

void show_courses_case(vector<Course> &courses){
  if (!courses.size()) throw runtime_error("No courses available.");
  sort(courses.begin(), courses.end());
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
          int i=0;
          for (Course c_copy : courses){
              if (c_copy.get_course_name()==name+"_copy"){
                  cout << "This copy already exists. Do you want to overwrite it? (Y/n)." << endl;
                  char answer;
                  cin >> answer;
                  if (answer=='Y' || answer=='y'){
                      courses.erase(courses.begin()+i);
                      courses.push_back(Course(make_shared<Course>(c)));
                      return;
                  }
                  else if (answer=='N' || answer=='n') return;
                  else throw invalid_argument("Invalid option.");
              };
              i++;
          }
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
  for (Course& c : courses)
      if (c.get_course_name()==course){
          int ID;
          cout << "ID: ";
          cin >> ID;
          if (cin.fail()){
              cin.clear();
              cin.ignore(9999,'\n');
              throw invalid_argument("Invalid input.");
          }
          shared_ptr<Student> target_student = nullptr;
          for (auto& s : c.get_students()) {
              if (s->get_id() == ID) {
                  target_student = s;
                  break;
              }
          }

          if (!target_student) throw runtime_error("Student not found.");

          c.take_student(ID);

          int i = 0;
          for (auto& q : target_student->courses) {
              if (q.course->get_course_name() == c.get_course_name()) {
                  target_student->courses.erase(target_student->courses.begin() + i);
                  break;
              }
              i++;
          }
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