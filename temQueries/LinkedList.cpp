#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {clear();}

LinkedList::LinkedList(const LinkedList& other)
{
	Node* cur = other.head;
	Node* prev = nullptr;
	while(cur != nullptr) {
		Node* newNode = new Node(cur->data.id, cur->data.year, cur->data.month, cur->data.temperature);
		if(head==nullptr) {head = newNode;}
		if(head!=nullptr) {prev->next = newNode;}
		prev = newNode;
		cur = cur->next;
	}
	tail = prev;
	// Implement this function
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	clear();
	Node* cur = source.head;
	Node* prev = nullptr;
	while(cur != nullptr) {
		Node* newNode = new Node(cur->data.id, cur->data.month, cur->data.year, cur->data.temperature);
		if(head==nullptr) {head = newNode;}
		if(head!=nullptr) {prev->next = newNode;}
		prev = newNode;
		cur = cur->next;
	}
	tail = prev;
	// Implement this function
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	Node* val = new Node(location, year, month, temperature);
	
	if(head == nullptr) { // if there is nothing in the LL
		head = val;
		head->next = nullptr;
		tail = head;
		return;
	}
	
	Node* index = head;
	Node* temp = head->next;
	if(head == tail) { // if there is one thing in the LL
		if(*val < *head) { // place 1st index
			temp = head;
			head = val;
			head->next = temp;
			temp->next = nullptr;
			tail = temp;
		}
		else { // place second index
			head->next = val;
			val->next = nullptr;
			tail = val;
		}
		return;
	}
	if(*val < *head) {
		val->next = head;
		head = val;
		return;
	}
	while(index->next != nullptr && *index->next < *val) {
		index = index->next;
	}
	temp = index->next;
	val->next = temp;
	index->next = val;
}

void LinkedList::clear() {
	// Implement this function
	while(head != nullptr)
	{
		Node* temp = head->next;
		delete head;
		head = temp;
	}
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	string outputString;
	Node* index = head;
	ostringstream ss;
	while(index != nullptr) {
		ss << index->data.id << " " << index->data.year << " " << index->data.month << " " << index->data.temperature << endl;
		index = index->next;
	}
	outputString = outputString + ss.str();
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}

double LinkedList::calcAvg(string loc, int begin, int end) { // calculateds the average
	double sum = 0;
	int count = 0;
	Node* temp = head; //start at the head
	
	while(temp != nullptr) { // while temp is not at the end
		if(temp->data.id == loc && temp->data.year >= begin && temp->data.year <= end) {
			sum += temp->data.temperature; // add to the sum if the value is correct
			count += 1; // add to the count too
		}
		temp = temp->next;
	}
	if(count == 0) {return -9999;} // unkown check
	double avg =  sum / count; // returns this value for the average
	return avg;
}

int LinkedList::mode(string loc, int begin, int end) { 
	Node* temp = head; // begin at the head
	vector <int> query;
	while(temp != nullptr) { // go unitl it reaches the end
		if(temp->data.id == loc && temp->data.year >= begin && temp->data.year <= end) {
			query.push_back(round(temp->data.temperature)); // add to the vector for every input that qualifies
		}
		temp = temp->next; //continue to the next node
	}
	if(query.size() == 0) {return -9999;} // check if it is unknown
	for(int i = 0; i < query.size() - 1; i++) { //DUMB BUBBLE SORT
		for(int j = 0; j <  query.size() - 1; j++) {
			if(query.at(j) > query.at(j+1)) {
				int tempnum = query.at(j+1);
				query.at(j+1) = query.at(j);
				query.at(j) = tempnum;
			}
		}
	}// END DUMB BUBBLE SORT
	int maxMode = 0;
	int maxModeCount = 0;
	for(int i = 0; i < query.size(); i++) { // increment through the vector
		int mode = query.at(i); // set mode to the increment
		int countM = 0; // set its count for the mode to zero
		for(int j = 0; j < query.size(); j++) { // incement through the array again
			if(mode == query.at(j)) {countM++;} // count up for everything that is equal
		}
		if(countM >= maxModeCount) { //if the new mode is greater than the biggest mode
			maxModeCount = countM; // set the new mode to the greatest mode
			maxMode = mode; 
		}
	}
	return maxMode; // return the greatest mode
}













