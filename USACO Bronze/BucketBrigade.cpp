#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	char c[10][10];
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            cin >> c[i][j];
        }
    }
    int xb = -1;
    int yb = -1;
    int xr = -1;
    int yr = -1;
    int xl = -1;
    int yl = -1;
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            if(c[i][j]=='B'){
                xb = i;
                yb = j;
            }
            else if(c[i][j]=='R'){
                xr = i;
                yr = j;
            }
            else if(c[i][j]=='L'){
                xl = i;
                yl = j;
            }
        }
    }
    int ans;
    if(xb==xr and xr==xl){
        if(min(yb,yl)<yr and yr<max(yb,yl))ans = abs(yl-yb)+2;
        else ans = abs(yl-yb);
    }
    else if(yb==yr and yr==yl){
        if(min(xb,xl)<xr and xr<max(xb,xl))ans = abs(xl-xb)+2;
        else ans = abs(xl-xb);
    }
    else{
        ans = abs(xl-xb) + abs(yl-yb);
    }
    cout << ans-1 << endl;
}
