#include "../include/Graph.h"
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

Graph::Graph(int V) : V(V) {}

void Graph::addEdge(int src, int dest, int weight) {
  edges.push_back({src, dest, weight});
}

void Graph::displayGraph() {
  for (const auto &edge : edges) {
    cout << "Source: " << edge.src << ", Destination: " << edge.dest
         << ", Weight: " << edge.weight << endl;
  }
}

std::vector<int> Graph::findShortestPath(int src, int dest) {
  return dijkstra(src, dest);
}

std::vector<int> Graph::dijkstra(int src, int dest) {
  vector<int> dist(V, INT_MAX);
  vector<int> prev(V, -1);
  dist[src] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, src});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (const auto &edge : edges) {
      if (edge.src == u) {
        int v = edge.dest;
        int weight = edge.weight;

        if (dist[u] + weight < dist[v]) {
          dist[v] = dist[u] + weight;
          prev[v] = u;
          pq.push({dist[v], v});
        }
      }
    }
  }

  vector<int> path;
  for (int at = dest; at != -1; at = prev[at]) {
    path.push_back(at);
  }
  reverse(path.begin(), path.end());

  if (path.size() == 1 && path[0] != dest) {
    return {};
  }

  return path;
}
