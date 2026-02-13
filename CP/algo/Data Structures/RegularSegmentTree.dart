struct node{ // Make changes here
    int sum;
    node(int x = 0){
        sum = x;
    }
};

class SegTree{
    #define lc x+1
    #define rc 2*(mid-start+1) + x

    int n; vector<node>t; vector<int>a;

    node unite(node a, node b){ // Make changes here
        return node(a.sum+b.sum);
    }

    private:
        void build(int x, int start, int end){ // Make changes here
            if(start==end){
                t[x] = node(a[start]);
                return;
            }
            int mid = (start+end)/2;
            build(lc,start,mid);
            build(rc,mid+1,end);
            t[x] = unite(t[lc],t[rc]);
            return;
        }

        void update(int x, int start, int end, int idx, int val){
            if(start==end){
                t[x] = node(val); return;
            }
            int mid = (start+end)/2;
            if(idx<=mid){
                update(lc,start,mid,idx,val);
            }
            else{
                update(rc,mid+1,end,idx,val);
            }
            t[x] = unite(t[lc],t[rc]); return;
        }

        node query(int x, int start, int end, int l, int r){
            if(l<=start and end<=r){
                return t[x];
            }
            int mid = (start+end)/2;
            if(r<=mid){
                return query(lc,start,mid,l,r);
            }
            if(mid<l){
                return query(rc,mid+1,end,l,r);
            }
            return unite(query(lc,start,mid,l,r),query(rc,mid+1,end,l,r));
        }

    public:
        SegTree(vector<int>& tmp){
            n = tmp.size();
            t.resize(2 * n);
            a = tmp;
            build(0, 0, n - 1);
        }

        node query(int l, int r){
            return query(0, 0, n - 1, l, r);
        }

        void update(int pos, int val){ // Make changes here
            update(0, 0, n - 1, pos, val);
        }
};
