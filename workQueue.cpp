/************************
 * Tran Le
 * FALL2017
 * CSS342:      Project#2 Linked List
 * File Name:   wokQueue.cpp
 * Vim on Cygwin 
 * Took TOO long :)
 *************************/
using namespace std; 
#include "workQueue.h"
#include <stdexcept>

/*******Constructor*******/
WorkQueue::WorkQueue() {
	// Create a NULL WorkQueue
	this->head = NULL;
	this->size = 0; 
}
WorkQueue::WorkQueue(const WorkQueue& obj) {
	*this = obj; 
//	// Make a pointer pointing to head of obj
//	WorkItemListNode* objPtr = obj.head; 
//	// Create a head node for this obj
//	this->head = new ListNode(objPtr->value);
//	++size;
//	// Create a pointer pointing to head of this obj
//	WorkItemListNode* currPtr = this->head; 
//	objPtr = objPtr->next;
//	while(objPtr) {
//		currPtr->next = new ListNode(objPtr->value);
//		currPtr = currPtr->next;
//		objPtr = objPtr->next;
//		++size;
//	}
}

/**********Destructor**********/ 
WorkQueue::~WorkQueue() { deleteAllWorkItems(); }

/********Getters and Setters*******/ 
void WorkQueue::addWorkItem(const WorkItem& item) {	
	// First WorkItem to be added
	if (this->head == NULL || this->head->list.getPriority() > item.getPriority()) { 
		// Make a new list{
		WorkItemList newList(item.getPriority());
		// Add item to the list
		newList.addWorkItem(item); 
		this->head = new WorkItemListNode(newList, this->head); 
		++size; 
		return;
	}else if (this->head->list.getPriority() == item.getPriority()) {
		this->head->list.addWorkItem(item);
		++size;
		return;
	}
	
	// Iterate until currPtr finds the correct priority #, or a priority # that is bigger
	for (WorkItemListNode* currPtr = this->head; currPtr != NULL; currPtr = currPtr->next) {
		if (currPtr->next == NULL || currPtr->next->list.getPriority() > item.getPriority()) { 
		 // currPtr->next priority # is bigger or NULL, then add a new list and then add WorkItem
			WorkItemListNode* temp = currPtr->next;
			WorkItemList newList(item.getPriority());
			newList.addWorkItem(item);	
			currPtr->next = new WorkItemListNode(newList, temp); 	
			++size;
			return; 
		// else the priority # is equal, add 
		} else if (currPtr->next->list.getPriority() == item.getPriority()) {
			currPtr->next->list.addWorkItem(item);
			++size;
			return;
		}
	}	
}

	
//	// Method needs to add the WorkItem in the correct place based on priority number
//	WorkItemListNode* currPtr = this-> head; 
//	// Iterate until currPtr gets to the end of the correct priority number (obj's priority number)
//	while (currPtr->next->item.getPriority() <= item.getPriority()) {
//		currPtr = currPtr->next; 
//	}
//	// Need a temp ptr for the next WorkItemListNode
//	WorkItemListNode* temp = currPtr->next;
//	// Insert and connect the WorkItem
//	currPtr->next = new WorkItemListNode(item, temp); 
//	++size; 


int WorkQueue::getNumWorkItems() const {
	return this->size; 	
}

int WorkQueue::getNumWorkItems(int priority) const {
	// If the priority is not in the list 
	//if (!this->hasWorkItem(priority)) 
	//	return 0; 

	// Gets number of WorkItems based on a priority number
	WorkItemListNode* currPtr = this->head; 
	while (currPtr) { 
		if (currPtr->list.getPriority() == priority) 
			return currPtr->list.getSize();
		currPtr = currPtr->next;
	}
	return 0;	
}

bool WorkQueue::hasWorkItem(int priority) const {
	// Checks if the queue has a WorkItem in a certain priority
	WorkItemListNode* currPtr = this->head; 
	while (currPtr) {
		if (currPtr->list.getPriority() >= priority)
			return true;
		currPtr = currPtr->next;
	}
	return false; 
}

bool WorkQueue::containsKey(const string& key) const {
	// Checks if the queue has a WorkItem of a certain key
	WorkItemListNode* currPtr = this->head; 
	while (currPtr) {
		if (currPtr->list.containsKey(key)) 
			return true;
		currPtr = currPtr->next;
	}
	return false;
}

/*******Functions********/
const WorkItem& WorkQueue::nextWorkItem(int priority) const {
	WorkItemListNode* currPtr = this->head; 
	while(currPtr) {
		if (currPtr->list.getPriority() >= priority)
			return currPtr->list.nextWorkItem(); 
		currPtr = currPtr->next;
	}	
	throw logic_error("This priority does not exist."); 
}


void WorkQueue::deleteWorkItem(string key) {
	WorkItemListNode* currPtr = this->head; 
	while (currPtr) {
		if (currPtr->list.deleteWorkItem(key)) {
			// List size will now be off
			--size;
			break;
		}
		currPtr = currPtr->next;
	}
}

void WorkQueue::deleteAllWorkItems() {
	WorkItemListNode* currPtr = this->head; 
	while (currPtr) {
		WorkItemListNode* garbage = currPtr; 
		currPtr = currPtr->next; 
		delete garbage;
	}	
	this->head = NULL;
	this->size = 0; 
}

void WorkQueue::bumpWorkItem(const string& key) {
	WorkItemListNode* currPtr = this->head; 
	while (currPtr) {
		if (currPtr->list.bumpWorkItem(key))
			break;
		currPtr = currPtr->next;
	}
}

/********Operator Overload**********/
WorkQueue& WorkQueue::operator=(const WorkQueue& obj) {
	this->size = 0; 
	// Make a pointer pointing to head of obj
	WorkItemListNode* objPtr = obj.head; 
	// Create a head node for this obj
	this->head = new WorkItemListNode(objPtr->list);
	size += objPtr->list.getSize();
	// Create a pointer pointing to head of this obj
	WorkItemListNode* currPtr = this->head; 
	objPtr = objPtr->next;
	while(objPtr) {
		currPtr->next = new WorkItemListNode(objPtr->list);
		size += objPtr->list.getSize();
		currPtr = currPtr->next;
		objPtr = objPtr->next;
	}
	
	return *this;    	
}
