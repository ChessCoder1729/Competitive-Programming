#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n';

bool chosen[8];
set <string>ans;
string perm;

int size(string s){
    int i = 0;
    while(s[i]) i++;
    return i;
}

void solve(string s, int n){
    if(size(perm)==n) ans.insert(perm);
    else{
        for(int i = 0;i<n;i++){
            if(chosen[i]) continue;
            else{
                chosen[i] = true;
                perm += s[i];
                solve(s,n);
                chosen[i] = false;
                perm.pop_back();
            }
        }
    }
}

int main() {
    fastio;
    string s;
    cin >> s;
    int n = size(s);
    solve(s,n);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << endl;
}
