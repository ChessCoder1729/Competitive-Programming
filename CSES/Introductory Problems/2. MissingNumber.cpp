#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
const int N = 2e5+1;
// to comment multiple lines at once ctrl+/
bool vis[N];
 
 
int main(){
    fastio;
    int n; cin >> n;
    int temp;
    for(int i = 0;i<n;i++){
        cin >> temp;
        vis[temp] = true;
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            cout << i; break;
        }
    }
}