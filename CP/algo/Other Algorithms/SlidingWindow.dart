/*
Sliding Window for Dynamic Cost function [in this code, for finding number of unordered pairs of equal values]
Useful when summation (l_(i+1)-l_i) + (r_(i+1)-r_i) is small
e.g. In Divide and Conquer
*/


int c2(int x){
    return (x*(x-1))/2;
}

struct Window{
    int l = 0;
    int r = -1;
    int cost = 0;
    int n;
    vector<int>freq;
    vector<int>a;

    void init(vector<int>&tmp){
        a = tmp;
        n = a.size();
        freq.resize(n+1);
    }

    void shift(int ql, int qr){
        while(l>ql){
            l--;
            cost -= c2(freq[a[l]]);
            freq[a[l]]++;
            cost += c2(freq[a[l]]);
        }
        while(l<ql){
            cost -= c2(freq[a[l]]);
            freq[a[l]]--;
            cost += c2(freq[a[l]]);
            l++;
        }
        while(r>qr){
            cost -= c2(freq[a[r]]);
            freq[a[r]]--;
            cost += c2(freq[a[r]]);
            r--;
        }
        while(r<qr){
            r++;
            cost -= c2(freq[a[r]]);
            freq[a[r]]++;
            cost += c2(freq[a[r]]);
        }
    }
};
