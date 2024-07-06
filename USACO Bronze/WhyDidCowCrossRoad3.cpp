#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n';

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

int main() {
    fastio;
    usaco("cowqueue");
    int n,a,b;
    cin >> n;
    vector <pair<int,int>>v;
    for(int i = 0;i<n;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(ans<=v[i].first){
            ans = v[i].first + v[i].second;
        }
        else{
            ans += v[i].second;
        }
    }
    cout << ans;
}