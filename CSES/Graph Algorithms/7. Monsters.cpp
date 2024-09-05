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
vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
#define pb push_back
const long long inf = 1e18;
const long long mod = 1e9+7;
const int N = 2e5;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}
 
// to comment multiple lines at once ctrl+/
// Find and replace Ctrl+H
vector<int>parent; bool done = false;
vector<ll> unweighted_djikstra(int src, vector<vector<pair<int,ll>>>&adj){
    vector<ll>dist(adj.size(),inf); 
    if(!done){
        parent.resize(adj.size());
    }
    deque <int> q;
    dist[src] = 0;
    q.push_back(src);
    while (!q.empty()){
        int v = q.front();
        q.pop_front();
        for(auto child : adj[v]){
            if (dist[child.first] > dist[v] + child.second){
                if(!done){
                    parent[child.first] = v;
                }
                dist[child.first] = dist[v] + child.second;
                if (child.second == 0)
                    q.push_front(child.first);
                else
                    q.push_back(child.first);
            }
        }
    }
    return dist;
}
 
void path(int val, int hero){
    vector<int>p;
    while(val!=hero){
        p.pb(val); val = parent[val];
    }
    p.pb(hero);
    reverse(p.begin(),p.end());
    cout << p.size()-1 << endl;
    for(int i = 0;i<p.size()-1;i++){
        if(p[i+1]==p[i]+1){
            cout << 'R';
        }
        else if(p[i+1]==p[i]-1){
            cout << 'L';
        }
        else if(p[i+1]>p[i]){
            cout << 'D';
        }
        else{
            cout << 'U';
        }
    }
}
 
int main(){
    fastio; judge();
    int n,m; cin >> n >> m; pair<int,int>hero; vector<int>mon;
    char c[n][m]; queue<pair<pair<int,int>,int>>q;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> c[i][j];
            if(c[i][j]=='A'){
                hero.first = i; hero.second = j;
            }
            if(c[i][j]=='M'){
				q.push({{i,j},'M'}); 
    	    }
        }
    }
	q.push({{hero.first,hero.second},'A'});
	while(!q.empty()){
		pair<pair<int,int>,char>x = q.front(); q.pop();
		char d = x.second;
		pair<int,int>coord = x.first;
		if(coord.first<n-1 and c[coord.first+1][coord.second]=='.'){
			c[coord.first+1][coord.second] = (d=='M'?'M':'D');
			q.push({{coord.first+1,coord.second},d});
		}
		if(coord.first>=1 and c[coord.first-1][coord.second]=='.'){
			c[coord.first-1][coord.second] = (d=='M'?'M':'U');
			q.push({{coord.first-1,coord.second},d});
		}
		if(coord.second>=1 and c[coord.first][coord.second-1]=='.'){
			c[coord.first][coord.second-1] = (d=='M'?'M':'L');
			q.push({{coord.first,coord.second-1},d});
		}
		if(coord.second<m-1 and c[coord.first][coord.second+1]=='.'){
			c[coord.first][coord.second+1] = (d=='M'?'M':'R');
			q.push({{coord.first,coord.second+1},d});
		}
	}
	pair<int,int>ans = {-1,-1};
	for(int j = 0;j<m;j++){
		if(c[n-1][j]!='M' and c[n-1][j]!='#' and c[n-1][j]!='.'){
			ans = {n-1,j};
		}
		if(c[0][j]!='M' and c[0][j]!='#' and c[0][j]!='.'){
			ans = {0,j};
		}
	}
	for(int i = 0;i<n;i++){
		if(c[i][m-1]!='M' and c[i][m-1]!='#' and c[i][m-1]!='.'){
			ans = {i,m-1};
		}
		if(c[i][0]!='M' and c[i][0]!='#' and c[i][0]!='.'){
			ans = {i,0};
		}
	}
	string s;
	if(ans.first==-1){
		pn; return 0;
	}
	py;
	while(c[ans.first][ans.second]!='A'){
		s += c[ans.first][ans.second];
		if(c[ans.first][ans.second]=='R'){
			ans.second--;
		}
		else if(c[ans.first][ans.second]=='L'){
			ans.second++;
		}
		else if(c[ans.first][ans.second]=='U'){
			ans.first++;
		}
		else{
			ans.first--;
		}
	}
	reverse(s.begin(),s.end());
	cout << s.size() << endl;
	cout << s;
}