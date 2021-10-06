#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
using namespace std;
bool intersect(pair<pair<int, int>, pair<int ,int>> x, pair<pair<int, int>, pair<int, int>> y)
{
    return x.first.second < y.first.second && x.second.second > y.first.second && y.first.first < x.first.first && y.second.first > x.first.first;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<pair<pair<int, int>, pair<int, int>>> x, y;
    int x1, y1, x2, y2;
    for(int i = 0; i < n; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        pair<pair<int, int>, pair<int, int>> tmp = {{x1, y1}, {x2, y2}};
        if(x1 == x2)
            x.pb(tmp);
        else
            y.pb(tmp);
    }
    for(int i = 0; i < q; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        pair<pair<int, int>, pair<int, int>> cur = {{x1, y1}, {x2, y2}};
        int res = 0;
        if(x1 == x2)
        {
            for(int i = 0; i < y.size(); ++i) 
                if(intersect(cur, y[i])) 
                    ++res;
        }
        else
        {
            for(int i = 0; i < x.size(); ++i) 
                if(intersect(x[i], cur)) 
                    ++res;
        }
        cout << res << endl;
    }
    return 0;
}