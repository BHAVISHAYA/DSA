//todo - BFS of a graph 
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int nodes) {
  vector<int> vis(nodes + 1, 0);
  queue<int> q;
  q.push(1);
  vis[0] = 1;
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    cout << node << " ";
    for(auto &value: adj[node]) {
      if(!vis[value]) {
        vis[value] = 1;
        q.push(value);
      }
    }
  }
  return; 
}
//* Space Complexity = O(N)
//* Time Complexity = O(N) + O(2E)

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
  bfs(adj, nodes);
}

//* Input 
// 5 4
// 0 1
// 0 2
// 0 3
// 2 4

//* Output 
// 0 1 2 3 4 