#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mod = 1e9+7;
const int N = 1e5;
// to comment multiple lines at once ctrl+/
 
 
int main(){
    fastio;
    string s;
    cin >> s;
    int n=s.size();
    int curr = 1; int best = 1; char c = s[0];
    for(int i = 1;i<n;i++){
        if(s[i]==c){
            curr++;
        }
        else{
            best = max(best,curr);
            c = s[i]; curr = 1;
        }
    }
    best = max(best,curr);
    cout << best;
}