//todo - Que: 16 Longest sub-array with given sum 
//todo - Link 1 (https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505)
//todo - Link 2 (https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1)

#include<bits/stdc++.h>
using namespace std;

//* This will works for both when array contains positive as well as negative numbers or zero also 
int lenOfLongestSubArrWithSumK(long long int *arr, long long int n, long long int k) {
  map<long long int, long long int> m;
  long long int sum = 0, length = 0;
  for(long long int i = 0 ; i < n ; i++) {
    sum += arr[i];
    if(m.find(sum) == m.end()) {
      m[sum] = i;
    }
    if(sum == k) {
      length = max(length, i + 1);
    }
    if(m.find(sum - k) != m.end()) {
      long long int tempLen = i - m[sum - k];
      length = max(length, tempLen);
    }
  }
  return length;
}
//* Time Complexity = O(n * log n)
//* Space Complexity = O(n)


//* If array contains only positives or zeros then we can use Two Pointer approach 
int maxLenSubArrWithSumK(long long int *arr, long long int n, long long int k) {
  long long int i = 0, j = 0, sum = 0, length = 0;
  while(j < n) {
    sum += arr[j];
    while(sum > k && i <= j) {
      sum -= arr[i];
      i++;
    }
    if(sum == k) {
      length = max(length, j - i + 1);
    }
    j++;
  }
  return length;
}
//* Time Complexity = O(2n)
//* Space Complexity = O(1)

int main() {
  long long n, k;
  cin >> n >> k;
  long long arr[n];
  for(long long int i = 0 ; i < n ; i++) {
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