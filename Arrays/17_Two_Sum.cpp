//todo - Que: 16 Two Sum (Find two numbers whose sum is equal to target)

#include<bits/stdc++.h>
using namespace std;

vector<int> findIndexes(int *arr, int n, int target) {
  unordered_map<int, int> m;
  for(int i = 0 ; i < n ; i++) {
    if(m.find(target - arr[i]) != m.end()) {
      return { i, m[target - arr[i]] };
    }
    if(m.find(arr[i]) == m.end())
    m[arr[i]] = i;
  } 
  return {}; 
}
//* Time Complexity = O(N) In case of unordered map 
//* Time Complexity = O(N * logN) In case of ordered map 


//* Using two pointer approach 
void findIndex(int *arr, int n, int target) {
  sort(arr, arr + n);
  int i = 0, j = n - 1;
  while(i < j) {
    if(arr[i] + arr[j] < target) {
      i++;
    } else if (arr[i] + arr[j] > target) {
      j--;
    } else {
      cout << i << " " << j << endl; 
      return; 
    }
  }
  cout << "Not exist" << endl;
  return;
}
//* Time Complexity = O(N * logN) for sorting + O(N) for traversing 
//* Space Complexity = O(1)


int main() {
  int n, target; 
  cin >> n >> target;
  int arr[n];
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  vector<int> index = findIndexes(arr, n, target); 
  if(index.size() == 0) 
  cout << "Not exist" << endl;
  else {
    sort(index.begin(), index.end());
    cout << "Indexes = " << index[0] << " " << index[1] << endl;
  }
  findIndex(arr, n, target);
}