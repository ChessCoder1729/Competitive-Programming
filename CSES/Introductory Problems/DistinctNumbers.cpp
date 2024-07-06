#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n';

int main() {
    fastio;
    set <long long>s;
    int n;
    cin >> n;
    int temp;
    for(int i = 0;i<n;i++){
        cin >> temp;
        s.insert(temp);
    }
    cout << s.size();
}
