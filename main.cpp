#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>
#include <iomanip>

#include "node.h"
#include "student.h"

using namespace std;

/*
Code by Michael Yan, 1/11/2020

This code runs a linked lists-based student list program, allowing the user to add, print, and delete students,
as well as print the student list out in ascending order of student id.

The node.h and node.o files were supplied by Tejash Panda.
*/

//void add(int newValue);
//void print(Node* next);

Node* head = NULL; //head begins as null since list starts as empty

void add(Node* previous, char* firstName, char* lastName, int id, float gpa){ //add function
	Student* newStudent = new Student(firstName, lastName, id, gpa);
	//Node* previous = new Node();	
	//previous->setStudent(newStudent); add to next recursion to make it the previous node
	if(head == NULL){ //add student to head if list is empty
		head = new Node();
		head->setStudent(newStudent);
	}
	else if(newStudent->getId() < head->getStudent()->getId()){ //sorting: add new student to front of list
		Node* temp = new Node(); //temporary node to store old head
		//temp = head->getStudent();
		temp->setStudent(head->getStudent());
		temp->setNext(head->getNext());
		head->setStudent(newStudent);
		head->setNext(temp);
	}
	else if(previous->getNext() == NULL){ //ELSE if at the end of a list, if new student not less than
		Node* newNode = new Node();
		newNode->setStudent(newStudent);
		previous->setNext(newNode); //the previous node points to new node
	}
	else if(newStudent->getId() < previous->getNext()->getStudent()->getId()){ //sorting: same as first sorting except adds before previous instead of before head
		Node* newNode = new Node();
		newNode->setStudent(newStudent);
		
		newNode->setNext(previous->getNext());
		previous->setNext(newNode);
		
		//newNode->setNext(head->getNext());
		//temp = head->getNext();
		//temp->setStudent(newStudent);
	}
	else{
		//head = head->getNext();
		//previous = previous->getNext();
		//Node* previous = new Node();
		//previous->setStudent(newStudent); //
		add(previous->getNext(), firstName, lastName, id, gpa); //call function recursively until one of the above conditions is met
	}
	//add(head);
}



void remove(Node* next, Node* prev, int inputId){ //delete renamed remove
	//char inputId = input;
	char yesNo; //confirmation input
	if(next == head && next->getStudent()->getId() == inputId){ //if student to be deleted is head
		//print(next);
		cout << "\nYou have selected the following student: ";
		cout << "Name: " << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << ", ID: " << next->getStudent()->getId() << ", GPA: "  << fixed << setprecision(2) << next->getStudent()->getGpa() << "\n" << endl;
		cout << "Would you like to delete the selected student? Please confirm ('y' or 'n'): ";
		cin >> yesNo;
		cin.clear();
		cin.ignore(10000, '\n');
		if(yesNo == 'y'){
			cout << "\nThe selected student has been deleted.\n\n";
			if(next->getNext() == NULL){ //condition for only 1 student in database
				next->~Node(); //delete node using destructor
				head = NULL; //no students left so head is null
			}
			else{
				head = next->getNext(); //head is now the next node
				next->~Node();
				remove(head, NULL, inputId); //retry function (more students with same id)
			}
		}
		else if(yesNo == 'n'){
			cout << "\nThe selected student will not be deleted.\n\n";
			if(next->getNext() != NULL){ //if there are more in the list with the same id, continue iterating through with the same user input
				remove(next->getNext(), next, inputId); //continue to next node
			}
		}
		else{ //unrecognized input
			cout << "\nPlease confirm with 'y' or 'n'.\n\n";
		}
	}
	
	else if(next->getStudent()->getId() == inputId){ //for nodes other than head
		//print(next);
		cout << "\nYou have selected the following student: ";
		cout << "Name: " << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << ", ID: " << next->getStudent()->getId() << ", GPA: "  << fixed << setprecision(2) << next->getStudent()->getGpa() << "\n" << endl;
		cout << "Would you like to delete the selected student? Please confirm ('y' or 'n'): ";
		cin >> yesNo;
		cin.clear();
		cin.ignore(10000, '\n');
		if(yesNo == 'y'){
			cout << "\nThe selected student has been deleted.\n\n";
			prev->setNext(next->getNext()); //previous node next is next node next
			next->~Node();
		}
		else if(yesNo == 'n'){
			cout << "\nThe selected student will not be deleted.\n\n";
			if(next->getNext() != NULL){ //if there are more in the list with the same id, continue iterating through with the same user input
				remove(next->getNext(), next, inputId); //continue to next node
			}
		}
		else{
			cout << "\nPlease confirm with 'y' or 'n'.\n\n";
		}
	}
	
	
	if(next->getNext() != NULL){ //whenever head is not to be deleted, come here to get to next node
		remove(next->getNext(), next, inputId); //continue iterating thru with a non head next
	}
}


void print(Node* next){ //print function
	/*if(next == head){
		cout << "List:\n\n";
	}*/
	
	//next = head;
	
	if(next != NULL){
		cout << "Name: " << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << ", ID: " << next->getStudent()->getId() << ", GPA: "  << fixed << setprecision(2) << next->getStudent()->getGpa() << "\n" << endl; //prints student info in the node
		//cout << "Name: " << next->getNext()->getStudent()->getFirstName() << " " << next->getNext()->getStudent()->getLastName() << ", ID: " << next->getNext()->getStudent()->getId() << ", GPA: "  << fixed << setprecision(2) << next->getNext()->getStudent()->getGpa() << "\n" << endl;
		print(next->getNext()); //print next node recursively
	}
	else if(next == NULL){
		cout << "(End of list)\n" << endl;
	}
}

void average(Node* current){ //average function
	int amountStudent = 0;
	float gpaSum = 0;
	
	//     recursion //no
	//float aveVal;
	
	/*if(current != NULL){ //if list isn't empty
		amountStudent++;
		gpaSum = ((current->getStudent())->getGpa()) + gpaSum;
		current = current->getNext();
	}
	else{
		cout << ""
	}*/
	
	//aveVal = gpaSum / amountStudent;
	
	
	//amountStudent++;
	
	if(current == head){
		gpaSum += (current->getStudent())->getGpa();
		amountStudent++;
	}
	
	while(current->getNext() != NULL){
		gpaSum += head->getNext()->getStudent()->getGpa();
		amountStudent++;
		current = current->getNext();
	}
	
	
	
	cout << "\nAverage GPA: " << gpaSum / amountStudent << endl << endl;
	//cout << "Average GPA: " << aveVal << endl;
	
}


int main(){
	
	while(true){ //while running
		char input[100];
		char* firstName = new char[50];
		char* lastName = new char [50];
		int id = 0;
		float gpa = 0;
		cout << "Enter a command ('add', 'print', 'delete', 'average', 'exit'): ";
		cin.getline(input, 100); //get user input for commands
		
		if(strcmp(input, "add") == 0){ //if user wants to add a student
			
			//prompts
			cout << "Enter the student's first name: ";
			cin.getline(firstName, 50);
			cout << "Enter the student's last name: ";
			cin.getline(lastName, 50);
			cout << "Enter their student id: ";
			cin >> id;
			cin.clear(); cin.ignore(10000, '\n');
			cout << "Enter the student's gpa: ";
			cin >> gpa;
			cin.clear(); cin.ignore(10000, '\n');
			
			cout << endl;
			
			add(head, firstName, lastName, id, gpa); //call add method and implement user inputs
			//print(head);
			//Student* temp = new Student(firstName, lastName, id, gpa);
			
			//add(new Node(firstName, lastName, id, gpa));
			
		}
		
		else if(strcmp(input, "print") == 0){ //if user wants to print the list
			cout << "\nList:\n\n";
			print(head); //call print method, prints node head
		}
		
		else if(strcmp(input, "delete") == 0){ //if user would like to delete a student
			int inputId;
			if(head == NULL){ //if there are no nodes in the linkedlist
				cout << "\nThere are currently no students in the database.\n\n";
			}
			else{
				cout << "\nEnter the ID of the student you would like to delete: ";
				cin >> inputId;
				cin.clear();
				cin.ignore(10000, '\n');
				remove(head, NULL, inputId); //previous is null because head
			}
		}
		
		else if(strcmp(input, "average") == 0){ //average all student gpa
			if(head == NULL){
				cout << "\nThere are currently no students in the database.\n\n";
			}
			else{
				average(head); //call average method
			}
		}
		
		else if(strcmp(input, "exit") == 0){ //if user wants to exit
			return false; //kill program
		}
		
		else{ //if user enters an unsupported command
			cout << "\nThat action is not recognized.\n\n"; //cycles back
		}
		
		
	}
  
}
