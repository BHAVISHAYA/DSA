//todo - Representation of graph 
 
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m; 

  //? Method 1 - Adjacency Matrix
  int adj[n + 1][m + 1];
  for(int i = 0 ; i < m ; i++) {
    int u, v;
    cin >> u >> v; 
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  //* Space Complexity = O(n^2)



  //? Method 2 - Adjacency List 
  vector<int> adj2[n + 1];
  for(int i = 0 ; i < m ; i++) {
    int u, v;
    cin >> u >> v; 
    adj2[u].push_back(v);
    adj2[v].push_back(u);
  }
  //* Space Complexity = O(2E) because every edge has two nodes 
}