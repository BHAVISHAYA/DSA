//todo - Que 8 Right rotate an array by k places 
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

void rightRotateAnArrByKPlaces(int *arr, int n, int k) {
  k = k % n; 
  k = n - k;
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
  rightRotateAnArrByKPlaces(arr, n, k);
  printArr(arr, n);
}