#include<bits/stdc++.h>
using namespace std;

bool isCycleExist(int startNode, int parent, vector<int> adj[], vector<int> &vis) {
  vis[startNode] = 1;
  for(auto &value : adj[startNode]) {
    if(!vis[value]) {
      if(isCycleExist(value, startNode, adj, vis)) {
        return true; 
      }
    } else {
      if(vis[value] == 1 && value != parent) {
        return true; 
      }
    }
  }
  return false;
}

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
  bool isCyclePresent = false; 
  for(int i = 1 ; i <= n ; i++) {
    if(!vis[i]) {
      if(isCycleExist(i, 0, adj, vis)) {
        isCyclePresent = true; 
        break;
      }
    }
  }

  cout << "Is cycle present = " << (isCyclePresent == 1 ? "True" : "False") << endl;
}

//* Time Complexity = O(N + 2E) [DFS] + O(N) [For loop]
//* Space Complexity = O(N) [Recursion call stack] + O(N) [Visited array]