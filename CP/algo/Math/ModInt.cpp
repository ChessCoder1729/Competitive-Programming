#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int mod = 1e9 + 7;

int mul(int x, int y) {
    return int((ull)x * y % mod);
}
int add(int x, int y) {
    return x + y - (x + y >= mod) * mod;
}
int sub(int x, int y) {
    return x - y + (x < y) * mod;
}

int qexp(int a, int b = mod-2, int m = mod) {
    if(mp.count(a)){
        return mp[a];
    }
    int res = 1;
    while (b) {
        if (b % 2) res =  mul(res,a);
        a = mul(a,a);
        b /= 2;
    }
    return res;
    return mp[a] = res;
}
