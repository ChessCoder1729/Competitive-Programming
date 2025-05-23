//  DONT FORGET TO RUN SIEVE
// Credits : NEAL's template
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1LL);
    smallest_factor.assign(maximum + 1, 0LL);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

// Determines whether n is prime in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(1) time.
bool is_prime(int64_t n) {
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);

    if (n <= sieve_max)
        return prime[n];

    for (int64_t p : primes) {
        if (p * p > n)
            break;

        if (n % p == 0)
            return false;
    }

    return true;
}

// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<int, int>> prime_factorize(int n) {
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<int, int>> result;

    if (n <= sieve_max) {
        while (n != 1) {
            int p = smallest_factor[n];
            int exponent = 0;

            do {
                n /= p;
                exponent++;
            } while (n % p == 0);

            result.emplace_back(p, exponent);
        }

        return result;
    }

    for (int p : primes) {
        if (int64_t(p) * p > n)
            break;

        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}

vector<int> generate_factors(const vector<pair<int, int>> &prime_factors, bool sorted = false) {
    static vector<int> buffer;
    int product = 1;

    for (auto &pf : prime_factors)
        product *= pf.second + 1;

    vector<int> factors = {1};
    factors.reserve(product);

    if (sorted)
        buffer.resize(product);

    for (auto &pf : prime_factors) {
        int p = pf.first;
        int exponent = pf.second;
        int before_size = factors.size();

        for (int i = 0; i < exponent * before_size; i++)
            factors.push_back(factors[factors.size() - before_size] * p);

        if (sorted && factors[before_size - 1] > p)
            for (int section = before_size; section < factors.size(); section *= 2)
                for (int i = 0; i + section < factors.size(); i += 2 * section) {
                    int length = min(2 * section, (int)(factors.size()) - i);
                    merge(factors.begin() + i, factors.begin() + i + section,
                          factors.begin() + i + section, factors.begin() + i + length,
                          buffer.begin());
                    copy(buffer.begin(), buffer.begin() + length, factors.begin() + i);
                }
    }

    return factors;
}
