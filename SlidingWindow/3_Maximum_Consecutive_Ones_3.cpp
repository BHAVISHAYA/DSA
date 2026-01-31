//todo - Que Link - https://leetcode.com/problems/max-consecutive-ones-iii/description/

//* We'll modify this question and convert it to -> longest subarray with at most K zeros 

#include<bits/stdc++.h>
using namespace std;

//? Brute Force Approach  
int maxConsOnesBFA(int *arr, int n, int k) {
  int maxLen = 0;
  for(int i = 0 ; i < n ; i++) {
    int zeros = 0;
    for(int j = i ; j < n ; j++) {
      if(arr[j] == 0) {
        zeros++; 
      }

      if(zeros <= k) {
        maxLen = max(maxLen, j - i + 1);
      } else {
        break;
      }
    }
  }
  return maxLen;
}
//* Time Complexity = O(N^2)
//* Space Complexity = O(1)



//? Better Approach
int maxConsOnesBA(int *arr, int n, int k) {
  int l = 0, r = 0, zeros = 0, maxLen = 0;
  while(r < n) {
    if(arr[r] == 0) {
      zeros++;
    }

    while(zeros > k) {
      if(arr[l] == 0) {
        zeros--;
      }
      l++;
    }

    maxLen = max(maxLen, r - l + 1);
    r++;
  }
  return maxLen;
}
//* Time Complexity = O(N + N) = O(2N)
//* Space Complexity = O(1)

// Worst Test Case 
// 1 1 1 1 1 1 0 0 
// k = 1



//? Most Optimal Approach 
int maxConsOnes(int *arr, int n, int k) {
  int l = 0, r = 0, maxLen = 0, zeros = 0;
  while(r < n) {
    if(arr[r] == 0) {
      zeros++;
    }

    if(zeros > k) {
      if(arr[l] == 0) {
        zeros--;
      }
      l++;
    }

    // Here, we need to make sure that we will compare only if zeros is less than equal to k
    if(zeros <= k) {
      maxLen = max(maxLen, r - l + 1);
    }
    r++;
  } 
  return maxLen;
}
//* Time Complexity = O(N)
//* Space Complexity = O(1)


int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  cout << maxConsOnesBFA(arr, n, k) << endl;
  cout << maxConsOnesBA(arr, n, k) << endl; 
  cout << maxConsOnes(arr, n, k) << endl;
}



// Input 1 
// 11 2
// 1 1 1 0 0 0 1 1 1 1 0

// Output 1 
// 6 

// Input 2 
// 19 3
// 0 0 1 1 0 0 1 1 1 0 1 1 0 0 0 1 1 1 1

// Output 2 
// 10