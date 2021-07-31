/*
●	Изучить такие структуры данных из стандартной библиотеки C++, 
как vector (массив), list (список) и set (множество).

●	Для этих структур данных замерить время работы таких операций, 
как вставка N элементов и поиск M разных элементов (M взять достаточно большим), 
для разных значений N. Для vector и list исследовать два режима вставки: 
вставку в конец (push_back) и вставку в начало (insert(begin(), ...)).
*/

#include <iostream>

#include "vector.cpp";
#include "list.cpp"
#include "set.cpp";

#include <vector>
#include <list>
#include <set>

using namespace std;

int main() {

	vector<int> Vector;
	list<int> List;
	set<int> Set;

	insertToVectorBegin(Vector, 1);
	insertToVectorBack(Vector, 2);
	cout << findInVector(Vector,2);

	InsertListBegin(List, 3);
	InsertListBack(List, 4);
	cout << findInList(List, 3);

	insertInSetBack(Set, 5);
	insertInSetBack(Set, 6);
	cout << findInSet(Set, 5);



}