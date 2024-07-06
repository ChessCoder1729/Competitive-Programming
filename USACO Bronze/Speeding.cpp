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
    usaco("speeding");
    int n,m;
    cin >> n >> m;
    int limit[100];
    int speed[100];
    int curr = 0;
    int temp1, temp2;
    for(int i = 0;i<n;i++){
        cin >> temp1 >> temp2;
        for(int j = curr;j<curr+temp1;j++){
            limit[j] = temp2;
        }
        curr += temp1;
    }
    curr = 0;
    for(int i = 0;i<m;i++){
        cin >> temp1 >> temp2;
        for(int j = curr;j<curr+temp1;j++){
            speed[j] = temp2;
        }
        curr += temp1;
    }
    int ans = 0;
    for(int i = 0;i<100;i++){
        ans = max(ans,speed[i]-limit[i]);
    }
    cout << ans;
}

