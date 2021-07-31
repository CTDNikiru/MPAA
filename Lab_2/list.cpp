#include <list>
using namespace std;

void InsertListBack(list<int>& myList, int value) {
	myList.push_back(value);
}

void InsertListBegin(list<int>& myList, int value) {
	myList.insert(myList.begin(), value);
}

int findInList(list<int> myList, int elem) {
	return *find(myList.begin(), myList.end(), elem);
}