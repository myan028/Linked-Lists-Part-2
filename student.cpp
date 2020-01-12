#include <iostream>
#include <cstring>
#include <vector>

#include "student.h"

using namespace std;

Student::Student(char* newFirstName, char* newLastName, int newId, float newGpa){
  firstName = newFirstName;
  lastName = newLastName;
  id = newId;
  gpa = newGpa;
}

char* Student::getFirstName(){
	return firstName;
}

char* Student::getLastName(){
	return lastName;
}

int Student::getId(){
	return id;
}

float Student::getGpa(){
	return gpa;
}

Student::~Student(){ //destructor
  delete[] firstName;
  delete[] lastName;
}
