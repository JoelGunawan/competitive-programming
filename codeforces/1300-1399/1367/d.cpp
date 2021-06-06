#include <bits/stdc++.h>

using namespace std;

bool notDone(string t)
{
    for(int i = 0; i < t.size(); ++i)
        if(t[i] == '?')
            return true;
    return false;
}

void solve()
{
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    vector<int> counter(26, 0);
    for(int i = 0; i < s.size(); ++i)
        ++counter[s[i] - 'a'];
    string t(m, '?');
    int zeroCount = 0;
    vector<int> doneIndexes;
    vector<int> nextIndex;
    int last = 26;
    while(notDone(t))
    {
        for(int i = 0; i < m; ++i)
        {
            if(t[i] == '?')
            {
                int sum = 0;
                for(int j : doneIndexes)
                    sum += abs(i - j);
                if(sum == b[i])
                    nextIndex.push_back(i);
            }
        }

        for(int i : nextIndex)
            doneIndexes.push_back(i);

        for(int i = last - 1; i >= 0; --i)
            if(counter[i] >= nextIndex.size())
            {
                last = i;
                break;
            }

        for(int i : nextIndex)
            t[i] = (char)(last + 'a');

        nextIndex.clear();
        //cout << t << endl;
    }
    cout << t << endl;
}

int main()
{
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}
