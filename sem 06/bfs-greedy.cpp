#include <iostream>
#include <vector>
#include <queue>
#include <map>  
#include <set> 
using namespace std;

struct Node {
    char vertex;
    int h;
    bool operator>(const Node &other) const {
        return h > other.h;
    }
};

void bestFirst(map<char, vector<char>> &graph, map<char, int> &h, char start, char goal) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<char> visited;
    pq.push({start, h[start]});
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        cout << current.vertex << " ";
        if (current.vertex == goal) return;
        visited.insert(current.vertex);
        for (char neigh : graph[current.vertex]) {
            if (!visited.count(neigh)) {
                pq.push({neigh, h[neigh]});
            }
        }
    }
}

int main() {
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}}, {'E', {}}, {'F', {}}
    };
    map<char, int> heuristic = {
        {'A', 5}, {'B', 3}, {'C', 4},
        {'D', 1}, {'E', 2}, {'F', 0}
    };
    bestFirst(graph, heuristic, 'A', 'F');
    return 0;
}
