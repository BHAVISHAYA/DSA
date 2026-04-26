#include<bits/stdc++.h>
using namespace std;

void dfs(int startNode, vector<int> adj[], vector<int> &vis) {
  vis[startNode] = 1;
  for(auto &value: adj[startNode]) {
    if(!vis[value]) {
      dfs(value, adj, vis);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m; 
  vector<int> adj[n + 1];
  for(int  i = 0 ; i < m ; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> vis(n + 1, 0);
  int ct = 0;
  for(int  i = 0 ; i < n ; i++) {
    if(!vis[i]) {
      dfs(i, adj, vis);
      ct++;
    }
  }
  cout << "Number of connected components = " << ct << endl; 
}
//* Time Complexity = O(N) + O(V + 2E)
//* Space Complexity = O(N) + O(N)