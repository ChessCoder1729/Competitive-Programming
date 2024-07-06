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
    usaco("paintbarn");
    int n,k; cin >> n >> k;
    int area[1001][1001];
    int x1, x2, y1, y2;
    for(int i = 0;i<n;i++){
        cin >> x1 >> y1 >> x2 >> y2; 
        area[x1][y1]++;
        area[x1][y2]--;
        area[x2][y1]--;
        area[x2][y2]++;
    }
    int ans = 0;
    for(int i = 0;i<1000;i++){
        for(int j = 0;j<1000;j++){
            if(i>0) area[i][j] += area[i-1][j];
            if(j>0) area[i][j] += area[i][j-1];
            if(i>0 and j>0) area[i][j] -= area[i-1][j-1];
            if(area[i][j]==k) ans++;
        }
    }
    cout << ans;
}

