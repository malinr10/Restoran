#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>

struct Edge {
  int src;
  int dest;
  int weight;
};

class Graph {
public:
  Graph(int V);
  void addEdge(int src, int dest, int weight);
  void displayGraph();
  std::vector<int> findShortestPath(int src, int dest);

private:
  int V;
  std::vector<Edge> edges;
  std::vector<int> dijkstra(int src, int dest);
};

#endif
