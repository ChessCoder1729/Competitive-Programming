inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct Query {
    int l, r, idx;
    int64_t ord;

    inline void calc_order(){
        ord = hilbertOrder(l,r,21,0);
    }

    bool operator<(const Query& q) {
        return ord < q.ord;
    }
};

struct Mos {
    vector<int> a;
    int n;
    int current_answer;

    void add(){

    }

    void init(vector<int>&vec){
        a = vec;
        n = (int)(a.size());
    }

    vector<int> processQueries(vector<Query>& queries) {

        for(auto &q : queries){
            q.calc_order();
        }

        vector<int> result(queries.size());
        sort(all(queries));


        int left = 0, right = -1; current_answer = 0;

        for (const auto& q : queries) {

            while (right < q.r) {
                right++;
                add_right(right);
            }
            while (right > q.r) {
                remove_right(right);
                right--;
            }

            while (left < q.l) {
                remove_left(left);
                left++;
            }
            while (left > q.l) {
                left--;
                add_left(left);
            }

            result[q.idx] = ?;
        }

        return result;
    }
};
