//todo - Que: 16 Longest sub-array with given sum 
//todo - Link (https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505)

#include<bits/stdc++.h>
using namespace std;

//* This will works for both when array contains positive as well as negative numbers or zero also 
int lenOfLongestSubArrWithSumK(int *arr, int n, int k) {
  map<long long int, int> m;
  long long int sum = 0, length = 0;
  for(int i = 0 ; i < n ; i++) {
    sum += arr[i];
    if(m.find(sum) == m.end()) {
      m[sum] = i;
    }
    if(sum == k) {
      if(length < i + 1) {
        length = i + 1;
      }
    }
    if(m.find(sum - k) != m.end()) {
      int tempLen = i - m[sum - k];
      if(length < tempLen) {
        length = tempLen;
      }
    }
  }
  return length;
}
//* Time Complexity = O(n * log n)
//* Space Complexity = O(n)


//* If array contains only positives or zeros then we can use Two Pointer approach 
int maxLenSubArrWithSumK(int *arr, int n, int k) {
  int i = 0, j = 0;
  long long int sum = 0, length = 0;
  while(j < n) {
    sum += arr[j];
    while(sum > k && i <= j) {
      sum -= arr[i];
      i++;
    }
    if(sum == k) {
      if(length < ( j - i + 1)) {
        length = j - i + 1;
      }
    }
    j++;
  }
  return length;
}

int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  cout << "Length of longest sub-array with sum k = " << lenOfLongestSubArrWithSumK(arr, n, k) << endl;
  cout << "Length = " << maxLenSubArrWithSumK(arr, n, k) << endl;
}

//* Input 
// 4 3
// 2 0 0 3

//* Output 
// Length = 3