#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[100];
    int b[100];
    string s[100];
    for(int i = 0;i<n;i++) cin >> s[i] >> a[i] >> b[i];
    
    int mininc = -999999999; int maxinc = 999999999;
    for(int i = n-1;i>=0;i--){
        if(s[i]=="none"){
            mininc = max(mininc,a[i]);
            maxinc = min(maxinc,b[i]);
        }
        else if(s[i]=="on"){
            mininc -= b[i];
            maxinc -= a[i];
            mininc = max(0,mininc);
        }
        else{
            mininc += a[i];
            maxinc += b[i];
        }
    }
    cout << mininc << ' ' << maxinc << endl;
    mininc = -999999999; maxinc = 999999999;
    for(int i = 0;i<n;i++){
        if(s[i]=="none"){
            mininc = max(mininc,a[i]);
            maxinc = min(maxinc,b[i]);
        }
        else if(s[i]=="on"){
            mininc += a[i];
            maxinc += b[i];
        }
        else{
            mininc -= b[i];
            maxinc -= a[i];
            mininc = max(0,mininc);
        }
    }
    cout << mininc << ' ' << maxinc;
}

