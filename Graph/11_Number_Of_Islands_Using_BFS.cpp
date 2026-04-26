#include<bits/stdc++.h>
using namespace std;

int delRow[] = { -1, 0, 1, 0 };
int delCol[] = { 0, 1, 0, -1 };

void bfs(int startRow, int startCol, vector<vector<int>> &grid, vector<vector<int>> &vis) {
  queue<pair<int, int>> q;
  q.push({startRow, startCol});
  vis[startRow][startCol] = 1;
  while(!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    for(int i = 0 ; i < 4 ; i++) {
      int newRow = row + delRow[i];
      int newCol = col + delCol[i];

      if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
        q.push({newRow, newCol});
        vis[newRow][newCol] = 1;
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int> (m, 0));
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      cin >> grid[i][j];
    }
  }
  vector<vector<int>> vis(n, vector<int> (m, 0));
  int islands = 0;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if(grid[i][j] == 1 && !vis[i][j]) {
        bfs(i, j, grid, vis);
        islands++;
      }
    }
  }
  cout << "Number of islands = " << islands << endl;
}
//* Time Complexity = O(N * M)
//* Space Complexity = O(N * M) [For visited array] + O(N * M) [For queue space] (in worst case)