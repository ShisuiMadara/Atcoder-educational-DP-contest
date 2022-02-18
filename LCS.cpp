#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 1e4 + 10, int_max = 0x3f3f3f3f;
const ll INF = 1e18;

int dp[10000][10000];

int main()
{
    string s1, s2;
    cin>>s1>>s2;

    int n1,n2;
    n1 = s1.length();
    n2 = s2.length();

    for(int i = 1; i<=n1; ++i)
    {
        for(int j = 1; j<=n2; ++j)
        {
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
        }
    }

    int i = n1, j = n2;
    string ans;
    while(i>0 && j>0)
    {
        if(dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else if(dp[i][j] == dp[i][j-1])
        {
            j--;
        }
        else
        {
            ans += s2[j-1];
            i--;
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout<<ans;
}
