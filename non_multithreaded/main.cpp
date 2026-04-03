#include <iostream>
#include "node.h"
#include "linkedlist.h"
#include "test.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		test(argv[1]);
	}

//	cout << "Meow\n";
	SinglyLinkedList a;
	a.insert("orange");
	a.insert("apple");
	a.insert("banana");
	a.insert("zunchini");
	a.insert("aaa");

	return 0;
}
