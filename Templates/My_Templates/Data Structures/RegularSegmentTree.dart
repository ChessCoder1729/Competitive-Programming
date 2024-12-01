struct node{ // Make changes here
    int sum;
};

class SegTree{
    #define lc x+1
    #define rc 2*(mid-start+1) + x
    
    int n; vector<node>t; vector<int>a;

    node unite(node a, node b){ // Make changes here    
        node ans;
        ans.sum = a.sum + b.sum;
        return ans;
    }

    private:
        void build(int x, int start, int end){ // Make changes here
            if(start==end){
                t[x].sum = a[start];
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
                t[x].sum = val; return;
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

        void update_range(int x, int start, int end, int l, int r){
            // if the number of times we update each number is constant
            if(start>r or end<l) return;
            if(start==end){
                //a[start] = 
                return;
            }
            int mid = (start+end)/2; 
            // Insert some if condition, s.t. if operation performed, then no change
            update_range(lc,start,mid,l,r);
            update_range(rc,mid+1,end,l,r);
            t[x] = unite(t[lc],t[rc]); return;
            // Refer to https://codeforces.com/contest/1797/submission/290285800
        }

        node query(int x, int start, int end, int l, int r){
            if(l<=start and end<=r){
                return t[x];
            }
            int mid = (start+end)/2;
            if(r<=mid){
                return query(lc,start,mid,l,r);
            }
            else if(mid<l){
                return query(rc,mid+1,end,l,r);
            }
            else{
                return unite(query(lc,start,mid,l,r),query(rc,mid+1,end,l,r));
            }
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

        void update_range(int l, int r){ // Make changes here
            update_range(0, 0, n - 1, l, r);
        }

        void update(int pos, int val){ // Make changes here
            update(0, 0, n - 1, pos, val);
        }
};