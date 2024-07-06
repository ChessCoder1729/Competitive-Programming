#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;cin >> n;
    vector<ll>a(n);
    for(int i = 0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int mid = n/2;
    ll ans = 0;
    for(int i = 0;i<n;i++){
        ans += abs(a[i]-a[mid]);
    }
    mid--;
    ll ans2 = 0;
    for(int i = 0;i<n;i++){
        ans2 += abs(a[i]-a[mid]);
    }
    cout << min(ans,ans2);
