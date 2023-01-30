#include "course.h"
#include "student.h"
#include <algorithm>
#include <cassert>
#include <sstream>
#include <string>

using namespace std;

ostream &operator<<(ostream &out, const Course &course) {
  out << "Course ID: " << course.courseId << endl;
  out << "Course Name: " << course.courseName << endl;
  return out;
}

Course::Course(string courseId, string courseName) {
  this->courseId = courseId;
  this->courseName = courseName;
}

Course::~Course() { stdList.clear(); }

bool Course::addStudent(int stdId, Student *stdPtr) {
  if (isEnrolled(stdId)) {
    return false;
  }
  stdList[stdId] = stdPtr;
  return true;
}

bool Course::removeStudent(int stdId) {
  if (!isEnrolled(stdId)) {
    return false;
  }
  stdList.erase(stdId);
  return true;
}

bool Course::isEnrolled(int stdId) {
  if (stdList.count(stdId) == 1) {
    return true;
  }
  return false;
}

string Course::getCourseTitle() { return courseName; }

bool Course::cmpLastname(Student *std1, Student *std2) {
  return std1->lastName < std2->lastName;
}

bool Course::cmpID(Student *std1, Student *std2) {
  return std1->stdId < std2->stdId;
}

string Course::getClassListByLastName(const string &courseNumber) const {
  vector<Student *> tmp;
  for (auto key : stdList) {
    tmp.push_back(key.second);
  }

  string classList;
  classList += '[';
  sort(tmp.begin(), tmp.end(), cmpLastname);
  for (auto student : tmp) {
    if (student->isInCourse(courseNumber)) {
      classList += student->lastName + ", " + student->firstName + " ";
      classList += "(" + to_string(student->stdId) + "), ";
    }
  }
  classList.pop_back();
  classList.pop_back();
  classList += ']';
  for (int i = 0; i < tmp.size(); i++) {
    tmp[i] = nullptr;
  }
  return classList;
}

string Course::getClassListByID(string courseId) const {
  vector<Student *> tmp;
  for (auto key : stdList) {
    tmp.push_back(key.second);
  }

  string classList;
  classList += '[';
  sort(tmp.begin(), tmp.end(), cmpID);
  for (auto student : tmp) {
    if (student->isInCourse(courseId)) {
      classList += student->lastName + ", " + student->firstName + " ";
      classList += "(" + to_string(student->stdId) + "), ";
    }
  }
  classList.pop_back();
  classList.pop_back();
  classList += ']';
  for (int i = 0; i < tmp.size(); i++) {
    tmp[i] = nullptr;
  }
  return classList;
}