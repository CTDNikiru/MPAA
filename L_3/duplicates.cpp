#include "duplicates.h"
using namespace std;

/*
●	Реализовать две функции/алгоритма: has_duplicates и get_duplicates. 
	Функция has_duplicates должна проверять, 
	содержит ли входной массив целых чисел дубликаты. 
	get_duplicates должна возвращать, в виде массива, 
	все те элементы входного массива, которые имеют дубликаты; 
	порядок элементов в результирующем массиве не важен. 
	
	Дополнительно: реализованные алгоритмы должны обладать временной сложностью 
	лучше чем O(n2).

●	Проверить корректность реализации на приложенных юнит-тестах.

●	Замерить время работы функций на входных массивах разного размера.

*/




bool has_duplicates(const std::vector<int>& data)
{
	if (data.size() == 0 || data.size() == 1) return false;

	for (int i = 0; i < data.size() - 1; i++)
	{
		for (int j = i + 1; j < data.size(); j++)
		{
			if (data[i] == data[j])
			{
				return true;
			}
		}
	}
	return false;
}

vector<int> vDuplicates;

struct BinaryTree
{
	int data;
	BinaryTree* left;
	BinaryTree* right;
};

void pushInDuplicatedTree(int pushData, BinaryTree** tree) {
	if (*tree == NULL) {
		*tree = new BinaryTree;
		(*tree)->data = pushData;
		(*tree)->left = (*tree)->right = NULL;
		return;
	}
	if (pushData > (*tree)->data) {
		pushInDuplicatedTree(pushData, &(*tree)->right);
	}
	else if (pushData == (*tree)->data)
	{
		return;
	}
	else { pushInDuplicatedTree(pushData, &(*tree)->left); }

}

void pushInTree(int pushData, BinaryTree** tree, BinaryTree** DuplicatedTree) {
	if (*tree == NULL) {
		*tree = new BinaryTree;
		(*tree)->data = pushData;
		(*tree)->left = (*tree)->right = NULL;
		return;
	}
	if (pushData > (*tree)->data) {
		pushInTree(pushData, &(*tree)->right, &(*DuplicatedTree));
	}
	else if(pushData == (*tree)->data)
	{
		pushInDuplicatedTree(pushData, &(*DuplicatedTree));
	}
	else { pushInTree(pushData, &(*tree)->left , &(*DuplicatedTree)); }

}

void getAllDuplicates(BinaryTree* tree)
{
	if (tree != NULL) {      //Пока не встретится пустой узел
		getAllDuplicates(tree->left);  //Рекурсивная функция вывода левого поддерева
		vDuplicates.push_back(tree->data);
		getAllDuplicates(tree->right); //Рекурсивная функция вывода правого поддерева
	}
}

std::vector<int> get_duplicates(const std::vector<int>& data)
{
	vDuplicates.clear();

	if (data.size() == 0 || data.size() == 1) {
		return vDuplicates;
	}
	BinaryTree* mytree = NULL;
	BinaryTree* treeDuplicates = NULL;
	
	for (int i = 0; i < data.size(); i++) {
		pushInTree(data[i], &mytree, &treeDuplicates);
	}
	
	getAllDuplicates(treeDuplicates);

	delete mytree;
	delete treeDuplicates;

	return vDuplicates;
}