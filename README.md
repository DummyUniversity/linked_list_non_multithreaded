# linked_list_non_multithreaded

Non-multithreaded singly linked list for `std::string`. The list is always sorted in ascending order, and does not allow duplicates.

The `words.txt` file contains 10,000 words that each contains 100 characters, ranging from ASCII-33 to ASCII-126 which are all readily readable characters (no whitespaces, etc.). There is a small chance that there are duplicate words in the file.

The test, in `test.cpp`, creates two linked lists and fills both with the same strings. The first list, referred to as the standard, is filled sequentially. The second is filled by for loop parallelisation. It contains two tests. The first checks if the lists are exactly the same, using the comparision `==` operator. The second checks if the parallelised insertions are at least as fast as 1.25 times the sequential insertions.

Compile command: `g++ main.cpp test.cpp node.cpp linkedlist.cpp -fopenmp -o a.exe`

Run command: `./a.exe 000`
