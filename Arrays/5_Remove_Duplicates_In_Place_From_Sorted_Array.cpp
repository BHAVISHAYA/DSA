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

void removeDuplicateInPlace(int *arr, int n) {
  int i = 0, j = 0;
  while(j < n) {
    if(arr[i] == arr[j]) {
      j++;
    } 
    else {
      i++;
      swap(arr[i], arr[j]);
      j++;
    }
  }
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
  printArr(arr, n);
  removeDuplicateInPlace(arr, n);
  printArr(arr, n);
}