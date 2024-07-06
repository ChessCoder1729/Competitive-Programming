#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.txt","w",stdout);
    int n;cin >> n;
    vector<ll>a(n);
    for(int i = 0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll curr = 0; ll ans = -1;
    for(int i = 0;i<n;i++){
        if((a[i])<=curr+1){
            curr += a[i];
        }
        else{
            ans = curr + 1; break;
        }
    }
    if(ans==-1) ans = curr + 1;
    cout << ans;
}   