#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector <string> s(n);
    for(int i = 0;i<n;i++) cin>>s[i];
    int curr = 0;
    int pos = 0;
    while(pos<n){
        if((curr + s[pos].size())>k){
            cout << endl;
            curr = 0;
        }
        else{
            if(curr==0){
                cout << s[pos];
            }
            else{
                cout << ' ' << s[pos];
            }
            curr += s[pos].size();
            pos++;
        }
    }
    return 0;
}
