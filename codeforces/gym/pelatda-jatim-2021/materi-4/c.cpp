        #include <bits/stdc++.h>
        #define ll long long
        #define pb push_back
        #define pii pair<int, int>
        #define ins insert
        #define pf push_front
        #define ub upper_bound
        #define lb lower_bound
        #define endl "\n"
        #pragma GCC optimize("Ofast")
        #pragma GCC optimize("unroll-loops")
        using namespace std;
        bool adj[1001][1001], vis[1001]; int p[1001];
        vector<int> dfs(int nd)
        {
            // returns the list of connected components
            vector<int> cur = {nd};
            vis[nd] = 1;
            for(int i = 1; i <= 1000; ++i)
            {
                if(adj[nd][i] && !vis[i])
                {
                    vector<int> tmp = dfs(i);
                    for(auto it = tmp.begin(); it != tmp.end(); ++it)
                        cur.pb(*it);
                }
            }
            return cur;
        }
        int main()
        {
            //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
            int n;
            cin >> n;
            for(int i = 1; i <= n; ++i)
                cin >> p[i];
            for(int i = 1; i <= n; ++i)
            {
                for(int j = 1; j <= n; ++j)
                {
                    char in;
                    cin >> in;
                    adj[i][j] = (in == '1');
                }
            }
            vector<int> set[n + 1];
            for(int i = 1; i <= n; ++i)
            {
                if(!vis[i])
                    set[i] = dfs(i), sort(set[i].begin(), set[i].end());
            }
            // for each set we determine what the minimum permutation is and we make the array p that way
            for(int i = 1; i <= n; ++i)
            {
                if(set[i].size() > 0)
                {
                    int numbers[set[i].size()];
                    for(int j = 0; j < set[i].size(); ++j)
                        numbers[j] = p[set[i][j]];
                    sort(numbers, numbers + set[i].size());
                    for(int j = 0; j < set[i].size(); ++j)
                        p[set[i][j]] = numbers[j];
                }
            }
            for(int i = 1; i <= n; ++i)
                cout << p[i] << " ";
            cout << endl;
            return 0;
        }