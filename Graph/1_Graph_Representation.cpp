//todo - Representation of graph 
 
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m; 

  //? Method 1 - Adjacency Matrix
  int adj[n + 1][m + 1];
  for(int i = 0 ; i < n + 1 ; i++) {
    for(int j = 0 ; j < m + 1 ; j++) {
       adj[i][j] = 0;
    }
  }

  for(int i = 1 ; i <= m ; i++) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  //* Space Complexity = O(n^2)


  cout << "\n" << "Adjacency Matrix Way" << endl;
  for(int i = 0 ; i < n + 1 ; i++) {
    for(int j = 0 ; j < m + 1 ; j++) {
       cout << adj[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;



  //? Method 2 - Adjacency List 
  vector<int> adj2[n + 1];
  for(int i = 0 ; i < m ; i++) {
    int u, v;
    cin >> u >> v; 
    adj2[u].push_back(v);
    adj2[v].push_back(u);
  }
  //* Space Complexity = O(2E) because every edge has two nodes 

  cout << "\n" << "Adjacency List Way " << endl;
  for(int i = 0 ; i < n + 1 ; i++) {
    for(auto &value: adj2[i]) {
      cout << value << " ";
    }
    cout << endl;
  }
  cout << endl;

}