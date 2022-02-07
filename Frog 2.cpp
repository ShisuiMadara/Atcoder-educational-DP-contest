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

    int jump;
    cin>>jump;

    for(int i = 0; i< n; ++i)
    {
        cin>>arr[i];
    }

    dp[0] = 0;
    dp[1] = abs(arr[1]-arr[0]);

    for(int target = 2; target<n; ++target)
    {
        for(int jump_length = 1; jump_length <= jump; jump_length++)
        {
            if(target - jump_length >= 0)
            {
                dp[target] = min(dp[target], dp[target - jump_length] + abs(arr[target] - arr[target - jump_length]));
            }
        }
    }

    cout<<dp[n-1];
}
