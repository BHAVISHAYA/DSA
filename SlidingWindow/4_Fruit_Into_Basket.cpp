//todo - Que Link - https://leetcode.com/problems/fruit-into-baskets/description/

#include<bits/stdc++.h>
using namespace std;

int totalFruit(int *arr, int n) {
  unordered_map<int, int> m;
  int l = 0, r = 0, maxLen = 0;
  while(r < n) {
    while(m.size() > 2) {
      m[arr[l]]--;
      if(m[arr[l]] == 0) {
        m.erase(arr[l]);
      }
      l++;
    }
    m[arr[r]]++;
    if(m.size() <= 2)
    maxLen = max(maxLen, r - l + 1);
    r++;
  }
  return maxLen;
}
//* Time Complexity = O(N + N) = O(2N)
//* Space Complexity = O(3)

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  cout << "Total fruits = " << totalFruit(arr, n) << endl;
}