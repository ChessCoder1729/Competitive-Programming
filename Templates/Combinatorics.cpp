#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define long long int;
const ll mod = 1e9 + 7;

struct combi{ // DONT FORGET TO PRECOMPUTE BEFORE START OF INT_MAIN()
    ll qexp(ll a, ll b, ll m) {
        ll res = 1;
        while (b) {
            if (b % 2) res = res * a % m;
            a = a * a % m;
            b /= 2;
        }
        return res;
    }
    vector<ll> fact, invf, inv;
    void mod_inverse_till_n(ll n, ll prime){//For a range of numbers from 1-n
        inv.assign(n+1,1);
        for (ll i = 2; i <= n; i++) 
            inv[i] = inv[prime % i] * (prime - prime / i) % prime;      
    }
    ll modinverse(ll n, ll prime=mod){// Only for 1 number
        return qexp(n,prime-2,prime);
    }
    void precompute(ll n, ll prime) { // change depending on prime
        fact.assign(n + 1, 1); 
        for (ll i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % prime;
        invf.assign(n + 1, 1); 
        invf[n] = qexp(fact[n], prime - 2, prime);
        for (ll i = n - 1; i > 0; i--) invf[i] = invf[i + 1] * (i + 1) % prime;
    }
    ll ncr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invf[r] % mod * invf[n - r] % mod;
        //return fact[n] * qexp(fact[k], mod - 2, mod) % mod * qexp(fact[n - k], mod - 2, mod) % mod;
    }
    ll npr(ll n, ll r){ 
        if(r > n) return 0;
        return fact[n] * invf[r] %mod;
    }
    pair<ll, ll> fib (ll n) { // returns n^th and (n+1)^th fibonacci
        if (n == 0) return {0, 1};
        auto p = fib(n >> 1);
        int c = p.first * (2 * p.second - p.first);
        int d = p.first * p.first + p.second * p.second;
        if (n & 1)
            return {d, c + d};
        else
            return {c, d};
    }
};  