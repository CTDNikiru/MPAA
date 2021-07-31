﻿#include "count_sort.h"

// Return sorted array. 
// All elements of array are assumed to be from [min, max] range.

/*
●	Реализовать алгоритм сортировки подсчетом (функция count_sort).

●	Проверить корректность реализации на прилагающихся юнит-тестах.

●	Замерить время работы на входных массивах разного размера, 
    сравнить со временем работы стандартной сортировки std::sort.

●	Предположить и проверить, что будет, 
    если вместо обычного массива counts использовать ассоциативный массив (std::map).
*/

std::vector<int> count_sort(const std::vector<int>& array, int min, int max) {

	/*
	Принцип работы сортировки подсчетом

	Создается массив размером max - min + 1 и обнуляется
	Берется число из массива который необходимо отсортировать

	В созданном массиве число по индексу равному числу из массива,
	который надо отсортировать увеличивается на еденицу

	Совершается проход по созданному массиву и в результирующий массив
	записываются индексы по которым в созданном массиве число равно 1

	Если число больше нуля это действие повторяется столько раз, сколько необходимо
	*/


	if (array.size() == 0 || array.size() == 1) return array;

    std::vector<int> result;

	int len = max - min + 1;
	int* arr = new int[len];

	for (size_t i = 0; i < len; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < array.size(); i++)
	{
		arr[array[i]-min]++;
	}

	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= 1) {
			for (int j = 0; j < arr[i]; j++)
				result.push_back(i + min);
		}
	}

    return result;
}