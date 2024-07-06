#include <bits/stdc++.h>
using namespace std;

void c1(vector <int>&temp1){
	for(int i = 0;i<26;i++) temp1[i] = 0;
}
void c2(vector <int>&temp2){
	for(int i = 0;i<26;i++) temp2[i] = 0;
}

int main(){
	
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
	int n;
	cin >> n;
	int a[26];
	for(int i = 0;i<26;i++) a[i] = 0;
	string s1, s2;
	vector <int> temp1(26);
	vector <int> temp2(26);
	c1(temp1);
	c2(temp2);
	while(n--){
		cin >> s1 >> s2;
		for(int i = 0;i<s1.size();i++){
			temp1[int(s1[i])-97]++;
		}
		for(int i = 0;i<s2.size();i++){
			temp2[int(s2[i])-97]++;
		}
		for(int i = 0;i<26;i++){
			a[i] += max(temp1[i],temp2[i]);
		}
		c1(temp1);
		c2(temp2);
	}
	for(int i = 0;i<26;i++) cout << a[i] << endl;
}
