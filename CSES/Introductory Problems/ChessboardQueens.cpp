#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n';


int main() {
    fastio;
    bool ok[8][8];
    char temp;
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            cin >> temp;
            ok[i][j] = (temp=='.');
        }
    }
    int cnt = 0;
    vector <int> v(8);
    set <int> s;
    for(int i = 0;i<8;i++) v[i] = i;
    do{
        bool yes = true;
        for(int i = 0;i<8;i++){
            if(ok[i][v[i]]==false) yes = false;
        }
        for(int i = 0;i<8;i++)s.insert(i+v[i]);
        if(yes) yes = (s.size()==8);
        s.clear();
        for(int i = 0;i<8;i++) s.insert(i-v[i]);
        if(yes) yes = (s.size()==8);
        s.clear();
        if(yes) cnt++;
    }while(next_permutation(v.begin(),v.end()));
    cout << cnt;
}