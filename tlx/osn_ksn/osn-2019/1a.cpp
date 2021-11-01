#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, c;
    cin >> r >> c;
    int a[r][c], prefix[r][c];
    char input;
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            cin >> input, a[i][j] = input - '0';
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
        {
            if(i == 0 && j == 0)
                prefix[i][j] = a[i][j];
            else if(i == 0)
                prefix[i][j] = prefix[i][j - 1] + a[i][j];
            else if(j == 0)
                prefix[i][j] = prefix[i - 1][j] + a[i][j];
            else
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
        }
    int rectangle_size = prefix[r - 1][c - 1];
    // find possible size pairs
    // and try all combinations
    vector<pair<int, int>> rectangles;
    for(int i = 1; i * i <= rectangle_size; ++i)
    {
        if(rectangle_size % i == 0)
            rectangles.push_back({i, rectangle_size / i});
    }
    // try for each rectangle pair
    int res = INT_MAX;
    for(auto it = rectangles.begin(); it != rectangles.end(); ++it)
    {
        pair<int, int> cur = *it;
        for(int i = 0; i <= r - cur.first; ++i)
            for(int j = 0; j <= c - cur.second; ++j)
            {
                if(i == 0 && j == 0)
                    res = min(res, cur.first * cur.second - prefix[i + cur.first - 1][j + cur.second - 1]);
                else if(i == 0)
                    res = min(res, cur.first * cur.second - prefix[i + cur.first - 1][j + cur.second - 1] + prefix[i + cur.first - 1][j - 1]);
                else if(j == 0)
                    res = min(res, cur.first * cur.second - prefix[i + cur.first - 1][j + cur.second - 1] + prefix[i - 1][j + cur.second - 1]);
                else
                    res = min(res, cur.first * cur.second - prefix[i + cur.first - 1][j + cur.second - 1] + prefix[i + cur.first - 1][j - 1]
                    + prefix[i - 1][j + cur.second - 1] - prefix[i - 1][j - 1]);
            }
        swap(cur.first, cur.second);
        for(int i = 0; i <= r - cur.first; ++i)
            for(int j = 0; j <= c - cur.second; ++j)
            {
                if(i == 0 && j == 0)
                    res = min(res, cur.first * cur.second - prefix[i + cur.first - 1][j + cur.second - 1]);
                else if(i == 0)
                    res = min(res, cur.first * cur.second - prefix[i + cur.first - 1][j + cur.second - 1] + prefix[i + cur.first - 1][j - 1]);
                else if(j == 0)
                    res = min(res, cur.first * cur.second - prefix[i + cur.first - 1][j + cur.second - 1] + prefix[i - 1][j + cur.second - 1]);
                else
                    res = min(res, cur.first * cur.second - prefix[i + cur.first - 1][j + cur.second - 1] + prefix[i + cur.first - 1][j - 1]
                    + prefix[i - 1][j + cur.second - 1] - prefix[i - 1][j - 1]);
            }
    }
    if(res == INT_MAX)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}