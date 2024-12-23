#include <bits/stdc++.h>
using namespace std;

/**
Maximum gain substring
You are given a string str consisting of lowercase English letters and
an array values of size 26 where value/i] denotes the value of ith
letter of English alphabet.
Task
You have to extract the substring such that the profit is maximum.
Profit of string is calculated as the product of the sum of values of
letters present in string and the index value of smallest character (in
English alphabets) present in the string.
Note: Index value of letters from a to z is 1 to 26 respectively.
**/

long long fun(string s, vector<int> vc) {
  
  map<int, vector<int>> mp;
  int n = s.length();
  
  for(int i=0; i<n; i++) {
    int letter = s[i] - 'a';
    mp[letter].push_back(i);
  }
  
  long long res = 0ll;
  
  
  for(auto it:mp) {
    int letter = it.first;
    vector<int> temp = it.second;
    vector<bool> vis(n, false);
    
    long long mx = 0ll;
    
    for(int j:temp) {
      if(vis[j] == false) {
        
        long long sm = 0;
        vis[j] = true;
        int d = s[j] - 'a';
        sm += vc[d];
        int left = j - 1, right = j + 1;
        
        while(left >= 0 and vis[left] == false and (s[left] - 'a') >= letter) {
          vis[left] = true;
          d = s[left] - 'a';
          sm += vc[d];
          left--;
        }
        while(right < n and vis[right] == false and (s[right] - 'a') >= letter) {
          vis[right] = true;
          d = s[right] - 'a';
          sm += vc[d];
          right++;
        }
        
        mx = max(mx, sm);
        
      }
      
    }  
    
    mx *= (letter+1);
    res = max(mx, res);
    
  }
  
  
  cout << res;
  
  
}

int main() {
  
  string s;
  cin >> s;
  vector<int> vc(26);
  for(int i=0; i<26; i++) {
    cin >> vc[i];
  }
  
  fun(s, vc);
  
  return 0;
  
}
