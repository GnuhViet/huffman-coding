#include <iostream>
#include "TreeNode.h"
#include "Coding.h"
#include <map>

typedef unsigned int uint;

using namespace std;

int main() {
	map<char, uint> test;
	test.insert(pair<char, uint>('a', 5));
	test.insert(pair<char, uint>('b', 9));
	test.insert(pair<char, uint>('c', 12));
	test.insert(pair<char, uint>('d', 13));
	test.insert(pair<char, uint>('e', 16));
	test.insert(pair<char, uint>('f', 45));
	
	cout << "before table: " << endl;
	for (auto it = test.begin(); it != test.end(); ++it)
		cout << it->first << ": " << it->second << endl;

	Coding test1(test);
	test1.getTable();
	
	map<char, string> result;
	result = test1.getTable();
	cout << "\n\nafter table: " << endl;
	for (auto it = result.begin(); it != result.end(); ++it)
		cout << it->first << ": " << it->second << endl;
}
