#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int> (m, 0));
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      cin >> grid[i][j];
    }
  }
  
  // Create delRow[] and delCol[] to visit horizontally and vertically 
  int delRow[] = { -1, 0, 1, 0 };
  int delCol[] = { 0, 1, 0, -1 };

  // Create minTime and freshCt variable to store minimum time and to keep track of fresh oranges 
  int minTime = 0, freshCt = 0;

  // Create visited array to keep track of individual cell
  vector<vector<int>> vis(n, vector<int> (m, 0));

  // Create queue (obviously, because we are using BFS technique)
  // Queue Format [ {{row, col}, time} ]
  queue<pair<pair<int, int>, int>> q;

  // Now, traverse the grid to get count of fresh oranges and store all the initial rotten oranges 
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if(grid[i][j] == 1) {
        freshCt++;
      } else if(grid[i][j] == 2) {
        q.push({{i, j}, 0});
        vis[i][j] = 1;
      }
    }
  }

  while(!q.empty()) {
    int row = q.front().first.first;
    int col = q.front().first.second;
    int t = q.front().second;
    q.pop();

    minTime = max(minTime, t);

    for(int i = 0 ; i < 4 ; i++) {
      int newRow = row + delRow[i];
      int newCol = col + delCol[i];
      if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
        q.push({{newRow, newCol}, t + 1});
        vis[newRow][newCol] = 1;
        grid[newRow][newCol] = 2;
        freshCt--;
      }
    }
  }

  if(freshCt > 0) {
    cout << "Not Possible to rot all oranges" << endl;
  } else {
    cout << "Minimum time to rot all oranges = " << minTime << endl;
  }
}
//* Time Complexity = O(N * M)
//* Space Complexity = O(N * M) [For visited array] + O(N * M) [Queue space]