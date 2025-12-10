#include <iostream>
#include <map> 
#include <vector> 
using namespace std;

bool dls(map<char, vector<char>> &graph, char node, char target, int depth) {
    if (depth == 0)
        return node == target;
    if (depth > 0) {
        for (char child : graph[node]) {
            if (dls(graph, child, target, depth - 1))
                return true;
        }
    }
    return false;
}

bool ids(map<char, vector<char>> &graph, char start, char target, int maxDepth) {
    for (int depth = 0; depth <= maxDepth; depth++) {
        cout << "Depth Level: " << depth << endl;
        if (dls(graph, start, target, depth)) {
            cout << "Found: " << target << endl;
            return true;
        }
    }
    cout << "Not Found\n";
    return false;
}

int main() {
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}}, {'E', {}}, {'F', {}}
    };
    
    ids(graph, 'A', 'E', 3);
    return 0;
}
