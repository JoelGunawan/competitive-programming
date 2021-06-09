#include<bits/stdc++.h>
using namespace std;
vector<int> memo;
set<int> numbers;
string s;

void update(int game)
{
    auto it = numbers.lower_bound(game); --it; int x = game; x -= *it; --it;
    if(game <= s.size() / 2 + 1)
    {
        memo[game] = 1;
        if(s[game - 1] == '?')
            ++memo[game];
    }
    else if(s[game - 1] == '?')
        memo[game] = memo[*it + 2 * x - 1] + memo[*it + 2 * x];
    else if(s[game - 1] == '0')
        memo[game] = memo[*it + 2 * x - 1];
    else
        memo[game] = memo[*it + 2 * x];
    if(game != s.size())
        update((game - *(--numbers.lower_bound(game)) + 1) / 2 + *(numbers.lower_bound(game)));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int k, q;
    cin >> k >> s >> q;
    int n = s.size();  
    // init numbers
    int cur = 0;
    for(int i = k - 1; i >= 0; --i)
    {
        numbers.insert(cur);
        cur += (1 << i);
    }
    numbers.insert(cur);

    // init memo
    memo = vector<int>(n + 1, 0);
    for(int i = 1; i <= n / 2 + 1; ++i)
        update(i);      

    for(int i = 0; i < q; ++i)
    {
        int p; char c;
        cin >> p >> c;
        s[p - 1] = c;
        update(p);
        cout << memo[n] << endl;
    }
    return 0;
}