// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define pb push_back
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const ll inf = 1e18;
const ll mod = 1e9+7;


#ifndef ONLINE_JUDGE
#include "algo/Standard_Stuff/debug.cpp"
#else
#define debug(...) 42
#endif

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}

struct min_priority_queue{
    priority_queue<pair<int,int>>pq;
    void push(pair<int,int>x){
        pq.push({-1*x.first,x.second});
    }
    pair<int,int> top(){
        return {-1*pq.top().first,pq.top().second};
    }
    void pop(){
        pq.pop();
    }
    int size(){
        return pq.size();
    }
};

signed main(){
    fastio; judge();
    int n; cin >> n;
    vector<pair<pair<int,int>,int>>a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a.begin(),a.end());
    min_priority_queue pq;
    vector<int>ans(n);
    for(int i = 0;i<n;i++){
        if(pq.size()==0){
            ans[a[i].second] = 1;
            pq.push({a[i].first.second,1});
            continue;
        }
        else{
            auto tmp = pq.top();
            if(tmp.first<a[i].first.first){
                pq.pop();
                ans[a[i].second] = tmp.second;
                pq.push({a[i].first.second,tmp.second});
            }
            else{
                ans[a[i].second] = pq.size()+1;
                pq.push({a[i].first.second,pq.size()+1});
            }
        }
    }
    cout << *max_element(ans.begin(),ans.end()) << endl;
    for(auto x : ans) cout << x << ' ';
}
