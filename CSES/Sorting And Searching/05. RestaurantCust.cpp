#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
const long long inf = 1e18;
const long long mod = 1e9+7;
const int n = 2e5;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

void usaco(string s) {
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

ll binexpo(ll base, ll pow){
	if(pow==1) return base;
	if(pow==0) return 1;
	if(pow%2==0){
		return (binexpo(base,pow/2)*binexpo(base,pow/2))%mod;
	}
	else{
		return (base*binexpo(base,pow/2)*binexpo(base,pow/2))%mod;
	}
}
int main(){
	fastio;
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	int t; cin >> t;
	while(t--){
		ll l,r,k; cin >> l >> r >> k;
		ll temp = 9/k + 1;
		ll a = binexpo(temp,l); ll b = binexpo(temp,r);
		cout << b-a << endl;
	}
}