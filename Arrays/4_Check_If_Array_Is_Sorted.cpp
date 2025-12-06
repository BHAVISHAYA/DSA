//todo - Que 4 Check is array is sorted 
#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n) {
  if(n <= 1) return true; 
  for(int i = 0 ; i < n - 1 ; i++) {
    if(arr[i] > arr[i + 1]) return false; 
  }
  return true; 
}
//* Time Complexity = O(n)
//* Space Complexity = O(1)

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0 ; i  < n ; i++) {
    cin >> arr[i];
  }
  if(isSorted(arr, n)) {
    cout << "Yes, array is sorted" << endl;
  } else {
    cout << "Array is not sorted" << endl;
  }
}