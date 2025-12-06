//todo - Que 5 Left rotate the array by K places 
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

void leftRotateTheArrByKPlaces(int *arr, int n, int k) {
  k = k % n;
  reverse(arr, arr + k);
  reverse(arr + k, arr + n);
  reverse(arr, arr + n);
}
//* Time Complexity = O(2n)
//* Space Complexity = O(1)

int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  printArr(arr, n);
  leftRotateTheArrByKPlaces(arr, n, k);
  printArr(arr, n);
}