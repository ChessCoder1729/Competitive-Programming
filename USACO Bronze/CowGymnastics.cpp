#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

int main() {
    fastio;
    usaco("gymnastics");
    int k,n;
    cin >> k >> n;
    int a[k][n];
    int temp;
    for(int i = 0;i<k;i++){
        for(int j = 0;j<n;j++){
            cin >> temp;
            temp--;
            a[i][j] = temp;
        }
    }
    int cnt[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) cnt[i][j] = 0;
    }
    for(int i = 0;i<k;i++){
        for(int j = 0;j<n-1;j++){
            for(int l = j+1;l<n;l++){
                cnt[a[i][j]][a[i][l]]++;
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(cnt[i][j]==k) ans++;
        }
    }
    cout << ans << endl;
}

