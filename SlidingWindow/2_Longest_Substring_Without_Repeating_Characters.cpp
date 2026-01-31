//todo - Que Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include<bits/stdc++.h>
using namespace std;

int longSubStrWithOutRepeatingChars(string &str) {
  unordered_map<char, int> m;
  long long int l = 0, r = 0, maxLength = 0;
  
  // Traverse till 'r' reaches end
  while(r < str.size()) {
    if(m.find(str[r]) != m.end()) {
      if(m[str[r]] >= l) {
        l = m[str[r]] + 1;
      }
    }
    m[str[r]] = r;
    maxLength = max(maxLength, r - l + 1);
    r++;
  } 

  return maxLength; 
}
//* Time Complexity = O(N)
//* Space Complexity = For unordered map 



int longSubStrWithOutRepeatingChar(string &str) {
  int hsh[256] = { -1 };
  long long int l = 0, r = 0, maxLength = 0;
  
  // Traverse till 'r' reaches end
  while(r < str.size()) {
    if(hsh[str[r]] != -1) {
      if(hsh[str[r]] >= l) {
        l = hsh[str[r]] + 1;
      }
    }
    hsh[str[r]] = r;
    maxLength = max(maxLength, r - l + 1);
    r++;
  } 

  return maxLength; 
}
//* Time Complexity = O(N)
//* Space Complexity = O(256)

int main() {
  string str;
  cin >> str; 
  int length = longSubStrWithOutRepeatingChars(str);
  int len = longSubStrWithOutRepeatingChar(str);
  cout << "Length = " << len << endl;
}