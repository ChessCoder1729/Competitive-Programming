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
    usaco("promote");
    int b,s,g,p; int fb,fs,fg,fp;
    cin >> b >> fb >> s >> fs >> g >> fg >> p >> fp;
    int inc1 = 0; int inc2 = 0; int inc3 = 0;
    int reg = b + s + g + p;
    int end = fb + fs + fg + fp;
    int extra = end - reg;
    b += extra;
    inc1 = b - fb;
    s += inc1;
    inc2 = s - fs;
    g += inc2;
    inc3 = g - fg;
    cout << inc1 << endl;
    cout << inc2 << endl;
    cout << inc3;
}

