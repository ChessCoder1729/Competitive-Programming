/*
ID: chessco3
TASK: ride
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	string s1 , s2;
	cin >> s1 >> s2;
	int ans = 1;
	int ans2 = 1;
	for(int i = 0;i<s1.size();i++){
		ans = ans*(int(s1[i])-64);
		ans = ans%47;
	}
	for(int i = 0;i<s2.size();i++){
		ans2 = ans2*(int(s2[i])-64);
		ans2 = ans2%47;
	}
	if(ans==ans2) cout << "GO" << endl;
	else cout << "STAY" << endl;
}