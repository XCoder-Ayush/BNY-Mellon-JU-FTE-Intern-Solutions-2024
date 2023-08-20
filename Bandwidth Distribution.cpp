BNY Mellon - Bandwidth Distribution

#define ll long 

ll getMaxRequests(vector<int> &bandwidth,vector<int> &request,int total_bandwidth){
    int n=request.size();
    vector<vector<ll>> dp(n,vector<ll>(total_bandwidth+1,0));
    for(int i=bandwidth[0];i<=total_bandwidth;i++){
        dp[0][i]=request[0];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=total_bandwidth;j++){
            if(j-bandwidth[i]>=0){
                dp[i][j]=max(dp[i][j],dp[i-1][j-bandwidth[i]] + request[i]);
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }else{
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
    }
    return dp[n-1][total_bandwidth];
}
