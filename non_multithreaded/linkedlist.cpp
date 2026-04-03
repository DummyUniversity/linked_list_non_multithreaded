#include "linkedlist.h"
#include <iostream>
#include <iostream>
using std::string;
using std::cout;


SinglyLinkedList::SinglyLinkedList() {}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &other)
{
	Node* otherCurrent = other.head;
	if (otherCurrent != NULL)
	{
		Node* n = new Node(otherCurrent->getData(), NULL);
		head = n;
	}

	Node* current = head;

	while (otherCurrent->getNext() != NULL)
	{
		otherCurrent = otherCurrent->getNext();
		Node* n = new Node(otherCurrent->getData(), NULL);

		current->setNext(n);
		current = current->getNext(); 
	}
}

bool SinglyLinkedList::operator == (const SinglyLinkedList &rhs) const
{
	Node* current = head;
	Node* rhsCurrent = rhs.head;

//	while ( !( (current == NULL && rhsCurrent == NULL) || (current != NULL && rhsCurrent != NULL) ) )
	while (current != NULL || rhsCurrent != NULL)
	{
		if ( ( current == NULL && rhsCurrent != NULL ) || ( current != NULL && rhsCurrent == NULL ) )
		{
			return false;
		}
		else
		{
			if (current->getData() != rhsCurrent->getData())
			{
				return false;
			}
		}

		current = current->getNext();
		rhsCurrent = rhsCurrent->getNext();
	}

	return true;
}

SinglyLinkedList& SinglyLinkedList::operator = (const SinglyLinkedList &other)
{
	if (this != &other)
	{
		//First delete the entire linked list
	
		Node* current = head;
		while (current != NULL)
		{
			Node* nodeToBeDeleted = current;
			current = current->getNext();
			delete nodeToBeDeleted;
			nodeToBeDeleted = NULL;
		}
	
		//Now copy the list
	
		Node* otherCurrent = other.head;
		if (otherCurrent != NULL)
		{
			Node* n = new Node(otherCurrent->getData(), NULL);
			head = n;
		}
	
		current = head;
	
		while (otherCurrent->getNext() != NULL)
		{
			otherCurrent = otherCurrent->getNext();
			Node* n = new Node(otherCurrent->getData(), NULL);
	
			current->setNext(n);
			current = current->getNext();
		}
	}

	return *this;
}

bool SinglyLinkedList::insert(const std::string data)
{
	if (head == NULL)
	{
		Node* newNode = new Node(data);
		head = newNode;
		head->setNext(NULL);	//Redundant
		return true;
	}
	else if (data < head->getData())	//Insertion before head
	{
		Node* newNode = new Node(data);
		newNode->setNext(head);
		head = newNode;
		return true;
	}
	else if (data == head->getData())	//Separate checking for equality for head
	{
		return false;
	}
	else
	{
		Node* current = head;
		Node* previous = NULL;
		while (current != NULL)
		{
			if (data == current->getData())
			{
				return false;
			}
			else
			{
				if (current->getNext() != NULL)
				{
					Node* next = current->getNext();
					if (data < next->getData())	//Insertion in middle
					{
						Node* newNode = new Node(data);
						newNode->setNext(next);
						current->setNext(newNode);
						return true;
					}
				}
			}

			previous = current;		//Traversal
			current = current->getNext();
		}

		Node* newNode = new Node(data);
		previous->setNext(newNode);
		newNode->setNext(NULL);	//Redundant
		return true;
	}
}

bool SinglyLinkedList::search(const std::string data) const
{
	Node* current = head;
	while (current != NULL)
	{
		if (data == current->getData())
		{
			return true;
		}
		current = current->getNext();
	}
	return false;
}

bool SinglyLinkedList::remove(const std::string data)
{
	//Not implemented
	return false;
}

void SinglyLinkedList::print() const
{
	Node* current = head;
	while (current != NULL)
	{
		cout << current->getData() << " ";
		current = current->getNext();
	}
	cout << "\n";
}


SinglyLinkedList::~SinglyLinkedList()
{
	Node* current = head;
	while (current != NULL)
	{
		Node* nodeToBeDeleted = current;
		current = current->getNext();
		delete nodeToBeDeleted;
		nodeToBeDeleted = NULL;
	}
}



