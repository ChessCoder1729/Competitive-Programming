#include<bits/stdc++.h>
using namespace std;
typedef long long int;

int gcd(int a, int b){
    if(a<b) swap(a,b);
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}
pair<int,int> euclid_gcd(int a, int b) { // ax + by = gcd(a,b)
    bool yes = false;
    if(a<b){ swap(a,b); yes = true;}
    int x,y;
    if (b == 0) {x = 1, y = 0; return {x,y};}
    pair<int,int>p = euclid_gcd(b,a%b); int x1 = p.first; int y1 = p.second;
    x = y1;
    y = x1 - y1 * (a / b);
    if(yes) return {y,x};
    return {x,y};
}
int qexp(int a, int b, int m) {
    int res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}
vector<int>divisors_tiint_n(int n){
// Very good for problems related to divisors, including isPrime factorisation
    vector<int>max_div(n+1);
    for (int i = 2; i <= n; i++) {
        if (max_div[i] == 0) { // i is a isPrime
            for (int j = i; j <= n; j += i) { max_div[j] = i; }
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
vector<int> segmentedSieve(int L, int R) {// Inclusive of both L and R
    // generate aint primes up to sqrt(R)
    int lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<int> primes;
    for (int i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
    vector<char> isPrime(R - L + 1, true);
    for (int i : primes)
        for (int j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    vector<int>isPrime;
    for(int i = 0; i<=R-L;i++){
        if(isPrime[i]){
            isPrime.push_back(L+i);
        }
    }
    return isPrime;
}

// Prime Factorization of a number in logn (Precomputation aintowed)
vector<int>spf(n+1,1);
void sieve(){
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) {
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1){
                    spf[j] = i;
                }
            }
        }
    }
}
vector<int> getFactorization(int x){
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
