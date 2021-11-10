#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2); tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
set<vector<int>> x;
int find_res(vector<int> a)
{
    x.insert(a);
    int res = 1;
    for(int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout << endl;
    for(int i = 0; i < a.size(); ++i)
    {
        if((i > 0 && a[i] > a[i - 1]) || (i < a.size() - 1 && a[i] > a[i + 1]))
        {
            // remove i-th number
            // and find res
            vector<int> tmp;
            for(int j = 0; j < a.size(); ++j)
                if(j != i)
                    tmp.pb(a[j]);
            if(x.find(tmp) == x.end())
                res += find_res(tmp);
        }
    }
    return res;
}
ll solve(vector<int> a)
{
    // find largest element and divide the array into left or right
    if(a.size() == 1)
        return 1;
    else if(a.size() == 2)
        return 2;
    ll res = 0;
    int maximum = 0, max_index;
    for(int j = 0; j < a.size(); ++j)
    {
        if(a[j] > maximum)
            maximum = a[j], max_index = j;
    }
    // solve the left, solve the right and solve the cur minus 2
    vector<int> left, right, after;
    for(int j = 0; j < a.size(); ++j)
    {
        if(j < max_index)
            left.pb(j);
        else if(j > max_index)
            right.pb(j);
        if(j != max_index)
            after.pb(j);
    }
    res = (res + solve(left)) % mod, res = (res + solve(right)) % mod, res = (res + solve(after)) % mod;
}
int main()
{
    fast_io();
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // brute force every deletion that is possible
    cout << solve(a) << endl;
    /*
    // use dsu to find head and multiply between left and right, multiply (left + 1) and (right + 1) if both exists
    pair<int, int> arr[n];
    for(int i = 0; i < n; ++i)
        arr[i] = {a[i], i};
    sort(arr, arr + n);
    reverse(arr, arr + n);
    vector<int> inversion_point;
    // find closest smaller than element using stack
    // this is the full solve approach
    // otherwise we need to find the closest left smaller than and the closest right smaller than
    for(int i = 0; i < n; ++i)
    {
        ll idx = arr[i].second, left = 0, right = 0;
        for(int j = idx - 1; j >= 0; --j)
        {
            //cout << dsu[j] << " ";
            if(j > 0 && a[j] > a[j - 1] && a[j] < a[j + 1])
                break;
            else if(dsu[j])
                left += dsu[j];
            else
                break;
        }
        //cout << endl;
        for(int j = idx + 1; j < n; ++j)
        {
            //cout << j << " " << dsu[j] << " ";
            if(dsu[j])
                right += dsu[j];
            else
                break;
        }
        //cout << endl;
        dsu[idx] = (left + 1) * (right + 1);
        dsu[idx] %= mod;
        //cout << left << " " << right << " " << idx << " " << dsu[i] << endl;
    }
    ll res = 0;
    for(int i = 0; i < n; ++i)
        cout << dsu[i] << " ", res = max(res, dsu[i]);
    cout << endl;
    cout << res << endl;   
    */
    return 0;
}