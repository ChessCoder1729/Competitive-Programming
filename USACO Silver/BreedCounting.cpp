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
    usaco("bcount");
    int n,q;
    cin >>n >> q;
    int cnt1[n]; int cnt2[n]; int cnt3[n];
    int temp;
    cin >> temp;
    if(temp==1){
        cnt1[0]=1;
        cnt2[0]=0;
        cnt3[0]=0;
    }
    else if(temp==2){
        cnt1[0]=0;
        cnt2[0]=1;
        cnt3[0]=0;
    }
    else{
        cnt1[0]=0;
        cnt2[0]=0;
        cnt3[0]=1;
    }
    for(int i = 1;i<n;i++){
        cin >> temp;
        if(temp==1){
            cnt1[i] = cnt1[i-1]+1;
            cnt2[i] = cnt2[i-1];
            cnt3[i] = cnt3[i-1];
        }
        else if(temp==2){
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
    int l,r;
    while(q--){
        cin >> l >> r;
        l--; r--;
        if(l>0){
            cout << cnt1[r] - cnt1[l-1] << ' ' << cnt2[r] - cnt2[l-1] << ' ' << cnt3[r] - cnt3[l-1] << endl;
        }
        else{
            cout << cnt1[r] << ' ' << cnt2[r] << ' ' << cnt3[r] << endl;
        }
    }
}

