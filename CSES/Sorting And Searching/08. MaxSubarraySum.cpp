#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
const int n = 1e5;
// to comment multiple lines at once ctrl+/
 
 
int main(){
    fastio;
    int n; cin >> n;
    vector <long long> a(n);
    for(int i = 0;i<n;i++) cin >> a[i];
    long long curr = a[0]; long long ans = a[0];
    for(int i = 1;i<n;i++){
        curr = max(curr+a[i],a[i]);
        ans = max(ans,curr);
    }
    cout << ans;
}