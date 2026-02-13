int longestCommonSubsequence(string s1, string s2) {
    int dp[s1.size()][s2.size()];
    bool yes = false;
    for(int i = 0;i<s2.size();i++){
        if(s1[0]==s2[i]){
            yes = true;
        }
        dp[0][i] = yes;
    }
    for(int i = 1;i<s1.size();i++){
        for(int j = 0;j<s2.size();j++){
            if(s1[i]==s2[j]){
                if(j==0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
            }
            else{
                if(j==0){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    return dp[s1.size()-1][s2.size()-1];
}
