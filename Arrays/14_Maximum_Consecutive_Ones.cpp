//todo - Que: 14 Maximum consecutive ones 
#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(int *arr, int n) {
  int ans = 0, ct = 0;
  for(int i = 0 ; i < n ; i++) {
    if(arr[i] == 1) {
      ct++;
      ans = max(ans, ct);
    } else {
      ct = 0;
    }
  }
  return ans;
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
  cout << "Maximum consecutive ones = " << maxConsecutiveOnes(arr, n) << endl;
}