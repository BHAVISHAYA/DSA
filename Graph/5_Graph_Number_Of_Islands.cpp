#include<bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<int>> &grid) {
  for(int i = 0 ; i < grid.size() ; i++) {
    for(int j = 0 ; j < grid[i].size() ; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int n, int m) {
  vis[row][col] = 1;
  for(int delRow = -1 ; delRow <= 1 ; delRow++) {
    for(int delCol = -1 ; delCol <= 1 ; delCol++) {
      int newRow = row + delRow;
      int newCol = col + delCol;
      // skip the current cell but allow all 8 neighbours (including orthogonal)
      if(row == newRow && col == newCol) {
        continue;
      }
      else {
        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0) {
          dfs(newRow, newCol, grid, vis, n, m);
        }
      }
    }
  }
}

int numberOfIslandsUsingDFS(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  int islands = 0;
  vector<vector<int>> vis(n, vector<int> (m, 0));
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if(grid[i][j] == 1 && vis[i][j] == 0) {
        dfs(i, j, grid, vis, n, m);
        islands++;
      } 
    }
  }
  return islands;
}

void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis) {
  vis[row][col] = 1;
  queue<pair<int, int>> q;
  q.push({row, col});
  while(!q.empty()) {
    int r = q.front().first; 
    int c = q.front().second; 
    q.pop();

    for(int delRow = -1 ; delRow <= 1 ; delRow++) {
      for(int delCol = -1 ; delCol <= 1 ; delCol++) {
        int newRow = r + delRow;
        int newCol = c + delCol;
        if(newRow == r && newCol == c) {
          continue;
        } else {
          if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
            vis[newRow][newCol] = 1;
            q.push({newRow, newCol});
          }
        }
      }
    }
  }
}

int numberOfIslandsUsingBFS(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  int islands = 0;
  vector<vector<int>> vis(n, vector<int> (m, 0));
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if(grid[i][j] == 1 && !vis[i][j]) {
        bfs(i, j, grid, vis);
        islands++;
      }
    }
  }
  return islands;
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
  printGrid(grid);
  cout << "Number of islands = " << numberOfIslandsUsingDFS(grid) << endl;
  cout << "Number of islands = " << numberOfIslandsUsingBFS(grid) << endl;
}
