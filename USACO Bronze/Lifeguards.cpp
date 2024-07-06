#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

int main() {
    fastio;
    usaco("lifeguards");
    int n;
    cin >> n;
    int a[1001];
    int temp1, temp2;
    int cnt = 0;
    for(int i = 0;i<1001;i++) a[i] = INT_MAX;
    for(int i = 0;i<n;i++){
        cin >> temp1 >> temp2;
        for(int j = temp1;j<temp2;j++){
            if(a[j]==INT_MAX){
                a[j] = i;
            }
            else{
                a[j] = -1;
            }
        }
    }
    int b[n];
    for(int i = 0;i<n;i++) b[i] = 0;
        
    for(int i = 0;i<1001;i++){
        if(a[i]==INT_MAX) continue;
        else{
            cnt++;
            if(a[i]>=0)b[a[i]]++;
        }
    }
    int m = INT_MAX;
    for(int i = 0;i<n;i++){
        m = min(m,b[i]); 
    }
    cout << cnt -m;
}

