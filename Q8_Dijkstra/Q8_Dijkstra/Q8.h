#ifndef Q8_H
#define Q8_H

#include<iostream>
#include<vector>
using namespace std;

const int MAX_VERTICES=50;

class Graph
{
 public:
  void read(const char* filename);
  void print(ostream& out);
  int shortest(int v1, int v2, vector<int> &path);

  void eliminateNodesNotExistInVector(vector<int> &path);
  int minDistance(int dist[], bool boolSet[]);
  void fillZero(int fillZero);
 private:
  int size;
  int max_edge_length;
  int distance[MAX_VERTICES][MAX_VERTICES];
};
#endif
