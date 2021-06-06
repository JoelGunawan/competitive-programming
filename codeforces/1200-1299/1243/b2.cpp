#include <bits/stdc++.h>

using namespace std;

void runcase()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> counter(26, 0);
    for(int i = 0; i < n; ++i)
    {
        ++counter[s[i] - 'a'];
        ++counter[t[i] - 'a'];
    }
    bool able = true;
    for(int i = 0; i < 26; ++i)
    {
        if(counter[i] % 2 == 1)
        {
            able = false;
            break;
        }
    }
    if(able)
    {
        cout << "Yes" << endl;
        vector<vector<int>> queries;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] != t[i])
            {
                for(int j = i + 1; j < n; ++j)
                {
                    if(s[i] == s[j])
                    {
                        swap(s[j], t[i]);
                        queries.push_back({j, i});
                        break;
                    }
                    else if(s[i] == t[j])
                    {
                        swap(s[i], t[i]);
                        swap(s[i], t[j]);
                        queries.push_back({i, i});
                        queries.push_back({i, j});
                        break;
                    }
                }
            }
        }
        cout << queries.size() << endl;
        for(int i = 0; i < queries.size(); ++i)
        {
            cout << queries[i][0] + 1 << " " << queries[i][1] + 1 << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) runcase();
    return 0;
}
