#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    long long a,b;
    map <long long,long long>m;
    for(int i = 0;i<n;i++){
        cin >> a >> b;
        for(int j = a;j<=b;j++){
            m[j]++;
        }
    }
    long long ans = 0;
    for(auto x:m){
        ans = max(ans,x.second);
    }
    cout << ans;
}