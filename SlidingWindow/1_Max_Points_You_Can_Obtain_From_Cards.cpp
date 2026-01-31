//todo - Que Link - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include<bits/stdc++.h>
using namespace std;

int maxPointsWeCanObtain(int arr[], int n, int k) {
  long long int leftSum = 0, rightSum = 0;
  for(int i = 0 ; i < k ; i++) {
    leftSum += arr[i];
  }

  long long int maxSum = leftSum + rightSum; 
  int r = n - 1;

  for(int i = k - 1 ; i >= 0 ; i--) {
    leftSum -= arr[i];
    rightSum += arr[r];
    maxSum = max(maxSum, leftSum + rightSum);
    r--;
  }

  return maxSum;
}
//* Time Complexity = O(k) + O(k) = O(2k)
//* Space Complexity = O(1)

int main() {
  int n, k; 
  cin >> n >> k; 
  int arr[n];
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  int maxPoints = maxPointsWeCanObtain(arr, n, k);
  cout << "Max Points = " << maxPoints << endl;
}