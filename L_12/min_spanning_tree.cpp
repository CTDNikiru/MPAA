#include "min_spanning_tree.h"
#include <iostream>


using namespace std;

vector<int> shortest_path(const Graph& graph, int start_vertex, int end_vertex) {

	if (start_vertex == end_vertex || graph.get_vertices().size() == 0) {
		return {};
	}

	auto edges = graph.get_vertices();
	vector<pair<double, int>> temp; //DISTANCE | LAST EDGE
	vector<int> visited;

	for (int i = 0; i < edges.size(); i++) {
		temp.push_back(make_pair(DBL_MAX, -1));
	}

	temp[start_vertex] = make_pair(0, 0);
	visited.push_back(start_vertex);

	while (visited[visited.size() - 1] != end_vertex) {
		vector<pair<int, double>> connectedWithLast = graph.get_adjacent_edges(visited[visited.size() - 1]);
		pair<double, int> theMin = make_pair(DBL_MAX, -1);

		if (connectedWithLast.size() == 0) { //если вдруг вершина не имеет ребер
			return{};
		}


		//ћј√»я
		for (int i = 0; i < connectedWithLast.size(); i++) {

			bool isNotVisited = find(visited.begin(), visited.end(), connectedWithLast[i].first) == visited.end();

			int lastIndex = connectedWithLast[i].first;

			if (temp[lastIndex].first > connectedWithLast[i].second&& isNotVisited) {
				if (temp[lastIndex].first == DBL_MAX) {
					temp[lastIndex].first = connectedWithLast[i].second;
					temp[lastIndex].second = visited[visited.size() - 1];
				}
				else {
					temp[lastIndex].first = connectedWithLast[i].second;
					temp[lastIndex].second = visited[visited.size() - 1];
				}
			}

		}
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i].first < theMin.first && find(visited.begin(), visited.end(), i) == visited.end()) {
				theMin = temp[i];
				theMin.second = i;
			}
		}
		visited.push_back(theMin.second);
	}

	vector<int> vResult;
	pair<double, int> lastVisited = temp[end_vertex];

	while (lastVisited.second != start_vertex) {
		vResult.push_back(lastVisited.second);
		lastVisited = temp[lastVisited.second];
	}
	reverse(vResult.begin(), vResult.end());
	vResult.push_back(end_vertex);
	vResult.insert(vResult.begin(), start_vertex);

	return vResult;
}

vector<pair<int, int>> min_spanning_tree(const Graph& graph) {
	vector<pair<int, int>> result;

	vector<int> edges = graph.get_vertices();

	if (edges.size() == 0) {
		return result;
	}

	int startIndex;
	int minCount = INT_MAX;

	for (int i = 0; i < edges.size(); i++) {
		if (minCount > graph.get_adjacent_vertices(edges[i]).size()) {
			minCount = graph.get_adjacent_vertices(edges[i]).size();
			startIndex = edges[i];
		}
	}

	vector<vector<int>> vShortestPath;

	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] != startIndex) {
			vShortestPath.push_back(shortest_path(graph, startIndex, edges[i]));
		}
	}

	for (int i = 0; i < vShortestPath.size(); i++) {
		for (int j = 0; j < vShortestPath[i].size() - 1; j++) {
			pair<int, int> newPair = make_pair(vShortestPath[i][j], vShortestPath[i][j + 1]);
			if (find(result.begin(), result.end(), newPair) == result.end()) {
				result.push_back(newPair);
			}
		}
	}

	return result;
}