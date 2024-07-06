#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false)
#define endl '\n';
int N = 1e6; 

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

int main() {
    //usaco("stacking");
    int n,k; cin >> n >> k;
    int l,r; vector <int> v(n);
    while(k--){
        cin >> l >> r; l--; r--; v[l]++;
        if(r!=n-1){
            v[r+1]--;
        }
    }
    int curr = 0;
    for(int i = 0;i<n;i++){
        curr += v[i];
        v[i] = curr;
    }
    sort(v.begin(),v.end());
    cout << v[n/2];
}

