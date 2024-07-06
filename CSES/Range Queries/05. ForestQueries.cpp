#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
const int n = 1e5;
// to comment multiple lines at once ctrl+/
 
 
int main(){
    fastio;
    int n,q; cin >> n >> q;
    char c[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> c[i][j];
        }
    }
    int ans[n][n]; ans[0][0] = 0;
    if(c[0][0]=='*'){
        ans[0][0] = 1;
    }
    for(int i = 1;i<n;i++){
        if(c[0][i]=='*'){
            ans[0][i] = ans[0][i-1] + 1; 
        }
        else{
            ans[0][i] = ans[0][i-1];
        }
    }
    for(int i = 1;i<n;i++){
        ans[i][0] = ans[i-1][0];
        if(c[i][0]=='*'){
            ans[i][0] = ans[i-1][0] + 1;
        }
        for(int j = 1;j<n;j++){
            ans[i][j] = ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
            if(c[i][j]=='*'){
                ans[i][j]++;
            }
        }
    }
    while(q--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; x2--; y1--; y2--;
        if(x1>0 and y1>0){
            cout << ans[x1-1][y1-1] + ans[x2][y2] - ans[x2][y1-1] - ans[x1-1][y2]  << endl; 
        }
        else if(x1==0){
            if(y1==0){
                cout << ans[x2][y2] << endl;
            }
            else{
                cout << ans[x2][y2] - ans[x2][y1-1]  << endl; 
            }
        }
        else{
            cout << ans[x2][y2] - ans[x1-1][y2] << endl;
        }
    }
}