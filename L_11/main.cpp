#define CATCH_CONFIG_RUNNER

#include "../catch.hpp"

#include "shortest_path.h"
#include <chrono>
#include <vector>

using namespace std;

std::pair<Graph, int> MGRA(int n) {

    if (n <= 1) {
        return {};
    }

    Graph result;
    int counter = 0;
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++) {
        bool imFill = (double)(rand()) / RAND_MAX > 0.5;
        for (int j = i + 1; j < n && imFill; j++) {
            result.add_edge(i, j, (double)(rand()));
            counter++;
        }
    }
    return std::make_pair(result, counter);
}

int main(int argc, char* argv[]) {

    for (int n = 0; n < 11; n++) {
        int count = pow(2, n);
        std::pair<Graph, int> g = MGRA(count);
        auto t1 = std::chrono::high_resolution_clock::now();

        shortest_path(g.first, 0, count);

        auto t2 = std::chrono::high_resolution_clock::now();
        double time = std::chrono::duration<double>(t2 - t1).count();
        std::cout << "vertexes: " << g.first.get_vertices().size() << " edges: " << g.second << ", time: " << time << std::endl;
    }

    int result = Catch::Session().run(argc, argv);
    return result;
}