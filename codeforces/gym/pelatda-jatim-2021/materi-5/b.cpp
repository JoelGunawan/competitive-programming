#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define ins insert
#define endl "\n"
#define lb lower_bound
#define ub upper_Bound
#define mp make_pair
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
vector<int> get_line_segment(int x_0, int y_0, int x_1, int y_1)
{
    return {y_0 - y_1, x_1 - x_0, x_1 * (y_1 - y_0) - y_1 * (x_1 - x_0)};
}
pair<double, double> get_intersect(vector<int> a, vector<int> b)
{
    return {(a[1] * b[2] - a[2] * b[1]) * 1.0 / (a[0] * b[2] - a[2] * b[0]), (a[0] * b[2] - a[2] * b[0]) * 1.0 / (a[1] * b[0] - a[0] * b[1])};
}
int main()
{
	/*
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        cout << get_intersect({a, b, c}, {d, e, f}).first << " " << get_intersect({a, b, c}, {d, e, f}).second << endl;
    }
	*/
    fast_io();
    pair<int, int> a[4], b[4];
    for(int i = 0; i < 4; ++i)
        cin >> a[i].first >> a[i].second;
    for(int i = 0; i < 4; ++i)
        cin >> b[i].first >> b[i].second;
    for(int i = 0; i < 4; ++i)
    {
        if(b[i].first >= min(a[0].first, a[2].first) && b[i].first <= max(a[0].first, a[2].first) 
        && b[i].second >= min(a[0].second, a[2].second) && b[i].second <= max(a[0].second, a[2].second))
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    for(int i = 0; i < 4; ++i)
    {
        double area = 0;
        for(int j = 0; j < 4; ++j)
            area += 1 / 2.0 * abs(a[i].first * b[j].second - b[j].first * a[i].second 
            + b[j].first * b[(j + 1) % 4].second - b[(j + 1) % 4].first * b[j].second
            + b[(j + 1) % 4].first * a[i].second - a[i].first * b[(j + 1) % 4].second);
        if(area == (a[2].first - a[0].first) * (a[2].first - a[0].first))
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    for(int i = 0; i < 4; ++i)
    {
        vector<int> cur_line = get_line_segment(b[i].first, b[i].second, b[(i + 1) % 4].first, b[(i + 1) % 4].second);
        for(int j = 0; j < 4; ++j)
        {
            vector<int> second_line = get_line_segment(a[j].first, a[j].second, a[(j + 1) % 4].first, a[(j + 1) % 4].second);
            pair<double, double> intersect = get_intersect(cur_line, second_line);
            if(intersect.first >= min(a[j].first, a[(j + 1) % 4].first) && intersect.first <= max(a[j].first, a[(j + 1) % 4].first) 
            && intersect.second >= min(a[j].second, a[(j + 1) % 4].second) && intersect.second <= max(a[j].second, a[(j + 1) % 4].second))
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    // check if line segments intersect with 
    cout << "NO" << endl;
    return 0;
}