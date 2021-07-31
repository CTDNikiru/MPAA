#include <set>
using namespace std;

void insertInSetBack(set<int> &mySet, int value) {
	mySet.insert(value);
}

int findInSet(set<int> mySet, int value) {
	return *find(mySet.begin(), mySet.end(), value);
}