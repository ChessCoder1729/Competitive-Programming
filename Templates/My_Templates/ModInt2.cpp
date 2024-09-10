ll add(ll a, ll b){
    return ((a%mod)+(b%mod))%mod;
}
ll prod(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}
ll qexp(ll a, ll b, ll m) {
        ll res = 1;
        while (b) {
            if (b % 2) res = prod(res,a);
            a = prod(a,a);
            b /= 2;
        }
        return res;
}
ll modinverse(ll n, ll prime=mod){// Only for 1 number
    return qexp(n,prime-2,prime);
}
 