#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define pb push_back
const long long inf = 1e18;
const long long mod = 1e9+7;
const int N = 2e5;
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

int req(int start, ll target, vector<ll>a){
    ll curr = 0;
    for(int i = start;i<a.size();i++){
        if((curr+a[i])>=target){
            return i;
        }
        curr += a[i];
    }
    return -1;
}
vector<int>solve(vector<ll>a, vector<ll>b, vector<ll>c,ll target){
    int pos1 = req(0,target,a); int pos2 = req(pos1+1,target,b);
    if(pos2!=-1){
        int pos3 = req(pos2+1,target,c);
        if(pos3!=-1){
            return {pos1,pos2};
        }
    }
    return {-1};
}

int main(){
    fastio; judge();
    int t; cin >> t;
    while(t--){
       int n; cin >> n;
       vector<ll>a(n); vector<ll>b(n); vector<ll>c(n); ll tot = 0;
        for(int i = 0;i<n;i++){
            cin >> a[i]; tot += a[i];
        }
        for(int i = 0;i<n;i++) cin >> b[i];
        for(int i = 0;i<n;i++) cin >> c[i];
        ll target = tot/3 + min(tot%3,1LL);
        vector<vector<int>>v;
        v.push_back(solve(a,b,c,target));
        v.push_back(solve(a,c,b,target));
        v.push_back(solve(b,a,c,target));
        v.push_back(solve(b,c,a,target));
        v.push_back(solve(c,a,b,target));
        v.push_back(solve(c,b,a,target));
        bool ans = false;
        for(int i = 0;i<6;i++){
            vector<int>v1 = v[i];
            if(v1.size()==2){
                ans = true;
                int pos1 = v1[0]; int pos2 = v1[1];
                if(i==0){
                    cout << 1 << ' ' << pos1+1 << ' ';
                    cout << pos1 + 2 << ' ' << pos2 + 1 <<  ' ';
                    cout << pos2 +2 << ' ' << n << endl; 
                }
                else if(i==1){
                    cout << 1 << ' ' << pos1 + 1 << ' ';
                    cout << pos2 + 2 << ' ' << n << ' ';
                    cout << pos1 + 2 << ' ' << pos2+1 << endl; 
                }
                else if(i==2){
                    cout << pos1 + 2 << ' ' << pos2+1 << ' ';
                    cout << 1 << ' ' << pos1 + 1 << ' ';
                    cout << pos2+2 << ' ' << n << endl;
                }
                else if(i==3){
                    cout << pos2+2 << ' ' << n << ' ';
                    cout << 1 << ' ' << pos1 + 1 << ' ';
                    cout << pos1+2 << ' ' << pos2 +1 << endl;  
                }
                else if(i==4){
                    cout << pos1 + 2 << ' ' << pos2 + 1 <<  ' ';
                    cout << pos2 +2 << ' ' << n << ' ';
                    cout << 1 << ' ' << pos1+1 << endl;
                }
                else{
                    cout << pos2 +2 << ' ' << n << ' ';
                    cout << pos1 + 2 << ' ' << pos2 + 1 <<  ' ';
                    cout << 1 << ' ' << pos1+1 << endl;
                }
                break;
            }
        }
        if(!ans){
            cout << -1 << endl;
        }
    }
}