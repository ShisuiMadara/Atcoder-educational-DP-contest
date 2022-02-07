#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const int MAX_N = 1e5 +10, int_max = 0x3f3f3f3f;
const ll INF = 1e18;

vector<ll>arr(MAX_N);
vector<ll>dp(MAX_N, INT_MAX);

int main()
{
    int n;
    cin>>n;

    for(int i = 0; i<n; ++i)
    {
        cin>>arr[i];
    }

    dp[0] = 0;

    dp[1] = abs(arr[1] - arr[0]);

    for(int i = 2; i<n; ++i)
    {
        dp[i] = min(dp[i-1] + abs(arr[i]-arr[i-1]), dp[i-2]+abs(arr[i]-arr[i-2]));
    }

    cout<<dp[n-1];

    
}
