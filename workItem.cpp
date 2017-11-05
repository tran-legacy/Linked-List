/************************
 * Tran Le
 * FALL2017
 * CSS342:      Project#2 Linked List
 * File Name:   wokItem.cpp
*************************/
#include "workItem.h"

/*****Constructors******/ 
WorkItem::WorkItem() {
	this->priority = 0; 
	this->key = ""; 
}

WorkItem::WorkItem(int priority, const string& key) {
	this->priority = priority; 
	this->key = key; 
}

/*****Copy Constructor******/
WorkItem::WorkItem(const WorkItem& obj) { 
 	this->priority = obj.getPriority();
    this->key = obj.getKey();
}

/**********Getters***********/
int WorkItem::getPriority() const { return this->priority; }
const string& WorkItem::getKey() const { return this->key; }

/*****Operator Overload******/ 
WorkItem& WorkItem::operator=(const WorkItem& rhs) {
	this->priority = rhs.getPriority(); 
	this->key = rhs.getKey(); 
	return *this; 
}
