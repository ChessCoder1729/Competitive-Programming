

// DONT FORGET TO PRECOMPUTE BEFORE START OF INT_MAIN()
int qexp(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}
vector<int> fact, invf, inv;
void mod_inverse_till_n(int n, int prime = mod){//For a range of numbers from 1-n
    inv.assign(n+1,1);
    for (int i = 2; i <= n; i++)
        inv[i] = inv[prime % i] * (prime - prime / i) % prime;
}
int modinverse(int n, int prime=mod){// Only for 1 number
    return qexp(n,prime-2,prime);
}
void precompute(int n, int prime = mod) { // change depending on prime
    fact.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % prime;
    invf.assign(n + 1, 1);
    invf[n] = qexp(fact[n], prime - 2, prime);
    for (int i = n - 1; i > 0; i--) invf[i] = invf[i + 1] * (i + 1) % prime;
}
int ncr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n]%mod * invf[r] % mod * invf[n - r] % mod;
    //return fact[n] * qexp(fact[k], mod - 2, mod) % mod * qexp(fact[n - k], mod - 2, mod) % mod;
}
int npr(int n, int r){
    if(r > n) return 0;
    return fact[n] * invf[r] %mod;
}
pair<int, int> fib (int n) { // returns n^th and (n+1)^th fibonacci
    if (n == 0) return {0, 1};
    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}


