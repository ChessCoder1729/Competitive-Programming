struct line {
	mutable int m, c, p;
	bool operator<(const line& l) const { return m < l.m; }
	bool operator<(int x) const { return p < x; }
};
// Returns max for a convex hull
struct LineContainer : multiset<line, less<>> {
	// (for doubles, use inf = 1/.0, ceil(a,b) = a/b)
	int div(int a, int b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b);
	}

    bool isect(iterator x, iterator y) {
		if (y == end()){
            x -> p = inf;
            return false;
        }
		if (x->m==y->m){
			x->p = -1*inf;
            if (x->c > y->c) {
                x->p = inf;
            }
        }
		else{
            x->p = div(y->c - x->c, x->m - y->m);
        }
		return x->p >= y->p;
	}
	void add(int m, int c) {
		auto it = insert({m, c, 0}) , next = it++, prev = next;
		while (isect(next, it)){
            it = erase(it);
        }
		if (prev != begin() && isect(--prev, next)){
            isect(prev, next = erase(next));
        }
		while ((next = prev) != begin() && (--prev)->p >= next->p){
            isect(prev, erase(next));
        }
	}
	int query(int x) {
		auto l = *lower_bound(x);
		return l.m * x + l.c;
	}
};
