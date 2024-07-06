#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "Yes" << endl;
#define pn cout << "No" << endl;
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

int main(){
    fastio; judge();
    string s; cin >> s;
    int idx1, idx2;
    for(int i = 0;i<=2;i++){
        if(s[i]=='R'){
            idx1 = i;
        }
        if(s[i]=='M'){
            idx2 = i;
        }
    }
    if(idx1<idx2){
        py;
    }
    else{
        pn;
    }
}