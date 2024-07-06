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
    usaco("hps");
    int n; cin >> n;
    int cnt1[n]; int cnt2[n]; int cnt3[n];
    char temp; cin >> temp;
    if(temp=='H'){
        cnt1[0] = 1;
        cnt2[0] = 0;
        cnt3[0] = 0;
    }
    else if(temp=='P'){
        cnt1[0] = 0;
        cnt2[0] = 1;
        cnt3[0] = 0;
    }
    else{
        cnt1[0] = 0;
        cnt2[0] = 0;
        cnt3[0] = 1;
    }
    for(int i = 1;i<n;i++){
        cin >> temp;
        if(temp=='H'){
        cnt1[i] = cnt1[i-1]+1;
        cnt2[i] = cnt2[i-1];
        cnt3[i] = cnt3[i-1];
        }
        else if(temp=='P'){
            cnt1[i] = cnt1[i-1];
            cnt2[i] = cnt2[i-1]+1;
            cnt3[i] = cnt3[i-1];
        }
        else{
            cnt1[i] = cnt1[i-1];
            cnt2[i] = cnt2[i-1];
            cnt3[i] = cnt3[i-1]+1;
        }
    }
    int ans = max(cnt1[n-1],max(cnt2[n-1],cnt3[n-1]));
    int t;
    for(int i = 0;i<n-1;i++){
        t = max(cnt1[i],max(cnt2[i],cnt3[i]));
        t += max(cnt1[n-1]-cnt1[i],max(cnt2[n-1]-cnt2[i],cnt3[n-1]-cnt3[i]));
        ans = max(ans,t);
    }
    cout << ans;
}

