#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector <long long>v(7);
    for(int i = 0;i<7;i++) cin >> v[i];
    sort(v.begin(),v.end());
    cout << v[0] << ' ' << v[1] << ' ' << v[6] - v[0] - v[1];
    return 0;
}
