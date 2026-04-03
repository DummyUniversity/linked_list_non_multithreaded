#include "test.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include "linkedlist.h"

using std::cout;
using std::vector;
using std::ifstream;

uint64_t getMillisecondsSinceEpoch()
{
	uint64_t milliseconds = 0;
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::chrono::system_clock::duration duration_since_epoch = now.time_since_epoch();
	std::chrono::milliseconds millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration_since_epoch);
	milliseconds = millis.count();
	return milliseconds;
}

int test(char* str)
{
	std::string test = str;

	if (test == "000")
	{
		cout << "Correct\n";
	}

	int noOfThreads	= 8;

	vector<string> words;
//	std::string filename = "google-10000-english-usa-no-swears-long.txt";
	std::string filename = "words.txt";
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		std::string line;
		while (std::getline(myfile, line))
		{
			words.push_back(line);
		}
	}
	else
	{
		cout << "Error opening input file.\n";
	}



	SinglyLinkedList r;
	uint64_t duration = getMillisecondsSinceEpoch();
	for (int i = 0; i < words.size(); i++)
	{
		r.insert(words[i]);
	}
	duration = getMillisecondsSinceEpoch() - duration;
	double standard_duration = duration;

	SinglyLinkedList a;
	duration = getMillisecondsSinceEpoch();
//	#pragma omp parallel for num_threads(noOfThreads)
	for (int i = 0; i < words.size(); i++)
	{
		a.insert(words[i]);
	}
	duration = getMillisecondsSinceEpoch() - duration;
	double parallelized_duration = duration;



	if (r == a)
	{
		cout << "Test 00 passed: The test linked list matches the reference linked list.\n";
	}
	else
	{
		cout << "Test 00 failed: The test linked list does not match the reference linked list.\n";
	}

	if (parallelized_duration < standard_duration / 1.25)
	{
		cout << "Test 01 passed: The test linked list is faster than 1.25x the reference linked list.\n";
	}
	else
	{
		cout << "Test 01 failed: The test linked list is slower than 1.25x the reference linked list.\n";
	}

	cout << "No of threads = " << noOfThreads << "\n";
	cout << "Standard (sequential for loop) hash table\t: " << standard_duration << " ms\n";
	cout << "Test (parallelized for loop) hash table\t\t: " << parallelized_duration << " ms\n";



	return 0;
}
