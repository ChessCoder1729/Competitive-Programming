vector<int>compress(vector<int>&col){
    vector<int>ans;
    map<int,int>mp; int curr = 1;
    for(auto x : col){
        if(mp[x]==0){
            mp[x] = curr;
            ans.pb(curr); curr++;
        }
        else{
            ans.pb(mp[x]);
        }
    }
    return ans;
}