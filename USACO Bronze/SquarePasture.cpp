#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int minx = min(x1,x2);
	int maxx = max(x1,x2);
	int miny = min(y1,y2);
	int maxy = max(y1,y2);
	cin >> x1 >> y1 >> x2 >> y2;
	minx = min(minx,min(x1,x2));
	maxx = max(maxx,max(x1,x2));
	miny = min(miny,min(y1,y2));
	maxy = max(maxy,max(y1,y2));
	cout << max(maxx-minx,maxy-miny)*max(maxx-minx,maxy-miny);
}
