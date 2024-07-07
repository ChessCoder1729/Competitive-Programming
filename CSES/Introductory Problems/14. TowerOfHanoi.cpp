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
void move(int n, int start, int end){
    if(n==1){
        cout << start << ' ' << end << endl;
        return;
    }
    if(start==1){
        if(end==2){
            move(n-1,1,3); cout << 1 << ' ' << 2 << endl; move(n-1,3,2);
        }
        else{
            move(n-1,1,2); cout << 1 << ' ' << 3 << endl; move(n-1,2,3);
        }
    }
    else if(start==2){
        if(end==1){
            move(n-1,2,3); cout << 2 << ' ' << 1 << endl; move(n-1,3,1);
        }
        else{
            move(n-1,2,1); cout << 2 << ' ' << 3 << endl; move(n-1,1,3);
        }
    }
    else{
        if(end==1){
            move(n-1,3,2); cout << 3 << ' ' << 1 << endl; move(n-1,2,1);
        }
        else{
            move(n-1,3,1); cout << 3 << ' ' << 2 << endl; move(n-1,1,2);
        }
    }
}

// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H

int main(){
    fastio; judge();
    int n; cin >> n;
    cout << (1<<n) - 1 << endl;
    move(n,1,3);
}