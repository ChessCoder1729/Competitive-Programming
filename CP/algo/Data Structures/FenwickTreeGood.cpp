struct FenwickTree {
       int size_;
       vector<int> tree;

       FenwickTree() = default;

       explicit FenwickTree(int n) { build(n); }

       void build(int n) {
         size_ = n + 3;
         tree.assign(size_, 0);
       }

       // Returns prefix sum [0, idx]
       int prefix_sum(int idx) const {
         if (idx < 0) return 0;
         int total = 0;
         for (++idx; idx > 0; idx -= idx & -idx) {
           total += tree[idx];
         }
         return total;
       }

       // Returns range sum [left, right]
       int range_sum(int left, int right) const {
         return prefix_sum(right) - prefix_sum(left - 1);
       }

       // Returns value at position pos
       int get(int pos) const {
         return prefix_sum(pos) - prefix_sum(pos - 1);
       }

       // Increments position pos by value
       void increment(int pos, int value) {
         for (++pos; pos < size_; pos += pos & -pos) {
           tree[pos] += value;
         }
       }

       // Applies range update: add value to interval [l, r]
       void apply_range(int l, int r, int value) {
         increment(l, value);
         increment(r + 1, -value);
       }

       // Smallest index i such that prefix_sum(i) >= target
       int find_lower_bound(int target) {
         if (target <= 0) return 0;
         int idx = 0;
         for (int step = 1 << (31 - __builtin_clz(size_)); step > 0; step >>= 1) {
           if (idx + step < size_ && tree[idx + step] < target) {
             target -= tree[idx + step];
             idx += step;
           }
         }
         return idx;
       }

       // Smallest index i such that prefix_sum(i) > target
       int find_upper_bound(int target) {
         if (target < 0) return 0;
         int idx = 0;
         for (int step = 1 << (31 - __builtin_clz(size_)); step > 0; step >>= 1) {
           if (idx + step < size_ && tree[idx + step] <= target) {
             target -= tree[idx + step];
             idx += step;
           }
         }
         return idx;
       }
     };
