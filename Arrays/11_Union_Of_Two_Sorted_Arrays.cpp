//todo - Que 10 Union of two sorted arrays 
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

void printVector(vector<int> &arr) {
  int n = arr.size();
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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  vector<int> brr(m);
  for(int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  for(int i = 0 ; i < m ; i++) {
    cin >> brr[i];
  }
}