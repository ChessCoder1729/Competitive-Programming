#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m,n,k;
    cin >> m >> n >> k;
    char c[m][n];
    char ans[m*k][n*k];
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            for(int x = i*k;x<(i+1)*k;x++){
                for(int y = j*k;y<(j+1)*k;y++){
                    ans[x][y] = c[i][j];
                }
            }
        }
    }
    for(int i = 0;i<m*k;i++){
        for(int j = 0;j<n*k;j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    
}
