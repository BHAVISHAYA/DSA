#include<bits/stdc++.h>
using namespace std;

int delRow[] = { -1, 0, 1, 0 };
int delCol[] = { 0, 1, 0, -1 };

void dfs(int sr, int sc, int oldColor, int newColor, vector<vector<int>> &grid, vector<vector<int>> &vis) {
  grid[sr][sc] = newColor;
  vis[sr][sc] = 1;
  for(int i = 0 ; i < 4 ; i++) {
    int newRow = sr + delRow[i];
    int newCol = sc + delCol[i];
    if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == oldColor && !vis[newRow][newCol]) {
      dfs(newRow, newCol, oldColor, newColor, grid, vis);
    }
  }
}

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
  vector<vector<int>> image(n, vector<int> (m, 0));
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      cin >> image[i][j];
    }
  }
  vector<vector<int>> vis(n, vector<int> (m, 0));
  int oldColor = image[sr][sc];
  printGrid(image);
  dfs(sr, sc, oldColor, newColor, image, vis);
  printGrid(image);
}
//* Time Complexity = O(N * M)
//* Space Complexity = O(N * M) [For vis 2D array] + O(N * M) [For Recursion Call Stack]