#ifndef NODE_20260328_H
#define NODE_20260328_H

#include <iostream>
using std::string;

class Node
{
	std::string data;
	Node* next = NULL;

public:

	Node(const std::string data, Node* next);
	Node(const std::string data);
	Node(const Node &other);
	Node& operator = (const Node &other);
	void setNext(Node* next);
	Node* getNext() const;
	void setData(const std::string data);
	std::string getData() const;
	void print() const;
	~Node();
};

#endif
