/*
Works by uniting the answers for [l,l+power of 2) and (r-power of 2, r] such that the 2 intersect
So it works for all functions, such that repeatedly doing function doesnt change value
*/

struct SparseTable{

    int unite(int a, int b){
        return min(a,b);
    }

    int n;
    int m;
    vector<int>a;
    vector<int>log_2;
    vector<vector<int>>table;

    void init(int N){
        n = N;
        log_2.resize(n+1);
        log_2[0] = log_2[1] = 0;
        for(int i = 2;i<=n;i++){
            log_2[i] = log_2[i/2] + 1;
        }
        m = log_2[n]+1;
        table.resize(n,vector<int>(m,-1));
    }
    void build(vector<int>&vec){
        a = vec;
        pre();
    }

    void pre(){
        for(int i = 0;i<n;i++){
            table[i][0] = a[i];
        }
        for(int j = 1;j<m;j++){
            for(int i = 0;i<n;i++){
                if((i+(1<<(j)))-1>=n){
                    break;
                }
                table[i][j] = unite(table[i][j-1], table[i+(1<<(j-1))][j-1]);
            }
        }
    }

    void print_all(){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout << table[i][j] << ' ';
            }
            cout << endl;
        }
    }

    int query(int l, int r){
        if (l > r){
            swap(l, r);
        }
        int d = r - l + 1;
        int p = log_2[d];
        return unite(table[l][p],table[r-(1<<p)+1][p]);
    }
};
