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
        if(n==1){
            cout << 1;
        }
        else if(n<=3){
            cout << "NO SOLUTION";
        }
        else if(n==4){
            cout << "2 4 1 3";
        }
        else{
            for(int i = n;i>=1;i-=2){
                cout << i << ' ';
            }
            for(int i = n-1;i>=1;i-=2){
                cout << i << ' ';
            }
        }
        //cout << "----------------------------" << endl;
    }
}