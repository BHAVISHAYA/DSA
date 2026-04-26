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

int main() {
  int n, m, sr, sc, newColor;
  cin >> n >> m >> sr >> sc >> newColor;
  vector<vector<int>> grid(n, vector<int> (m, 0));
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      cin >> grid[i][j];
    }
  }

  printGrid(grid);

  // Create a visited array
  vector<vector<int>> vis(n, vector<int> (m, 0));

  // Create a delRow and delCol array to visit horizontal and vertical neighbors
  int delRow[] = { -1, 0, 1, 0 };
  int delCol[] = { 0, 1, 0, -1 };

  // Save the old color for future use 
  int oldColor = grid[sr][sc];

  // Create a queue (obviously, because we are using BFS technique)
  queue<pair<int, int>> q;
  q.push({sr, sc});
  vis[sr][sc] = 1;
  grid[sr][sc] = newColor;

  while(!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    for(int i = 0 ; i < 4 ; i++) {
      int newRow = row + delRow[i];
      int newCol = col + delCol[i];
      if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == oldColor && !vis[newRow][newCol]) {
        q.push({newRow, newCol});
        vis[newRow][newCol] = 1;
        grid[newRow][newCol] = newColor;
      }
    }
  }

  printGrid(grid);
}
//* Time Complexity = O(N * M)
//* Space Complexity = O(N * M) [For visited array] + O(N * M) [For queue DS] (in Worst case)