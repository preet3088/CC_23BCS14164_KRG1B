class Solution {
public:
    int solve(vector<int>& arr, int k, int idx, vector<int> &dp)
    {
        int n = arr.size();
        if(idx==n) return 0;

        if(dp[idx] != -1) return dp[idx];
        int sum = 0, maxVal = 0 , ans = 0;
        int ul = min(n,idx+k);

        for(int i = idx; i < ul; i++)
        {
            maxVal = max(maxVal,arr[i]);
            int length = (i-idx+1);

            sum = (maxVal*length) + (solve(arr,k,i+1,dp));
            ans = max(ans,sum);
        }

        return dp[idx] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n+1,-1);
        return solve(arr,k,0,dp);
    }
};