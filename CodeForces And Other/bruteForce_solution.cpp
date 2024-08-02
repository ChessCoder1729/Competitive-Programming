#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  map<int, int> dp;
  for(int i = 0; i < n; i++){
    dp[a[i]] = dp[a[i] - 1] + 1;
  }
  
  int ma = INT_MIN;
  int ele = -1;
  
  for(auto it: dp){
    if(ma < it.second){
      ma = it.second;
      ele = it.first;
    }
  }
  
  int k = ele - ma + 1;
  
  cout << ma << '\n';
  
  for(int i = 0; i < n; i++){
    if(a[i] == k){
      cout << i + 1 << ' ';
      k++;
    }
  }
}