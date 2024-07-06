#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    long long max;
    cin >> max;
    vector <long long> a;
    long long temp;
    for(int i = 0;i<n;i++){
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end()); // 15 5 7 8 8 8 8 9 9 10 10
    int i = 0;
    int j = n-1;
    int cnt = 0;
    while(i<=j){
        if((a[i]+a[j])<=max){
            i++;
            j--;
            cnt++;
        }
        else{
            j--;
            cnt++;
        }
    }
    cout << cnt;
}