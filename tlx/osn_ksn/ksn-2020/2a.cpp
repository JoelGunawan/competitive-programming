#include <bits/stdc++.h>
using namespace std;
int C(int a, int b)
{
    if(a <= b)
        return 1;
    else
    {
        int res = 1;
        for(int i = a; i > max(b, a - b); --i)
            res *= i;
        for(int i = 2; i <= min(b, a - b); ++i)
            res /= i;
        return res;
    }
}
int main()
{
    int n, k;
    int skills[4];
    cin >> n >> k;
    for(int i = 0; i < 4; ++i)
        cin >> skills[i];
    sort(skills, skills + 4);
    int m[k][k];
    for(int i = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            cin >> m[i][j];
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x;
        if(x == 2)
            a[i] = {x, 0};
        else
            cin >> y, a[i] = {x, y};
    }
    // go through all possible values of skills, approx 10^5
    // go through each n and track which skills exist in a set (total n log n)
    // 20^4 * k^2
    // bottom up dp, check for each perpustakaan possible changes and go through the next and check
    // or is it an n * k^2 algo?
    // imagine all is 1, then what algo do you choose? as we need to consider all test cases
    // use value of previous perpustakaan
    // and see how far each subset can go
    // but there are 20^4 subsets, and we can't check them all
    // n * C(20, 4) == 10^5 * 10^5
    // n * C(k, 4) < 1e9 solution
    // check all k subsets
    // how to efficiently generate all subsets of k?
    int subset_count = C(k, 4);
    bool dp[n + 1][subset_count];
    memset(dp, 0, sizeof(dp));
    set<int> required[k];
    for(int i = 0; i < k; ++i)
    {
        for(int j = 0; j < k; ++j)
        {
            if(m[j][i])
                required[i].insert(j);
        }
    }
    vector<int> number_to_subset[subset_count];
    int idx = 0;
    for(int i = 1; i <= k - 3; ++i)
        for(int j = i + 1; j <= k - 2; ++j)
            for(int l = j + 1; l <= k - 1; ++l)
                for(int x = l + 1; x <= k; ++x)
                    number_to_subset[idx++] = {i, j, l, x};
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < subset_count; ++j)
        {
            // check previous
            vector<int> cur_skills = number_to_subset[j];
            // check whether subset fills the current
            if(required)
            // if current is perpustakaan try to check whether it is possible to make this subset using the previous subset
        }
    }
}