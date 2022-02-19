#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 1e5 + 10, int_max = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 1e9+7;

int n,m;
vector<vector<char>>arr(10000, vector<char>(10000, '#'));
vector<vector<int>>paths(10000, vector<int>(10000, 0));

int main()
{

    cin>>n>>m;

    for(int i = 1; i<=n; ++i)
    {
        for(int j = 1; j<=m; ++j)
        {
            cin>>arr[i][j];
        }
    }

    paths[1][1] = 1;

    for(int i = 1; i<=n; ++i)
    {
        for(int j = 1; j<=m; ++j)
        {
            if(arr[i][j] == '.')
            {
                int val1 =0, val2 = 0;

                if(arr[i-1][j] == '.')
                {
                    val1 = paths[i-1][j];
                }

                if(arr[i][j-1] == '.')
                {
                    val2 = paths[i][j-1];
                }

                paths[i][j] = max(paths[i][j], ((val1%mod)+(val2%mod))%mod);
            }
        }
    }

    //cout<<paths[1][1];

    // for(int i = 1; i<=n; ++i)
    // {
    //     for(int j = 1; j<=m; ++j)
    //     {
    //         cout<<paths[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    cout<<paths[n][m];
}
