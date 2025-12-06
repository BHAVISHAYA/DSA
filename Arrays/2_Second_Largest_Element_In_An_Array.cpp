// todo - Que 2 Second largest element in an array 
#include<bits/stdc++.h>
using namespace std;

int secondLargestElem(int arr[], int n) {
  int largest = INT_MIN; 
  int secondLargest = INT_MIN; 
  for(int i = 0 ; i < n ; i++) {
    if(arr[i] > largest) {
      secondLargest = largest;
      largest = arr[i];
    }
    else if(arr[i] != largest && arr[i] > secondLargest) {
      secondLargest = arr[i];
    }
  }

  // If second largest not exist 
  if(secondLargest == INT_MIN) {
    secondLargest = -1;
  }
  return secondLargest;
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

  int secondLargest = secondLargestElem(arr, n);
  cout << "Second largest number is " << secondLargest << endl;
}