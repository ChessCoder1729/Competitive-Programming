#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
    
ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
pair<ll,ll> euclid_gcd(ll a, ll b) { // ax + by = gcd(a,b)
    bool yes = false;
    if(a<b){ swap(a,b); yes = true;}
    ll x,y;
    if (b == 0) {x = 1, y = 0; return {x,y};}
    pair<ll,ll>p = euclid_gcd(b,a%b); ll x1 = p.first; ll y1 = p.second;
    x = y1;
    y = x1 - y1 * (a / b);
    if(yes) return {y,x};
    return {x,y};
}
ll qexp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}
vector<ll>divisors_till_n(int n){ 
// Very good for problems related to divisors, including isPrime factorisation
    vector<ll>max_div(n+1);
    for (ll i = 2; i <= n; i++) {
        if (max_div[i] == 0) { // i is a isPrime
            for (ll j = i; j <= n; j += i) { max_div[j] = i; }
        }
    }
    return max_div;
}
vector<int> phi_0_to_n(int n) {// Number of numbers copirme to n
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

// Time Complexity : O(N*log(log(N)))
vector<int> SieveOfEratosthenes(int n){
    vector<bool> isPrime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= n; i += p){
                isPrime[i] = false;
            }
        }
    }
    vector<int>primes;
    for(int i = 2;i<=n;i++){
        if(isPrime[i]){
            primes.pb(i);
        }
    }
    return primes;
}

// Time Complexity : O Nln(sqrt(N))
vector<ll> segmentedSieve(ll L, ll R) {// Inclusive of both L and R
    // generate all primes up to sqrt(R)
    ll lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<ll> primes;
    for (ll i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
    vector<char> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    vector<ll>isPrime;
    for(ll i = 0; i<=R-L;i++){
        if(isPrime[i]){
            isPrime.push_back(L+i);
        }
    }
    return isPrime;
}