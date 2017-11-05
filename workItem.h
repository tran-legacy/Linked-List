/************************
 * Tran Le
 * FALL2017
 * CSS342:      Project#2 Linked List
 * File Name:   workItem.h
*************************/

#ifndef WORK_ITEM_H
#define WORK_ITEM_H
#include <iostream> 
#include <string>
using namespace std; 

class WorkItem {
private:
   int priority; 
   string key; // Unique to each WorkItem
public: 
	// Constructors 
	WorkItem(); 
	WorkItem(int priority, const string & key);
	// Copy Constructor
	WorkItem (const WorkItem& obj);

	// Getters
	int getPriority() const;
	const string& getKey() const;
	
	// Operator overload
	WorkItem& operator=(const WorkItem& rhs);	
};

#endif // !WORK_ITEM_H
