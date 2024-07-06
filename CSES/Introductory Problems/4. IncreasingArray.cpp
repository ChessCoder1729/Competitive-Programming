#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
const int N = 1e5;
// to comment multiple lines at once ctrl+/
 
 
int main(){
    fastio;
    int t; t = 1;
    while(t--){
        int n; cin >> n;
        vector <long long>a(n); long long ans = 0;
        for(int i = 0;i<n;i++) cin >> a[i];
        for(int i = 1;i<n;i++){
            if(a[i]<a[i-1]){
                ans += -a[i] + a[i-1]; a[i] = a[i-1];
            }
        }
        cout << ans;
        //cout << "----------------------------" << endl;
    }
}