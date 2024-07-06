#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i<n;i++) cin >> a[i];
    int curr;
    int ans = INT_MAX;
    for(int i = 0;i<n;i++){
        curr = 0;
        for(int j = i+1;j<n;j++){
            curr += a[j]*(j-i);
        }
        for(int j = i-1;j>=0;j--){
            curr += a[j]*(n-i+j);
        }
        ans = min(ans,curr);
    }
    cout << ans << endl;
}

