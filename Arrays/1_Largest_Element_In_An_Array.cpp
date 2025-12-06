// todo - Que 1 Largest element in an array 
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0 ; i < n ; i++) {
    cin >> v[i];
  }
  int largestNum = INT_MIN; 
  for(int i = 0 ; i < n ; i++) {
    if (v[i] > largestNum) {
      largestNum = v[i];
    }
  }
  cout << "Largest number = " << largestNum << endl;
}
//* Time Complexity = O(n)
//* Space Complexity = O(1)