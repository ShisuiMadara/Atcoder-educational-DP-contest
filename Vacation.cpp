#include <bits/stdc++.h>

using namespace std;


int main(){
	
	int n;
	cin>>n;
	
	vector<vector<int>>arr;
	
	for(int i = 0; i<n; ++i){
		int a,b,c;
		
		cin>>a>>b>>c;
		
		arr.push_back({a,b,c});
	}
	
	vector<vector<int>>dp(n,vector<int>(3,0));
	
	dp[0] = arr[0];
	
	for(int i = 1; i<n; ++i){
		for(int j = 0; j<3; ++j){
			int add;
			if(j == 0) add = max(dp[i-1][1],dp[i-1][2]);
			else if(j == 1) add = max(dp[i-1][0],dp[i-1][2]);
			else add = max(dp[i-1][0],dp[i-1][1]);
			
			dp[i][j] += arr[i][j] + add;
		}
	}
	//for(auto&c : dp){
		//for(auto &d : c) cout<<d<<" ";
	//}
	cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
		
		
}

		
		

	
