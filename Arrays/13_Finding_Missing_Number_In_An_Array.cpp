//todo - Que: 13 Finding missing number in an array 
#include<bits/stdc++.h>
using namespace std;

int findMissingNumber(int *arr, int n) {
  int xor1 = 0, xor2 = 0;
  for(int i = 0 ; i < n - 1 ; i++) {
    xor1 = xor1 ^ arr[i];
    xor2 = xor2 ^ (i + 1);
  }
  xor2 = xor2 ^ n; 
  return xor1 ^ xor2;
}
//* Time Complexity = O(n)
//* Space Complexity = O(1)

int main() {
  int n;
  cin >> n;
  int arr[n - 1];
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  int missingNumber = findMissingNumber(arr, n);
  cout << "Missing Number = " << missingNumber << endl;
}