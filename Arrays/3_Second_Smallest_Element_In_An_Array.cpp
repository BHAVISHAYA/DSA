//todo - Que 3 Second smallest element in an array 
#include<bits/stdc++.h>
using namespace std;

int secondSmallestNumber(int arr[], int n) {
  int smallest = INT_MAX;
  int secondSmallest = INT_MAX; 
  for(int i = 0 ; i < n ; i++) {
    if(arr[i] < smallest) {
      secondSmallest = smallest;
      smallest = arr[i];
    }
    else if(arr[i] != smallest && arr[i] < secondSmallest) {
      secondSmallest = arr[i];
    }
  }

  // if second smallest not exist 
  if(secondSmallest == INT_MAX) {
    return -1;
  }
  return secondSmallest;
}
//* Time Complexity = O(n)
//* Space Complexity = O(1)

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  int secondSmallest = secondSmallestNumber(arr, n); 
  cout << "Second smallest number is " << secondSmallest << endl;
}