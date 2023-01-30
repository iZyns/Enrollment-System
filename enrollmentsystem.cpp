#include "enrollmentsystem.h"
#include "university.h"

#include <cassert>
#include <map>
#include <vector>

using namespace std;

EnrollmentSystem::~EnrollmentSystem() {
  for (auto university : universities)
    delete university.second;
}

bool EnrollmentSystem::addUniversity(const string &name) {
  if (universities.count(name) == 1) {
    return false;
  }
  University *uniPtr = new University(name);
  universities.insert(make_pair(name, uniPtr));
  return true;
}

// Set this university as the active university for other functions
bool EnrollmentSystem::setCurrentUniversity(const string &name) {
  if (universities.count(name) == 0) {
    return false;
  }
  currentUniversity = universities[name];
  return true;
}

string EnrollmentSystem::getUniversityName() const {
  University *tmp = this->currentUniversity;
  string name = tmp->getUniversityName();
  return name;
}

// // Read the course list for current active university
// // return true if file successfully read
bool EnrollmentSystem::readCourseList(const string &filename) {
  return currentUniversity->readCourseList(filename);
}

bool EnrollmentSystem::readStudentList(const string &filename) {
  return currentUniversity->readStudentList(filename);
}

// Read the student enrollment information for current active university
// return true if file successfully read
bool EnrollmentSystem::readEnrollmentInfo(const string &filename) {
  return currentUniversity->readEnrollmentInfo(filename);
}

// Add student to the given course, return true if successful
bool EnrollmentSystem::addCourse(int studentID, const string &courseNumber) {
  return currentUniversity->addCourse(studentID, courseNumber);
}

bool EnrollmentSystem::dropCourse(int studentID, const string &courseNumber) {
  return currentUniversity->dropCourse(studentID, courseNumber);
}

bool EnrollmentSystem::isInCourse(int studentID,
                                  const string &courseNumber) const {
  return currentUniversity->isInCourse(studentID, courseNumber);
}

string EnrollmentSystem::getCourseTitle(const string &courseNumber) {
  return currentUniversity->getCourseTitle(courseNumber);
}

string EnrollmentSystem::getEnrolledCourses(int studentID) const {
  return currentUniversity->getEnrolledCourses(studentID);
}

string
EnrollmentSystem::getClassListByLastName(const string &courseNumber) const {
  return currentUniversity->getClassListByLastName(courseNumber);
}

string EnrollmentSystem::getClassListByID(const string &courseName) const {
  return currentUniversity->getClassListByID(courseName);
}