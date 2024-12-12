struct Query { // to create vector just do vector<Mos::Query>q
    int l, r, idx;  
    
    bool operator<(const Query& q) const {
        int block_size = sqrt(2e5); // Set block size to sqrt(2e5)
        if (l / block_size != q.l / block_size)
            return l / block_size < q.l / block_size;
        return r < q.r;
    }
};
class Mos {
private:
    vector<int> a;
    int n;
    int block_size;

    // Function to add an element to the current range
    void add(int idx, vector<int>& op, int& current_answer) {
        op[a[idx]]++;
    }

    // Function to remove an element from the current range
    void remove(int idx, vector<int>& op, int& current_answer) {
        op[a[idx]]--;
    }

public:

    // Constructor to initialize the array and precompute the block size
    Mos(const vector<int>& a) : a(a), n(a.size()) {
        block_size = (int)sqrt(2e5);  // Set block size to sqrt(2e5)
    }
    
    // Function to answer range queries without sorting
    vector<int> processQueries(vector<Query>& queries) {
        vector<int> result(queries.size());
        sort(queries.begin(),queries.end());
        
        vector<int> op(n + 1, 0); // The operation on the element

        int left = 0, right = -1, current_answer = 0;

        // Process each query without sorting
        for (const auto& query : queries) {
            // Move the right pointer to the query's right boundary
            while (right < query.r) { add(++right, op, current_answer); }
            while (right > query.r) { remove(right--, op, current_answer); }

            // Move the left pointer to the query's left boundary
            while (left < query.l) { remove(left++, op, current_answer); }
            while (left > query.l) { add(--left, op, current_answer); }

            // Store the result for the current query
            result[query.idx] = current_answer;
        }

        return result;
    }
};
