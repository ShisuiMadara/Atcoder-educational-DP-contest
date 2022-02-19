    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    const int MAX_N = 1e5 + 10, int_max = 0x3f3f3f3f;
    const ll INF = 1e18;
     
    vector<int>arr[MAX_N];
    vector<int>visited(MAX_N, 0);
    vector<int>dist(MAX_N, 0);
     
    void dfs(int node)
    {
        visited[node] = 1;
     
        for(auto&c:arr[node])
        {
            if(!visited[c])
            {
                dfs(c);
            }
     
            dist[node] = max(dist[node], dist[c]+1);
        }
    }
     
    int main()
    {
        int n,m;
        cin>>n>>m;
     
        for(int i = 0; i<m; ++i)
        {
            int a,b;
            cin>>a>>b;
     
            arr[a].push_back(b);
        }
     
        for(int i = 1; i<=n; ++i)
        {
            if(!visited[i])
                dfs(i);
            
        }
     
        cout<<*max_element(dist.begin(), dist.begin()+n+1);
     
        return 0;
        
    }
