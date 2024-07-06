#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string s;
    cin >> s;
    string target;
    cin >> target;
    string ans;
    string temp;
    for(int i = 0;i<s.size();i++){
        temp += s[i];
        if(temp.size()>=target.size() and temp.substr(temp.size()-target.size())==target){
            temp.resize(temp.size()-target.size());
        }
    }
    cout << temp << endl;
}

