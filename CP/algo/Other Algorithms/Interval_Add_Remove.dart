// stores disjoint intervals in {intervals}
// Reference Q : https://codeforces.com/problemset/problem/915/E

/*
It is ammortized time complexity, because:
1. In add_range:
    Suppose initially you had k ranges, and you merge t of them, so you are left with (k-t+1) ranges
    Thus Time Complexity(k) = O(tlogt) + Time_Complexity((k-t+1))
    Thus, it is O(qlogq) ammortized
2. In remove_range:
    Similar to above
*/

struct IntervalManager{

    set<pair<int,int>>intervals_control,intervals;
    int len = 0; // total length of all intervals

    void add_range(int l, int r){
        if(r<l){
            return;
        }
        len += r-l+1;
        intervals.insert({l,r});
        intervals_control.insert({r,l});
    }

    void remove_range(int l, int r){
        if(r<l){
            return;
        }
        len -= r-l+1;
        intervals.erase(intervals.find({l,r}));
        intervals_control.erase(intervals_control.find({r,l}));
    }

    bool intersect(int l1, int r1, int l2, int r2){
        if(r1<l2 or r2<l1){
            return false;
        }
        return true;
    }

    void add(int l, int r){
        int curr_l = l, curr_r = r;

        while(true){
            if((int)(intervals_control.size())==0){
                add_range(curr_l,curr_r);
                return;
            }
            auto it = intervals_control.lower_bound({curr_l,0});
            if(it==intervals_control.end()){
                add_range(curr_l,curr_r);
                return;
            }
            auto tmp = *it;
            swap(tmp.first,tmp.second);
            if(!intersect(curr_l,curr_r,tmp.first,tmp.second)){
                add_range(curr_l,curr_r);
                return;
            }
            remove_range(tmp.first,tmp.second);
            curr_l = min(curr_l,tmp.first);
            curr_r = max(curr_r,tmp.second);
        }
    }

    void remove(int l, int r){
        int curr_l = l, curr_r = r;

        while(true){
            if((int)(intervals_control.size())==0){
                return;
            }
            auto it = intervals_control.lower_bound({curr_l,0});
            if(it==intervals_control.end()){
                return;
            }
            auto tmp = *it;
            swap(tmp.first,tmp.second);
            if(!intersect(curr_l,curr_r,tmp.first,tmp.second)){
                return;
            }
            remove_range(tmp.first,tmp.second);
            if(tmp.first<=curr_l and curr_r<=tmp.second){
                add_range(tmp.first,curr_l-1);
                add_range(curr_r+1,tmp.second);
                return;
            }
            if(tmp.first<=curr_l){
                add_range(tmp.first,curr_l-1);
                curr_l = tmp.second + 1;
                continue;
            }
            if(curr_r<=tmp.second){
                add_range(curr_r+1,tmp.second);
                curr_r = tmp.first - 1;
                continue;
            }
            // last case is if curr_l < tmp.first and tmp.second < curr_r, here we dont do anything because line 83.
        }
    }
};
