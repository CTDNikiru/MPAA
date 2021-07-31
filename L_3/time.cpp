#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include"duplicates.h"

std::vector<int> gen_random_array(int size) {
	std::vector<int> result(size);
	
	
	for (int i = 0; i < size; i++) {
		result[i] = 4;
		//result[i] = rand();
	}
	return result;
}

void measure(int size) {
	std::vector<int> data = gen_random_array(size);

	auto t1 = std::chrono::high_resolution_clock::now();
	has_duplicates(data);
	get_duplicates(data);
	auto t2 = std::chrono::high_resolution_clock::now();

	double time = std::chrono::duration<double>(t2 - t1).count();

	std::cout << "N: " << size << ", time: " << time << std::endl;
}
