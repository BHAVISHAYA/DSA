#include<bits/stdc++.h>
using namespace std;

void dfs(int startNode, vector<int> &vis, vector<int> adj[]) {
  vis[startNode] = 1;
  for(auto &value: adj[startNode]) {
    if(!vis[value]) {
      dfs(value, vis, adj);
    }
  }
}

int main() {
  int nodes, edges;
  cin >> nodes >> edges;
  vector<int> adj[nodes + 1];
  for(int i = 0 ; i < edges ; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> vis(nodes + 1, 0);
  int ans = 0;
  for(int i = 1 ; i <= nodes ; i++) {
    if(!vis[i]) {
      dfs(i, vis, adj);
      ans++;
    }
  }
  cout << "Number of province = " << ans << endl;
}

//* Time Complexity = O(N) [Outer loop] + O(N + 2E) [Overall DFS calls]
//* Space Complexity = O(N) [For vis array] + O(N) [Recursion stack space] 