#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    fastio;
    int n,m;
    cin >> n >> m;
    string plain[n];
    string spotty[n];
    for(int i = 0;i<n;i++) cin >> plain[i];
    for(int i = 0;i<n;i++) cin >> spotty[i];
    set <char> s1;
    set <char> s2;
    int cnt = 0;
    for(int i = 0;i<m;i++){
        bool a = true;
        for(int j = 0;j<n;j++){
            s1.insert(plain[j][i]);
        }
        for(int j = 0;j<n;j++){
            s2.insert(spotty[j][i]);
        }
        for(auto c : s1){
            if(s2.count(c)==0) continue;
            else{
                a = false;
                break;
            }
        }
        if(a) cnt++;
        s1.clear(); s2.clear();
    }
    cout << cnt;
    
}

