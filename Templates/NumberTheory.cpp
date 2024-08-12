template <typename T>
struct numbertheory{ // while running just do basicnt<ll>
    T gcd(T a, T b){
        if(a<b) swap(a,b);
        return b == 0 ? a : gcd(b, a % b);
    }
    T lcm(T a, T b){
        return a/gcd(a,b)*b;
    }
    pair<T,T> euclid_gcd(T a, T b) { // ax + by = gcd(a,b)
        bool yes = false;
        if(a<b){ swap(a,b); yes = true;}
        T x,y;
        if (b == 0) {x = 1, y = 0; return {x,y};}
        pair<T,T>p = euclid_gcd(b,a%b); T x1 = p.first; T y1 = p.second;
        x = y1;
        y = x1 - y1 * (a / b);
        if(yes) return {y,x};
        return {x,y};
    }
    vector<T>divisors_till_n(int n){ 
    // Very good for problems related to divisors, including prime factorisation
        vector<T>max_div(n+1);
        for (T i = 2; i <= n; i++) {
            if (max_div[i] == 0) { // i is a prime
                for (T j = i; j <= n; j += i) { max_div[j] = i; }
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
    vector<T> segmentedSieve(T L, T R) {// Inclusive of both L and R
        // generate all primes up to sqrt(R)
        T lim = sqrt(R);
        vector<char> mark(lim + 1, false);
        vector<T> primes;
        for (T i = 2; i <= lim; ++i) {
            if (!mark[i]) {
                primes.emplace_back(i);
                for (T j = i * i; j <= lim; j += i)
                    mark[j] = true;
            }
        }
        vector<char> isPrime(R - L + 1, true);
        for (T i : primes)
            for (T j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
                isPrime[j - L] = false;
        if (L == 1)
            isPrime[0] = false;
        vector<T>prime;
        for(T i = 0; i<=R-L;i++){
            if(isPrime[i]){
                prime.pb(L+i);
            }
        }
        return prime;
    }
};  