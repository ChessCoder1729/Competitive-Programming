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
    usaco("backforth");
    int a[10];
    int b[10];
    unordered_set <int> s;
    for(int i = 0;i<10;i++){
        cin >> a[i];
    }
    for(int j = 0;j<10;j++){
        cin >> b[j];
    }
    unordered_set <int> a2;
    for(int i = 0;i<9;i++){
        for(int j = i+1;j<10;j++){
            a2.insert(a[i]+a[j]);
        }
    }
    unordered_set <int> b2;
    for(int i = 0;i<9;i++){
        for(int j = i+1;j<10;j++){
            b2.insert(b[i]+b[j]);
        }
    }
    for(auto x1 : a2){
        for(auto x2 : b2){
            s.insert(x2-x1);
        }
    }
    s.insert(0);
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            s.insert(b[j]-a[i]);
        }
    }
    cout << s.size() << endl;
}

