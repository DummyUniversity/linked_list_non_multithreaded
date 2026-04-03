#ifndef SINGLY_LINKED_LIST_20260328_H
#define SINGLY_LINKED_LIST_20260328_H

#include "node.h"
#include <iostream>
using std::string;

class SinglyLinkedList
{
	Node* head = NULL;

public:

	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList &other);
	SinglyLinkedList& operator = (const SinglyLinkedList &other);
	bool operator == (const SinglyLinkedList &rhs) const;
	bool insert(const std::string data);
	bool search(const std::string data) const;
	bool remove(const std::string data);
	void print() const;
	~SinglyLinkedList();
};

#endif
