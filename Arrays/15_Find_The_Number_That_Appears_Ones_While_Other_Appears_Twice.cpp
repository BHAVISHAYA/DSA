//todo - Que: 15 Find the number that appears ones, while other appears twice 
#include<bits/stdc++.h>
using namespace std;

// Using the concept of xor operator - as we know that it is all about odd one out 
int numberThatAppearOnes(int *arr, int n) {
  int xo = 0;
  for(int i = 0 ; i < n ; i++) {
    xo = xo ^ arr[i];
  }
  return xo; 
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
  cout << "Number that appear only one's = " << numberThatAppearOnes(arr, n) << "\n";
}