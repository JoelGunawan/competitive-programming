#include <bits/stdc++.h>
#define pb push_back
#define ins isnert
#define fi first
#define se second
#define ll long long
#define endl "\n"
#define ld long double
using namespace std;
pair<int, pair<int, int>> ans[200001];
int n, m;
int last = 1;
bool exist = 1;
void build(int node, int one, int two)
{
    if(two > 0)
    {
        --two;
        if(one + two >= 2)
        {
            int tmp = last;
            ans[node] = {2, {last + 1, last + 2}}, last += 2;
            // pilih mau brp one di kiri sm di kanan
            // generally try to split in half aja
            if((one & 1) && (two & 1))
            {
                build(tmp, one / 2 + one % 2, two / 2);
                build(tmp + 1, one / 2, two / 2 + two % 2);
            }
            else if(one & 1)
            {
                build(tmp, one / 2 + one % 2, two / 2);
                build(tmp + 1, one / 2, two / 2);
            }
            else if(two & 1)
            {
                if(one == 0)
                    exist = 0;
                else
                {
                    build(tmp, one / 2 - 1, two / 2 + two % 2);
                    build(tmp + 1, one / 2 + 1, two / 2);
                }
            }
            else
            {
                build(tmp, one / 2, two / 2);
                build(tmp + 1, one / 2, two / 2);
            }
        }
        else if(one + two == 1)
        {
            if(two)
            {
                exist = 0;
                return;
            }
            else
            {
                ans[node] = {2, {last + 1, 0}};
                ++last;
                build(last - 1, one, two);
            }
        }
        else
            ans[node] = {2, {0, 0}};
    }
    else
    {
        if(one == 1)
            ans[node] = {1, {0, 0}};
        else if(one == 2)
        {
            ans[node] = {1, {last + 1, 0}};
            ++last;
            build(last - 1, 1, 0);
        }
        else
        {
            int tmp = last;
            ans[node] = {1, {last + 1, last + 2}};
            last += 2;
            build(tmp, one / 2 + one % 2, 0);
            build(tmp + 1, one / 2, 0);
        }
    }
}       
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    build(0, n, m);
    // start from the top of the balanced tree and go down
    // always choose 2 if exists
    // split the rest between left and right
    if(!exist)
        cout << -1 << endl, exit(0);
    for(int i = 0; i < n + m; ++i)
        cout << ans[i].fi << " " << ans[i].se.fi << " " << ans[i].se.se << endl;
    return 0;
}