#ifndef COURSE_H
#define COURSE_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// this class will be responsible in handling and storing courses information,
// including adding and removing student from the course.

//  forward declaration
class Student;

class Course {
  friend class Student;
  friend class University;
  friend class EnrollmentSystem;
  friend ostream &operator<<(ostream &out, const Course &course);

public:
  // constructor
  explicit Course(string courseId, string courseName);

  virtual ~Course();

  // add student to a course
  bool addStudent(int stdId, Student *stdPtr);
  // remove student from a course
  bool removeStudent(int stdId);

  bool isEnrolled(int stdId);

  string getCourseTitle();

  string getClassListByLastName(const string &courseNumber) const;

  static bool cmpLastname(Student *std1, Student *std2);

  static bool cmpID(Student *std1, Student *std2);

  string getClassListByID(string courseId) const;

private:
  // holds the course id
  string courseId;
  // holds the course name
  string courseName;
  // stores student pointers for each course
  map<int, Student *> stdList;
};

#endif