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
    usaco("guess");
    vector <vector <string>>v;
    vector <string>temp;
    string s;
    int n;
    cin >> n;
    set <string> cnt;
    int c[n];
    for(int i = 0;i<n;i++){
        cin >> s >> c[i];
        for(int j = 0;j<c[i];j++){
            cin >> s;
            temp.push_back(s);
        }
        v.push_back(temp);
        temp.clear();
    }
    int ans = INT_MIN;
    int x;
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            for(int k = 0;k<c[i];k++) cnt.insert(v[i][k]);
            for(int k = 0;k<c[j];k++) cnt.insert(v[j][k]);
            x = c[i] + c[j] - cnt.size() + 1;
            ans = max(ans,x);
            cnt.clear();
        }
    }
    cout << ans;
}

