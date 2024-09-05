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
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 2e5;
vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void judge(){
	srand(time(NULL));
	#ifndef ONLINE_JUDGE
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	#endif
}
 
void usaco(string s) {
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

void join(ll u, ll v,vector<vector<ll>>&adj){
	adj[u].pb(v); adj[v].pb(u);
}

int main(){
	fastio; //judge();
	usaco("piggyback");
	ll b,e,p,n,m;
	cin >> b >> e >> p >> n >> m;
	vector<vector<ll>>adj(n);
	for(ll i = 0,u,v;i<m;i++){
		cin >> u >> v; join(u-1,v-1,adj);
	}
	vector<ll>dist1(n,inf); vector<ll>dist2(n,inf);
	vector<bool>vis(n,false);
	queue<ll>q; q.push(0);//b
	dist1[0] = 0; vis[0] = true;
	while(!q.empty()){
		ll node = q.front(); q.pop();
		for(auto child : adj[node]){
			if(!vis[child]){
				dist1[child] = dist1[node] + b; q.push(child);
				vis[child] = true;
			}
		}
	}
	q.push(1);
	for(ll i = 0;i<n;i++) vis[i] = false;
	dist2[1] = 0; vis[1] = true;
	while(!q.empty()){
		ll node = q.front(); q.pop();
		for(auto child : adj[node]){
			if(!vis[child]){
				dist2[child] = dist2[node] + e; q.push(child);
				vis[child] = true;
			}
		}
	}
	vector<ll>dist3(n,inf);
	for(ll i = 0;i<n;i++) vis[i] = false;
	q.push(n-1);
	dist3[n-1] = 0; vis[n-1] = true;
	while(!q.empty()){
		ll node = q.front(); q.pop();
		for(auto child : adj[node]){
			if(!vis[child]){
				dist3[child] = dist3[node] + p; q.push(child);
				vis[child] = true;
			}
		}
	}
	ll ans = inf;
	for(int i = 0;i<n;i++){
		ans = min(ans,dist1[i]+dist2[i]+dist3[i]);
	}
	cout << ans;
}