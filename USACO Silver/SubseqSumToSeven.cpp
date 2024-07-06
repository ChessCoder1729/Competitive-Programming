#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

int main() {
    fastio;
    usaco("div7");
    int n; cin >> n;
    long long sum[n];
    int ans = 0;
    long long temp; cin >> sum[0];
    for(int i = 1;i<n;i++){
        cin >> temp;
        sum[i] = temp + sum[i-1];
    }
    if(sum[0]%7==0){
        ans++;
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i-ans;j++){
            if((sum[i]-sum[j])%7==0){
                ans = i - j;
                break;
            }
        }
    }
    cout << ans;
}

