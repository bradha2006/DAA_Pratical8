#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS traversal
void BFS(int startNode, const vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;

    // Mark the starting node as visited and push it into the queue
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal starting from node " << startNode << ": ";

    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent has not been visited, mark it visited and enqueue it
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    // Adjacency list representation
    vector<vector<int>> adjList(vertices);

    cout << "Enter the edges (u v) meaning an undirected edge between u and v:" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        // Assuming 0-indexed vertices (0 to vertices - 1)
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove this line if the graph is directed
    }

    int startNode;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startNode;

    // Vector to keep track of visited nodes
    vector<bool> visited(vertices, false);

    // Perform BFS
    BFS(startNode, adjList, visited);

    return 0;
}
