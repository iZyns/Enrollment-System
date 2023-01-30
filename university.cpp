#include "university.h"
#include "student.h"

#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

University::University() = default;

University::University(string uniName) { this->uniName = uniName; }

University::~University() {
  for (auto student : studentContainer) {
    delete student.second;
    student.second = nullptr;
  }
  for (auto course : courseContainer) {
    delete course.second;
    course.second = nullptr;
  }
}

// creates Course Objects for every course on the list and stores the pointers
// in a map
bool University::readCourseList(const string &filename) {
  ifstream inFile;
  inFile.open(filename);

  if (!inFile.is_open()) {
    return false;
  }

  string id;
  string name;

  while (inFile >> id) {
    getline(inFile, name);
    name.erase(0, 1);
    if (courseContainer.count(id) != 1) {
      Course *obj = new Course{id, name};
      courseContainer.insert(make_pair(id, obj));
    }
  }
  return true;
}

// creates Student Objects for every student on the list and stores the pointers
// in a map
bool University::readStudentList(const string &filename) {
  ifstream inFile;
  inFile.open(filename);

  if (!inFile.is_open()) {
    return false;
  }

  int id;
  string name;

  while (inFile >> id) {
    getline(inFile, name);
    name.erase(0, 1);
    if (studentContainer.count(id) != 1) {
      Student *obj = new Student{id, name};
      studentContainer.insert(make_pair(id, obj));
    }
  }
  return true;
}

bool University::readEnrollmentInfo(const string &filename) {
  ifstream inFile;
  inFile.open(filename);

  if (!inFile.is_open()) {
    return false;
  }

  int stdId;
  string courseId;

  while (inFile >> stdId) {
    inFile >> courseId;
    addCourse(stdId, courseId);
  }

  return true;
}

bool University::addCourse(int stdId, const string &courseId) {

  if (studentContainer.count(stdId) == 0 ||
      courseContainer.count(courseId) == 0) {
    return false;
  }

  Student *stdPtr = studentContainer.at(stdId);
  Course *coursePtr = courseContainer.at(courseId);
  stdPtr->addCourse(courseId, coursePtr);
  coursePtr->addStudent(stdId, stdPtr);
  return true;
}

bool University::dropCourse(int stdId, const string &courseId) {

  if (studentContainer.count(stdId) == 0 ||
      courseContainer.count(courseId) == 0) {
    return false;
  }

  Student *stdPtr = studentContainer.at(stdId);
  Course *coursePtr = courseContainer.at(courseId);
  stdPtr->dropCourse(courseId);
  coursePtr->removeStudent(stdId);

  return true;
}

string University::getUniversityName() const { return uniName; }

bool University::isInCourse(int stdId, string courseId) {
  return studentContainer[stdId]->isInCourse(courseId);
}

string University::getCourseTitle(const string &courseNumber) {
  return courseContainer[courseNumber]->getCourseTitle();
}

string University::getEnrolledCourses(int stdId) const {
  return studentContainer.at(stdId)->getEnrolledCourses();
}

string University::getClassListByLastName(const string &courseNumber) const {
  return courseContainer.at(courseNumber)->getClassListByLastName(courseNumber);
}

string University::getClassListByID(const string &courseNumber) const {
  return courseContainer.at(courseNumber)->getClassListByID(courseNumber);
}