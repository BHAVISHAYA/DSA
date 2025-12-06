//todo - Que 5 Left rotate the array by one place 
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

void leftRotateTheArrayByOnePlace(int *arr, int n) {
  int temp = arr[0];
  for(int i = 0 ; i < n  - 1 ; i++) {
    arr[i] = arr[i + 1];
  }
  arr[n - 1] = temp;
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
  leftRotateTheArrayByOnePlace(arr, n);
  printArr(arr, n);
}