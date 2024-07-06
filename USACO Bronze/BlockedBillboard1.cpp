#include <bits/stdc++.h>
using namespace std;

int area(int x1, int y1,int x2,int y2){
    return (x2-x1)*(y2-y1);
}

int ans(int x1,int y1,int x2,int y2,int xb1,int yb1,int xb2,int yb2){
    return area(x1,y1,x2,y2)-max(0,min(x2,xb2)-max(x1,xb1))*max(0,min(y2,yb2)-max(y1,yb1));
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int xl1, yl1, xr1, yr1, xl2, yl2, xr2,yr2, xlb, ylb, xrb, yrb;
    cin >> xl1 >> yl1 >> xr1 >> yr1 >>  xl2 >> yl2>> xr2>>yr2>>xlb>>ylb>>xrb>>yrb;
    cout << ans(xl1,yl1,xr1,yr1,xlb,ylb,xrb,yrb) + ans(xl2,yl2,xr2,yr2,xlb,ylb,xrb,yrb);
    return 0;
}

