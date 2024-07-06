#include <bits/stdc++.h>
using namespace std;
const int n = 1000000007;

int main(){
	long long n;
	cin >> n;
	long long x;
	cin >> x;
	long long temp;
	vector <long long> c(n);
	for(int i = 0;i<n;i++){
		cin >> c[i];
	}
	sort(c.begin(),c.end());
	vector <long long>dp(x+1,0);
	dp[0] = 0;
	for(int i = 1;i<=x;i++){
		for(int j = 0;j<n;j++){
			if(i<c[j]) break;
			else dp[i] += dp[i-c[j]]+1;
		}
	}
	if(dp[x]==1e9) cout << -1;
	else cout << dp[x];

}