#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';

void usaco(string s) {
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

int main() {
    fastio;
    usaco("lineup");
    int n;
    cin >> n;
    string a, temp, b;
    vector <pair<string,string>>cows;
    for(int i = 0;i<n;i++){
        cin >> a >> temp >> temp >> temp >> temp >> b;
        cows.push_back({a,b});
    }
    vector <string> v(8);
    v[0] = "Beatrice"; v[1] = "Belinda"; v[2] = "Bella";
    v[3] = "Bessie"; v[4] = "Betsy"; v[5] = "Blue"; v[6] = "Buttercup";
    v[7] = "Sue";
    do{
        bool ans = true;
        int pos1, pos2;
        for(auto x : cows){
            for(int i = 0;i<8;i++){
                if(x.first==v[i]) pos1 = i;
                if(x.second==v[i]) pos2 = i;
            }
            if(abs(pos1-pos2)!=1){
                ans = false;
                break;
            }
        }
        if(ans){
            for(int i = 0;i<8;i++) cout << v[i] << endl;
            break;
        }
    }while(next_permutation(v.begin(),v.end()));
    
}

