#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct combi{ // DONT FORGET TO PRECOMPUTE BEFORE START OF INT_MAIN()
    T qexp(T a, T b, T m) {
        T res = 1;
        while (b) {
            if (b % 2) res = res * a % m;
            a = a * a % m;
            b /= 2;
        }
        return res;
    }
    vector<T> fact, invf, inv;
    void mod_inverse_tiT_n(T n, T prime){//For a range of numbers from 1-n
        inv.assign(n+1,1);
        for (T i = 2; i <= n; i++) 
            inv[i] = inv[prime % i] * (prime - prime / i) % prime;      
    }
    T modinverse(T n, T prime){// Only for 1 number
        return qexp(n,prime-2,prime);
    }
    void precompute(T n) {
        fact.assign(n + 1, 1); 
        for (T i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
        invf.assign(n + 1, 1); 
        invf[n] = qexp(fact[n], mod - 2, mod);
        for (T i = n - 1; i > 0; i--) invf[i] = invf[i + 1] * (i + 1) % mod;
    }

    T ncr(T n, T r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invf[r] % mod * invf[n - r] % mod;
        //return fact[n] * qexp(fact[k], mod - 2, mod) % mod * qexp(fact[n - k], mod - 2, mod) % mod;
    }
    T npr(T n, T r){ 
        if(r > n) return 0T;
        return fact[n] * invf[r] %mod;
    }
    pair<T, T> fib (T n) { // returns n^th and (n+1)^th fibonacci
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