#define CATCH_CONFIG_RUNNER

#include "../catch.hpp"
#include "permunation.cpp"
#include "tsp.h"
#include "greedy.cpp"
#include <chrono>
#include <iostream>

double difference(const Graph& g, const vector<int>& v1, const vector<int>& v2) {
    double result = 0.0;
    int n = g.get_vertices().size();
    for (int i = 0; i < n; i++) {
        result += g.edge_weight(v1[i % n], v1[(i + 1) % n]) - g.edge_weight(v2[i % n], v2[(i + 1) % n]);
    }

    return result;
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    int result = Catch::Session().run(argc, argv);

    for (int n = 5; n < 10; n++) {
        Graph g;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                g.add_edge(i, j, (rand() % 100) / 10.0);
        }

        auto t1 = std::chrono::high_resolution_clock::now();
        std::vector<int> res_2opt = tsp(g, 0);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto seconds = std::chrono::duration<double>(t2 - t1).count();
        std::cout << n << " вершин. Время на метод локального поиска: " << seconds << std::endl;

        t1 = std::chrono::high_resolution_clock::now();
        std::vector<int> res_perms = perm(g, 0);
        t2 = std::chrono::high_resolution_clock::now();
        seconds = std::chrono::duration<double>(t2 - t1).count();
        std::cout << n << " вершин. Время на полный перебор: " << seconds << std::endl;

        t1 = std::chrono::high_resolution_clock::now();
        std::vector<int> res_greedy = tsp_greed(g, 0);
        t2 = std::chrono::high_resolution_clock::now();
        seconds = std::chrono::duration<double>(t2 - t1).count();
        std::cout << n << " вершин. Время на жадный алгоритм: " << seconds << std::endl;

        double dif = difference(g, res_perms, res_2opt);
        std::cout << " Разница между полным перебором и локальным поиском: " << dif << "\n";
        dif = difference(g, res_greedy, res_2opt);
        std::cout << " Разница между жадным алгоритмом и локальным поиском: " << dif << "\n\n";


    }

    for (int n = 100; n < 300; n += 50) {
        Graph g;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                g.add_edge(i, j, (rand() % 100) / 10.0);
        }
        auto t1 = std::chrono::high_resolution_clock::now();
        std::vector<int> res_greedy = tsp_greed(g, 0);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto seconds = std::chrono::duration<double>(t2 - t1).count();
        std::cout << n << " вершин. Время на жадный алгоритм: " << seconds << std::endl;

        t1 = std::chrono::high_resolution_clock::now();
        std::vector<int> res_2opt = tsp(g, 0);
        t2 = std::chrono::high_resolution_clock::now();
        seconds = std::chrono::duration<double>(t2 - t1).count();
        std::cout << n << " вершин. Время на локальный поиск: " << seconds << std::endl;

        double dif = difference(g, res_greedy, res_2opt);
        std::cout << " Разница между жадным алгоритмом и локальным поиском: " << dif << "\n";


    }
    return result;
}
