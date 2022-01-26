#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
#pragma GCC optimize("Ofast")
using namespace std;
bool custom_comp(vector<int> a, vector<int> b)
{
    int max_a = 0, max_b = 0;
    for(auto i : a)
        max_a = max(i, max_a);
    for(auto i : b)
        max_b = max(i, max_b);
    return max_a < max_b;
}
vector<vector<int>> arr;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // only the n lines with the highest maximums matter
    int n, m;
    cin >> n >> m;
    vector<int> a[m];
    for(int i = 0; i < m; ++i)
        a[i] = vector<int>(n);
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    // find max of each line
    // and put that into an array
    // select the first n lines
    arr = vector<vector<int>>(min(n, m), vector<int>(n));
    //if(m <= n)
    //    for(int i = 0; i < arr.size(); ++i)
    //        arr.pb(a[i]);
    //else
    {
        // filter the n lines with largest maximum
        sort(a, a + m, custom_comp);
        reverse(a, a + m);
        for(int i = 0; i < arr.size(); ++i)
            arr[i] = a[i];
    }
    // cek elemennya
    // kalo misal ada elemen di array atas yg lebih besar dari array bawah ilangin aja array bawahnya
    // dan kita pake subsetnya cuman yang >= the minimum maximum in the arr
    int cur_max[2][1 << n];
    memset(cur_max, 0, sizeof(cur_max));
    for(int i = 0; i < arr.size(); ++i)
    {
        // brute force setiap subset
        // trs cari maximumnya
        for(int j = 0; j < n; ++j)
        {
            for(int k = 1; k < 1 << n; ++k)
            {
                for(int l = 0; l <= k; ++l)
                {
                    if((k | l) == k)
                    {
                        int tmp = 0;
                        for(int o = 0; o < n; ++o)
                            if((1 << o) & l)
                                tmp += arr[i][(j + o) % n];
                        cur_max[(i + 1) % 2][k] = max(cur_max[(i + 1) % 2][k], tmp + cur_max[i % 2][k ^ l]);
                    }
                }
            }
        }
    }
    cout << cur_max[arr.size() % 2][(1 << n) - 1] << endl;
    return 0;
}