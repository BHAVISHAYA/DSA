//todo - DFS of a graph 
#include<bits/stdc++.h>
using namespace std;

void dfs(int startNode, vector<int> &vis, vector<int> adj[]) {
  vis[startNode] = 1;
  cout << startNode << " ";
  for(auto &value: adj[startNode]) {
    if(!vis[value]) {
      dfs(value, vis, adj);
    }
  }
  return;
}
//* Space Complexity = O(N)
//* Time Complexity = O

int main() {
  int n, m; 
  cin >> n >> m; 
  vector<int> adj[n + 1];
  for(int i = 0 ; i < m ; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> vis(n + 1, 0);
  int startNode = 0;
  dfs(startNode, vis, adj);
}