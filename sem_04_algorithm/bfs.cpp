#include <iostream>
#include <queue>

using namespace std;

// Define the maximum number of nodes in the graph
const int MAX_NODES = 9; // 0-8 for 9 nodes

// Function to perform BFS on a graph
void bfs(int graph[MAX_NODES][MAX_NODES], int start, int numNodes) {
    bool visited[MAX_NODES] = {false}; // Track visited nodes
    queue<int> q; // Queue for BFS

    visited[start] = true; // Mark the starting node as visited
    q.push(start); // Enqueue the starting node

    while (!q.empty()) {
        int current = q.front(); // Get the front node
        q.pop(); // Dequeue the front node
        cout << current + 4 << " "; // Print the current node (adding 4 to match the actual node value)

        // Explore all adjacent nodes
        for (int neighbor = 0; neighbor < numNodes; neighbor++) {
            // Check if there is an edge and if the neighbor has not been visited
            if (graph[current][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true; // Mark neighbor as visited
                q.push(neighbor); // Enqueue the neighbor
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0}, // Node 4 (0) -> 7 (1), 11 (2)
        {0, 0, 0, 1, 1, 0, 0, 0, 0}, // Node 7 (1) -> 5 (3), 3 (4)
        {0, 0, 0, 0, 0, 1, 1, 1, 0}, // Node 11 (2) -> 1 (5), 6 (6), 8 (7)
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, // Node 5 (3) -> No children
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, // Node 3 (4) -> No children
        {0, 0, 0, 0, 0, 0, 0, 0, 1}, // Node 1 (5) -> 12 (8)
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, // Node 6 (6) -> No children
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, // Node 8 (7) -> No children
        {0, 0, 0, 0, 0, 0, 0, 0, 0}  // Node 12 (8) -> No children
    };
    // https://github.com/samratpro/data_stracture_in_c/blob/master/sem_04_algorithm/matrix%20visual.png
    // Perform BFS starting from the root node (Node 4, index 0)
    cout << "BFS Traversal starting from node 4: ";
    bfs(graph, 0, MAX_NODES);
    cout << endl;

    return 0;
}
