#include <bits/stdc++.h>
using namespace std;

set<set<char>>s[4];
void tst(char a,char b, char c){
	set<char>s1;
	s1.insert(a);
	s1.insert(b);
	s1.insert(c);
	s[s1.size()].insert(s1);
}

int main() {
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);
	char c[3][3];
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			cin >> c[i][j];
		}
	}
	tst(c[0][0],c[0][1],c[0][2]);
    tst(c[1][0],c[1][1],c[1][2]);
    tst(c[2][0],c[2][1],c[2][2]);
    tst(c[0][0],c[1][0],c[2][0]);
    tst(c[0][1],c[1][1],c[2][1]);
    tst(c[0][2],c[1][2],c[2][2]);
	tst(c[0][0],c[1][1],c[2][2]);
	tst(c[0][2],c[1][1],c[2][0]);
	cout << s[1].size() << endl << s[2].size();
}
