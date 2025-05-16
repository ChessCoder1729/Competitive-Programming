// Works for functions which even if applied repeatedly continue working

vector<vector<int>> buildSparseTable(vector<int> &arr){
    int n = arr.size();

    // create the 2d table
    vector<vector<int>> lookup(n + 1,
                vector<int>(log2(n) + 1));

    // GCD of single element is element itself
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];

    // Build sparse table
    for (int j = 1; j <= log2(n); j++)
        for (int i = 0; i <= n - (1 << j); i++)
            lookup[i][j] = __gcd(lookup[i][j - 1],
            lookup[i + (1 << (j - 1))][j - 1]);

    return lookup;
}

// Returns GCD of arr[L..R]
int query(int L, int R, vector<vector<int>> & lookup) {

    // Find highest power of 2 that is smaller
    // than or equal to count of elements
    int j = (int)log2(R - L + 1);

    // Compute GCD of last 2^j elements with first
    // 2^j elements in range.
    return __gcd(lookup[L][j], lookup[R - (1 << j) + 1][j]);
}
