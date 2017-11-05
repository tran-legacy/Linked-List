/************************
 * Tran Le
 * FALL2017
 * CSS342:      Project#2 Linked List
 * File Name:   workItemList.h
*************************/
#ifndef WORK_ITEM_LIST_H
#define WORK_ITEM_LIST_H

using namespace std; 
#include "workItem.h"

class WorkItemList {
private:
    // WorkItemNode that contains a WorkItem and a pointer to the next node
    struct WorkItemNode {
        WorkItem item;
        WorkItemNode* next;

        WorkItemNode(const WorkItem& item, WorkItemNode* next = NULL) {
            this->item = item;
            this->next = next;
        }
    };
     
	int priority;	
	int size;
	WorkItemNode* head;	
public:
	// Constructor
	WorkItemList();
   	WorkItemList(int priority); 	
	// Destructor 
	virtual ~WorkItemList(); 	
	
	// Getters and Setters
	int getPriority() const; 	
	int getSize() const;
	const WorkItem& nextWorkItem() const; 
	bool containsKey(const string& key) const; 

	// Functions
	void addWorkItem(const WorkItem& item);
	bool deleteWorkItem(const string& key); 
	bool bumpWorkItem(const string&key); 
	void deleteWorkItemList();

	// Operator Overload 
	WorkItemList& operator=(const WorkItemList& obj); 
};

#endif	// !WORK_ITEM_LIST_H


