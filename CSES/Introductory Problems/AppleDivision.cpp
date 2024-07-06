#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

long long ans = INT_MAX;
long long total = 0;

void solve(vector<long long>&p, int i, int n,long long currentsum){
    if(i==n){
        ans = min(ans,abs(total-2*currentsum));
    }
    else{
        solve(p,i+1,n,currentsum);
        currentsum += p[i];
        solve(p,i+1,n,currentsum);
        currentsum -= p[i];
    }
}

int main(){
    fastio;
    int n;
    cin >> n;
    vector <long long>p(n);
    for(int i = 0;i<n;i++){
        cin >> p[i];
        total += p[i];
    }
    solve(p,0,n,0);
    cout << ans;
}
