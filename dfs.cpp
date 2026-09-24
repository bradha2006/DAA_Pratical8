#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Class representing a Graph using an adjacency list
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    // Constructor
    Graph(int vertices) {
        this->V = vertices;
        adj.resize(vertices);
    }

    // Function to add a directed edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v); // For undirected graph, add: adj[v].push_back(u);
    }

    // Iterative DFS algorithm using a stack
    void DFS(int startNode) {
        // Vector to keep track of visited nodes, initialized to false
        vector<bool> visited(V, false);
        
        // Explicit stack for DFS
        stack<int> s;

        // Push the starting node into the stack
        s.push(startNode);

        cout << "\nDepth-First Search Traversal starting from vertex " << startNode << ":\n";

        while (!s.empty()) {
            // Get the top element from the stack
            int curr = s.top();
            s.pop();

            // If the node has not been visited yet, process it
            if (!visited[curr]) {
                cout << curr << " ";
                visited[curr] = true;
            }

            // Push all unvisited adjacent neighbors of the current node onto the stack.
            // Pushing from right to left (reverse order) ensures they are popped 
            // in standard ascending order if the adjacency list is sorted.
            for (auto it = adj[curr].rbegin(); it != adj[curr].rend(); ++it) {
                int neighbor = *it;
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int vertices, edges;

    cout << "Enter the total number of vertices (0-indexed): ";
    cin >> vertices;

    cout << "Enter the total number of edges: ";
    cin >> edges;

    Graph g(vertices);

    cout << "Enter the edges (Format: source destination):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startNode;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startNode;

    if(startNode >= 0 && startNode < vertices) {
        g.DFS(startNode);
    } else {
        cout << "Invalid starting vertex!" << endl;
    }

    return 0;
}
