#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
const long long inf = 1e18;
const long long mod = 1e9+7;
const int n = 2e5;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
int main(){
    fastio;
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int n; cin >> n;
    queue<int>q;
    for(int i = 1;i<=n;i++){
        q.push(i);
    }
    bool tmp = false;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(tmp){
            cout << temp << ' ';
        }
        else{
            q.push(temp);
        }
        tmp = !tmp;
    }
}