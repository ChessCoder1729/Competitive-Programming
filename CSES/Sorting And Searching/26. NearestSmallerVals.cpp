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
 
void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H
 
int main(){
    fastio; judge();
    int n; cin >> n;
    vector<ll>a(n);
    for(int i = 0;i<n;i++) cin >> a[i];
    stack<pair<ll,int>>s;
    for(int i = 0;i<n;i++){
        while(s.size()>0){
            ll tmp = s.top().first;
            if(tmp>=a[i]){
                s.pop();
            }
            else{
                break;
            }
        }
        if(s.size()==0){
            cout << 0 << ' ';
        }
        else{
            cout << s.top().second << ' ';
        }
        s.push({a[i],i+1});
    }
}