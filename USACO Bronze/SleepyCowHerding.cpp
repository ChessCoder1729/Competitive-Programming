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
    usaco("herding");
    vector <long long>v(3);
    for(int i = 0;i<3;i++) cin >> v[i];
    sort(v.begin(),v.end());
    long long ans2 = max(v[1]-v[0],v[2]-v[1])-1;
    if(v[1]==v[0]+1 and v[2]==v[1]+1){
        cout << 0 << endl;
        cout << 0;
    }
    else{
        if(v[1]-v[0]==2 or v[2]-v[1]==2){
            cout << 1 << endl;
        }
        else if(v[1]-v[0]==1 and v[2]-v[1]==1){
            cout << 0 << endl;
        }
        else{
            cout << 2 << endl;
        }
        cout << ans2;
    }
}

