#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct Node {
    char vertex;
    int f, g;  // f = g + h, g = cost from start

    // For min-heap (smallest f first)
    bool operator>(const Node &other) const {
        return f > other.f;
    }
};

void aStar(map<char, vector<char>> &graph,
           map<pair<char,char>, int> &cost,
           map<char, int> &h,
           char start, char goal)
{
    // Priority queue: smallest f value on top
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<char> visited;

    // Push starting node: g=0, f = 0 + h[start]
    pq.push({start, h[start], 0});

    cout << "Expansion order: ";

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        cout << cur.vertex << " ";

        if (cur.vertex == goal) {
            cout << endl;
            return;
        }

        // Mark as visited *after* popping and printing
        visited.insert(cur.vertex);

        // Expand neighbors
        for (char neigh : graph[cur.vertex]) {
            if (!visited.count(neigh)) {  // Don't re-expand already visited
                int edge_cost = cost[{cur.vertex, neigh}];
                int new_g = cur.g + edge_cost;
                int new_f = new_g + h[neigh];
                pq.push({neigh, new_f, new_g});
            }
        }
    }

    cout << "(goal not reached)" << endl;
}

int main() {
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}}, {'E', {}}, {'F', {}}
    };

    map<pair<char,char>, int> cost = {
        {{'A','B'}, 1}, {{'A','C'}, 4},
        {{'B','D'}, 2}, {{'B','E'}, 5},
        {{'C','F'}, 3}
    };

    map<char, int> heuristic = {
        {'A', 7}, {'B', 6}, {'C', 2},
        {'D', 1}, {'E', 3}, {'F', 0}
    };

    aStar(graph, cost, heuristic, 'A', 'F');

    return 0;
}
