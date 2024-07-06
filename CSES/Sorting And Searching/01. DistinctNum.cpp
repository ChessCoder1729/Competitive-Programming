#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <long long> v;
    long long temp;
    for(int i = 0;i<n;i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(v[i]==v[i+1]){
            continue;
        }
        else{
            cnt++;
        }
    }
    cout << cnt;
}