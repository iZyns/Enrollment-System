#ifndef STUDENT_H
#define STUDENT_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// This class will be responsible in handling and storing student information,
// including adding and dropping student from a course

// forward declaration
class Course;

class Student {
  friend class Course;
  friend class University;
  friend class EnrollmentSystem;
  friend ostream &operator<<(ostream &out, const Student &student);

public:
  // constructor
  explicit Student();

  virtual ~Student();

  Student(int stdId, string stdName);

  // add course to a student
  bool addCourse(string courseId, Course *coursePtr);

  // drop course from a student
  bool dropCourse(string courseId);

  // check if a student is in the course
  bool isInCourse(string courseId);

  string getEnrolledCourses();

private:
  // hold the studen't id
  int stdId;
  // hold the student's name
  string stdName;

  string firstName;

  string lastName;
  // stores course pointer for each course
  // course id, course ptr
  map<string, Course *> enrolledCourse;
};

#endif