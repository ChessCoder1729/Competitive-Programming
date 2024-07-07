#include <bits/stdc++.h>
using namespace std;
const int n = 1000000007;

int main(){
	int n;
	cin >> n;
	int x;
	cin >> x;
	int temp;
	vector <int> c;
	for(int i = 0;i<n;i++){
		cin >> temp;
		c.push_back(temp);
	}
	sort(c.begin(),c.end());
	int ans[x+1];
	ans[0] = 0;
	for(int i = 1;i<c[0];i++){
		ans[i] = INT_MAX;
	}
	vector <int> v;
	for(int i = c[0];i<=x;i++){
		for(int j = 0;j<n;j++){
			if(c[j]<=i){
				v.push_back(ans[x-c[j]]);
			}
			else{
				break;
			}
		}
		temp = INT_MAX;
		for(int i = 0;i<v.size();i++){
			if(v[i]<temp){
				temp = v[i];
			}
			else{
				continue;
			}
		}
		ans[i] = temp;
	}
	cout << ans[x] << '\n';
}