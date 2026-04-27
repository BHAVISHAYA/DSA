#include<bits/stdc++.h>
using namespace std;

bool isCycleExist(int startNode, vector<int> adj[], vector<int> &vis) {
  // Create a queue (obviously, because we are using BFS technique)
  queue<pair<int, int>> q;
  q.push({startNode, 0});
  vis[startNode] = 1;

  while(!q.empty()) {
    int node = q.front().first;
    int parent = q.front().second; 
    q.pop();

    for(auto &value: adj[node]) {
      if(!vis[value]) {
        q.push({value, node});
        vis[value] = 1;
      } else {
        // Already visited and also not the parent 
        if(vis[value] == 1 && value != parent) {
          return true;
        }
      }
    }
  }

  return false; 
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
  bool isCyclePresent = false;
  for(int i = 1 ; i <= nodes ; i++) {
    if(!vis[i]) {
      if(isCycleExist(i, adj, vis)) {
        isCyclePresent = true;
        break;
      }
    }
  }

  cout << "Is cycle present = " << (isCyclePresent == 1 ? "true" : "false") << endl;
}

//* Time Complexity = O(N + 2E)
//* Space Complexity = O(N) [Queue] + O(N) [For visited array] ~ O(N) 