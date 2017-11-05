/************************
 * Tran Le
 * FALL2017
 * CSS342:      Project#2 Linked List
 * File Name:   workItemList.cpp
*************************/
using namespace std; 
#include "workItemList.h"
#include <stdexcept>

/********Constructors************/
WorkItemList::WorkItemList() {
	this->size = 0; 
	this->head = NULL;
}

WorkItemList::WorkItemList(int priority) {
	this->size = 0; 
	this->priority = priority;	
	this->head = NULL;
}

/**********Destructor***********/
WorkItemList::~WorkItemList() {
	deleteWorkItemList(); 
}

/***********Getters and Setters**********/
int WorkItemList::getPriority() const {
	return this->priority;
}

int WorkItemList::getSize() const {
	return this->size;
}	

const WorkItem& WorkItemList::nextWorkItem() const{
	if (this->head == NULL)
		throw logic_error("Item does not exit.");
	return this->head->item;
}
bool WorkItemList::containsKey(const string& key) const {
	WorkItemNode* currPtr = this->head; 
	while (currPtr) {
		if (currPtr->item.getKey() == key) 
			return true; 
		currPtr = currPtr->next; 
	}
	return false; 
}

/**********************Functions************************/
void WorkItemList::addWorkItem(const WorkItem& item) {
	// If it's the first item being added
	if (this->head == NULL)  {
		this->head = new WorkItemNode(item); 
		++size; 
		return; 
	}

	WorkItemNode* currPtr = this->head; 
	while (currPtr->next) 
		currPtr = currPtr->next; 
	currPtr->next = new WorkItemNode(item); 
	++size; 
}

bool WorkItemList::deleteWorkItem(const string& key) {
	// If list is null 
	if (this->head == NULL) {
		return false; 
	}
	// If the head is the one 
	if (this->head->item.getKey() == key) {
		WorkItemNode* garbage = this->head; 
		this->head = this->head->next; 
		delete garbage; 
		--size; 
		return true;
	}
	// If it's within the list
	WorkItemNode* currPtr = this->head->next;
	WorkItemNode* prevPtr = this->head; 
	while (currPtr) {
		if (currPtr->item.getKey() == key) {
			WorkItemNode* garbage = currPtr; 
			currPtr = currPtr->next;
		    prevPtr->next = currPtr; 	
			delete garbage;
			--size; 
			return true; 
		}
		currPtr = currPtr->next;
	}
}
void WorkItemList::deleteWorkItemList() {
	WorkItemNode* currPtr = this->head; 
	while (currPtr) {
		WorkItemNode* garbage = currPtr; 
		currPtr = currPtr->next; 
		delete garbage;
	}	
	this->head = NULL;
	this->size = 0;
   	this->priority = 0; 	

}

bool WorkItemList::bumpWorkItem(const string& key) {
	if (this->head == NULL) 
		return false; 

	WorkItemNode* currPtr = this->head; 
	WorkItemNode* prevPtr = NULL; 
	while(currPtr) {
		if (currPtr->item.getKey() == key) {
			if (prevPtr == NULL)
				return true;
			// Detach the target
			prevPtr->next = currPtr->next;
    		// Attach to head of the priority	
			currPtr->next = this->head; 
			this->head = currPtr;
			return true; 	 
		}
		prevPtr = currPtr;
		currPtr = currPtr->next; 
	}
	return false;

}

/********Operator Overload**********/
WorkItemList& WorkItemList::operator=(const WorkItemList& obj) {
	WorkItemNode* objPtr = obj.head;
    this->priority = obj.priority;	
	this->addWorkItem(objPtr->item);
	objPtr = objPtr->next;
	while (objPtr) {
		this->addWorkItem(objPtr->item); 
		objPtr = objPtr->next; 
	}
	
		
	return *this; 
}	
