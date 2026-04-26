#include<bits/stdc++.h>
using namespace std;

void bfs(int startNode, vector<int> adj[], vector<int> & vis) {
  queue<int> q;
  q.push(startNode);
  vis[startNode] = 1;
  while(!q.empty()) {
    int node = q.front();
    q.pop();

    for(auto &value: adj[node]) {
      if(!vis[value]) {
        q.push(value);
        vis[value] = 1;
      }
    }
  }
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
  int ct = 0;
  for(int i = 0 ; i < n ; i++) {
    if(!vis[i]) {
      bfs(i, adj, vis);
      ct++;
    }
  }
  cout << "Number of connected components = " << ct << endl;
}
//* Time Complexity = O(N) + [O(N) + O(2E)]
//* Space Complexity = O(N) + O(N);