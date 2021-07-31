#include "perm.h"
#include <algorithm>

using namespace std;


vector<int> random_path(const Graph& g, int start_vertex) {
    vector<int> path = { start_vertex };
    int size = g.get_vertices().size();
    for (int i = 0; i < size && path.size() == i + 1; i++) {
        for (auto u : g.get_adjacent_vertices(path[i])) {
            if (find(path.begin(), path.end(), u) == path.end()) {
                path.push_back(u);
                break;
            }
        }
    }
    if (path.size() < size) {
        return vector<int> {};
    }
    else {
        return path;
    }
}

double tsp_path_length(const Graph& graph, const vector<int>& path) {
    double length = 0.0;
    int N = path.size();
    for (int i = 0; i < N; i++) {
        if (graph.has_edge(path[i % N], path[(i + 1) % N])) {
            length += graph.edge_weight(path[i % N], path[(i + 1) % N]);
        }
        else {
            return (double)INT_MAX;
        }
    }
    return length;
}

vector<int> transform(const vector<int>& path, int a, int b, int c, int d) {
    vector<int> new_path = {};
    int it_a = std::find(path.begin(), path.end(), a) - path.begin();
    for (int i = 0; i <= it_a; i++) {
        new_path.push_back(path[i]);
    }
    int it_b = std::find(path.begin(), path.end(), b) - path.begin();
    int it_c = std::find(path.begin(), path.end(), c) - path.begin();
    for (int i = it_c; i >= it_b; i--) {
        new_path.push_back(path[i]);
    }

    int it_d = std::find(path.begin(), path.end(), d) - path.begin();
    for (int i = it_d; i < path.size(); i++) {
        new_path.push_back(path[i]);
    }

    return new_path;

}

vector<int> two_opt_improve(const Graph& g, const vector<int>& path) {
    int size = path.size();
    double old_weight = 0;
    double new_weight = (double)INT_MAX;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 2; j < size - 1; j++) {
            if (g.has_edge(path[i], path[i + 1]) && g.has_edge(path[i], path[j + 1])) {
                old_weight = g.edge_weight(path[i], path[i + 1]) + g.edge_weight(path[j], path[j + 1]);
                if (g.has_edge(path[i], path[j]) && g.has_edge(path[i + 1], path[j + 1])) {
                    new_weight = g.edge_weight(path[i], path[j]) + g.edge_weight(path[i + 1], path[j + 1]);
                }
                if (new_weight < old_weight) {
                    return transform(path, path[i], path[i + 1], path[j], path[j + 1]);
                }
            }
        }
    }
    return path;
}


const vector<int> tsp(const Graph& graph, int start_vertex) {
    vector<int> current_path = random_path(graph, start_vertex);
    vector<int> improved_path;
    if (current_path.size() <= 1) {
        return  vector<int> {};
    }

    while (1) {
        improved_path = two_opt_improve(graph, current_path);
        if (tsp_path_length(graph, improved_path) < tsp_path_length(graph, current_path)) {
            current_path = improved_path;
        }
        else {
            int last = current_path.size() - 1;
            if (!graph.has_edge(start_vertex, current_path[last]))
            {
                return vector<int> {};
            }
            else {
                return current_path;
            }
        }
    }
}
