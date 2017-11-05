/************************
 * Tran Le
 * FALL2017
 * CSS342: 		Project#2 Linked List 
 * File Name:	workQueue.h
*************************/

#ifndef WORK_QUEUE_H
#define WORK_QUEUE_H
#include <iostream> 
#include <string> 
#include "workItem.h"
#include "workItemList.h"
using namespace std; 

class WorkQueue {
private:
	struct WorkItemListNode {
		WorkItemList list; 
		WorkItemListNode* next; 

		WorkItemListNode(const WorkItemList& list, WorkItemListNode* next = NULL) {
			this->list = list;
			this->next = next; 
		}
	};
	int size; // Size of the queue
	// Header node	
	WorkItemListNode* head; 
public: 
	// Constructor 
	WorkQueue(); 
	WorkQueue(const WorkQueue& obj); 
	// Destructor 
	virtual ~WorkQueue(); 

	// Getters and Setters 
	void addWorkItem(const WorkItem& obj); 	
	int getNumWorkItems() const; 
	int getNumWorkItems(int priority) const; 
	bool hasWorkItem(int priority) const; 
	bool containsKey(const string& key) const; 
		

	// Functions
	const WorkItem& nextWorkItem(int priority) const; 
	void deleteWorkItem(const string key); 
	void deleteAllWorkItems(); 
	void bumpWorkItem(const string& key); 
	
	// Operator Overload
	WorkQueue& operator=(const WorkQueue& obj); 

};

#endif  // !WORK_QUEUE_H
