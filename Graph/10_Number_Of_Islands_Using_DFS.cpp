#include<bits/stdc++.h>
using namespace std;

int delRow[] = { -1, 0, 1, 0 };
int delCol[] = { 0, 1, 0, -1 };

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis) {
  vis[row][col] = 1;
  for(int i = 0 ; i < 4 ; i++) {
    int newRow = row + delRow[i];
    int newCol = col + delCol[i];
    if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() &&  grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
      dfs(newRow, newCol, grid, vis);
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
  int islands = 0;
  vector<vector<int>> vis(n, vector<int> (m, 0));
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if(grid[i][j] == 1 && !vis[i][j]) {
        dfs(i, j, grid, vis);
        islands++;
      }
    }
  }
  cout << "Number of islands = " << islands << endl;
}
//* Time Complexity = O(N * M)
//* Space Complexity = O(N * M) [For vis array] + O(N * M) [Recursion call stack]