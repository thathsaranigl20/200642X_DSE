#include <iostream>
#include <limits.h>

#define V 6

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}

// Function to print the constructed dista0 10 0 0 15 5

void printSolution(int dist[])
{
    for (int i = 0; i < V; i++)
        std::cout << "Distance of node" <<i << "="<< dist[i] << "\n";
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i
  
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in the shortest path tree or shortest distance from src to i is finalized
  
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
  
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
  
        sptSet[u] = true;
  
        for (int v = 0; v < V; v++)
  
            // Update dist[v] only if it is not in sptSet, there is an edge from u to v,
            // and the total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
  
    // Print the constructed distance array
   printSolution(dist);
}

int main()
{
    int graph[V][V];
    std::cout << "Enter the adjacency matrix (6x6):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cin >> graph[i][j];
        }
    }
  
    int source;
    std::cout << "Enter the source node: ";
    std::cin >> source;
  
    dijkstra(graph, source);
  
    return 0;
}
