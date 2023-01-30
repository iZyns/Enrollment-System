#include "student.h"
#include "course.h"

#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const Student &student) {
  out << "Student Name: " << student.stdName
      << ", Student ID: " << student.stdId;
  return out;
}

// default constructor
Student::Student() = default;

Student::~Student() { enrolledCourse.clear(); }

// constructor
Student::Student(int stdId, string stdName) {
  this->stdId = stdId;
  this->stdName = stdName;

  size_t spacePos = stdName.find(" ");
  this->firstName = stdName.substr(0, spacePos);
  this->lastName = stdName.substr(spacePos + 1);
}

// add course to a student
bool Student::addCourse(string courseId, Course *coursePtr) {
  if (isInCourse(courseId)) {
    return false;
  }
  enrolledCourse[courseId] = coursePtr;
  return true;
}

// drop course from a student
bool Student::dropCourse(string courseId) {
  enrolledCourse.erase(courseId);
  return true;
}

// check if a student is in the course
bool Student::isInCourse(string courseId) {
  if (enrolledCourse.count(courseId) == 1) {
    return true;
  }
  return false;
}

string Student::getEnrolledCourses() {
  string final;
  final.push_back('[');
  vector<Course *> temp;
  for (auto key : enrolledCourse) {
    temp.push_back(key.second);
  }
  sort(temp.begin(), temp.end());
  for (int i = 0; i < temp.size(); i++) {
    if (i == temp.size() - 1) {
      final += temp[i]->courseId;
    } else {
      final += temp[i]->courseId + ", ";
    }
  }
  final.push_back(']');

  return final;
}