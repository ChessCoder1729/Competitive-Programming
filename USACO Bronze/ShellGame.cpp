#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n][3];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<3;j++){
            cin >> a[i][j];
        }
    }
    int curr;
    int ans = 0;
    int pos;
    for(int i = 1;i<=3;i++){
        curr = 0;
        pos = i;
        for(int j = 0;j<n;j++){
            if(a[j][0]==pos or a[j][1]==pos){
                pos = a[j][0] + a[j][1] - pos;
            }
            if(pos==a[j][2]) curr++;
        }
        ans = max(curr,ans);
    }
    cout << ans << endl;
}

