#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> pairs(k);
        vector<bool> used(2 * n, 0);
        for(int i = 0; i < k; ++i)
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            pairs[i] = make_pair(min(tmp1, tmp2), max(tmp1, tmp2));
            used[tmp1 - 1] = 1; used[tmp2 - 1] = 1;
        }        
        vector<int> unused;
        for(int i = 0; i < 2 * n; ++i)
            if(!used[i])
                unused.push_back(i + 1);
        for(int i = 0; i < unused.size() / 2; ++i)
            pairs.push_back(make_pair(unused[i], unused[unused.size() / 2 + i]));
        int result = 0;
        for(int i = 0; i < pairs.size(); ++i)
        {
            for(int j = i + 1; j < pairs.size(); ++j)
            {
                //cout << pairs[i].first << " " << pairs[i].second << " " << pairs[j].first << " " << pairs[j].second << endl;
                if((pairs[i].second > pairs[j].second && pairs[j].second > pairs[i].first && pairs[i].first > pairs[j].first) 
                || (pairs[j].second > pairs[i].second && pairs[i].second > pairs[j].first && pairs[j].first > pairs[i].first))
                    ++result;
            }
        }
        cout << result << endl;
    }
    return 0;
}