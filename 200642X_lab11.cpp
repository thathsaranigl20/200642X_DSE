#include <iostream>
#include <vector>
#include <climits>

#define V 6 // Number of vertices in the graph

// Function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int findMinKey(const std::vector<int>& key, const std::vector<bool>& mstSet)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(const std::vector<int>& parent, const std::vector<std::vector<int>>& graph)
{
    std::cout << "Prim's Minimum Spanning Tree (Nodes and Weights):\n";
    for (int i = 1; i < V; i++) {
        std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

// Function to construct and print the MST for a graph represented using adjacency matrix representation
void primMST(const std::vector<std::vector<int>>& graph)
{
    std::vector<int> parent(V); // Array to store constructed MST
    std::vector<int> key(V, INT_MAX); // Key values used to pick minimum weight edge in cut
    std::vector<bool> mstSet(V, false); // To represent set of vertices not yet included in MST

    // Always include first vertex (Node 0) in MST
    key[0] = 0; // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of MST

    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = findMinKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main()
{
    std::vector<std::vector<int>> graph(V, std::vector<int>(V));

    std::cout << "Enter the adjacency matrix (6x6):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cin >> graph[i][j];
        }
    }

    primMST(graph);

    return 0;
}