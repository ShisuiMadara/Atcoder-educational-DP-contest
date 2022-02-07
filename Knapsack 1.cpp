    #include <bits/stdc++.h>
    using namespace std;
     
    const int MAX_N = 1e4 + 5;
     
     
    int main()
    {
     
    	long long n, capacity;
    	cin>>n>>capacity;
     
     
    	vector<long long>weights(n), values(n);
     
    	for(long long i = 0; i<n ;++i)
    	{
    		long long w,v;
    		cin>>w>>v;
     
    		weights[i] = w;
    		values[i] = v;
    	}	
     
    	vector<vector<long long>>dp(n+1, vector<long long>(capacity+1, 0));
     
    	for(long long item = 0; item <=n; ++item)
    	{
    		for(long long cap =0; cap <= capacity; ++cap)
    		{
    			if(cap == 0 || item == 0)
    			{
    				
    				continue;
    			}
    			
    			dp[item][cap] = dp[item-1][cap];
    			
    			if(cap - weights[item-1] >= 0)
    			{
    				dp[item][cap] = max(dp[item][cap], dp[item-1][cap-weights[item-1]] + values[item-1]);
    			}
    		}
    	}
     
    	cout<<dp[n][capacity];
    }
