#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int node, int color, vector<vector<int>>& graph, vector<int>& colors) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[node][i] == 1 && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& colors, int V) {
    if (V == graph.size()) {
        return true;
    }

    for (int c = 1; c <= m; ++c) {
        if (isSafe(V, c, graph, colors)) {
            colors[V] = c;
            if (graphColoringUtil(graph, m, colors, V + 1)) {
                return true;
            }
            colors[V] = 0;
        }
    }

    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m, int N) {
    vector<int> colors(N, 0);
    if (graphColoringUtil(graph, m, colors, 0)) {
        return true;
    }
    return false;
}

int main() {
    int N = 4;
    int M = 3;
    vector<vector<int>> graph = { {0, 1, 0, 1},
                                  {1, 0, 1, 0},
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0} };
    cout << (graphColoring(graph, M, N) ? 1 : 0) << endl;  // Output: 1

    return 0;
}
