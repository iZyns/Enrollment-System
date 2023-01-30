#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "course.h"
#include "student.h"
#include <map>
#include <string>

using namespace std;

class University {
  friend class EnrollmentSystem;

public:
  explicit University();

  University(string uniName);

  virtual ~University();

  bool readCourseList(const string &filename);

  bool readStudentList(const string &filename);

  bool readEnrollmentInfo(const string &filename);

  string getUniversityName() const;

  bool isInCourse(int stdId, string courseId);

  string getEnrolledCourses(int stdId) const;

  string getCourseTitle(const string &courseNumber);

  string getClassListByLastName(const string &courseNumber) const;

  string getClassListByID(const string &courseName) const;

  bool addCourse(int stdId, const string &courseId);

  bool dropCourse(int stdId, const string &courseId);

private:
  string uniName;

  map<string, Course *> courseContainer;

  map<int, Student *> studentContainer;
};

#endif