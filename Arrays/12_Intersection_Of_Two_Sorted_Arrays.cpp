//todo - Que 12: Intersection ot two sorted arrays 
#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n) {
  cout << "Array = [";
  for(int i = 0 ; i < n ; i++) {
    if(i != n - 1) {
      cout << arr[i] << ", ";
    } else {
      cout << arr[i] << "]";
    }
  }
  cout << "\n";
}

void printVector(vector<int> &arr) {
  int n = arr.size();
  cout << "Array = [";
  for(int i = 0 ; i < n ; i++) {
    if(i != n - 1) {
      cout << arr[i] << ", ";
    } else {
      cout << arr[i] << "]";
    }
  }
  cout << "\n";
}

vector<int> intersectionOfTwoSortedArrays(vector<int> &arr, vector<int> &brr) {
  vector<int> ans; 
  int i = 0, j = 0;
  while(i < arr.size() && j < brr.size()) {
    if(arr[i] < brr[j]) {
      i++;
    } 
    else if(arr[i] == brr[j]) {
      ans.push_back(arr[i]);
      i++;
      j++;
    } 
    else {
      j++;
    }
  }
  return ans; 
}
//* Time Complexity = O(n + m) 
//* Space Complexity = O(n + m), to return the answer and that will be the worst case 

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  vector<int> brr(m);
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  for(int i = 0 ; i < m ; i++) {
    cin >> brr[i];
  }
  vector<int> ans = intersectionOfTwoSortedArrays(arr, brr);
  cout << "1st ";
  printVector(arr);

  cout << "2nd ";
  printVector(brr);

  cout << "Intersection of two ";
  printVector(ans);
}