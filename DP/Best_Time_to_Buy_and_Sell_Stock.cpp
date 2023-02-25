class Solution
{
public:
    // brute force
    int maxProfit(vector<int> &arr)
    {
        int maxPro = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[i])
                {
                    maxPro = max(arr[j] - arr[i], maxPro);
                }
            }
        }

        return maxPro;
    }

    // recursion+memoization
    int solve(int idx, int stock, int t, vector<int> &prices, vector<vector<int>> &dp)
    {
        // base case ->if we have no stock or we have completed at most one transaction
        if (idx == prices.size() || t == 1)
            return 0;
        if (dp[idx][stock] != -1)
            return dp[idx][stock];
        int profit = 0;
        if (stock == 0) // didnt bought anything yet no option for selling
        {
            int buy = solve(idx + 1, 1, t, prices, dp) - prices[idx];
            int dont_buy = solve(idx + 1, stock, t, prices, dp);
            profit = max(buy, dont_buy);
        }
        else if (stock == 1) // bought a stock previously we can sell it now
        {
            int sell = (prices[idx]) + solve(idx + 1, 0, t + 1, prices, dp);
            int dont_sell = solve(idx + 1, stock, t, prices, dp);
            profit = max(sell, dont_sell);
        }
        return dp[idx][stock] = profit;
    }

    // space optimization
    int maxProfit(vector<int> &arr)
    {
        int maxPro = 0;
        int n = arr.size();
        int minPrice = INT_MAX;

        for (int i = 0; i < arr.size(); i++)
        {
            minPrice = min(minPrice, arr[i]);
            maxPro = max(maxPro, arr[i] - minPrice);
        }

        return maxPro;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int t = 0;
        int res = solve(0, 0, t, prices, dp); // initially we dont have any stock
        return res;
    }
};