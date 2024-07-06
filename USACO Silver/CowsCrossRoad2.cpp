#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n';
const int N = 1e5 + 1;
bool broken[N];

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

int main() {
    fastio;
    usaco("maxcross");
    int n,k,b;
    cin >> n >> k >> b;
    int temp;
    for(int i = 0;i<b;i++){
        cin >> temp;
        broken[temp] = true;
    }
    int ans = INT_MAX;
    int curr = 0;
    for(int i = 1;i<=k;i++){
        curr += broken[i];
    }
    ans = min(ans,curr);
    for(int i = 2;i<=n-k+1;i++){
        curr += broken[i+k-1];
        curr -= broken[i-1];
        ans = min(ans,curr);
    }
    cout << ans;
}

