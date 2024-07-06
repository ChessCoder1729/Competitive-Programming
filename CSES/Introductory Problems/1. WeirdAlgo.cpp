#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x;
    cin >> x;
    int n;
    cin >> n;
    vector <long long>v;
    long long temp;
    long long ans =0;
    for(int i = 0;i<n;i++){
        cin >> temp;
        v.push_back(temp);
        for(int i =  0;i<v.size();i++){
            if(v[i]==temp){
                ans = max(v[i]-v[i-1],ans);
                ans = max(v[i+1]-v[i],ans);
                cout << ans << endl;
            }
            else if(v[i]>temp) break;
            else continue;
        }
    }
}