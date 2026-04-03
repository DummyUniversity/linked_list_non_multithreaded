#include "node.h"
#include <cstring>
#include <iostream>
using std::cout;

Node::Node(const std::string data, Node* next)
{
	this->data = data;
	this->next = next;
}

Node::Node(const std::string data)
{
	this->data = data;
	this->next = NULL;
}

Node::Node(const Node &other)
{
	data = other.data;
	next = other.next;
}

Node& Node::operator = (const Node &other)
{
	if (this != &other)
	{
		data = other.data;
		next = other.next;
	}

	return *this;
}

void Node::setNext(Node* next)
{
	this->next = next;
}


Node* Node::getNext() const
{
	return next;
}


void Node::setData(const std::string data)
{
	this->data = data;	
}

std::string Node::getData() const
{
	return data;
}


void Node::print() const
{
	cout << data;
}


Node::~Node()
{
	
}

