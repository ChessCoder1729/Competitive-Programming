#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    long long k;
    cin >> n >> m>>k;
    vector <long long> a;
    vector <long long> b;
    long long temp;
    for(int i = 0;i<n;i++){
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0;i<m;i++){
        cin >> temp;
        b.push_back(temp);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int cnt = 0;
    bool flag;
    bool ans = true;
    int i = 0;
    int j = 0;
    while(i<n){
        if(j>=m){
            break;
        }
        else{
            if(a[i]<b[j]-k){
                i++;
            }
            else if(a[i]>b[j]+k){
                j++;
            }
            else{
                i++;
                j++;
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}