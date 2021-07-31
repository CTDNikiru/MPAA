
#include "tsp.h"
#include <set>
#include <sstream>
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

using namespace std;

vector<int> AllPerm(const Graph& graph, int start_vertex) {

    
}

vector<int> tsp(const Graph& graph, int start_vertex) {

    if (graph.get_vertices().size() < 2) {
        return {};
    }
    vector<int> myints = graph.get_vertices();
    sort(myints.begin(), myints.end());

    pair<double, vector<int>> theMin = make_pair(DBL_MAX, vector<int>());

    do {
        if (myints[0] == start_vertex) {
            double sum = 0;
            for (int i = 0; i < myints.size() - 1; i++) {
                try {
                    sum += graph.edge_weight(myints[i], myints[i + 1]);
                }
                catch (exception e) {
                    return {};
                }
            }
            if (sum < theMin.first) {
                theMin = make_pair(sum, myints);
            }
        }
    } while (std::next_permutation(myints.begin(), myints.end()));

    return theMin.second;
}

vector<int> tsp_greed(const Graph& graph, int start_vertex) {
    if (graph.get_vertices().size() < 2) {
        return {};
    }
    vector<int> Path = { start_vertex };
    
    while (Path.size() != graph.get_vertices().size()) {
        auto vertexes = graph.get_adjacent_edges(start_vertex);
        pair<int, double> theMin = make_pair(-1, DBL_MAX);
        for (int i = 0; i < vertexes.size(); i++) {
            if (theMin > vertexes[i] && find(Path.begin(), Path.end(), vertexes[i].first) == Path.end()) {
                theMin = vertexes[i];
            }
        }
        Path.push_back(theMin.first);
    }
    return Path;
}