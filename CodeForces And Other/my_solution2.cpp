#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define pb push_back
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 2e5;
// Check for queue, priorioty_queue, stack, ordered_set solutions
// stack => LIFO (whatever goes in last comes out last)
// queue => FIFO (whatever goes in first comes out first)
// priority_queue => Dynamic queries of minimum/maximum
// ordered_set => set in vector form
//[order_of_key(k) gives number of elements less than k, while find_by_order(i) gives i^th element]

// To comment multiple lines : ctrl + /
// To find and replace : ctrl+H

void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}

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
    vector<ll>prime;
    for(ll i = 0; i<=R-L;i++){
        if(isPrime[i]){
            prime.push_back(L+i);
        }
    }
    return prime;
}

bool check(int fa, int na, int da, int fc, int nc, int dc){
    if((fc-fa)%da!=0 or dc%da!=0){
        return false;
    }
    int pos_start = (fc-fa)/da, pos_end = (fc+dc*(nc-1)-fa)/da;
    if(0<=pos_start and pos_end<=na-1){
        return true;
    }
    return false;
}


int solve(int d1, int d){
    int d2 = 1; int p = 2; int curr1 = 1; int tmp = d;
    int curr2 = 1; int val = 1;
    while(true){
        if(d1==1){
            break;
        }
        curr1 = curr2 = 1;
        while(d1%p==0){
            curr1 *= p; d1 /= p;
        }
        while(tmp%p==0){
            curr2 *= p; tmp /= p;
        }
        if(curr1!=curr2){
            d2 *= curr2;
        }
        else{
            val *= curr1;
        }
        p++;
    }
    d1 = val; d2 *= tmp;
    return d2;
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
ll modinverse(ll n, ll prime=mod){// Only for 1 number
    return qexp(n,prime-2,prime);
}

ll prod(ll a, ll b){
    return (a*b)%mod;
}
ll add(ll a, ll b){
    return (a+b)%mod;
}

ll summation_inverse(ll d){
    ll sum = 0;
    for(int i = 1;i<=sqrt(d);i++){
        if((i*i)==d){
            sum = add(sum,modinverse(prod(i,i)));
        }
        else if(d%i==0){
            sum = add(sum,modinverse(prod(i,i)));
            sum = add(sum,modinverse(prod(d/i,d/i)));
        }
    }
    return sum;
}

void codeforces_solver(){
    int a1,d1,n1,a,d,n;
    cin >> a1 >> d1 >> n1 >> a >> d >> n;
    if(!check(a1,n1,d1,a,n,d)){
        cout << 0 << endl; return;
    }

    int prev = a - d, suff = a + n*d;
    if(prev<a1 or suff>a1+d1*(n1-1)){
        cout << -1 << endl; return;
    }
    // Everything alright
    int d2 = solve(d1,d);

    int ans = prod(d,d);
    ans = prod(ans,modinverse(prod(d2,d2)));
    ans = prod(ans,summation_inverse(d1));
    cout << ans << endl;
}

signed main(){
    fastio; judge();
    int tc = 1; cin >> tc;
    for(int testcase = 1;testcase<=tc;testcase++){
        //cout << "Case #" << testcase << ": ";
        codeforces_solver();
        
        
        // cout << "------------------------------------------" << endl;
    }
}