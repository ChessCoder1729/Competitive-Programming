#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    long long a,b;
    vector <vector <long long>>v;
    vector <long long> temp;
    for(int i = 0;i<n;i++){
        cin >> a >> b;
        temp.push_back(b);
        temp.push_back(a);
        v.push_back(temp);
        temp.clear();
    }
    sort(v.begin(),v.end());
    int cnt = 1;
    a = v[0][0];
    long long i = 1;
    while(i<n){
        if(a <= v[i][1]){
            a = v[i][0];
            cnt++;
            i++;
        }
        else{
            i++;
        }
    }
    cout << cnt;

    
}