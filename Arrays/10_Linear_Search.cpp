//todo - Que 10 Linear Search 
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

bool isExist(int *arr, int n, int toFind) {
  for(int i = 0 ; i < n ; i++) {
    if(arr[i] == toFind) {
      return true;
    }
  }
  return false; 
}
//* Time Complexity = O(n)
//* Space Complexity = O(1)

int main() {
  int n, toFind;
  cin >> n >> toFind;
  int arr[n];
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  if(isExist(arr, n, toFind)) {
    cout << "Yes, exists" << endl;
  } else {
    cout << "Not Exists" << endl;
  }
}