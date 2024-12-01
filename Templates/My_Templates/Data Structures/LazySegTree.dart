struct node {
    long long sum;  // The sum of the range (used for sum queries)
};
 
struct lazyNode {
    bool is_set = false;  // Flag for set operation
    long long set_val = LLONG_MAX;  // Value for the set operation
    long long add_val = 0;  // Value for the add operation
};
 
class LazySegmentTree {
private:
    vector<node> tree;
    vector<lazyNode> lazy;
    int n;
    vector<int>a;
    
    #define mid (start+end)/2
    #define lc x + 1 
    #define rc 2*(mid-start+1)+x 
 
    node unite(node a, node b) {
        node ans;
        ans.sum = a.sum + b.sum;
        return ans;
    }
 
    void build(int x, int start, int end) {
        if (start == end) {
            tree[x].sum = a[start];  
        } 
        else{
            build(lc, start, mid);  
            build(rc, mid + 1, end); 
            tree[x] = unite(tree[lc], tree[rc]);  
        }
    }
 
    void push(int x, int start, int end) {
        if (lazy[x].is_set) {  
 
            tree[x].sum = (end - start + 1) * lazy[x].set_val;
 
            if (start != end) {  
                lazy[lc].is_set = true;
                lazy[rc].is_set = true;
                lazy[lc].set_val = lazy[rc].set_val = lazy[x].set_val;
                lazy[lc].add_val = lazy[rc].add_val = 0;
            }
 
            lazy[x].is_set = false;  
        } 
        tree[x].sum += (end - start + 1) * lazy[x].add_val;

        if (start != end) { 
            lazy[lc].add_val += lazy[x].add_val;
            lazy[rc].add_val += lazy[x].add_val;
        }

        lazy[x].add_val = 0; 
    }
 
    void update(int x, int start, int end, int l, int r, int add_value) {
        push(x, start, end); 
 
        if (l > r) {
            return;  
        }
 
        if (l <= start && end <= r) {
            if (add_value != 0) { 
                lazy[x].add_val += add_value;
            }
            push(x, start, end);  
            return;
        }
 
        update(lc, start, mid, l, min(r, mid), add_value);  
        update(rc, mid + 1, end, max(l, mid + 1), r, add_value);  
        tree[x] = unite(tree[lc], tree[rc]);  // Update current node using unite
    }
 
    void set(int x, int start, int end, int l, int r, int set_value) {
        push(x, start, end); 
 
        if (l > r) {
            return;  
        }
 
        if (l <= start && end <=r) {
 
            lazy[x].is_set = true;
            lazy[x].set_val = set_value;
            lazy[x].add_val = 0;  
            push(x, start, end);  
            return;
        }
 
        set(lc, start, mid, l, min(r, mid), set_value);  
        set(rc, mid + 1, end, max(l, mid + 1), r, set_value);  
        tree[x] = unite(tree[lc], tree[rc]); 
    } 
 
    node query(int x, int start, int end, int l, int r) {
        push(x, start, end);  
 
        if (l > r) {
            node result = {0};  
            return result;
        }
 
        if (l <= start && end<=r) {
            return tree[x];  
        }
 
        node left_result = query(lc, start, mid, l, min(r, mid));  
        node right_result = query(rc, mid + 1, end, max(l, mid + 1), r);  
        
        return unite(left_result, right_result); 
    }
 
 
public:
    LazySegmentTree(vector<long long>&tmp) {
        n = tmp.size();
        a = tmp;
        tree.resize(2 * n);
        lazy.resize(2 * n);
        build(0, 0, n - 1);  // Build the tree using the input array
    }
 
    void update(int l, int r, int add_value) {
        update(0, 0, n - 1, l, r, add_value);
    }
 
    void set(int l, int r, long long set_value) {
        set(0, 0, n - 1, l, r, set_value);
    }
 
    node query(int l, int r) {
        node result = query(0, 0, n - 1, l, r);
        return result;  // Return only the sum from the queried node
    }
};