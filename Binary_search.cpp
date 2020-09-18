

//http://codekata.com/kata/kata02-karate-chop/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int needle, vector<int> values);
unsigned int middleOf(int leftBound, int rightBound);
void testBinarySearch();


int main() {
	testBinarySearch();
	return 0;
}


int binarySearch(int needle, vector<int> values) {
	const int NOT_FOUND = -1;

	const unsigned int length = values.size();

	// If empty, needle will never be found
	if (length == 0) {
		return NOT_FOUND;
	}

	// Bracket the needle with [leftBound, rightBound]
	unsigned int leftBound = 0;
	unsigned int rightBound = length - 1;

	// Start at middle of bracket
	// If even number of entries, use the one on the left
	unsigned int position = middleOf(leftBound, rightBound);

	// Binary search ends in at most ceil of log base 2 of length + 1
	const unsigned int maxIterations = ceil(log(length) / log(2)) + 1;

	int value;
	for (unsigned int iteration = 0; iteration < maxIterations; ++iteration) {
		value = values.at(position);

		if (value == needle) {
			return position;
		} else if (value < needle) {
			leftBound = position;
			rightBound = rightBound;
			position = position + middleOf(leftBound, rightBound);
		} else if (value > needle) {
			leftBound = leftBound;
			rightBound = position;
			position = position - middleOf(leftBound, rightBound);
		}
	}

	return NOT_FOUND;
}


unsigned int middleOf(int leftBound, int rightBound) {
	return (rightBound - leftBound + 1) / 2;
}
// An assert is a statement in C++ which tests for a condition like the one explained above.
// If the condition is true, the program continues normally and if the condition is false, the program is terminated 
// and an error message is displayed. We can provide an assertion using an assert preprocessor macro.

// Test cases given on website
void testBinarySearch() {
	vector<int> values;
	assert(-1 == binarySearch(3, values));

	values.push_back(1);
	assert(-1 == binarySearch(3, values));
	assert( 0 == binarySearch(1, values));

	values.push_back(3);
	values.push_back(5);
	assert( 0 == binarySearch(1, values));
	assert( 1 == binarySearch(3, values));
	assert( 2 == binarySearch(5, values));
	assert(-1 == binarySearch(0, values));
	assert(-1 == binarySearch(2, values));
	assert(-1 == binarySearch(4, values));
	assert(-1 == binarySearch(6, values));

	values.push_back(7);
	assert( 0 == binarySearch(1, values));
	assert( 1 == binarySearch(3, values));
	assert( 2 == binarySearch(5, values));
	assert( 3 == binarySearch(7, values));
	assert(-1 == binarySearch(0, values));
	assert(-1 == binarySearch(2, values));
	assert(-1 == binarySearch(4, values));
	assert(-1 == binarySearch(6, values));
	assert(-1 == binarySearch(8, values));

	std::cout << "All tests passed!";
}
