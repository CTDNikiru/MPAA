#include "tsp.h"
#include <algorithm>

using namespace std;

vector<int> perm(const Graph& graph, int start_vertex) {

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