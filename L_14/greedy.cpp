#pragma once
#include "graph.h"

#include <vector>

using namespace std;

inline
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