// idx & -idx finds the lowest set bit in a number
// The number num stores prefix sum data in (num - (num&(-num)) , num]
// For update : https://www.youtube.com/live/kPaJfAUwViY?si=0vaUdqn6VGGTBn0M&t=926
// Walk a BIT : https://www.youtube.com/live/kPaJfAUwViY?si=AEQa0jS6s8mNisjc&t=2121

struct FenwickTree{
    vector<int>tree;
    int N;

    void update(int idx, int delta){
        if(idx >= N){
            return;
        }
        idx++;
        while(idx <= N){
            tree[idx-1] += delta;
            idx += (idx&(-idx));
        }
    }

    void update_range(int l, int r, int delta){
        update(l,delta);
        update(r+1,-1*delta);
    }

    int sum(int idx){
        idx++;
        int ans = 0;
        while(idx > 0){
            ans += tree[idx-1];
            idx -= (idx&(-idx));
        }
        return ans;
    }
    

    int query(int l, int r){
        if(l==0){
            return sum(r);
        }
        return sum(r) - sum(l-1);
    }

    void init(vector<int>&a){
        N = a.size();
        tree.resize(N,0);
        for(int i = 0;i<N;i++){
            update(i,a[i]);
        }
    }
};
