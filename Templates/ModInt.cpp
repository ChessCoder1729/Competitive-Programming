#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;

struct mint{long long val;};
mint to_mint(long long x){
    mint p; if(x>0){ p.val = x%mod; } else {p.val = mod - (-1*x)%mod;} return p;
}
ostream& operator<<(ostream&COUT, mint &a){COUT << a.val; return COUT;}
istream& operator>>(istream&CIN, mint &a){CIN >> a.val; return CIN;}
mint operator+(mint &a, mint &b) {return to_mint((a.val+b.val));}
void operator+=(mint &a, mint&b) {a = a+b;}
mint operator-(mint &a, mint&b){return to_mint(a.val*b.val);}
void operator-=(mint &a, mint &b){a = a-b;}
mint operator*(mint &a, mint &b){return to_mint(a.val*b.val);}
void operator*=(mint &a, mint &b){a = a*b;}
mint operator/(mint &a, mint &b){return to_mint((a.val/b.val));}