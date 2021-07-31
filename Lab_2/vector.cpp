#include <vector>
using namespace std;

void insertToVectorBack(vector<int>&myVector, int value) {
	myVector.push_back(value);
}

void insertToVectorBegin(vector<int>& myVector, int value) {
	myVector.insert(myVector.begin(), value);
}

int findInVector(vector<int> myVector, int value) {
	return *find(myVector.begin(), myVector.end(), value);
}