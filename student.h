#include <iostream>
#include <cstring>
#include <vector>

#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student{
 public:
  Student(char* newFirstName, char* newLastName, int newId, float newGpa);
  char* getFirstName();
  char* getLastName();
  int getId();
  float getGpa();
  ~Student();
 private:
  char* firstName = new char[100];
  char* lastName = new char[100];
  int id;
  float gpa;
  


};

#endif